#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "LinkedList.h"
typedef struct{
    int id_bike;
    char nombre[20];
    char tipo[20];
    int tiempo;
}eBicicleta;

#endif //
eBicicleta* bicicleta_newParametros(char* idStr, char*nombreStr, char* tipoStr, char* tiempoStr);
eBicicleta* bicicleta_new();

int bicicleta_setId(eBicicleta* this,int id);
int bicicleta_setTiempo(eBicicleta* this,int tiempo);
int bicicleta_setNombre(eBicicleta* this,char* nombre);
int bicicleta_setTipo(eBicicleta* this,char* tipo);

int bicicleta_getId(eBicicleta* this,int* id);
int bicicleta_getNombre(eBicicleta* this,char* nombre);
int bicicleta_getTipo(eBicicleta* this,char* tipo);
int bicicleta_getTiempo(eBicicleta* this,int* tiempo);

int mostrarBicicleta(eBicicleta* e);
int listarBicicletas(LinkedList* lista);

