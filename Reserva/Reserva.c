#include "Reserva.h"
#include <stdio.h>
#include <stdio.h>
#include <time.h>

int setFecha (Reserva *r) 
{

       time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
		r->Fecha=tlocal;

       return 0;
}



