#include "Reserva.h"
#include <stdio.h>
#include <stdio.h>
#include <time.h>

struct tm setFecha (Reserva *r) 
{

       time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
		r->Fecha=tlocal;

       return tlocal;
}



