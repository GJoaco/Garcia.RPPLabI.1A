#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED



#endif // INFORME_H_INCLUDED
/** \brief Muestra el menu de informes y da a elegir una opcion a ejecutar
 *
 * \param Vector noteboks
 * \param Tamaño vector notebooks
 * \param Vector tipos
 * \param Vector marcas
 * \param Vector clientes
 * \param Tamaño de vector clientes marca tipos servicios
 * \param Vector trabajos
 * \param Tamaño vector trabajos
 * \return
 *
 */

void menuInformes(eNotebook notebooks[],int tam,eTipo tipos[],eMarca marcas[],eCliente clientes[],int tamVarios,eServicio servicios[],eTrabajo trabajos[],int tamTrabajo,eProcesador procesadores[]);
/** \brief Muestra todas las notebooks separadas por marca
 *
 * \param Vector noteboks
 * \param Tamaño vector notebooks
 * \param Vector tipos
 * \param Tamaño de vector clientes marca tipos servicios
 * \param Vector marcas
 * \param Vector clientes
 * \return
 *
 */
void mostrarNotebookPorMarca(eNotebook notebooks[],int tam,eTipo tipos[], int tamVarios,eMarca marcas[],eCliente clientes[],eProcesador procesadores[]);
/** \brief Muestra las notebooks de una marca elegida
 *
 * \param Vector noteboks
 * \param Tamaño vector notebooks
 * \param Vector tipos
 * \param Vector marcas
 * \param Vector clientes
 * \return
 *
 */
void mostrarNotebookDeMarca (eNotebook notebooks[],int tam,eTipo tipos[],eMarca marcas[],eCliente clientes[],eProcesador procesadores[]);
/** \brief Muestra la o las notebooks mas baratas
 *
 * \param Vector noteboks
 * \param Tamaño vector notebooks
 * \param Vector tipos
 * \param Vector marcas
 * \param Vector clientes
 * \return
 *
 */
void notebooksBaratas (eNotebook notebooks[],int tam,eTipo tipos[],eMarca marcas[],eCliente clientes[],eProcesador procesadores[]);
/** \brief Muestra las notebooks del tipo seleccionado
 *
 * \param Vector noteboks
 * \param Tamaño vector notebooks
 * \param Vector tipos
 * \param Vector marcas
 * \param Vector clientes
 * \return
 *
 */
void mostrarNotebookDeTipo (eNotebook notebooks[],int tam,eTipo tipos[],eMarca marcas[],eCliente clientes[],eProcesador procesadores[]);
/** \brief Muestra la cantidad de notebooks con las caracteristicas elegidas
 *
 * \param Vector noteboks
 * \param Tamaño vector notebooks
 * \param Vector tipos
 * \param Vector marcas
 * \param Vector clientes
 * \return
 *
 */
void cantidadTipoYMarca (eNotebook notebooks[],int tam,eTipo tipos[],eMarca marcas[],eCliente clientes[]);
/** \brief Muestra la o las marcas mas elegidas
 *
 * \param Vector noteboks
 * \param Tamaño vector notebooks
 * \param Vector marcas
 * \param Tamaño de vector clientes marca tipos servicios
 * \return
 *
 */
void mostrarMarcasMasElegidas (eNotebook notebooks[], int tam, eMarca marcas[],int tamVarios);
/** \brief Muestra todos los trabajos realizados a la notebook elegida
 *
 * \param Vector noteboks
 * \param Tamaño vector notebooks
 * \param Vector trabajos
 * \param Tamaño vector trabajos
 * \param Vector marcas
 * \param Vector tipos
 * \param Vector clientes
 * \param Vector servicios
 * \return
 *
 */
void trabajosRealizados (eNotebook notebooks[],int tam,eTrabajo trabajos[], int tamTrabajo,eMarca marcas[],eTipo tipos[],eCliente clientes[],eServicio servicios[],eProcesador procesadores[]);
/** \brief Muestra la suma del costo de todos los trabajos realizados a la notebook seleccionada
 *
 * \param Vector noteboks
 * \param Tamaño vector notebooks
 * \param Vector clientes
 * \param Vector marcas
 * \param Vector tipos
 * \param Tamaño vector trabajos
 * \param Vector trabajos
 * \return
 *
 */

void sumaDeImportes (eNotebook notebooks[],int tam,eCliente clientes[],eMarca marcas[],eTipo tipos[],int tamTrabajos,eTrabajo trabajos[],eProcesador procesadores[]);
/** \brief Muestra todas las notebooks a las que se les realizo el servicio elegido
 *
 * \param Vector noteboks
 * \param Tamaño vector notebooks
 * \param Vector servicios
 * \param Tamaño de vector clientes marca tipos servicios
 * \param Vector trabajos
 * \param Tamaño vector trabajos
 * \param Vector clientes
 * \param Vector marcas
 * \return
 *
 */
void mostrarNotebooksConServicio (eNotebook notebooks[],int tam, eServicio servicios[], int tamVarios,eTrabajo trabajos[], int tamTrabajo,eCliente clientes[],eMarca marcas[],eTipo tipos[],eProcesador procesadores[]);
/** \brief Muestra todos los trabajos realizados a la notebook elegida
 *
 * \param Vector servicios
 * \param Vector trabajos
 * \param Tamaño vector trabajos
 * \return
 *
 */
void mostrarServiciosFecha(eServicio servicios[],eTrabajo trabajos[], int tamTrabajo);
void masNucleos(eNotebook notebooks[], int tam, eProcesador procesadores[],eMarca marcas[],eTipo tipos[],eCliente clientes[],int tamProc);
void mostrarNotebooksProcesador(eNotebook notebooks[], int tam, eProcesador procesadores[],eMarca marcas[],eTipo tipos[],eCliente clientes[]);
void menosPotente (eNotebook notebooks[], int tam, eProcesador procesadores[],eMarca marcas[],eTipo tipos[],eCliente clientes[],int tamProc);
void masPotencia(eNotebook notebooks[], int tam, eProcesador procesadores[],eMarca marcas[],eTipo tipos[],eCliente clientes[],int tamProc);
void notebooksDeCliente(eNotebook notebooks[], int tam, eProcesador procesadores[],eMarca marcas[],eTipo tipos[],eCliente clientes[],int tamVarios);
void mostrarNotebookPorProcesador(eNotebook notebooks[],int tam,eTipo tipos[], int tamVarios,eMarca marcas[],eCliente clientes[],eProcesador procesadores[]);
void mostrarNotebookPorCliente(eNotebook notebooks[],int tam,eTipo tipos[], int tamVarios,eMarca marcas[],eCliente clientes[],eProcesador procesadores[]);
