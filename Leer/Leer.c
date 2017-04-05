#include <stdio.h>

#define MAX_NUM 10

int LeerUsuarios(void)
{
	
  FILE* f;
  char c;
  
  int num_lines = 0;
  
  //abrir fichero para lectura
  f = fopen("Usuarios.txt", "r");
  
  //leer mientras no se llegue al final del fichero EOF
  while ((c = fgetc(f)) != EOF)
    {
      if (c == '\n')
	     num_lines++;  
      putchar(c);
    }
  //cerrar fichero
  fclose(f);
  
  printf("El fichero tiene %i usuarios registrados\n", num_lines-1);
  
  return 0;
}

int LeerInstalaciones(void)
{
  
  FILE* f;
  char c;
  
  int num_lines = 0;
  
  //abrir fichero para lectura
  f = fopen("Instalaciones.txt", "r");
  
  //leer mientras no se llegue al final del fichero EOF
  while ((c = fgetc(f)) != EOF)
    {
      if (c == '\n')
       num_lines++;  
      putchar(c);
    }
  //cerrar fichero
  fclose(f);
  
  printf("El fichero tiene %i instalaciones registrados\n", num_lines-1);
  
  return 0;
}

int LeerReservas()
{
   FILE* f;
  char c;
  
  int num_lines = 0;
  
  //abrir fichero para lectura
  f = fopen("Reservas.txt", "r");
  
  //leer mientras no se llegue al final del fichero EOF
  while ((c = fgetc(f)) != EOF)
    {
      if (c == '\n')
       num_lines++;  
      putchar(c);
    }
  //cerrar fichero
  fclose(f);
  
  printf("El fichero tiene %i reservas registrados\n", num_lines-1);
  
  return 0;
}

int SacarUsuarios()
{

}

