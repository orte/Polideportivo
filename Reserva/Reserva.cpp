#include "Reserva.h"
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <fstream>



#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH	15

using namespace std;

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
	char nombre[MAX_LENGTH];
	char nombre_aux[MAX_LENGTH];
	char frmt_str[MAX_LENGTH]; 
	char frmt_str_[MAX_LENGTH]; 



	char nombre_auxaux[MAX_LENGTH];
	char ap1_aux[MAX_LENGTH];
	char ap2_aux[MAX_LENGTH];



	printf("Ha elegido hacer una reserva :  \n" );

	printf("Introduce tu nombre de usuario : \n ");

	printf("Nombre: \n "); //HAY QUE AÑADIR AQUI UNA VALIDACION QUE COMPRUEBE SI EXISTE

	cin >> nombre_aux;
	int i ;
	int resultado ;
	int resultado_2;

	//VALIDACION

/*for (i = 0; i < total; i++)
	{
		
		printf("Nombre: %s\n", u[i].nombre);

		printf("str %s\n", frmt_str );

		resultado = strcmp(u[i].nombre, frmt_str);

		if ( resultado ==0)
			break;

	}

*/

	ifstream salida;
	salida.open("Usuarios.txt",ios::in);
	

if(salida.fail())
	{
		cout<< "Error al abrir el archivo" << endl;

	}
	else
	{
		
		salida>>nombre;




		while(!salida.eof())
		{
			salida>> ap1_aux >> ap2_aux;
			cout<<"J";
			if(strcmp(nombre,nombre_aux)==0)
					{
						cout<<"P";
						resultado=0;
					}

		}
		salida.close();
	}

	
	if(resultado==0)
	{

			char nombrei_aux[MAX_LENGTH];
			char nombrei[MAX_LENGTH];

		cout<< "Usuario correcto" << endl;
		ifstream salida_1;
		cout<< "Ingrese ahora el nombre de la instalacion :" << endl;
		cin >> nombrei;
		salida.open("Instalaciones.txt",ios::in);
	

	if(salida.fail())
	{
		cout<< "Error al abrir el archivo" << endl;

	}
	else
	{ 
		char nombrei_aux[MAX_LENGTH];
		
		


salida>>nombrei_aux;

		while(!salida.eof())
		{
			salida>>nombrei_aux;

		
			if(strcmp(nombrei,nombrei_aux)==0)
					{
						cout<<"P";
						resultado_2=0;
					}

		}
		salida.close();
	}


		/**printf("El nombre de usuario es correcto\n" );

	printf("Introduce el nombre de la instalacion que quieres reservar : \n ");

	printf("Nombre: \n "); //HAY QUE AÑADIR AQUI UNA VALIDACION QUE COMPRUEBE SI EXISTE
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);

	sscanf(str, "%s", frmt_str_); 


	
	
	//VALIDACION
	for (i = 0; i < total; i++)
	{
		

		resultado_2 = strcmp(ins[i].nombre, frmt_str_);

		if ( resultado_2 ==0)
			break;

	}**/


	if(resultado_2==0)
	{

		printf("Introduzca por cuanto tiempo utilizara la instalacion (En horas.\n");
		printf("Duracion : \n");

		float dur;
		char d_[MAX_LENGTH];
		cin >> d_;  //fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);//
		sscanf(d_, "%f", &r->duracion);
		sscanf(d_, "%f", &dur);
		
		


		printf("La reserva se ha realizado correctamente!\n");

	r->nombre_usuario = (char *)malloc((strlen(nombre_aux) + 1) * sizeof(char)); //strlen() da la longitud en bytes
																		//Siempre reservo el (tamaño +1)


	//Para tal cosa reservame espacio = (tipo *) malloc((strlen(lo q quiero guardar)+1)* sizeof(tipo de var));

	strcpy(r->nombre_usuario, nombre_aux); //Guardar(aqui, lo que esta aqui)

	//reservar la memoria justa para la cadena almacenada
	r->nombre_instalacion = (char *)malloc((strlen(nombrei) + 1) * sizeof(char)); 

	
	strcpy(r->nombre_instalacion, nombrei);

	setFecha(r);

	 time_t tiempo = time(0);
     struct tm *tlocal = localtime(&tiempo);
     char output[128];
     strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
     

	EscribirReserva(nombre_aux,nombrei,output,dur);

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
   fprintf(f, " %s\t \t  %s \t \t  %s \t\t  %f  \n", nombre_us,nombre_ins,fecha,dur); //Escribir en fichero
  
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
	

	char nombre_usuario_[MAX_LENGTH];
	char nombre_usuario_aux[MAX_LENGTH];
	char nombre_inst_[MAX_LENGTH];
	char nombre_inst_aux[MAX_LENGTH];
	char fecha_[MAX_LENGTH];
	char fecha_aux[MAX_LENGTH];
	char duracion_[MAX_LENGTH];



	ifstream salida;
	salida.open("Reservas.txt",ios::in);

	ofstream entrada;
	entrada.open("temp_3.txt", ios::out);

	if(salida.fail())
	{
		cout<< "Error al abrir el archivo" << endl;

	}
	else
	{
		cout<< "Introduce los siguientes campos de la reserva a borrar :" << endl;
		cout<< "Nombre del usuario que hizo la reserva :" << endl;

		cin >> nombre_usuario_aux;

		cout<< "Nombre de la instalacion :" << endl;
		cin >> nombre_inst_aux;

		//cout << "Fecha de la reserva :"  << endl;



		salida>>nombre_usuario_>> nombre_inst_;

		while(!salida.eof())
		{
				salida>> fecha_ >> duracion_;

					if(strcmp(nombre_usuario_,nombre_usuario_aux)==0) 
				{
						if (strcmp(nombre_inst_,nombre_inst_aux) ==0)
					{
						cout<< "ELIMINADO" << endl;
					}
				}
					else
						 {
						 	entrada<<nombre_usuario_<< " " << nombre_inst_ <<" " <<fecha_<<  " " << duracion_ << " " << endl;
						 }

				salida>> nombre_usuario_;
		}

		entrada.close();
		salida.close();

		remove("Reservas.txt");
		rename ("temp_3.txt","Reservas.txt");
	}
}



