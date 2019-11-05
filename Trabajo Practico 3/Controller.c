#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOK = 0;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* f = fopen(path, "r");
        if( f == NULL)
        {
            printf("No se pudo abrir el archivo.");
            system("pause");
            return todoOK;
        }
        todoOK = 1;
    }

    return todoOK;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOK = 0;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* f = fopen(path, "rb");
        if( f == NULL)
        {
            printf("No se pudo abrir el archivo.\n");
            system("pause");
            return todoOK;
        }
        todoOK = 1;
    }

    return todoOK;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /**< Se agrego PATH */
int controller_ListEmployee(char* path, LinkedList* pArrayListEmployee)
{
       int todoOK = 0;

    Employee* auxEmpleado = NULL;
    int cantidadLeida;
    FILE*pArchivo;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE*pArchivo = fopen(path, "rb");
        if( pArchivo == NULL)
        {
            printf("No se pudo abrir el archivo.\n");
            system("pause");
           return todoOK;
        }
        todoOK = 1;
    }

    while(!feof(pArchivo)){
        cantidadLeida = fread(auxEmpleado,sizeof(Employee),1,pArchivo);
        if(cantidadLeida == 1){
            printf("Id: %d , nombre %s, Hora %d , sueldo %d",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
        }

    }

return todoOK;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}


