#include <stdio.h>
#include <stdlib.h>

/** \brief  Menu Principal de Opciones
 * \param
 * \return opcion
 */
int menu()
{
    int opcion;

    system("cls");
    printf("------- ABM Autos -------\n\n");
    printf("1-Alta auto.\n");
    printf("2-Modificar auto.\n");
    printf("3-Baja auto.\n\n");
    printf("4-Listar autos.\n");
    printf("5-Listar Marcas.\n");
    printf("6-Listar Colores.\n");
    printf("7-Listar servicios.\n");
    printf("8-Alta trabajo.\n");
    printf("9-Listar trabajos.\n\n");
    printf("10-Informes.\n");
    printf("20-Salir.\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
