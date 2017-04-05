#include <stdio.h>
#include "Polideportivo/Usuario/Usuario.h"


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

  char name[30];
  char ap1[30];
  char ap2[30];

  Usuario *u;

  int num_l=0;
  FILE  *f;
  f = fopen("Usuarios.txt","r");  
 
    
  while 
    (fscanf(f,"%s %s %s",name,ap1,ap2) != EOF)  //&ID
  {/*Leer datos */
       u->nombre=name;
       u->ap1=ap1;
       u->ap=ap2;
       num_l++;

  }
  fclose(f); 


  MostrarUsuarios(Usuario u[],num_l-1);


  return 0;

}

