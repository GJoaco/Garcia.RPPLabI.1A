#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Notebook.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Cliente.h"
#include "Informe.h"


void menuInformes(eNotebook notebooks[],int tam,eTipo tipos[],eMarca marcas[],eCliente clientes[],int tamVarios,eServicio servicios[],eTrabajo trabajos[],int tamTrabajo,eProcesador procesadores[])
{
    int opciones;

    do
    {
        system("cls");
        printf("*****MENU INFORMES*****\n\n");

        printf("1. Mostrar notebooks de x tipo\n");
        printf("2. Mostrar notebooks de x marca\n");
        printf("3. Mostrar notebooks mas baratas\n");
        printf("4. Mostrar notebooks por marca\n");
        printf("5. Mostrar cuantas notebooks hay de x marca y x tipo\n");
        printf("6. Mostrar marca/s mas elegida/s\n");
        printf("7. Mostrar trabajos hechos a x notebook\n");
        printf("8. Mostrar la suma de los importes de los servicios que se le hicieron a una notebook\n");
        printf("9. Mostrar notebooks que hayan recibido x servicio\n");
        printf("10. Mostrar servicios realizados en x fecha\n");
        printf("11. Mostrar notebook con mas nucleos\n");
        printf("12. Mostrar notebooks con x procesador\n");
        printf("13. Mostrar notebook con mas potencia\n");
        printf("14. Mostrar notebook de x cliente\n");
        printf("15. Mostrar notebook menos potente\n");
        printf("16. Mostrar notebooks por procesador\n");
        printf("17. Mostrar notebooks por cliente\n");
        printf("19. Salir\n");

        utn_getEntero(&opciones,20,"\nIngrese una opcion: ","Error. Vuelva a intentarlo",1,19);

        switch(opciones)
        {
        case 1:
            system("cls");
            mostrarNotebookDeTipo(notebooks,tam,tipos,marcas,clientes,procesadores);
            system("pause");
            break;
        case 2:
            system("cls");
            mostrarNotebookDeMarca(notebooks,tam,tipos,marcas,clientes,procesadores);
            system("pause");

            break;
        case 3:
            system("cls");
            notebooksBaratas(notebooks,tam,tipos,marcas,clientes,procesadores);
            system("pause");

            break;
        case 4:
            system("cls");
            mostrarNotebookPorMarca(notebooks,tam,tipos,tamVarios,marcas,clientes,procesadores);
            system("pause");

            break;
        case 5:
            system("cls");
            cantidadTipoYMarca(notebooks,tam,tipos,marcas,clientes);
            system("pause");

            break;
        case 6:
            system("cls");
            mostrarMarcasMasElegidas(notebooks,tam,marcas,tamVarios);
            system("pause");

            break;
        case 7:
            system("cls");
            trabajosRealizados(notebooks,tam,trabajos,tamTrabajo,marcas,tipos,clientes,servicios,procesadores);
            system("pause");
            break;
        case 8:
            system("cls");
            sumaDeImportes(notebooks,tam,clientes,marcas,tipos,tamTrabajo,trabajos,procesadores);
            system("pause");
            break;
        case 9:
            system("cls");
            mostrarNotebooksConServicio(notebooks,tam,servicios,tamVarios,trabajos,tamTrabajo,clientes,marcas,tipos,procesadores);
            system("pause");
            break;
        case 10:
            system("cls");
            mostrarServiciosFecha(servicios,trabajos,tamTrabajo);
            system("pause");
            break;
        case 11:
            system("cls");
            masNucleos(notebooks,tam,procesadores,marcas,tipos,clientes,tamVarios);
            system("pause");
            break;
        case 12:
            system("cls");
            mostrarNotebooksProcesador(notebooks,tam,procesadores,marcas,tipos,clientes);
            system("pause");
            break;
        case 13:
            system("cls");
            masPotencia(notebooks,tam,procesadores,marcas,tipos,clientes,tamVarios);
            system("pause");
            break;
        case 14:
            system("cls");
            notebooksDeCliente(notebooks,tam,procesadores,marcas,tipos,clientes,tamVarios);
            system("pause");
            break;
        case 15:
            system("cls");
            menosPotente(notebooks,tam,procesadores,marcas,tipos,clientes,tamVarios);
            system("pause");
            break;
        case 16:
            system("cls");
            mostrarNotebookPorProcesador(notebooks,tam,tipos,tamVarios,marcas,clientes,procesadores);
            system("pause");
            break;
        case 17:
            system("cls");
            mostrarServiciosFecha(servicios,trabajos,tamTrabajo);
            system("pause");
            break;
        case 18:
            system("cls");
            listarPotencia(notebooks,tam,marcas,tipos,clientes,procesadores);
            system("pause");
            break;
        case 19:
            break;
        }
    }while(opciones!=19);
}

