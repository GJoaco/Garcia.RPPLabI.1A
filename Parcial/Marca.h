#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    int cantidad;
}eMarca;

#endif // MARCA_H_INCLUDED
/** \brief Muestra todos las marcas disponibles y permite al usuario elegir una
 *
 * \return Id de la marca elegida
 *
 */

int obtenerIdMarca();
/** \brief Muestra todas las marcas
 *
 * \param Vector de marcas
 * \param Tamaño del vector marcas
 *
 */
void listarMarcas (eMarca marcas[], int tamMarcas);
