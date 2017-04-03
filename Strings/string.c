#include "strings.h"

#include <stdio.h>
#include <stdlib.h>

void printStr(char *str)
{
	while (*str != '\0')
	{
		printf("%c", *str);
		str++;
	}
}

int length(char *str)
{
	int c = 0;
	while (*str != '\0')
	{
		c++;
		str++;
	}
	return c;
}

char* clone(char *str)
{
	int size = length(str);
	char *newStr = (char *) malloc((size + 1) * sizeof(char));
	char *pStr = newStr;

	while(*str != '\0')
	{
		*pStr = *str;
		str++;
		pStr++;
	}

	*pStr = '\0';

	return newStr;
}

void concat(char *str1, char *str2)
{
	while (*str1 != '\0')
		str1++;

	copy(str1, str2);
}

void copy(char *dest, char *src)
{
	while ((*dest = *src) != '\0')
	{
		dest++;
		src++;
	}
}


