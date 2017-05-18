#ifndef RESERVA_H_
#define RESERVA_H_
#ifdef __cplusplus

extern "C" {
#endif
	#include <stdio.h>
	#include <stdlib.h>


typedef struct 
{
	char *identificador ; //Provisional, lo suyo seria poner un atributo hora y localizar cada reserva por su hora y usuario.
	char *nombre_usuario ; //Luego se hara con el int pero de momento para probar lo hacemos asi.
	char *nombre_instalacion;
	struct tm *Fecha;
	float duracion;
} Reserva;

struct tm* setFecha(Reserva *r);


		#ifdef __cplusplus
		}
#endif

#endif
