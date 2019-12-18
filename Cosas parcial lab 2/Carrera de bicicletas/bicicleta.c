#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "LinkedList.h"
#include "controller.h"

eBicicleta* bicicleta_new(){
    eBicicleta* nuevo = (eBicicleta*) malloc( sizeof(eBicicleta));
    if(nuevo != NULL)
    {
        nuevo->id_bike = 0;
        strcpy(nuevo->nombre, " ");
        strcpy(nuevo->tipo, " ");
        nuevo->tiempo = 0;
    }
    return nuevo;
}

eBicicleta* bicicleta_newParametros(char* idStr, char*nombreStr, char* tipoStr, char* tiempoStr){
  eBicicleta* nuevo = bicicleta_new();

    int id;
    int tiempo;

    id = atoi(idStr);
    tiempo = atoi(tiempoStr);

    if( nuevo != NULL)
    {
        if( bicicleta_setId(nuevo, id) &&
           bicicleta_setNombre(nuevo,nombreStr) &&
           bicicleta_setTipo(nuevo, tipoStr) &&
           bicicleta_setTiempo(nuevo,tiempo))
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

int bicicleta_setId(eBicicleta* this,int id){
    int todoOk = 0;
    if(this != NULL && id >= 0)
    {
        this->id_bike = id;
        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_setTiempo(eBicicleta* this,int tiempo){
    int todoOk = 0;

    if(this != NULL && tiempo >= 0)
    {
        this->tiempo = tiempo;
        todoOk = 1;
    }
    return todoOk;
}
int bicicleta_setNombre(eBicicleta* this,char* nombre){
    int todoOk = 0;
    if( this != NULL && nombre != NULL && strlen(nombre) < 20)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_setTipo(eBicicleta* this,char* tipo){
    int todoOk = 0;
    if( this != NULL && tipo != NULL && strlen(tipo) < 20)
    {
        strcpy(this->tipo, tipo);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarBicicleta(eBicicleta* e)
{
    int todoOk = 0;
    int id;
    char nombre[20];
    char tipo[20];
    int tiempo;

    if( e != NULL)
    {
        bicicleta_getId(e,&id);
        bicicleta_getNombre(e,nombre);
        bicicleta_getTipo(e,tipo);
        bicicleta_getTiempo(e,&tiempo);

        printf("%4d      %10s       %10s     %2d \n",id,nombre,tipo,tiempo);
        todoOk = 1;
    }

    return todoOk;
}
int listarBicicletas(LinkedList* lista){
    int todoOk = 0;
    eBicicleta* aux;
    int flag = 0;
    if(lista != NULL)
    {

        printf("  Id           Nombre            Tipo    Tiempo\n\n");
        for( int i=0; i < ll_len(lista); i++)
        {
            aux = (eBicicleta*) ll_get(lista,i);
            mostrarBicicleta(aux);
            flag = 1;
        }
        if(flag == 0){
            printf("No hay cachorros cargados para mostrar\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_getId(eBicicleta* this,int* id){
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id_bike;
        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_getNombre(eBicicleta* this,char* nombre){
    int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_getTipo(eBicicleta* this,char* tipo){
    int todoOk = 0;

    if( this != NULL && tipo != NULL)
    {
        strcpy(tipo, this->tipo);
        todoOk = 1;
    }
    return todoOk;
}


int bicicleta_getTiempo(eBicicleta* this,int* tiempo){
    int todoOk = 0;

    if( this != NULL && tiempo != NULL)
    {
        *tiempo = this->tiempo;
        todoOk = 1;
    }
    return todoOk;
}

