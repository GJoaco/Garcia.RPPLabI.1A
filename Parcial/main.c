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
#include "Procesador.h"

#define TAM 10
#define TAMTRABAJO 10
#define TAMVARIOS 4

void inicializarPrograma(eNotebook notebooks[],int tam,eTrabajo trabajos[], int tamTrabajo);
void menu();

int main()
{
    eMarca marcas [TAMVARIOS] = {{1000, "Acer"},{1001, "Asus"},{1002, "Compaq"},{1003, "HP"}};
    eTipo tipos [TAMVARIOS] = {{5000,"Gamer"},{5001,"Disenio"},{5002,"Ultrabook"},{5003,"Normal"}};
    eServicio servicios [TAMVARIOS] = {{2000,"Bateria",250},{2001,"Antivirus",300},{2002,"Actualizacion",400},{2003,"Fuente",600}};
    eCliente clientes[TAMVARIOS] = {{4000,"Jose",'m'},{4001,"Lucia",'f'},{4002,"Morena",'f'},{4003,"Lucas",'m'}};
    eProcesador procesadores [TAMVARIOS] = {{6000,"I3",3.9,4},{6001,"Ryzen 5",4.5,6},{6002,"pentium",2.8,4},{6003,"I7",4.8,8}};
    eNotebook notebooks[TAM] =
    {
        {3000,"Notebook1",1000,5001,20000},
        {3001,"Notebook2",1001,5001,10000},
        {3002,"Notebook3",1002,5000,10000},
        {3003,"Notebook4",1003,5002,50000},
        {3004,"Notebook5",1002,5001,80000}
    };
    eTrabajo trabajos [TAMTRABAJO] =
    {
        {1,3000,2001,{4,2,2020}},
        {2,3000,2002,{22,1,2021}},
        {3,3000,2003,{22,1,2021}},
        {4,3001,2000,{12,6,2020}},
        {5,3004,2003,{29,3,2020}}
    };


    char opciones[20];
    int todoOk;
    int idNotebooks = 2999;
    int idtrabajos = 5;
    int idCliente=3999;
    int idProg=5999;
    int opcion1=1;

    inicializarPrograma(notebooks,TAM, trabajos,TAMTRABAJO);
    for(int i=0; i<5;i++)
    {
        if(idCliente<4003)
        {
            idCliente++;
        }
        if(idProg<6003)
        {
            idProg++;
        }
        notebooks[i].isEmpty=0;
        trabajos[i].isEmpty=0;
        notebooks[i].idCliente=idCliente;
        notebooks[i].idProc=idProg;
    }



    do
    {
        system("cls");
        menu();

        fflush(stdin);
        scanf("%s",opciones);
        opciones[0]=tolower(opciones[0]);

        todoOk=isChar(opciones);


        while(todoOk==-1)
        {
            printf("Error. Vuelva a intentarlo: ");
            scanf("%s",opciones);
            opciones[0]=tolower(opciones[0]);
            todoOk=isChar(opciones);
        }

        switch(opciones[0])
        {
        case 'a':
            system("cls");
            opcion1=1;
            idNotebooks++;
            altaNotebook(notebooks,TAM,idNotebooks,clientes,TAMVARIOS);
            system("pause");
            break;
        case 'b':
            if(opcion1==1)
            {
                system("cls");
                modificarNotebook(notebooks,TAM,marcas,tipos,clientes,procesadores);
                system("pause");
            }
            else
            {
                printf("\nPrimero debe dar de alta una notebook\n");
                system("pause");
            }

            break;
        case 'c':
            if(opcion1==1)
            {
                system("cls");
                bajaNotebooks(notebooks,TAM,marcas,tipos,clientes,procesadores);
                system("pause");
            }
            else
            {
                printf("\nPrimero debe dar de alta una notebook\n");
                system("pause");
            }

            break;
        case 'd':
            if(opcion1==1)
            {
                system("cls");
                listarNotebooks(notebooks,TAM,marcas,tipos,clientes,procesadores);
                system("pause");
            }
            else
            {
                printf("\nPrimero debe dar de alta una notebook\n");
                system("pause");
            }

            break;
        case 'e':
            if(opcion1==1)
            {
                system("cls");
                listarMarcas(marcas,TAMVARIOS);
                system("pause");
            }
            else
            {
                printf("\nPrimero debe dar de alta una notebook\n");
                system("pause");
            }

            break;
        case 'f':
            if(opcion1==1)
            {
                system("cls");
                listarTipos(tipos,TAMVARIOS);
                system("pause");
            }
            else
            {
                printf("\nPrimero debe dar de alta una notebook\n");
                system("pause");
            }

            break;
        case 'g':
            if(opcion1==1)
            {
                system("cls");
                listarServicios(servicios,TAMVARIOS);
                system("pause");
            }
            else
            {
                printf("\nPrimero debe dar de alta una notebook\n");
                system("pause");
            }

            break;
        case 'h':
            if(opcion1==1)
            {
                system("cls");
                listarProcesador(procesadores,TAMVARIOS);
                system("pause");
            }
            else
            {
                printf("\nPrimero debe dar de alta una notebook\n");
                system("pause");
            }

            break;
        case 'i':
            if(opcion1==1)
            {
                system("cls");
                idtrabajos++;
                altaTrabajos(trabajos,notebooks,marcas,tipos,idtrabajos,TAM,clientes,procesadores);
                system("pause");
            }
            else
            {
                printf("\nPrimero debe dar de alta una notebook\n");
                system("pause");
            }

            break;
        case 'j':
            if(opcion1==1)
            {
                system("cls");
                listarTrabajos(trabajos,TAMTRABAJO,notebooks,TAM,servicios,TAMVARIOS);
                system("pause");
            }
            else
            {
                printf("\nPrimero debe dar de alta una notebook\n");
                system("pause");
            }

            break;
        case 'k':
            if(opcion1==1)
            {
                system("cls");
                listarClientes(clientes,TAMVARIOS);
                system("pause");
            }
            else
            {
                printf("\nPrimero debe dar de alta una notebook\n");
                system("pause");
            }

            break;
        case 'l':
            if(opcion1==1)
            {
                system("cls");
                menuInformes(notebooks,TAM,tipos,marcas,clientes,TAMVARIOS,servicios,trabajos,TAMTRABAJO,procesadores);
                system("pause");
            }
            else
            {
                printf("\nPrimero debe dar de alta una notebook\n");
                system("pause");
            }

            break;
        case 'm':

            break;
        }

    }while(opciones[0]!='l');


    printf("\n%d\n",notebooks[0].id);



    return 0;
}

void inicializarPrograma(eNotebook notebooks[],int tam,eTrabajo trabajos[], int tamTrabajo)
{
    for(int i=0; i<tam; i++)
    {
        notebooks[i].isEmpty=1;
        trabajos[i].isEmpty=1;

    }
}
void menu()
{
    printf("*****MENU DE OPCIONES*****\n\n");

    printf("A. ALTA NOTEBOOK\n");
    printf("B. MODIFICAR NOTEBOOK\n");
    printf("C. BAJA NOTEBOOK\n");
    printf("D. LISTAR NOTEBOOKS\n");
    printf("E. LISTAR MARCAS\n");
    printf("F. LISTAR TIPOS\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. LISTAR PROCESADORES\n");
    printf("I. ALTA TRABAJO\n");
    printf("J. LISTAR TRABAJOS\n");
    printf("K. LISTAR CLIENTES\n");
    printf("L. INFORMES\n");
    printf("M. SALIR\n");
    printf("\nElija una opcion: ");
}