void mostrarNotebookPorMarca(eNotebook notebooks[],int tam,eTipo tipos[], int tamVarios,eMarca marcas[],eCliente clientes[],eProcesador procesadores[])
{
    int flag=0;

    for(int i=0; i<tamVarios; i++)
    {
        printf("%s: \n",marcas[i].descripcion);

        for(int j=0; j<tam;j++)
        {
            if(notebooks[j].idMarca==marcas[i].id && notebooks[i].isEmpty==0)
            {
                mostrarNotebook(notebooks[j],tam,marcas,tipos,clientes,procesadores);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No hay notebooks que mostrar\n");
        }
        flag=0;
        printf("\n");
    }
}

void mostrarNotebookDeMarca (eNotebook notebooks[],int tam,eTipo tipos[],eMarca marcas[],eCliente clientes[],eProcesador procesadores[])
{
    int marca;

    marca=obtenerIdMarca();



    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].idMarca==marca && notebooks[i].isEmpty==0)
        {
            mostrarNotebook(notebooks[i],tam,marcas,tipos,clientes,procesadores);
        }
    }
}

void notebooksBaratas (eNotebook notebooks[],int tam,eTipo tipos[],eMarca marcas[],eCliente clientes[],eProcesador procesadores[])
{
    eNotebook aux;
    int contador=0;
    int contador2=0;
    int flag=0;
    float menorPrecio;

    printf("Notebook/s mas barata/s:\n");

    for(int i=0; i<tam; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(notebooks[i].precio > notebooks[j].precio)
            {
                aux=notebooks[i];
                notebooks[i]=notebooks[j];
                notebooks[j]=aux;
            }
        }
        if((notebooks[i].precio<menorPrecio || flag==0) && notebooks[i].isEmpty==0)
        {
            menorPrecio=notebooks[i].precio;
            flag=1;
        }
    }

    for(int i=0; i<tam; i++)
    {
        if(menorPrecio==notebooks[i].precio && notebooks[i].isEmpty==0)
        {
            contador++;
        }
    }

    for(int i=0; i<tam; i++)
    {

        if(notebooks[i].isEmpty==0)
        {
            contador2++;
            mostrarNotebook(notebooks[i],tam,marcas,tipos,clientes,procesadores);
        }
        if(contador2==contador)
        {
            break;
        }
    }
}

void mostrarNotebookDeTipo (eNotebook notebooks[],int tam,eTipo tipos[],eMarca marcas[],eCliente clientes[],eProcesador procesadores[])
{
    int tipo;

    tipo=obtenerIdTipo();



    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].idTipo==tipo && notebooks[i].isEmpty==0)
        {
            mostrarNotebook(notebooks[i],tam,marcas,tipos,clientes,procesadores);
        }
    }
}

void cantidadTipoYMarca(eNotebook notebooks[],int tam,eTipo tipos[],eMarca marcas[],eCliente clientes[])
{
    int tipo;
    int marca;
    int contador=0;

    printf("Eliga un tipo de notebook: \n");
    tipo=obtenerIdTipo();
    printf("Eliga una marca de notebook: \n");
    marca=obtenerIdMarca();

    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].idMarca==marca && notebooks[i].idTipo==tipo && notebooks[i].isEmpty==0)
        {
            contador++;
        }
    }

    printf("\nHay %d notebooks con esas caracteristicas.\n", contador);
}

