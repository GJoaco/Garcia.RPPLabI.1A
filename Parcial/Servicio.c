#include <stdio.h>
#include "Servicio.h"
#include "utn.h"

int obtenerIdServicio()
{
    int retorno;

    printf("2000. Bateria $250\n");
    printf("2001. Antivirus $300\n");
    printf("2002. Actualizacion $400\n");
    printf("2003. Fuente $600\n");

    utn_getEntero(&retorno,20,"Elija un servicio: ","Error. Vuelva a intentarlo: ",2000,2003);

    return retorno;
}

void listarServicios (eServicio servicios[], int tamServicios)
{
    printf("*****LISTADO SERVICIOS*****\n\n");
    printf("Id    Servicio       precio\n");

    for(int i=0; i<tamServicios; i++)
    {
        printf("%d  %-13s  $%d\n",servicios[i].id,servicios[i].descripcion,servicios[i].precio);
    }
}
