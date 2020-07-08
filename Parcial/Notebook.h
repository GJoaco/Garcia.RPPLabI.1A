
#include "Marca.h"
#include "Tipo.h"
#include "Cliente.h"
#include "Procesador.h"


#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;
    int idCliente;
    int idProc;
}eNotebook;


#endif // NOTEBOOK_H_INCLUDED
/** \brief Muestra todas las notebooks disponibles y permite al usuario elegir una
 *
 * \return Id de la notebook elegida
 *
 */
int obtenerIdNotebook(eNotebook notebooks[],int tam,eMarca marcas[],eTipo tipos[],eCliente clientes[],eProcesador procesadores[]);
/** \brief Busca en el vector notebooks un indice libre
 *
 * \param Vector de notebooks
 * \param Tamaño del vector
 * \return Indice libre
 *
 */
int obtenerIndiceNotebooks(eNotebook notebooks[], int tam);
/** \brief Busca por id una notebook dentro de su vector
 *
 * \param Vector de notebooks
 * \param Tamaño del vector notebooks
 * \param Id de la notebook que desea buscar el usuario
 * \return El indice donde se encuentra la notebook o en caso de que no se encuentre -1
 *
 */
int buscarNotebook (eNotebook notebooks[], int tam, int id);
/** \brief Agrega una nueva notebook con las caracteristicas que indique el usuario
 *
 * \param Vector de notebooks
 * \param Tamaño del vector de notebooks
 * \param Id que se asignara a la nueva notebook
 *
 */
void altaNotebook (eNotebook notebooks[], int tam, int id,eCliente clientes[],int tamClientes);
/** \brief Modifica una caracterisca de la notebook que el usuario indique
 *
 * \param Vector de notebooks
 * \param Tamaño del vector de notebooks
 * \param Vector de marcas
 * \param Vector de tipos
 *
 */

void modificarNotebook (eNotebook notebooks[],int tam,eMarca marcas[],eTipo tipos[],eCliente clientes[],eProcesador procesadores[]);
/** \brief Elimina la notebook que el usuario indique
 *
 * \param Vector de notebooks
 * \param Tamaño del vector de notebooks
 * \param Vector de marcas
 * \param Vector de tipos
 *
 */

void bajaNotebooks (eNotebook notebooks[],int tam,eMarca marcas[],eTipo tipos[],eCliente clientes[],eProcesador procesadores[]);
/** \brief Muestra todas las notebooks
 *
 * \param Vector de notebooks
 * \param Tamaño del vector de notebooks
 * \param Vector de marcas
 * \param Vector de tipos
 *
 */
void listarNotebooks (eNotebook notebooks[], int tam,eMarca marcas[], eTipo tipos[],eCliente clientes[],eProcesador procesadores[]);
/** \brief Muestra la notebook que se le ingresa por parametro
 *
 * \param Vector de notebooks
 * \param Tamaño del vector de notebooks
 * \param Vector de marcas
 * \param Vector de tipos
 *
 */
void mostrarNotebook (eNotebook notebook, int tam, eMarca marcas[], eTipo tipos[],eCliente clientes[],eProcesador procesadores[]);

