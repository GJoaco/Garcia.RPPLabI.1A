#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED
/** \brief Muestra todos los tipos disponibles y permite al usuario elegir uno
 *
 * \return Id del tipo elegido
 *
 */

int obtenerIdTipo();
/** \brief Muestra todos los tipos
 *
 * \param Vector de tipos
 * \param Tamaño del vector tipos
 *
 */

void listarTipos (eTipo tipos[], int tamTipos);
