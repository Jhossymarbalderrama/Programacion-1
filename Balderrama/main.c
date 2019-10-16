#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "fecha.h"
#include "autos.h"
#include "color.h"
#include "marca.h"
#include "servicios.h"
#include "trabajo.h"
#include "menu.h"

#define TAMAUTOS 10
#define TAMARCAS 5
#define TAMCOLOR 5
#define TAMSERVICIO 4
#define TAMTRABAJO 10

void menuInformes(eAuto autos[],int tamAutos,eMarca marcas[],int tamMarcas,eColor colores[],int tamColor,eServicio servicios[],int tamServicio,eTrabajo trabajos[],int tamTrabajo);
int menuInformesOpciones();
void mostrarAutosXMarca(eAuto autos[],int tamAuto,eMarca marcas[], int tamMarcas,eColor colores[],int tamColor);
void mostrarAutosXColor(eAuto autos[],int tamAuto,eMarca marcas[], int tamMarcas,eColor colores[],int tamColor);
void mostrarAutorXModelo(eAuto autos[],int tamAuto,eMarca marcas[], int tamMarcas,eColor colores[],int tamColor);
void mostrarAutosXMarcaYModelo(eAuto autos[],int tamAuto,eMarca marcas[], int tamMarcas,eColor colores[],int tamColor);
void mostrarAutosXMarcaYColor(eAuto autos[],int tamAuto,eMarca marcas[], int tamMarcas,eColor colores[],int tamColor);

