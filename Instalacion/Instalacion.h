#ifndef INSTALACION_H_
#define INSTALACION_H_

#ifdef __cplusplus

extern "C" {
#endif
	#include <stdio.h>
	#include <stdlib.h>


				typedef struct 
				{
				char *nombre ;
				int id_ins;
				} 	
				Instalacion;
				
void MostrarInstalaciones(Instalacion ins[], int total_int);
void AnadirInstalacion (Instalacion *ins);
int EliminarInstalacion();
int EscribirInstalacion(char *nom); 
int LeerInstalaciones(void);
void clear_if_needed(char *str);

				#ifdef __cplusplus
			}
#endif

#endif