void mostrarMarcasMasElegidas (eNotebook notebooks[], int tam, eMarca marcas[],int tamVarios)
{
    int asus=0;
    int acer=0;
    int hp=0;
    int compaq=0;
    int marca=0;
    char marcaNombre[17];
    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].idMarca==1000 && notebooks[i].isEmpty==0)
        {
            acer++;
        }
        else if(notebooks[i].idMarca==1001 && notebooks[i].isEmpty==0)
        {
            asus++;
        }
        else if(notebooks[i].idMarca==1002 && notebooks[i].isEmpty==0)
        {
            compaq++;
        }
        else if(notebooks[i].idMarca==1003 && notebooks[i].isEmpty==0)
        {
            hp++;
        }
    }

    if(marca<acer)
    {
        strcpy(marcaNombre,"Acer");
        marca=acer;
    }
    if(marca<asus)
    {
        strcpy(marcaNombre,"Asus");
        marca=asus;
    }
    else if(marca==asus)
    {
        strcat(marcaNombre," Asus");
    }
    if(marca<compaq)
    {
        strcpy(marcaNombre,"Compaq");
        marca=compaq;
    }
    else if(marca==compaq)
    {
        strcat(marcaNombre," Compaq");
    }
    if(marca<hp)
    {
        strcpy(marcaNombre,"Hp");
        marca=hp;
    }
    else if(marca==hp)
    {
        strcat(marcaNombre," Hp");
    }

    printf("Marca/s mas vendida/s: %s\n",marcaNombre);






}
void trabajosRealizados (eNotebook notebooks[],int tam,eTrabajo trabajos[], int tamTrabajo,eMarca marcas[],eTipo tipos[],eCliente clientes[],eServicio servicios[],eProcesador procesadores[])
{
    int idNotebook;

    idNotebook=obtenerIdNotebook(notebooks,tam,marcas,tipos,clientes,procesadores);

    for(int i=0; i<tamTrabajo; i++)
    {
        if(trabajos[i].idNotebook==idNotebook && trabajos[i].isEmpty==0)
        {
            mostrarTrabajo(trabajos[i], tamTrabajo,notebooks,servicios);
        }
    }

}

void sumaDeImportes (eNotebook notebooks[],int tam,eCliente clientes[],eMarca marcas[],eTipo tipos[],int tamTrabajos,eTrabajo trabajos[],eProcesador procesadores[])
{
    int id;
    int suma=0;

    id=obtenerIdNotebook(notebooks,tam,marcas,tipos,clientes,procesadores);

    for(int i=0; i<tamTrabajos; i++)
    {
        if(trabajos[i].idNotebook == id)
        {
            if(trabajos[i].idServicio==2000)
            {
                suma=suma+250;
            }
            else if(trabajos[i].idServicio==2001)
            {
                suma=suma+300;
            }
            else if(trabajos[i].idServicio==2002)
            {
                suma=suma+400;
            }
            else
            {
                suma=suma+600;
            }
        }
    }
    printf("La suma total de los importes de los servicios que se le hicieron a esta notebook es de: %d\n\n",suma);

}

void mostrarNotebooksConServicio (eNotebook notebooks[],int tam, eServicio servicios[], int tamVarios,eTrabajo trabajos[], int tamTrabajo,eCliente clientes[],eMarca marcas[],eTipo tipos[],eProcesador procesadores[])
{
    int idServicio;
    int idNotebook;
    int indice;
    int flag=0;


    idServicio=obtenerIdServicio();

    for(int i=0; i<tamTrabajo; i++)
    {
        if(trabajos[i].idServicio==idServicio)
        {
            indice=buscarNotebook(notebooks,tam,trabajos[i].idNotebook);
            printf("%d %d %d:\n",trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);
            mostrarNotebook(notebooks[indice],tam,marcas,tipos,clientes,procesadores);
        }
    }
}

void mostrarServiciosFecha(eServicio servicios[],eTrabajo trabajos[], int tamTrabajo)
{
    eFecha fecha;

    utn_getEntero(&fecha.dia,20,"Ingrese dia:","Error. Vuelva a intentarlo: ",1,31);
    utn_getEntero(&fecha.mes,20,"Ingrese mes:","Error. Vuelva a intentarlo: ",1,12);
    utn_getEntero(&fecha.anio,20,"Ingrese anio:","Error. Vuelva a intentarlo: ",2000,2050);

    for(int i=0; i<tamTrabajo; i++)
    {
        if(fecha.dia == trabajos[i].fecha.dia && fecha.mes == trabajos[i].fecha.mes && fecha.anio == trabajos[i].fecha.anio)
        {
            printf("%d  %-13s  $%d\n",servicios[i].id,servicios[i].descripcion,servicios[i].precio);
        }
    }
}

