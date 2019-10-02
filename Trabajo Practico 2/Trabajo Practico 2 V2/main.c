#include <stdio.h>
#include <stdlib.h>
#include "employeeLibrary.h"

#define TAM 10 /**< Luego cambiar el TAM por 1000 */


int main()
{
    eEmpleados lista[TAM];
    int id = 1;
    char salir = 'n';

    inicializarEmpleados(lista, TAM);

    /**< HardCodeo de Datos */
    id = id + hardcodeoEmpleados(lista, TAM, 10);
    do
    {
        switch(menu())
        {
        case 1:
            if(altaEmpleado(lista, TAM, id))
            {
                id++;
            }
            break;
        case 2:
            bajaEmpleado(lista,TAM);
            break;
        case 3:/**< Sacar Opcion de MODIFICAR */
            modificarEmpleado(lista,TAM);
            break;
        case 4:
            odenarEmpleados(lista,TAM);
            break;
        case 5:
            mostrarEmpleados(lista,TAM);
            break;
        case 6:
            printf("\nCorfirma Salida?");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}


