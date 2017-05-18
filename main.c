#include "Usuario/Usuario.h"
#include "Reserva/Reserva.h"
#include "Instalacion/Instalacion.h"
#include "Leer/Leer.h"
#include "Escribir/Escribir.h"


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_USUARIOS 7 // Temporal, para comprobar la correcta creacion de alumnos. Al hacer ficheros la eiminaremos.
#define MAX_INST 7
#define MAX_R 4 
#define MAX_LENGTH	15

int menu(void);
void clear_if_needed(char *str);
void AnadirUsuario(Usuario *u, int total);
void MostrarUsuarios ();
void AnadirInstalacion(Instalacion *u);
void MostrarInstalaciones();
void HacerReserva(Reserva *r,Usuario *u,int total,Instalacion *i, int total_int);
void MostrarReservas();
int EliminarUsuario(); //Falta

int EliminarInstalacion();
int EliminarReserva();


int main (void)
{
	int option;
	int total = 0;
	int total_int = 0;
	int total_r =0;

	Usuario usuarios [MAX_USUARIOS];
	Instalacion instalaciones [MAX_INST];
	Reserva reservas [MAX_R];

do
	{
		option = menu();
		switch (option)
		{
			case 1: 
				{
					AnadirUsuario(&usuarios[total],total);
					total++;
				} 
				break;

			case 2: MostrarUsuarios(usuarios,total);
				break;

			case 3: EliminarUsuario();
				break;

			case 4: 
				{
					AnadirInstalacion(&instalaciones[total_int]);
					total_int ++;
				} 
				break;

			case 5: MostrarInstalaciones(instalaciones,total_int);
				break;

			case 6: EliminarInstalacion();
				break;

			case 7: 
				{
					HacerReserva(&reservas[total_r], usuarios,total, instalaciones, total_int );
					total_r ++;
				} 
				break;

			case 8: MostrarReservas(reservas,total_r);
				break;

			case 9: EliminarReserva();
				break;




		}
	} while(option != 0);

	//liberamos la memoria reservada con cada malloc
	//liberarMemoria(asignaturas, total);


	return 0;
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

int menu(void)
{
	char str[MAX_LENGTH];
	int len;
	int option;

	do {
		printf("\t1. Registrar nuevo  Usuario\n");
		printf("\t2. Imprimir listado de Usuarios\n");
		printf("\t3. Eliminar Usuario\n");
		printf("\t4. Registrar nueva instalacion\n");
		printf("\t5. Imprimir listado de las instalaciones disponibles \n");
		printf("\t6. Dar de baja una instalacion\n");
		printf("\t7. Realizar una reserva \n");
		printf("\t8. Imprimir listado de las reservas realizadas \n");
		printf("\t9. Dar de baja una reserva\n");
		
		

		printf("\n");
		printf("Seleccione una opción (e para salir): ");

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		len = sscanf(str, "%d", &option);
		printf("\n");
	} while ((len == 0 && str[0] != 'e') || (len > 0 && (option > 9 || option < 1)));

	return (str[0] == 'e')?0:option;
}

void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}


//FALTA HACER ESTO UNA VEZ QUE HAYAMOS HECHO EL METODO DE LECTURA (con sentio) DE FICHEROS ~ J


int EliminarReserva()
{
	return 0;
}