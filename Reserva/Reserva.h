#ifndef RESERVA_H_
#define RESERVA_H_
#ifdef __cplusplus

extern "C" {
#endif
	#include <stdio.h>
	#include <stdlib.h>
	#include "../Instalacion/Instalacion.h"
#include "../Usuario/Usuario.h"


typedef struct 
{
	char *identificador ; //Provisional, lo suyo seria poner un atributo hora y localizar cada reserva por su hora y usuario.
	char *nombre_usuario ; //Luego se hara con el int pero de momento para probar lo hacemos asi.
	char *nombre_instalacion;
	struct tm *Fecha;
	float duracion;
} Reserva;

struct tm* setFecha(Reserva *r);
struct tm* setFecha(Reserva *r);
void HacerReserva(Reserva *r,Usuario u[],int total, Instalacion ins[], int total_int);
int EscribirReserva(char *nom_us, char *nom_ins,char fecha[128], float duracion);
int LeerReservas();
int EliminarReserva()
;

void MostrarReservas(Reserva r[], int total_r);
void clear_if_needed(char *str);



		#ifdef __cplusplus
		}
#endif

#endif
