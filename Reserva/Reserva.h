#ifndef RESERVA_H_
#define RESERVA_H_


typedef struct 
{
	char *identificador ; //Provisional, lo suyo seria poner un atributo hora y localizar cada reserva por su hora y usuario.
	char *nombre_usuario ; //Luego se hara con el int pero de momento para probar lo hacemos asi.
	char *nombre_instalacion;
	struct tm *Fecha;
} Reserva;

struct tm setFecha(Reserva *r);
#endif
