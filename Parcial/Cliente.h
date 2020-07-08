#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;

}eCliente;

#endif // CLIENTE_H_INCLUDED
/** \brief Muestra todos los clientes
 *
 * \param Vector de clientes
 * \param Tamaño del vector de clientes
 *
 */

void listarClientes (eCliente clientes[], int tamClientes);
/** \brief Obtiene un cliente por Id
 *
 * \param Vector de clientes
 * \param Tamaño del vector de clientes
 *
 */

int obtenerIdCliente(eCliente clientes[], int tamClientes);
