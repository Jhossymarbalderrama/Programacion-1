#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicleta.h"
#include "controller.h"

int cargarArchivo(LinkedList* lista, char* path)
{

    int todoOk = 0;
    FILE* f;
    char buffer[4][100];
    int cant;
    eBicicleta* aux = NULL;


    if(lista != NULL && path != NULL)
    {

        f = fopen(path, "r");

        if( f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            return todoOk;
        }

        fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3]);
        while(!feof(f))
        {
            cant = fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3]);

            if(cant == 4)
            {
                aux = bicicleta_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                if( aux != NULL)
                {
                    ll_add(lista,aux);

                }
            }
            else
            {
                break;
            }
        }

        todoOk = 1;


    }
    return todoOk;
}

/** guardar en text*/
int controller_saveAsText(char* path, LinkedList* e)
{

    int todoOk = 0;
    int cant;
    FILE* f;
    eBicicleta* aux = NULL;


    if(e!= NULL && path != NULL)
    {

        f = fopen(path,"w");
        if(f == NULL)
        {
            return todoOk;
        }

        fprintf(f,"id_bike,nombre,tipo,tiempo\n");
        for(int i = 0; i < ll_len(e); i++)
        {
            aux = ll_get(e,i);

            cant = fprintf(f,"%2d  %10s %5s %2d\n",aux->id_bike,aux->nombre,aux->tipo,aux->tiempo);
            if(cant < 1)
            {
                return todoOk;
            }
        }
        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}


void getTiempo(void* elemento)
{
    int aleatorio;
    eBicicleta* bici;
    bici = (eBicicleta*)elemento;

    aleatorio = rand() % (71)+50;

    if(bici->tiempo == 0)
    {
        bici->tiempo = aleatorio;
    }
}

int setTiempo(LinkedList* lista)
{
    int todoOk = 0;
    LinkedList* lista2 = ll_newLinkedList();

    lista2 = ll_map(lista,(void*)getTiempo);

    if(lista2 != NULL)
    {
        lista = lista2;
        todoOk = 1;
    }
    /*
        if(controller_saveAsText("ListaConTiempos.csv",lista)){
            todoOk = 1;
        }
    */
    return todoOk;
}


int filtroTipoBMX(void* elemento)
{
    int todoOk = 0;
    char tipo[20];

    eBicicleta* bici;
    bici = (eBicicleta*)elemento;
    bicicleta_getTipo(bici,tipo);

    if(strcmp(tipo,"BMX")==0)
    {
        todoOk = 1;
    }
    return todoOk;
}

int filtroTipoPLAYERA(void* elemento)
{
    int todoOk = 0;
    char tipo[20];

    eBicicleta* bici;
    bici = (eBicicleta*)elemento;
    bicicleta_getTipo(bici,tipo);

    if(strcmp(tipo,"PLAYERA")==0)
    {
        todoOk = 1;
    }
    return todoOk;
}

int filtroTipoMTB(void* elemento)
{
    int todoOk = 0;
    char tipo[20];

    eBicicleta* bici;
    bici = (eBicicleta*)elemento;
    bicicleta_getTipo(bici,tipo);

    if(strcmp(tipo,"MTB")==0)
    {
        todoOk = 1;
    }
    return todoOk;
}

int filtroTipoPASEO(void* elemento)
{
    int todoOk = 0;
    char tipo[20];

    eBicicleta* bici;
    bici = (eBicicleta*)elemento;
    bicicleta_getTipo(bici,tipo);

    if(strcmp(tipo,"PASEO")==0)
    {
        todoOk = 1;
    }
    return todoOk;
}



int archivoTipo(LinkedList* lista)
{

    int todoOk = 0;
    LinkedList* lista2 = ll_newLinkedList();

    switch(menuFiltro())
    {
    case 1:
        lista2 = ll_filter(lista,filtroTipoBMX);
        break;
    case 2:
        lista2 = ll_filter(lista,filtroTipoPLAYERA);
        break;
    case 3:
        lista2 = ll_filter(lista,filtroTipoMTB);
        break;
    case 4:
        lista2 = ll_filter(lista,filtroTipoPASEO);
        break;
    default:
        printf("Opcion Incorrecta\n");
    }

    if(controller_saveAsText("ArchivoXTipo.csv",lista2))
    {
        todoOk = 1;
    }

    return todoOk;
}

int menuFiltro(void)
{
    int opcion = 0;
    printf("-----   Elija el Tipo   -----\n\n");
    printf("1- BMX\n");
    printf("2- PAYERA\n");
    printf("3- MTB\n");
    printf("4- PASEO\n");
    printf("Ingrese el Nro del Tipo: ");
    scanf("%d",&opcion);

    return opcion;
}

int ordenadoXTipoYTiempo(void* bicicleta1, void* bicicleta2)
{
    int retorno = -2;

    eBicicleta* lista1;
    eBicicleta* lista2;

    lista1 = (eBicicleta*)bicicleta1;
    lista2 = (eBicicleta*)bicicleta2;

    if(bicicleta1 != NULL && bicicleta2 != NULL){
            /**retorno = strcmp(lista1->tipo, lista2->tipo); */ /**1 solo criterio*/

            if(strcmp(lista1->tipo, lista2->tipo) == 0){

                retorno = lista1->tiempo > lista2->tiempo;

            }else if(strcmp(lista1->tipo, lista2->tipo)> 0){

                retorno = strcmp(lista1->tipo, lista2->tipo);

            }else{
                 retorno = lista1->tiempo > lista2->tiempo;
            }
    }
    return retorno;
}

