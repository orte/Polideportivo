#ifndef USUARIO_H_
#define USUARIO_H_

#ifdef __cplusplus

extern "C" {
	#endif
	#include <stdio.h>
	#include <stdlib.h>



	typedef struct 
	{	
		char *nombre ;
		char *ap1;
		char *ap2;
		int id_us;
	} Usuario;
	
	void AnadirUsuario(Usuario *u, int total);
	void clear_if_needed(char *str);
	void MostrarUsuarios(Usuario u[], int total);
	int EscribirUsuario(char *nom, char *ap_1, char *ap_2) ;
	int LeerUsuarios();

	int EliminarUsuario();


	#ifdef __cplusplus
			}
#endif

#endif
