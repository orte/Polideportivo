#include "Usuario.h"
#include <stdio.h>
#include <iostream>
#include <fstream>


#define MAX_LENGTH	15
#include <string.h>

#include <stdlib.h>
#include <time.h>



using namespace std;


void AnadirUsuario(Usuario *u, int total)
{
	char str[MAX_LENGTH];
	char frmt_str[MAX_LENGTH];
	

	char nombre[MAX_LENGTH];
	char ap1[MAX_LENGTH];
	char ap2[MAX_LENGTH];


	printf("Ha elegido añadir un nuevo Usuario :  \n" );

	printf("Introduzca su nombre : \n ");

	printf("Nombre: \n ");
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);


	//Para guardar en memoria algo que no sabemos cuanto ocupa.
	sscanf(str, "%s", frmt_str); //eliminar el \n final. Cogemos la entrada y lo convertimos en String

	//reservar la memoria justa para la cadena almacenada
	u->nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //strlen() da la longitud en bytes
																		//Siempre reservo el (tamaño +1)


	//Para tal cosa reservame espacio = (tipo *) malloc((strlen(lo q quiero guardar)+1)* sizeof(tipo de var));

	strcpy(u->nombre, frmt_str); //Guardar(aqui, lo que esta aqui)
	strcpy(nombre, frmt_str); 
	clear_if_needed(frmt_str);

	printf("Apellido 1: \n ");
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);


	//Para guardar en memoria algo que no sabemos cuanto ocupa.
	sscanf(str, "%s", frmt_str); //eliminar el \n final. Cogemos la entrada y lo convertimos en String

	//reservar la memoria justa para la cadena almacenada
	u->ap1 = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //strlen() da la longitud en bytes
																		//Siempre reservo el (tamaño +1)


	//Para tal cosa reservame espacio = (tipo *) malloc((strlen(lo q quiero guardar)+1)* sizeof(tipo de var));

	strcpy(u->ap1, frmt_str); //Guardar(aqui, lo que esta aqui)
	strcpy(ap1, frmt_str); 
	clear_if_needed(frmt_str);

	printf("Apellido 2: \n ");
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);


	//Para guardar en memoria algo que no sabemos cuanto ocupa.
	sscanf(str, "%s", frmt_str); //eliminar el \n final. Cogemos la entrada y lo convertimos en String

	//reservar la memoria justa para la cadena almacenada
	u->ap2 = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //strlen() da la longitud en bytes
																		//Siempre reservo el (tamaño +1)


	//Para tal cosa reservame espacio = (tipo *) malloc((strlen(lo q quiero guardar)+1)* sizeof(tipo de var));

	strcpy(u->ap2, frmt_str); //Guardar(aqui, lo que esta aqui)
	strcpy(ap2, frmt_str); 
	clear_if_needed(frmt_str);

	int id_ref= 0; 
	 int i ;
for (i = 0; i < total; i++)
	{
		
		printf("ID: %d\n", u[i].id_us);

		if(u[i].id_us>id_ref)
		{
			id_ref=u[i].id_us;
		}
		
	}	

	int nuevo_id= id_ref+1;
	printf("%d\n",nuevo_id );

EscribirUsuario(nombre,ap1,ap2);	
//u->id_us = &nuevo_id; //Da error ,no se porque

printf(" El ID del usuario es: %d\n",&u->id_us );


//ESTA POR TERMINAR ,FALTA ARREGLARLO.

	
}


void MostrarUsuarios(Usuario u[], int total)
{

	int i;

	printf("Listado de usuarios registrados: \n\n");	
	for (i = 0; i < total; i++)
	{
		
		printf("Nombre: %s\n", u[i].nombre);
		printf("Ap1: %s\n", u[i].ap1);
		printf("Ap2: %s\n", u[i].ap2);
		printf("ID: %s\n", u[i].id_us);

		printf("\n");
	}
	printf("------------------------------\n");


	printf("Ahora haremos lo mismo pero leeremos de fichero \n");
	LeerUsuarios();
}

void EscribirUsuario(char *nom, char *ap_1, char *ap_2) 
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
    fprintf(f, "%s %s %s\n", nombre,ap1,ap2); //Escribir en fichero
  
  //cerrar fichero
  fclose(f);
  


 }
 
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

void EliminarUsuario()
{
	char nombre_aux[MAX_LENGTH];
	char nombre_auxaux[MAX_LENGTH];
	char ap1_aux[MAX_LENGTH];
	char ap2_aux[MAX_LENGTH];



	ifstream salida;
	salida.open("Usuarios.txt",ios::in);

	ofstream entrada;
	entrada.open("temp.txt", ios::out);

	if(salida.fail())
	{
		cout<< "Error al abrir el archivo" << endl;

	}
	else
	{
		cout<< "Introduce el nombre del usuario a borrar :" << endl;
		cin >> nombre_auxaux;
		int i=0;


		salida>>nombre_aux;

		while(!salida.eof())
		{
				salida>> ap1_aux >> ap2_aux;

					if(strcmp(nombre_aux,nombre_auxaux)==0)
					{
						cout<< "ELIMINADO" << endl;
						i=1;

					}
					else
						 {
						 	entrada<<nombre_aux<< " " <<ap1_aux << " " << ap2_aux << " " << endl;
						 }


				salida>> nombre_aux;

				
		}

				if(i=0)
				{
					cout<< "Usuario no encontrado";
				}
		entrada.close();
		salida.close();

		remove("Usuarios.txt");
		rename ("temp.txt","Usuarios.txt");

	
	}




}







