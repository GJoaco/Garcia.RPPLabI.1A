#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    int precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED
/** \brief Muestra todos los servicios disponibles y permite al usuario elegir uno
 *
 * \return Id del servicio elegido
 *
 */
int obtenerIdServicio();
/** \brief Muestra todos los servicios
 *
 * \param Vector de servicios
 * \param Tamaño del vector servicios
 *
 */
void listarServicios (eServicio servicios[], int tamServicios);
