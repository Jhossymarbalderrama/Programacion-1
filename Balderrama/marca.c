#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "marca.h"

/** \brief Cargo Descripcion Marca
 * \param   int id, eMarca marcas[], int tam, char desc[]
 * \return todoOk
 */
int cargarDescMarca(int id, eMarca marcas[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == marcas[i].id){
            strcpy(desc, marcas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

/** \brief Muestro Marcas
 * \param   eMarca marcas[], int tam
 * \return
 */
void mostrarMarcas (eMarca marcas[], int tam){
    printf("     Id           Marca\n\n");
    for(int i=0; i < tam; i++){
        mostrarMarca( marcas[i]);
    }
    printf("\n");
}

/** \brief Muestro Marca
 * \param   eMarca marcas
 * \return
 */
void mostrarMarca (eMarca marcas){

    printf("  %d      %10s\n", marcas.id, marcas.descripcion);

}
