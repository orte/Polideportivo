#ifndef STRINGS_H_
#define STRINGS_H_

//imprime la cadena pasada caracter a caracter
void printStr(char *str);

//obtiene la longitud de la cadena pasada (sin contar el \0)
int length(char *str);

//Crea una copia de la cadena pasada
//Reserva memoria internamente.
//Es el programador el que debe liberar la cadena copia
char* clone(char *str);

//concatena a str1 la cadena str2
//supone que str1 tiene suficiente espacio para la dos cadenas (incluido el \0 final)
void concat(char *str1, char *str2);

//copia la cadena src en el destino
//dest tiene que tener suficiente espacio para almacenar src (incluido el \0 final)
void copy(char *dest, char *src);

#endif
