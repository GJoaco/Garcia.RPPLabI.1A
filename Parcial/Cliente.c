#include <stdio.h>
#include "utn.h"
#include "Cliente.h"

int obtenerIdCliente(eCliente clientes[], int tamClientes)
{
    int retorno;

    for(int i=0; i<tamClientes; i++)
    {
        printf("%d   %s   %c\n",clientes[i].id,clientes[i].nombre,clientes[i].sexo);
    }

    utn_getEntero(&retorno,20,"Elija un cliente: ","Error. Vuelva a intentarlo: ",4000,4004);

    return retorno;
}
void listarClientes (eCliente clientes[], int tamClientes)
{
    printf("*****LISTADO CLIENTES*****\n\n");
    printf("Id     Cliente      Sexo\n");

    for(int i=0; i<tamClientes; i++)
    {
        printf("%d   %-10s   %c\n",clientes[i].id,clientes[i].nombre,clientes[i].sexo);
    }
}
