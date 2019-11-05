#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fIngreso;

} eEmpleado;

int cargarEmpleado(eEmpleado* e, int legajo, char* nombre, char sexo, float sueldo, eFecha fecha);
eEmpleado* newEmpleado();
int mostrarEmpleado(eEmpleado* emp);
eEmpleado* newEmpleadoParam(int leg, char* nombre, char sexo, float sueldo, int dia, int mes, int anio);
int mostrarEmpleados(eEmpleado* vec, int tam);
eEmpleado* agregarEmpleado(eEmpleado* vec, int* tam, eEmpleado* emp);

int main()
{
    eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado));
    int tam = 0;
    if( lista == NULL)
    {
        printf("No se pudo conseguir lugar\n");
        exit(EXIT_FAILURE);
    }

    eEmpleado* pEmp = newEmpleadoParam(1234, "Jorge", 'm', 25000, 12, 5, 2010);
    eEmpleado* pEmp1 = newEmpleadoParam(1235, "Juana", 'f', 35000, 23, 5, 2010);
    eEmpleado* pEmp2 = newEmpleadoParam(1236, "Matias", 'm', 34000, 12, 4, 2010);
    eEmpleado* pEmp3 = newEmpleadoParam(1236, "Jaime", 'm', 12000, 2, 7, 2010);

    lista = agregarEmpleado(lista, &tam, pEmp);
    lista = agregarEmpleado(lista, &tam, pEmp1);
    lista = agregarEmpleado(lista, &tam, pEmp2);
    lista = agregarEmpleado(lista, &tam, pEmp3);
    mostrarEmpleados(lista, tam);

    free(pEmp);
    return 0;
}

int cargarEmpleado(eEmpleado* e, int legajo, char* nombre, char sexo, float sueldo, eFecha fecha)
{
    int todoOk = 0;

    e->legajo = legajo;
    strcpy(e->nombre, nombre);
    e->sexo = sexo;
    e ->sueldo = sueldo;
    e->fIngreso = fecha;
    todoOk = 1;

    return todoOk;
}

eEmpleado* newEmpleado()
{

    eEmpleado* p;

    p = (eEmpleado*) malloc( sizeof(eEmpleado));

    if( p != NULL)
    {
        p->legajo = 0;
        strcpy(p->nombre, "sin definir");
        p->sexo = 'm';
        p->sueldo = 0;
        p->fIngreso = (eFecha)
        {
            1,1,1990
        };
    }

    return p;

}


int mostrarEmpleado(eEmpleado* emp)
{
    int todoOk =0;

    if( emp != NULL)
    {
        printf(" %d  %s  %c  %.2f  %02d/%02d/%d\n", emp->legajo, emp->nombre, emp->sexo, emp->sueldo, emp->fIngreso.dia, emp->fIngreso.mes, emp->fIngreso.anio);
        todoOk = 1;
    }

    return todoOk;
}

eEmpleado* newEmpleadoParam(int leg, char* nombre, char sexo, float sueldo, int dia, int mes, int anio)
{

    eEmpleado* nuevoEmpleado;

    nuevoEmpleado = newEmpleado();

    if(nuevoEmpleado != NULL)
    {

        nuevoEmpleado->legajo = leg;
        strcpy(nuevoEmpleado->nombre, nombre);
        nuevoEmpleado->sexo = sexo;
        nuevoEmpleado->sueldo = sueldo;
        nuevoEmpleado->fIngreso.dia = dia;
        nuevoEmpleado->fIngreso.mes = mes;
        nuevoEmpleado->fIngreso.anio = anio;
    }

    return nuevoEmpleado;
}

eEmpleado* agregarEmpleado(eEmpleado* vec, int* tam, eEmpleado* emp)
{
    eEmpleado* aux;

    if( vec != NULL && tam != NULL && emp != NULL)
    {
        *(vec + *tam) = *emp;

        aux = realloc( vec, (*tam +2) *  sizeof(eEmpleado) );

        if( aux != NULL)
        {
            vec = aux;
            (*tam)++;
        }
    }

    return vec;

}

int mostrarEmpleados(eEmpleado* vec, int tam)
{
    int todoOk = 0;

    if( vec != NULL)
    {

        for(int i=0; i < tam; i++)
        {
            mostrarEmpleado(vec +i);
        }
        todoOk = 1;
    }

    return todoOk;

}


