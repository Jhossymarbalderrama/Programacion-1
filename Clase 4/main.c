#include <stdio.h>
#include <stdlib.h>
#include "Balderrama.h"

//int getInRange(char* , char*, int , int, int, int );

int main()
{
    //int numero;

    printf("%d",getInRange("Ingrese Edad: ", "Error. Reingrese Edad: " ,18 ,65 ,3 ,-1));

    return 0;
}

/*
int getInRange(char* mensaje, char* mensajeError, int nroMin, int nroMax, int intentos, int retornoError){
    int numero;
    int contador=0;

    printf("%s", mensaje);
    scanf("%d", &numero);

    while(!(numero >= nroMin && numero <= nroMax)){
        //printf("Ingrese un Numero: ");
        printf("%s", mensajeError);
        scanf("%d", &numero);

        if(contador == intentos){
            return retornoError;
        }

        contador ++;
    }
    return numero;
}
*/
