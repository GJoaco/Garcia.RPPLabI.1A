#include <stdio.h>
#include "utn.h"
#include "Tipo.h"

void listarTipos (eTipo tipos[], int tamTipos)
{
    printf("*****LISTADO TIPOS*****\n\n");
    printf("Id    Tipo\n");

    for(int i=0; i<tamTipos; i++)
    {
        printf("%d  %s\n",tipos[i].id,tipos[i].descripcion);
    }
}
int obtenerIdTipo()
{
    int retorno;

    printf("5000. Gamer\n");
    printf("5001. Disenio\n");
    printf("5002. Ultrabook\n");
    printf("5003. Normal\n");

    utn_getEntero(&retorno,20,"Elija un tipo: ","Error. Vuelva a intentarlo: ",5000,5003);

    return retorno;
}