int main()
{
    int idAuto = 100;
    int idTrabajo = 60000;
    eMarca marcas[] = { {1000,"Renault"},{1001,"Fiat"}, {1002,"Ford"}, {1003,"Chevrolet"}, {1004,"Peugeot"}};
    eColor colores[] = {{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eServicio servicios[] = {{20000,"Lavado",250},{20001,"Pulido",300},{20002,"Encerado",400},{20003,"Completo",600}};
    eAuto vehiculos[TAMAUTOS];
    eTrabajo trabajos[TAMTRABAJO];

    inicializarAutos(vehiculos,TAMAUTOS);
    inicializarTrabajos(trabajos,TAMTRABAJO);

    idAuto = idAuto + hardcodearAutos(vehiculos,TAMAUTOS, 9);

    char respuesta = 'n';
    do
    {
        switch(menu())
        {
        case 1:
            altaAuto(vehiculos,TAMAUTOS,marcas,TAMARCAS,colores,TAMCOLOR);
            break;
        case 2:
            modificarAuto(vehiculos,TAMAUTOS,colores,TAMCOLOR,marcas,TAMARCAS);
            break;
        case 3:
            bajaAuto(vehiculos,TAMAUTOS,colores,TAMCOLOR,marcas,TAMARCAS);
            break;
        case 4:
            mostrarAutos(vehiculos,TAMAUTOS,colores,TAMCOLOR,marcas,TAMARCAS);
            break;
        case 5:
            mostrarMarcas(marcas,TAMARCAS);
            break;
        case 6:
            mostrarColores(colores,TAMCOLOR);
            break;
        case 7:
            mostrarServicios(servicios,TAMSERVICIO);
            break;
        case 8:
            if(altaTrabajo(trabajos,TAMTRABAJO,idTrabajo,vehiculos,TAMAUTOS,servicios,TAMSERVICIO,colores,TAMCOLOR,marcas,TAMARCAS))
            {
                idTrabajo++;
            }
            break;
        case 9:
            mostrarTrabajos(trabajos,TAMTRABAJO,servicios,TAMSERVICIO);
            break;
        case 10:
            menuInformes(vehiculos,TAMAUTOS,marcas,TAMARCAS,colores,TAMCOLOR,servicios,TAMSERVICIO,trabajos,TAMTRABAJO);
            break;
        case 20:
            printf("Confirma salir?:");
            fflush(stdin);
            respuesta = getche();
            printf("\n\n");
            break;

        default:
            printf("\nOpcion Invalida!\n\n");

        }
        system("pause");
    }
    while(respuesta == 'n');

    return 0;
}


void menuInformes(eAuto autos[],int tamAutos,eMarca marcas[],int tamMarcas,eColor colores[],int tamColor,eServicio servicios[],int tamServicio,eTrabajo trabajos[],int tamTrabajo){

    char respuesta = 'n';

    do{

        switch(menuInformesOpciones()){
            case 1:
                mostrarAutosXMarca(autos,tamAutos,marcas,tamMarcas,colores,tamColor);
                break;
            case 2:
                mostrarAutosXColor(autos,tamAutos,marcas,tamMarcas,colores,tamColor);
                break;
            case 3:
                mostrarAutorXModelo(autos,tamAutos,marcas,tamMarcas,colores,tamColor);
                break;
            case 4:
                mostrarAutosXMarcaYModelo(autos,tamAutos,marcas,tamMarcas,colores,tamColor);
                break;
            case 5:
                mostrarAutosXMarcaYColor(autos,tamAutos,marcas,tamMarcas,colores,tamColor);
                break;
            case 20:
                printf("Confirma salir?:");
                fflush(stdin);
                respuesta = getche();
                printf("\n\n");
            break;

            default:
                printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }while(respuesta == 'n');
}

int menuInformesOpciones()
{
    int opcion;

    system("cls");
    printf("------- INFORMES -------\n\n");
    printf("1-Mostrar Autos de una Marca.\n");
    printf("2-Mostrar Autos de un Color.\n");
    printf("3-Mostrar Autos de un Modelo.\n");
    printf("4-Mostrar Autos por Marca y Modelo.\n");
    printf("5-Mostrar Autos por Marca y Color.\n");
    printf("20-Salir.\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarAutosXMarca(eAuto autos[],int tamAuto,eMarca marcas[], int tamMarcas,eColor colores[],int tamColor){
    int idMarca;
    int cont = 0;
    char nombreMarca[20];
    int flag = 0;

    system("cls");
    printf("-------- INFORMES --------\n\n");
    printf("----- Autos Por Marca -----\n");


    do{

    mostrarMarcas(marcas,tamMarcas);
    printf("\nIngrese ID de la Marca: ");
    scanf("%d",&idMarca);

    }while(idMarca < 1000 && idMarca > 1005);


    for(int i = 0; i < tamAuto; i++){
        if(autos[i].isEmpty == 0 && autos[i].idMarca == idMarca){
            cont++;
        }
    }

    for(int i = 0; i<tamMarcas; i++){
        if(marcas[i].id == idMarca){
            strcpy(nombreMarca,marcas[i].descripcion);
            printf("La cantidad de %s son : %d .",nombreMarca,cont);
            printf("\n   ID       Patente        Marca    Color    Modelo  \n\n");
            break;
        }
    }

        for(int i=0; i < tamAuto; i++)
    {
        if( autos[i].isEmpty == 0 && autos[i].idMarca == idMarca)
        {
            mostrarAuto(autos[i],marcas,tamAuto,colores);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay Autos que mostrar\n");
    }
}

void mostrarAutosXColor(eAuto autos[],int tamAuto,eMarca marcas[], int tamMarcas,eColor colores[],int tamColor){
    int idColor;
    int cont = 0;
    char nombreColor[20];
    int flag = 0;

    system("cls");
    printf("-------- INFORMES --------\n\n");
    printf("----- Autos Por Color -----\n");


    do{

    mostrarColores(colores,tamColor);
    printf("\nIngrese ID de la Color: ");
    scanf("%d",&idColor);

    }while(idColor < 5000 && idColor > 5004);


    for(int i = 0; i < tamAuto; i++){
        if(autos[i].isEmpty == 0 && autos[i].idColor == idColor){
            cont++;
        }
    }

    for(int i = 0; i<tamColor; i++){
        if(colores[i].id == idColor){
            strcpy(nombreColor,colores[i].nombreColor);
            printf("La cantidad de %s son : %d .",nombreColor,cont);
            printf("\n   ID       Patente        Marca    Color    Modelo  \n\n");
            break;
        }
    }

        for(int i=0; i < tamAuto; i++)
    {
        if( autos[i].isEmpty == 0 && autos[i].idColor == idColor)
        {
            mostrarAuto(autos[i],marcas,tamAuto,colores);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay Autos que mostrar\n");
    }

}

void mostrarAutorXModelo(eAuto autos[],int tamAuto,eMarca marcas[], int tamMarcas,eColor colores[],int tamColor){
    int modelo;
    int flag = 0;

    system("cls");
    printf("-------- INFORMES --------\n\n");
    printf("----- Autos Por Modelo -----\n");


    printf("\nIngrese el Modelo: ");
    scanf("%d",&modelo);

    printf("\n   ID       Patente        Marca    Color    Modelo  \n\n");
    for(int i = 0; i<tamAuto ; i++){
        if(autos[i].isEmpty == 0 && autos[i].modelo == modelo){
            mostrarAuto(autos[i],marcas,tamAuto,colores);
            flag = 1;
        }
    }

    printf("\n");
    if(flag == 0){
        printf("No hay Autos con este anio de Modelo.\n");
    }
}

void mostrarAutosXMarcaYModelo(eAuto autos[],int tamAuto,eMarca marcas[], int tamMarcas,eColor colores[],int tamColor){

    int idMarca;
    int modelo;
    int flag = 0;

    system("cls");
    printf("-------- INFORMES --------\n\n");
    printf("----- Autos Por Marca y Modelo -----\n");


    do{

    mostrarMarcas(marcas,tamMarcas);
    printf("\nIngrese ID de la Marca: ");
    scanf("%d",&idMarca);

    }while(idMarca < 1000 && idMarca > 1005);

    printf("\nIngrese el Modelo: ");
    scanf("%d",&modelo);

    printf("\n   ID       Patente        Marca    Color    Modelo  \n\n");
    for(int i = 0; i<tamAuto ; i++){
        if(autos[i].isEmpty == 0 && autos[i].idMarca == idMarca && autos[i].modelo == modelo){
            mostrarAuto(autos[i],marcas,tamAuto,colores);
            flag = 1;
        }
    }

    printf("\n");
    if(flag == 0){
        printf("No hay Autos con este anio de Modelo.\n");
    }
}

void mostrarAutosXMarcaYColor(eAuto autos[],int tamAuto,eMarca marcas[], int tamMarcas,eColor colores[],int tamColor){
    int idMarca;
    int idColor;
    int flag = 0;

    system("cls");
    printf("-------- INFORMES --------\n\n");
    printf("----- Autos Por Marca y Color -----\n");


    do{

    mostrarMarcas(marcas,tamMarcas);
    printf("\nIngrese ID de la Marca: ");
    scanf("%d",&idMarca);

    }while(idMarca < 1000 && idMarca > 1005);


    do{

    mostrarColores(colores,tamColor);
    printf("\nIngrese ID de la Color: ");
    scanf("%d",&idColor);

    }while(idColor < 5000 && idColor > 5004);

    printf("\n   ID       Patente        Marca    Color    Modelo  \n\n");
    for(int i = 0; i<tamAuto ; i++){
        if(autos[i].isEmpty == 0 && autos[i].idMarca == idMarca && autos[i].idColor == idColor){
            mostrarAuto(autos[i],marcas,tamAuto,colores);
            flag = 1;
        }
    }

    printf("\n");
    if(flag == 0){
        printf("No hay Autos con este Color.\n");
    }


}
