
#include "Notebook.h"
#include "Servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief Busca en el vector trabajos un indice libre
 *
 * \param Vector de trabajos
 * \param Tamaño del vector
 * \return Indice libre
 *
 */

int obtenerIndiceTrabajo(eTrabajo trabajos[], int tam);
/** \brief Muestra todos los trabajos
 *
 * \param Vector de trabajos
 * \param Tamaño del vector trabajos
 * \param Vector de notebooks
 * \param Tamaño del vector notebooks
 * \param Vector de servicios
 * \param Tamaño del vector servicios
 *
 */

void listarTrabajos (eTrabajo trabajos[],int tamTrabajos,eNotebook notebooks[], int tam,eServicio servicios[], int tamServicios);
/** \brief Agrega un nuevo trabajo con las caracteristicas que indique el usuario
 *
 * \param Vector de trabajos
 * \param Vector de notebooks
 * \param Vector de servicios
 * \param Id que se asignara al nuevo trabajo
 * \param Tamaño del vector de trabajos
 *
 */
void altaTrabajos (eTrabajo trabajos[], eNotebook notebooks[],eMarca marcas[],eTipo tipos[],int id,int tam,eCliente clientes[],eProcesador procesadores[]);
/** \brief Muestra el trabajo que se le ingresa por parametro
 *
 * \param Vector de trabajos
 * \param Tamaño del vector de trabajos
 * \param Vector de notebooks
 * \param Vector de servicios
 *
 */
void mostrarTrabajo (eTrabajo trabajo,int tamTrabajos,eNotebook notebooks[],eServicio servicios[]);
