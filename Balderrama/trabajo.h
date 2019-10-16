#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "servicios.h"
#include "autos.h"

typedef struct{
    int id;
    char patente[10];
    int idServicio;
    int isEmpty;
    eFecha fecha;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

eTrabajo newtrabajo(int id,char patente[],int idServicio,eFecha fecha);
void mostrarTrabajos(eTrabajo trabajos[], int tamTrabajos,  eServicio servicios[], int tamServicio);
void mostrarTrabajo (eTrabajo trabajos,eServicio servicios[], int tamServicios);
int altaTrabajo(eTrabajo trabajos[], int tamTrabajos, int idTrabajo, eAuto autos[], int tamAutos, eServicio servicios[], int tamServicios, eColor colores[], int tamColores, eMarca marcas[], int tamMarcas);
void inicializarTrabajos(eTrabajo trabajos[], int tam);
int buscarLibreTrabajo(eTrabajo trabajo[], int tam);
