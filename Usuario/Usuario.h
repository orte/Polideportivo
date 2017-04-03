#ifndef USUARIO_H_
#define USUARIO_H_

#define MAX_LENGTH	15

typedef struct 
{
	char *nombre ;
	char *ap1;
	char *ap2;
	int id_us;
} Usuario;

void AnadirUsuario(Usuario *u );
void EliminarUsuario(Usuario *u);




#endif
