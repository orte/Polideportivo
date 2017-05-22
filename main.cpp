#include "Usuario/Usuario.h"
#include "Reserva/Reserva.h"
#include "Instalacion/Instalacion.h"


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

