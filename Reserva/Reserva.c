#include "Reserva.h"
#include <stdio.h>
#include <stdio.h>
#include <time.h>


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH	15

struct tm* setFecha (Reserva *r) 
{

       time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
		r->Fecha=tlocal;

       return tlocal;
}

void HacerReserva(Reserva *r,Usuario u[],int total, Instalacion ins[], int total_int)
{
	char str[MAX_LENGTH];
	char frmt_str[MAX_LENGTH]; 
	char frmt_str_[MAX_LENGTH]; 


	printf("Ha elegido hacer una reserva :  \n" );

	printf("Introduce tu nombre de usuario : \n ");

	printf("Nombre: \n "); //HAY QUE AÑADIR AQUI UNA VALIDACION QUE COMPRUEBE SI EXISTE

	fgets(str, MAX_LENGTH, stdin);
	sscanf(str, "%s", frmt_str);
	clear_if_needed(str);

	int i ;
	int resultado ;
	int resultado_2;

	//VALIDACION
	for (i = 0; i < total; i++)
	{
		
		printf("Nombre: %s\n", u[i].nombre);

		printf("str %s\n", frmt_str );

		resultado = strcmp(u[i].nombre, frmt_str);

		if ( resultado ==0)
			break;

	}


	if(resultado==0)
	{
		printf("El nombre de usuario es correcto\n" );

	printf("Introduce el nombre de la instalacion que quieres reservar : \n ");

	printf("Nombre: \n "); //HAY QUE AÑADIR AQUI UNA VALIDACION QUE COMPRUEBE SI EXISTE
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);

	sscanf(str, "%s", frmt_str_); 


	//Como todos los datos estan bien hacemos la reserva

	
	//VALIDACION
	for (i = 0; i < total; i++)
	{
		

		resultado_2 = strcmp(ins[i].nombre, frmt_str_);

		if ( resultado_2 ==0)
			break;

	}


	if(resultado_2==0)
	{

		printf("Introduzca por cuanto tiempo utilizara la instalacion (En horas.\n");
		printf("Duracion : \n");

		float dur;

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		sscanf(str, "%f", &r->duracion);
		sscanf(str, "%f", &dur);
		
		


		printf("La reserva se ha realizado correctamente!\n");

	r->nombre_usuario = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //strlen() da la longitud en bytes
																		//Siempre reservo el (tamaño +1)


	//Para tal cosa reservame espacio = (tipo *) malloc((strlen(lo q quiero guardar)+1)* sizeof(tipo de var));

	strcpy(r->nombre_usuario, frmt_str); //Guardar(aqui, lo que esta aqui)

	//reservar la memoria justa para la cadena almacenada
	r->nombre_instalacion = (char *)malloc((strlen(frmt_str_) + 1) * sizeof(char)); 

	
	strcpy(r->nombre_instalacion, frmt_str_);

	setFecha(r);

	 time_t tiempo = time(0);
     struct tm *tlocal = localtime(&tiempo);
     char output[128];
     strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
     

	EscribirReserva(frmt_str,frmt_str_,output,dur);

	}
}

	else
	{
		printf("Los datos son incorrectos.\n");
	}

}

void MostrarReservas(Reserva r[], int total_r)
{


	int i;

	printf("Listado de reservas realizadas: \n\n");	
	for (i = 0; i < total_r ; i++)
	{
		
		printf("Nombre de usuario: %s; Instalacion reservada: %s\n ", r[i].nombre_usuario,r[i].nombre_instalacion);
		struct tm *tlocal = r[i].Fecha;
		char output[128];
        strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
        printf("Fecha :%s\t \t Duracion:%f\n horas",output,r[i].duracion);

		

		printf("\n");
	}
	printf("------------------------------\n");


}

int EscribirReserva(char *nom_us, char *nom_ins,char *fecha_,float duracion) 
  {
  FILE* f; //file pointer
  char* nombre_us=nom_us;
  char* nombre_ins=nom_ins;
  char* fecha=fecha_;
  float dur=duracion;
  
  
  //abrir fichero para escritura "w"
  f = fopen("Reservas.txt", "a");
   
   if(f==NULL)
   {
  //escribir en fichero un string 
  fprintf(f, "Reservas : \n" );

  }
   fprintf(f, " Nombre de usuario : %s\t \t Nombre de instalacion : %s \t \t Fecha: %s \t\t Duracion: %f horas \n", nombre_us,nombre_ins,fecha,dur); //Escribir en fichero
  
  //cerrar fichero
  fclose(f);
  
  return 0;

}

int LeerReservas()
{
   FILE* f;
  char c;
  
  int num_lines = 0;
  
  //abrir fichero para lectura
  f = fopen("Reservas.txt", "r");
  
  //leer mientras no se llegue al final del fichero EOF
  while ((c = fgetc(f)) != EOF) // mientras el siguiente char del txt no sea End Of File..
    {
      if (c == '\n') //Si el siguiente caracter es un salto de linea..
       num_lines++;  //Aumentar numlines...
      putchar(c);
    }
  //cerrar fichero
  fclose(f);
  
  printf("El fichero tiene %i reservas registrados\n", num_lines-1);
  
  return 0;
}


int EliminarReserva()
{
	return 0;
}



