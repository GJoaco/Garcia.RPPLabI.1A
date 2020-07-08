#include <stdio.h>
#include <string.h>
#include "utn.h"
#include "Trabajo.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicio.h"
#include "Notebook.h"

void mostrarTrabajo (eTrabajo trabajo,int tamTrabajos,eNotebook notebooks[],eServicio servicios[])
{
    char notebook[20];
    char servicio[20];

    for(int i=0; i<tamTrabajos; i++)
    {
        if(trabajo.idNotebook==notebooks[i].id)
        {
            strcpy(notebook,notebooks[i].modelo);
        }
        if(trabajo.idServicio==servicios[i].id)
        {
            strcpy(servicio,servicios[i].descripcion);
        }
    }

    printf("%d     %-6s        %-13s    %02d/%02d/%d\n",trabajo.id,notebook,servicio,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
}



int obtenerIndiceTrabajo(eTrabajo trabajos[], int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(trabajos[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}





void listarTrabajos(eTrabajo trabajos[],int tamTrabajos,eNotebook notebooks[], int tam,eServicio servicios[], int tamServicios)
{
    printf("*****LISTADO TRABAJOS*****\n\n");
    printf("Id    Notebook      Servicio         Fecha\n");

    for(int i=0; i<tamTrabajos; i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            mostrarTrabajo(trabajos[i],tamTrabajos,notebooks,servicios);
        }

    }

}

void altaTrabajos (eTrabajo trabajos[], eNotebook notebooks[],eMarca marcas[],eTipo tipos[],int id,int tam,eCliente clientes[],eProcesador procesadores[])
{
    eTrabajo aux;
    int indice;

    indice=obtenerIndiceNotebooks(notebooks,tam);

    if(indice!=-1)
    {
        aux.id=id;
        aux.idNotebook=obtenerIdNotebook(notebooks,tam,marcas,tipos,clientes,procesadores);
        aux.idServicio=obtenerIdServicio();
        utn_getEntero(&aux.fecha.dia,20,"Ingrese dia: ","Error. Vuelva a intentarlo",1,31);
        utn_getEntero(&aux.fecha.mes,20,"Ingrese mes: ","Error. Vuelva a intentarlo",1,12);
        utn_getEntero(&aux.fecha.anio,20,"Ingrese anio: ","Error. Vuelva a intentarlo",2020,2030);
        aux.isEmpty=0;

        trabajos[indice]=aux;
    }
    else
    {
        printf("\nNo hay espacio disponible\n");
    }





}
