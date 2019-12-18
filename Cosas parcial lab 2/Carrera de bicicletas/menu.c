#include <stdio.h>
#include <stdlib.h>

int menu(void){

    int opcion;

    printf("-------       Menu De Inicio      -------\n\n");
    printf("1. Cargar archivo.\n");
    printf("2. Imprimir lista.\n");
    printf("3. Asignar tiempos.\n");
    printf("4. Filtrar por tipo.\n");
    printf("5. Mostrar posiciones.\n");
    printf("6. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
