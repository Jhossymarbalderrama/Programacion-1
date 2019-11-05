#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int mostrarEmpleado( Employee* e)
{
    int todoOk = 0;

    if( e != NULL)
    {

        printf("%d %s %d &d", e->id , e->nombre , e->horasTrabajadas , e->sueldo);
        todoOk = 1;
    }

    return todoOk;

}

int mostrarEmpleados( Employee** e, int tam)
{
    int todoOk = 0;

    if( e != NULL && tam > 0)
    {
        printf("Id   Nombre   Horas de Trabajo   Sueldo\n\n");
        for( int i=0; i < tam; i++)
        {
            mostrarEmpleado(*(e + i));
        }
        todoOk = 1;
    }

    return todoOk;

}