void masNucleos(eNotebook notebooks[], int tam, eProcesador procesadores[],eMarca marcas[],eTipo tipos[],eCliente clientes[],int tamProc)
{
    int idProc;
    int flag=0;
    int mayorNucleos;

    for(int i=0; i<tamProc; i++)
    {
        if(procesadores[i].nucleos>mayorNucleos || flag==0)
        {
            mayorNucleos=procesadores[i].nucleos;
            idProc=procesadores[i].id;
            flag=1;
        }
    }

    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].idProc==idProc)
        {
            mostrarNotebook(notebooks[i],tam,marcas,tipos,clientes,procesadores);
        }
    }
}

void mostrarNotebooksProcesador(eNotebook notebooks[], int tam, eProcesador procesadores[],eMarca marcas[],eTipo tipos[],eCliente clientes[])
{
    int proc;

    proc=obtenerIdProcesador();

    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].idProc==proc)
        {
            mostrarNotebook(notebooks[i],tam,marcas,tipos,clientes,procesadores);
        }
    }
}

void masPotencia(eNotebook notebooks[], int tam, eProcesador procesadores[],eMarca marcas[],eTipo tipos[],eCliente clientes[],int tamProc)
{
    int idProc;
    int flag=0;
    int masPotente;
    float aux;

    for(int i=0; i<tamProc; i++)
    {
        aux = (float) procesadores[i].frecuencia * procesadores[i].nucleos;

        if(aux > masPotente || flag==0)
        {
            masPotente=aux;
            idProc=procesadores[i].id;
            flag=1;
        }
    }

    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].idProc==idProc)
        {
            mostrarNotebook(notebooks[i],tam,marcas,tipos,clientes,procesadores);
        }
    }
}

void notebooksDeCliente(eNotebook notebooks[], int tam, eProcesador procesadores[],eMarca marcas[],eTipo tipos[],eCliente clientes[],int tamVarios)
{
    int id;

    id=obtenerIdCliente(clientes,tamVarios);

    for(int i=0; i<tam; i++)
    {
        if(id == notebooks[i].idCliente)
        {
            mostrarNotebook(notebooks[i],tam,marcas,tipos,clientes,procesadores);
        }
    }

}

void menosPotente (eNotebook notebooks[], int tam, eProcesador procesadores[],eMarca marcas[],eTipo tipos[],eCliente clientes[],int tamProc)
{
    int idProc;
    int flag=0;
    int menosPotencia;
    float aux;

    for(int i=0; i<tamProc; i++)
    {
        aux = (float) procesadores[i].frecuencia * procesadores[i].nucleos;

        if(aux < menosPotencia || flag==0)
        {
            menosPotencia=aux;
            idProc=procesadores[i].id;
            flag=1;
        }
    }

    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].idProc==idProc)
        {
            mostrarNotebook(notebooks[i],tam,marcas,tipos,clientes,procesadores);
        }
    }
}

void mostrarNotebookPorProcesador(eNotebook notebooks[],int tam,eTipo tipos[], int tamVarios,eMarca marcas[],eCliente clientes[],eProcesador procesadores[])
{
    int flag=0;

    for(int i=0; i<tamVarios; i++)
    {
        printf("%s: \n",procesadores[i].nombre);

        for(int j=0; j<tam;j++)
        {
            if(notebooks[j].idProc==procesadores[i].id && notebooks[i].isEmpty==0)
            {
                mostrarNotebook(notebooks[j],tam,marcas,tipos,clientes,procesadores);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No hay notebooks que mostrar\n");
        }
        flag=0;
        printf("\n");
    }
}

void mostrarNotebookPorCliente(eNotebook notebooks[],int tam,eTipo tipos[], int tamVarios,eMarca marcas[],eCliente clientes[],eProcesador procesadores[])
{
    int flag=0;

    for(int i=0; i<tamVarios; i++)
    {
        printf("%s: \n",clientes[i].nombre);

        for(int j=0; j<tam;j++)
        {
            if(notebooks[j].idCliente==clientes[i].id && notebooks[i].isEmpty==0)
            {
                mostrarNotebook(notebooks[j],tam,marcas,tipos,clientes,procesadores);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No hay notebooks que mostrar\n");
        }
        flag=0;
        printf("\n");
    }
}

