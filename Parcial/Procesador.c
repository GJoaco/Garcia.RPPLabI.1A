#include <stdio.h>
#include "utn.h"
#include "Procesador.h"

void listarProcesador (eProcesador procesadores[], int tamProc)
{
    printf("*****LISTADO PROCESADORES*****\n\n");
    printf("Id    \n");

    for(int i=0; i<tamProc; i++)
    {
        printf("%d  %s  %.2f %d\n",procesadores[i].id,procesadores[i].nombre,procesadores[i].frecuencia,procesadores[i].nucleos);
    }
}
int obtenerIdProcesador()
{
    int retorno;

    printf("6000. I3\n");
    printf("6001. Ryzen 5\n");
    printf("6002. Pentium\n");
    printf("6003. I7\n");

    utn_getEntero(&retorno,20,"Elija un procesador: ","Error. Vuelva a intentarlo: ",6000,6003);

    return retorno;
}
