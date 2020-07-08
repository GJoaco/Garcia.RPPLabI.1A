#include <stdio.h>
#include "utn.h"
#include "Marca.h"


int obtenerIdMarca()
{
    int retorno;

    printf("1000. Acer\n");
    printf("1001. Asus\n");
    printf("1002. Compaq\n");
    printf("1003. HP\n");

    utn_getEntero(&retorno,20,"Elija una marca: ","Error. Vuelva a intentarlo: ",1000,1003);

    return retorno;
}
void listarMarcas (eMarca marcas[], int tamMarcas)
{
    printf("*****LISTADO MARCAS*****\n\n");
    printf("Id    MARCA\n");

    for(int i=0; i<tamMarcas; i++)
    {
        printf("%d  %s\n",marcas[i].id,marcas[i].descripcion);
    }
}
