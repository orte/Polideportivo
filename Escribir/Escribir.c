#include <stdio.h>

#define MAX_NUM 10


  int EscribirUsuario(char *nom, char *ap_1, char *ap_2) 
  {
  FILE* f; //file pointer
  char* nombre=nom;
  char *ap1=ap_1;
  char *ap2=ap_2;
  
  //abrir fichero para escritura "w"
  f = fopen("Usuarios.txt", "w");
  
  //escribir en fichero un string 
  fprintf(f, "Usuarios : \n" );
  
    fprintf(f, " Nombre : %s\t \t Apellido 1 : %s \t\t Apellido 2 : %s\n", nombre,ap1,ap2); //Escribir en fichero
  
  //cerrar fichero
  fclose(f);
  
  return 0;

 }

 int EscribirInstalacion(char *nom) 
  {
  FILE* f; //file pointer
  char* nombre=nom;
  
  //abrir fichero para escritura "w"
  f = fopen("Instalaciones.txt", "w");
  
  //escribir en fichero un string 
  fprintf(f, "Instalaciones : \n" );
  
  fprintf(f, " %s\n "  , nombre); //Escribir en fichero
  
  //cerrar fichero
  fclose(f);
  
  return 0;

}