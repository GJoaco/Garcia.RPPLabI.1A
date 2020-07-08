#ifndef PROCESADOR_H_INCLUDED
#define PROCESADOR_H_INCLUDED

typedef struct
{
    int id;
    char nombre[10];
    float frecuencia;
    int nucleos;

}eProcesador;

#endif // PROCESADOR_H_INCLUDED

/** \brief Muestra todos los procesadores disponibles y permite al usuario elegir uno
 *
 * \return Id del procesador elegido
 *
 */

int obtenerIdProcesador();
/** \brief Muestra todos los procesadores
 *
 * \param Vector de procesadores
 * \param Tamaño del vector procesadores
 *
 */

void listarProcesador (eProcesador procesadores[], int tamProc);
