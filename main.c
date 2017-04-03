#include "Strings/strings.h"
#include "Usuario/Usuario.h"
#include <string.h>
//#include "Administrador/Administrador.h"
#include <stdio.h>
#include <stdlib.h>



int menu(void);
void clear_if_needed(char *str);
int main (void)
{

	menu();

	return 0;
}

int menu(void)
{
	char str[MAX_LENGTH];
	int len;
	int option;

	do {
		printf("\t1. Añadir Usuario\n");
		printf("\t2. Imprimir listado de Usuarios\n");
		printf("\t3. Eliminar Usuario\n");
		printf("\n");
		printf("Seleccione una opción (q para salir): ");

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		len = sscanf(str, "%d", &option);
		printf("\n");
	} while ((len == 0 && str[0] != 'q') || (len > 0 && (option > 3 || option < 1)));

	return (str[0] == 'q')?0:option;
}

void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}