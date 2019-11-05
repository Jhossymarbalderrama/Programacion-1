#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <conio.h>

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int menu();

int main()
{
    int option = 0;
    char respuesta = 'n';

    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        switch(menu(option))
        {
        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados)){
                printf("El archivo se cargo Exitosamente.\n");
            }
            break;
        case 2:
            if(controller_loadFromBinary("data.csv",listaEmpleados)){
                printf("El archivo se cargo Exitosamente.\n");
            }
            break;
        case 3:
            printf("Opcion 2");
            break;
        case 4:
            printf("Opcion 2");
            break;
        case 5:
            printf("Opcion 2");
            break;
        case 6:
            controller_ListEmployee("data.csv",listaEmpleados);
            break;
        case 7:
            printf("Opcion 2");
            break;
        case 8:
            printf("Opcion 2");
            break;
        case 9:
            printf("Opcion 2");
            break;
        case 10:
            printf("Confirma salir?: (S/N) ");
            fflush(stdin);
            respuesta = getche();
            printf("\n\n");
            break;
        }
        if(respuesta != 's'){
            system("pause");
            system("cls");
        }

    }
    while(respuesta == 'n');
    return 0;
}

int menu()
{
    int opcion;

    printf("----- MENU -----\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir.\n\n");

    printf("Ingrese Opcion: ");
    scanf("%d",&opcion);
    return opcion;
}

