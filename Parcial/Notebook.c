#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Notebook.h"
#include "Marca.h"
#include "Tipo.h"
#include "Cliente.h"
#include "utn.h"
#include "Procesador.h"

void mostrarNotebook (eNotebook notebook, int tam, eMarca marcas[], eTipo tipos[],eCliente clientes[],eProcesador procesadores[])
{
    char marca[20];
    char tipo[20];
    char nombre[20];
    char procesador[20];

    for(int i=0; i<tam; i++)
    {
        if(notebook.idMarca==marcas[i].id)
        {
            strcpy(marca,marcas[i].descripcion);
        }
        if(notebook.idTipo==tipos[i].id)
        {
            strcpy(tipo,tipos[i].descripcion);
        }
        if(notebook.idCliente==clientes[i].id)
        {
            strcpy(nombre,clientes[i].nombre);
        }
        if(notebook.idProc==procesadores[i].id)
        {
            strcpy(procesador,procesadores[i].nombre);

        }
    }
    printf("%d    %-10s     %-10s   %-10s   $%.2f   %-10s    %s\n",notebook.id,notebook.modelo,marca,tipo,notebook.precio,nombre,procesador);
}

int obtenerIdNotebook(eNotebook notebooks[],int tam,eMarca marcas[],eTipo tipos[],eCliente clientes[],eProcesador procesadores[])
{
    int retorno;
    int indice;

    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].isEmpty==0)
        {
            mostrarNotebook(notebooks[i],tam,marcas,tipos,clientes,procesadores);
        }
    }
    utn_getEntero(&retorno,20,"Elija una notebook: ","",0,99999);

    indice=buscarNotebook(notebooks,tam,retorno);

    while(indice==-1)
    {
        printf("Error. Id inexistente, vuelva a intentarlo: ");
        utn_getEntero(&retorno,20,"Elija una notebook: ","",0,99999);
        indice=buscarNotebook(notebooks,tam,retorno);
    }

    return retorno;
}

int obtenerIndiceNotebooks(eNotebook notebooks[], int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
int buscarNotebook (eNotebook notebooks[], int tam, int id)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].id==id && notebooks[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void altaNotebook (eNotebook notebooks[], int tam, int id,eCliente clientes[],int tamClientes)
{
    eNotebook aux;
    int indice;

    indice=obtenerIndiceNotebooks(notebooks,tam);

    if(indice!=-1)
    {
        aux.id=id;
        utn_getCadena(aux.modelo,20,20,"Ingrese modelo: ","Error. Vuelva a intentarlo: ");
        aux.idMarca=obtenerIdMarca();
        aux.idTipo=obtenerIdTipo();
        utn_getFlotante(&aux.precio,20,"Ingrese precio: ","Error. Vuelva a intentarlo",1,999999);
        aux.isEmpty=0;
        aux.idCliente=obtenerIdCliente(clientes,tamClientes);
        aux.idProc=obtenerIdProcesador();

        notebooks[indice]=aux;
    }
    else
    {
        printf("\nNo hay espacio disponible\n");
    }


}
void modificarNotebook (eNotebook notebooks[],int tam,eMarca marcas[],eTipo tipos[],eCliente clientes[],eProcesador procesadores[])
{
    int id;
    int opciones;
    char opcion[5];
    int indice;

    utn_getEntero(&id,20,"Ingrese el id de la notebook que desea modificar: ","Error. Vuelva a intentarlo: ",0,99999);
    indice=buscarNotebook(notebooks,tam,id);

    if(indice==-1)
    {
        printf("Error. Ese id no existe.\n");
    }
    else
    {
        printf("Usted a elegido esta notebooks: \n");
        mostrarNotebook(notebooks[indice],tam,marcas,tipos,clientes,procesadores);
        printf("Desea modificarlo? Ingrese s en caso de ser correcto ");
        scanf("%s",opcion);
        opcion[0]=tolower(opcion[0]);

        while(isChar(opcion)==-1)
        {
            printf("Error. Vuelva a intentarlo: ");
            scanf("%s",opcion);
            opcion[0]=tolower(opcion[0]);
        }

        if(opcion[0]=='s')
        {
            printf("\nQue desea modificar?\n");
            printf("1. Precio\n");
            printf("2. Tipo\n");
            utn_getEntero(&opciones,20,"","Error. Vuelva a intentarlo ",1,2);

            if(opciones==1)
            {
                utn_getFlotante(&notebooks[indice].precio,20,"Ingrese nuevo precio: ","Error. Vuelva a intentarlo",1,999999);
                printf("Precio modificado.\n");
            }
            else
            {
                notebooks[indice].idTipo=obtenerIdTipo();
                printf("Tipo modificado.\n");
            }
        }
    }

}

void listarNotebooks (eNotebook notebooks[], int tam,eMarca marcas[], eTipo tipos[],eCliente clientes[],eProcesador procesadores[])
{
    eNotebook aux;

    for(int i=0; i<tam; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(notebooks[i].idMarca > notebooks[j].idMarca)
            {
                aux=notebooks[i];
                notebooks[i]=notebooks[j];
                notebooks[j]=aux;
            }
            else if(notebooks[i].idMarca == notebooks[j].idMarca && notebooks[i].precio > notebooks[j].precio)
            {
                aux=notebooks[i];
                notebooks[i]=notebooks[j];
                notebooks[j]=aux;
            }
        }
    }

    printf("*****LISTA NOTEBOOKS*****\n\n");

    printf("Id      Modelo         Marca        Tipo         Precio      Cliente       Procesador\n");

    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].isEmpty==0)
        {
            mostrarNotebook(notebooks[i],tam, marcas,tipos,clientes,procesadores);
        }
    }
}

void bajaNotebooks (eNotebook notebooks[],int tam,eMarca marcas[],eTipo tipos[],eCliente clientes[],eProcesador procesadores[])
{
    int id;
    char opcion[5];
    int indice;

    utn_getEntero(&id,20,"Ingrese el id de la notebook que desea borrar: ","Error. Vuelva a intentarlo: ",0,99999);
    indice=buscarNotebook(notebooks,tam,id);

    if(indice==-1)
    {
        printf("Error. Ese id no existe.\n");
    }
    else
    {
        printf("Usted a elegido esta notebooks: \n");
        mostrarNotebook(notebooks[indice],tam,marcas,tipos,clientes,procesadores);
        printf("Desea borrarla? Ingrese s en caso de ser correcto ");
        scanf("%s",opcion);
        opcion[0]=tolower(opcion[0]);

        while(isChar(opcion)==-1)
        {
            printf("Error. Vuelva a intentarlo: ");
            scanf("%s",opcion);
            opcion[0]=tolower(opcion[0]);
        }

        if(opcion[0]=='s')
        {
            notebooks[indice].isEmpty=1;
            printf("Notebook borrada con exito.\n");
        }
    }

}


