#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "servicios.h"

/** \brief Muestro Los Servicios
 * \param   eServicio servicios[], int tam
 * \return
 */
void mostrarServicios (eServicio servicios[], int tam){
    printf(" Id         Servicio        Precio\n\n");
    for(int i=0; i < tam; i++){
        mostrarServicio( servicios[i]);
    }
    printf("\n");
}

/** \brief Muestro Servicio
 * \param eServicio servicios
 * \return
 */
void mostrarServicio (eServicio servicios){

    printf("  %d      %10s      %.2f\n", servicios.id, servicios.descripcion,servicios.precio);

}

/** \brief Cargo Descripcion Servicio
 * \param   int id, eServicio servicios[], int tam, char desc[]
 * \return todoOk
 */
int cargarDescServicio(int id, eServicio servicios[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == servicios[i].id){
            strcpy(desc, servicios[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

/** \brief Busco la Id Servicio
 * \param   int id, eServicio servicios[], int tam
 * \return indice
 */
int buscarIdServicio(int id, eServicio servicios[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( servicios[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
