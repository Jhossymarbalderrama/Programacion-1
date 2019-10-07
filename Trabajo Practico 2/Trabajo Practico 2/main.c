#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "employeeLibrary.h"

#define TAM 1000 /**< Cantidad de Empleados */


int main(void)
{
    eEmpleados lista[TAM];
    int id = 1;
    char salir = 'n';

    inicializarEmpleados(lista, TAM);
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
            informes(lista,TAM);
            break;
        case 5:
            printf("\nConfirmar Salida? (S/N): ");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("Opcion invalida\n");
            fflush(stdin);
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;
}


