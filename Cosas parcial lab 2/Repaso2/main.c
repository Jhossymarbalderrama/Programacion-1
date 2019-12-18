#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int id;
    char marca[30];
    char procesador[20];
    float precio;
}eNotebook;


float totalconAumento(float valor, int aumento);
int cantidadVocales(char x []);


void mostrarNotebook(eNotebook x);
void mostrarNoteboooks(eNotebook x[], int tam);
void ordenarXMarcayPrecio(eNotebook x[], int tam);

int main()
{/*
    float valor;
    int aum;
    float total;

    printf("-----   INICIO   -----\n\n");

    printf("Ingrese el Valor: ");
    scanf("%f",&valor);

    printf("Ingrese el Aumento: ");
    scanf("%d",&aum);

    total = totalconAumento(valor,aum);

    printf("El valor total con aumento es : %0.2f",total);

    printf("\n\n----- Cantidad de Vocales ----\n\n");

    char palabra[20];
    int can = 0;

    printf("Ingrese una palaba : ");
    fflush(stdin);
    gets(palabra);

    can = cantidadVocales(palabra);

    printf("La cantidad de Vocales de %s es de %d .",palabra,can);
*/

    printf("\n\nStructura\n");
    /*
    eNotebook notebook[5] = {{1,"intel","corei3",13000.50},
                            {2,"amd","razen3",25000.50},
                            {3,"intel","corei7",20000.00},
                            {4,"amd","razen",18000.70},
                            {5,"intel","corei9",30000.30}};
                            */

    eNotebook notebook[6] = {
        {1000,"amd","sentey",350.5},
        {1001,"intel","samsung",350.51},
        {1002,"intel","samsung",3900.5},
        {1003,"amd","hp",3.5},
        {1004,"intel","samsung",350.5},
        {1005,"amd","hp",30.5},
    };

    mostrarNoteboooks(notebook,5);
    ordenarXMarcayPrecio(notebook,5);
    printf("Ordenado por Marca\n");
    mostrarNoteboooks(notebook,5);


    return 0;
}

float totalconAumento(float valor, int aumento){

    float total = 0;

    total =  (valor * aumento) / 100;

    total = valor + total;

    return total;
}


int cantidadVocales(char x []){

    int tam = 0;
    int can = 0;
    tam = strlen(x);

    for(int i = 0; i< tam ; i++){
        if(x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u' ||
           x[i] == 'A' || x[i] == 'E' || x[i] == 'I' || x[i] == 'O' || x[i] == 'U' ){
            can++;
        }
    }

    return can;
}

void mostrarNotebook(eNotebook x){
    printf("ID: %d  MARCA: %s   PROCESADOR: %s   PRECIO: %0.2f \n",x.id,x.marca,x.procesador,x.precio);
}

void mostrarNoteboooks(eNotebook x[], int tam){
    for(int i = 0; i< tam; i++){
        mostrarNotebook(x[i]);
    }
}

void ordenarXMarcayPrecio(eNotebook x[], int tam){
    eNotebook aux;


    for(int i = 0; i<tam-1;i++){
        for(int j = i+1 ; j<tam;j++){
            if(!(strcmp(x[i].marca,x[j].marca)<1) && x[i].precio > x[j].precio){
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }else if(strcmp(x[i].marca,x[j].marca)>0){
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
        }
    }

}

