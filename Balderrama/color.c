#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "color.h"

/** \brief Cargo Descripcion Color
 * \param   int id, eColor colores[], int tam, char desc[]
 * \return  todoOk
 */
int cargarDescColor(int id, eColor colores[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == colores[i].id){
            strcpy(desc, colores[i].nombreColor);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

/** \brief Muestro los Colores
 * \param   eColor colores[], int tam
 * \return
 */
void mostrarColores(eColor colores[], int tam){
    printf(" Id         Color\n\n");
    for(int i=0; i < tam; i++){
        mostrarColor( colores[i]);
    }
    printf("\n");
}

/** \brief Muestro un Color
 * \param   eColor colores
 * \return
 */
void mostrarColor (eColor colores){

    printf("  %d      %10s\n", colores.id, colores.nombreColor);

}
