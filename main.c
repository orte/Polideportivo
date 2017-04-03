#include "Usuario/Usuario.h"
#include "Reserva/Reserva.h"
#include "Instalacion/Instalacion.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

			case 3: 
				break;

			case 4: 
				{
					AnadirInstalacion(&instalaciones[total_int]);
					total_int ++;
				} 
				break;

			case 5: MostrarInstalaciones(instalaciones,total_int);
				break;

			case 6: 
				break;

			case 7: 
				{
					HacerReserva(&reservas[total_r], usuarios,total, instalaciones, total_int );
					total_r ++;
				} 
				break;

			case 8: MostrarReservas(reservas,total_r);
				break;

			case 9: 
				break;




		}
	} while(option != 0);

	//liberamos la memoria reservada con cada malloc
	//liberarMemoria(asignaturas, total);


	return 0;
}


void AnadirUsuario(Usuario *u, int total)
{
	char str[MAX_LENGTH];
	char frmt_str[MAX_LENGTH];
	int id_ref= 0; 

	printf("Ha elegido añadir un nuevo Usuario :  \n" );

	printf("Introduzca su nombre : \n ");

	printf("Nombre: \n ");
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);


	//Para guardar en memoria algo que no sabemos cuanto ocupa.
	sscanf(str, "%s", frmt_str); //eliminar el \n final. Cogemos la entrada y lo convertimos en String

	//reservar la memoria justa para la cadena almacenada
	u->nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //strlen() da la longitud en bytes
																		//Siempre reservo el (tamaño +1)


	//Para tal cosa reservame espacio = (tipo *) malloc((strlen(lo q quiero guardar)+1)* sizeof(tipo de var));

	strcpy(u->nombre, frmt_str); //Guardar(aqui, lo que esta aqui)

	 int i ;
for (i = 0; i < total; i++)
	{
		
		printf("Nombre: %s\n", u[i].id_us);

		if(u[i].id_us>id_ref)
		{
			id_ref=u[i].id_us;
		}
		
	}	
	int nuevo_id= id_ref++;

u->id_us= &nuevo_id;


//ESTA POR TERMINAR ,FALTA ARREGLARLO.

	
}
void MostrarUsuarios(Usuario u[], int total)
{

	int i;

	printf("Listado de usuarios registrados: \n\n");	
	for (i = 0; i < total; i++)
	{
		
		printf("Nombre: %s\n", u[i].nombre);
		printf("ID: %s\n", u[i].id_us);

		printf("\n");
	}
	printf("------------------------------\n");
}

void AnadirInstalacion (Instalacion *ins)
{
	char str[MAX_LENGTH];
	char frmt_str[MAX_LENGTH]; 

	printf("Ha elegido añadir una nueva instalacion :  \n" );

	printf("Introduzca el nombre de la instalacion : \n ");

	printf("Nombre: \n ");
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);


	//Para guardar en memoria algo que no sabemos cuanto ocupa.
	sscanf(str, "%s", frmt_str); //eliminar el \n final. Cogemos la entrada y lo convertimos en String

	//reservar la memoria justa para la cadena almacenada
	ins->nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //strlen() da la longitud en bytes
																		//Siempre reservo el (tamaño +1)


	//Para tal cosa reservame espacio = (tipo *) malloc((strlen(lo q quiero guardar)+1)* sizeof(tipo de var));

	strcpy(ins->nombre, frmt_str); //Guardar(aqui, lo que esta aqui)

}

void MostrarInstalaciones(Instalacion ins[], int total_int)
{


	int i;

	printf("Listado de instalaciones registradas: \n\n");	
	for (i = 0; i < total_int ; i++)
	{
		
		printf("Nombre: %s\n", ins[i].nombre);

		printf("\n");
	}
	printf("------------------------------\n");
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
		//Para guardar en memoria algo que no sabemos cuanto ocupa.
	 //eliminar el \n final. Cogemos la entrada y lo convertimos en String

	//reservar la memoria justa para la cadena almacenada

	printf("Introduce el nombre de la instalacion que quieres reservar : \n ");

	printf("Nombre: \n "); //HAY QUE AÑADIR AQUI UNA VALIDACION QUE COMPRUEBE SI EXISTE
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);
//Para guardar en memoria algo que no sabemos cuanto ocupa.
	sscanf(str, "%s", frmt_str_); //eliminar el \n final. Cogemos la entrada y lo convertimos en String


	//Como todos los datos estan bien hacemos la reserva

	
	//VALIDACION
	for (i = 0; i < total; i++)
	{
		
		printf("Nombre de la i: %s\n", ins[i].nombre);

		printf("str %s\n", frmt_str_ );

		resultado_2 = strcmp(ins[i].nombre, frmt_str_);

		if ( resultado_2 ==0)
			break;

	}


	if(resultado_2==0)
	{

		printf("La reserva se ha realizado correctamente!\n");

	r->nombre_usuario = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //strlen() da la longitud en bytes
																		//Siempre reservo el (tamaño +1)


	//Para tal cosa reservame espacio = (tipo *) malloc((strlen(lo q quiero guardar)+1)* sizeof(tipo de var));

	strcpy(r->nombre_usuario, frmt_str); //Guardar(aqui, lo que esta aqui)

	//reservar la memoria justa para la cadena almacenada
	r->nombre_instalacion = (char *)malloc((strlen(frmt_str_) + 1) * sizeof(char)); //strlen() da la longitud en bytes
																		//Siempre reservo el (tamaño +1)


	//Para tal cosa reservame espacio = (tipo *) malloc((strlen(lo q quiero guardar)+1)* sizeof(tipo de var));

	strcpy(r->nombre_instalacion, frmt_str_); //Guardar(aqui, lo que esta aqui)

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
		
		printf("Nombre de usuario: %s; Instalaion reservada: %s\n ", r[i].nombre_usuario,r[i].nombre_instalacion);

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