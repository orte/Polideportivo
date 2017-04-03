#include "Strings/strings.h"
#include "Usuario/Usuario.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Instalacion/Instalacion.h"

#define MAX_USUARIOS 7 // Temporal, para comprobar la correcta creacion de alumnos. Al hacer ficheros la eiminaremos.
#define MAX_INST 7
#define MAX_LENGTH	15

int menu(void);
void clear_if_needed(char *str);
void AnadirUsuario(Usuario *u);
void MostrarUsuarios ();
void AnadirInstalacion(Instalacion *u);
void MostrarInstalaciones();

int main (void)
{
	int option;
	int total = 0;
	int total_int = 0;
	Usuario usuarios [MAX_USUARIOS];
	Instalacion instalaciones [MAX_INST];

do
	{
		option = menu();
		switch (option)
		{
			case 1: 
				{
					AnadirUsuario(&usuarios[total]);
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


		}
	} while(option != 0);

	//liberamos la memoria reservada con cada malloc
	//liberarMemoria(asignaturas, total);


	return 0;
}


void AnadirUsuario(Usuario *u)
{
	char str[MAX_LENGTH];
	char frmt_str[MAX_LENGTH]; 

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
	
}
void MostrarUsuarios(Usuario u[], int total)
{

	int i;

	printf("Listado de usuarios registrados: \n\n");	
	for (i = 0; i < total; i++)
	{
		
		printf("Nombre: %s\n", u[i].nombre);

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
		

		printf("\n");
		printf("Seleccione una opción (e para salir): ");

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		len = sscanf(str, "%d", &option);
		printf("\n");
	} while ((len == 0 && str[0] != 'e') || (len > 0 && (option > 6 || option < 1)));

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