#include <stdio.h>

#define MAX_NUM 10


 

 

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