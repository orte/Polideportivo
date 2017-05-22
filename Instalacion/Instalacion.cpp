#include "Instalacion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

#define MAX_LENGTH	15

using namespace std;


void MostrarInstalaciones(Instalacion ins[], int total_int)
{


	int i;

	printf("Listado de instalaciones registradas: \n\n");	
	for (i = 0; i < total_int ; i++)
	{
		
		printf("Nombre: %s\n", ins[i].nombre);

		printf("\n");
	}
	printf("------------------------------\n");

	printf("Ahora realizaremos lo mismo con ficheros \n");

	LeerInstalaciones();
}

void AnadirInstalacion (Instalacion *ins)
{
	char str[MAX_LENGTH];
	char frmt_str[MAX_LENGTH]; 
	char nombre[MAX_LENGTH]; 

	printf("Ha elegido añadir una nueva instalacion :  \n" );

	printf("Introduzca el nombre de la instalacion : \n ");

	printf("Nombre: \n ");
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);


	//Para guardar en memoria algo que no sabemos cuanto ocupa.
	sscanf(str, "%s", frmt_str); //eliminar el \n final. Cogemos la entrada y lo convertimos en String

	//reservar la memoria justa para la cadena almacenada
	ins->nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //strlen() da la longitud en bytes
																		//Siempre reservo el (tamaño +1)


	//Para tal cosa reservame espacio = (tipo *) malloc((strlen(lo q quiero guardar)+1)* sizeof(tipo de var));

	strcpy(ins->nombre, frmt_str); //Guardar(aqui, lo que esta aqui)
	strcpy(nombre, frmt_str); 
	clear_if_needed(frmt_str);


	EscribirInstalacion(nombre);

}
int EliminarInstalacion()
{

	char nombre_aux[MAX_LENGTH];
	char nombre_[MAX_LENGTH]; 
 




	ifstream salida;
	salida.open("Instalaciones.txt",ios::in);

	ofstream entrada;
	entrada.open("temp_2.txt", ios::out);

	if(salida.fail())
	{
		cout<< "Error al abrir el archivo" << endl;

	}
	else
	{
		cout<< "Introduce el nombre de la instalacion a borrar :" << endl;
		cin >> nombre_aux;


		salida>>nombre_;

		while(!salida.eof())
		{
				
					if(strcmp(nombre_aux,nombre_)==0)
					{
						cout<< "ELIMINADA" << endl;
					}
					else
						 {
						 	entrada<< nombre_ << endl;
						 }


				salida>> nombre_;
		}

		entrada.close();
		salida.close();

		remove("Instalaciones.txt");
		rename ("temp_2.txt","Instalaciones.txt");
	}

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
int LeerInstalaciones(void)
{
  
  FILE* f;
  char c;
  
  int num_lines = 0;
  
  //abrir fichero para lectura
	  f = fopen("Instalaciones.txt", "r"); 

	 														//sscanf(str2, "%[^\n]s", string); (?)


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