#include <stdio.h>

#define MAX_NUM 10


  int EscribirUsuario(char *nom, char *ap_1, char *ap_2) 
  {
  FILE* f; //file pointer
  char* nombre=nom;
  char *ap1=ap_1;
  char *ap2=ap_2;
  
  //abrir fichero para escritura "w"
  f = fopen("Usuarios.txt", "a");
  
  if(f==NULL)
   {
  //escribir en fichero un string 
  fprintf(f, "Usuarios : \n" );
  }
    fprintf(f, "%s\t \t  %s \t\t  %s\n", nombre,ap1,ap2); //Escribir en fichero
  
  //cerrar fichero
  fclose(f);
  
  return 0;

 }

 int EscribirInstalacion(char *nom) 
  {
  FILE* f; //file pointer
  char* nombre=nom;
  
  //abrir fichero para escritura "w"
  f = fopen("Instalaciones.txt", "a");
   
   if(f==NULL)
   {
  //escribir en fichero un string 
  fprintf(f, "Instalaciones : \n" );

  }
  fprintf(f, " %s\n "  , nombre); //Escribir en fichero
  
  //cerrar fichero
  fclose(f);
  
  return 0;

}

int EscribirReserva(char *nom_us, char *nom_ins,char *fecha_,float duracion) 
  {
  FILE* f; //file pointer
  char* nombre_us=nom_us;
  char* nombre_ins=nom_ins;
  char* fecha=fecha_;
  float dur=duracion;
  
  
  //abrir fichero para escritura "w"
  f = fopen("Reservas.txt", "a");
   
   if(f==NULL)
   {
  //escribir en fichero un string 
  fprintf(f, "Reservas : \n" );

  }
   fprintf(f, " Nombre de usuario : %s\t \t Nombre de instalacion : %s \t \t Fecha: %s \t\t Duracion: %f horas \n", nombre_us,nombre_ins,fecha,dur); //Escribir en fichero
  
  //cerrar fichero
  fclose(f);
  
  return 0;

}