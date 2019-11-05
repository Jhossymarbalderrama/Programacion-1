#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/**< "Extensiones para Archivos"*/
/**< FILE* , Algo = FOPEN(path,modo);
    Example:

    FOPEN("archivo.txt",w o wb)

  -  w = wb //Al inicio
  -  r = rb //Lectura
  -  a = ab //Al final

 */

typedef struct
{
    int id;
    char nombre[20];
    float sueldo;
} eEmpleado;

eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int id, char* nombre, float sueldo);
int setIdEmpleado(eEmpleado* e,int id);
int setSueldoEmpleado(eEmpleado* e,float sueldo);
int setNombreEmpleado(eEmpleado* e,char* nombre);
int getIdEmpleado(eEmpleado* e,int* id);
int getSueldo(eEmpleado* e,float* sueldo);
int getNombreEmpleado(eEmpleado* e,char* nombre);


int mostrarEmpleado(eEmpleado* e);
int mostrarEmpleados(eEmpleado** e,int tam);

eEmpleado** agrandarLista(eEmpleado vec,int tam);

int main()
{
    int tam = 0;
    /**< Creo auxiliar y seteo los campos de la structura como NULL */
    eEmpleado* auxEmpleado = NULL;
    eEmpleado** lista = (eEmpleado**) malloc(sizeof(eEmpleado*));
    int auxInt;
    float auxFloat;
    char auxCad[100];

    if(lista == NULL)
    {
        printf("No se pudo asignar memoria.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    printf("Ingrese ID: ");
    scanf("%d",&auxInt);

    printf("Ingrese Nombre: ");
    fflush(stdin);
    getc(auxCad);

    printf("Ingrese Sueldo: ");
    scanf("%f",&auxFloat);


    auxEmpleado = newEmpleadoParam(auxInt,auxCad,auxFloat);
    if(auxEmpleado == NULL)
    {
        printf("No se pudo crear el Empleado.\n");
    }
    else
    {
        printf("Empleado creado con exito.\n");
        *(lista + tam) = auxEmpleado;


        if(agrandarLista(lista, tam + 1) != NULL)
        {
            printf("Empleado Agregado a la Lista.\n");
            tam++;
        }

    }
    system("pause");

    mostrarEmpleados(lista,tam);

    return 0;
}

eEmpleado* newEmpleado()
{
    eEmpleado* nuevo ;

    nuevo = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->sueldo = 0;
    }
    return nuevo;
}

eEmpleado* newEmpleadoParam(int id, char* nombre, float sueldo)
{

    eEmpleado* nuevo = newEmpleado();

    if(nuevo != NULL)
    {
        if(setIdEmpleado(nuevo,id) && setNombreEmpleado(nuevo, nombre) && setSueldoEmpleado(nuevo, sueldo))
        {
            printf("Empleado creado correctamente\n");
        }
        else{
            nuevo = NULL;
        }
    }

    return nuevo;
}

int setIdEmpleado(eEmpleado* e,int id)
{
    int todoOk = 0;

    if(e != NULL && id >= 10000 && id <= 20000)
    {
        e->id = id;
        todoOk = 1;
    }


    return todoOk;
}

int setSueldoEmpleado(eEmpleado* e,float sueldo)
{
    int todoOk = 0;

    if(e != NULL && sueldo > 0)
    {
        e->sueldo = sueldo;
        todoOk = 1;
    }


    return todoOk;
}

int setNombreEmpleado(eEmpleado* e,char* nombre)
{
    int todoOk = 0;

    if(e != NULL && nombre != NULL && strlen(nombre) > 20)
    {
        strcpy(e->nombre,nombre);
        todoOk = 1;
    }


    return todoOk;
}

int getIdEmpleado(eEmpleado* e,int* id)
{

    int todoOk = 0;

    if(e!= NULL && id != NULL)
    {
        *id= e->id;
        todoOk = 1;
    }

    return todoOk;
}

int getSueldo(eEmpleado* e,float* sueldo)
{

    int todoOk = 0;

    if(e!= NULL && sueldo != NULL)
    {
        *sueldo= e->sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int getNombreEmpleado(eEmpleado* e,char* nombre)
{

    int todoOk = 0;

    if(e!= NULL && nombre != NULL)
    {
        strcpy(nombre,e->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int mostrarEmpleado(eEmpleado* e)
{
    int todoOk = 0;

    if(e != NULL)
    {
        printf("%d %s %.2f\n",e->id,e->nombre,e->sueldo);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarEmpleados(eEmpleado** e,int tam)
{
    int todoOk = 0;

    if(e != NULL && tam > 0 )
    {
        printf("ID   NOMBRE   SUELDO\n\n");
        for(int i = 0 ; i < tam ; i++)
        {
            mostrarEmpleado(*(e + i));
        }
        todoOk = 1;
    }

    return todoOk;
}

eEmpleado** agrandarLista(eEmpleado vec,int tam)
{

    eEmpleado** aux = (eEmpleado**) realloc(vec,sizeof(eEmpleado*) + tam);
    eEmpleado** aux =
    if(aux != NULL)
    {
        vec = aux;
    }

    return vec;
}
