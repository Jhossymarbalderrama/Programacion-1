#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>


/** \brief Muestra un Empleado
 * \param    Employee* e
 * \return  todoOk
 */

int mostrarEmpleado( Employee* e)
{
    int todoOk = 0;

    if( e != NULL)
    {
        printf("%4d  %14s        %4d          %6d\n", e->id, e->nombre, e->horasTrabajadas,e->sueldo);
        todoOk = 1;
    }

    return todoOk;
}


/** \brief Crea un empleado nuevo
 * \param
 * \return  nuevo
 */
Employee* employee_new()
{
    Employee* nuevo = (Employee*) malloc( sizeof(Employee));
    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->horasTrabajadas = 0;
        nuevo->sueldo = 0;
    }
    return nuevo;
}

/** \brief Seteo los datos del Nuevo Empleado
 * \param   char* idStr , char* nombreStr ,  char* horasTrabajadasStr , char* sueldoStr
 * \return nuevo
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevo = employee_new();
    int id;
    int horasTrabajadas;
    int sueldo;

    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);

    if( nuevo != NULL)
    {
        if(employee_setId(nuevo, id) &&
                employee_setNombre(nuevo, nombreStr)&&
                employee_setHorasTrabajadas(nuevo,horasTrabajadas)&&
                employee_setSueldo(nuevo, sueldo))
        {
            // printf("Empleado creado correctamente\n");
        }
        else
        {
            nuevo = NULL;
        }
    }

    return nuevo;
}


/** \brief Seteo ID
 * \param   Employee* this,int id
 * \return int todoOk
 */

int employee_setId(Employee* this,int id)
{

    int todoOk = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Seteo Nombre
 * \param   Employee* this,char* nombre
 * \return int todoOk
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if( this != NULL && nombre != NULL && strlen(nombre) < 128)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Seteo Horas Trabajadas
 * \param  Employee* this,int horasTrabajadas
 * \return int todoOk
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk = 0;
    if( this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Seteo Sueldo
 * \param  Employee* this,int sueldo
 * \return int todoOk
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;
    if( this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Obtengo Id
 * \param  Employee* this,int* id
 * \return int todoOk
 */
int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Obtengo Nombre
 * \param  Employee* this,char* nombre
 * \return int todoOk
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Obtengo Horas Trabajadas
 * \param  Employee* this,int* horasTrabajadas
 * \return int todoOk
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Obtengo sueldo
 * \param  Employee* this,int* sueldo
 * \return int todoOk
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Ordenamiento por ID
 * \param   void* empleado1,void* empleado2
 * \return int retorno
 */

int sortById(void* empleado1,void* empleado2)
{
    int retorno = 0;

    if(empleado1 != NULL && empleado2 != NULL)
    {

        if(((Employee*)empleado1)->id > ((Employee*)empleado2)->id)
        {
            retorno =  1;
        }
        if(((Employee*)empleado1)->id < ((Employee*)empleado2)->id)
        {
            retorno =  -1;
        }

    }
    else
    {
        return -2;
    }
    return retorno;
}


/** \brief Ordenamiento por Nombre
 * \param   void* empleado1,void* empleado2
 * \return int retorno
 */
int sortByName(void* empleado1,void* empleado2)
{
    int retorno = -2;

    Employee* emp;
    Employee* emp2;

    emp = (Employee*)empleado1;
    emp2 = (Employee*)empleado2;

    if(empleado1 != NULL && empleado2 != NULL)
    {
        retorno = strcmp(emp->nombre,emp2->nombre);
    }

    return retorno;
}


/** \brief Ordenamiento por Horas Trabajadas
 * \param   void* empleado1,void* empleado2
 * \return int retorno
 */
int sortByHoras(void* empleado1,void* empleado2)
{
    int retorno = 0;

    if(empleado1 != NULL && empleado2 != NULL)
    {

        if(((Employee*)empleado1)->horasTrabajadas > ((Employee*)empleado2)->horasTrabajadas)
        {
            retorno =  1;
        }
        if(((Employee*)empleado1)->horasTrabajadas < ((Employee*)empleado2)->horasTrabajadas)
        {
            retorno =  -1;
        }

    }
    else
    {
        return -2;
    }
    return retorno;
}


/** \brief Ordenamiento por sueldo
 * \param   void* empleado1,void* empleado2
 * \return int retorno
 */
int sortBySueldo(void* empleado1,void* empleado2)
{

    int retorno = 0;

    if(empleado1 != NULL && empleado2 != NULL)
    {

        if(((Employee*)empleado1)->sueldo > ((Employee*)empleado2)->sueldo)
        {
            retorno =  1;
        }
        if(((Employee*)empleado1)->sueldo < ((Employee*)empleado2)->sueldo)
        {
            retorno =  -1;
        }

    }
    else
    {
        return -2;
    }
    return retorno;
}


