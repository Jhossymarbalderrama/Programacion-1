#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarVectorInt(int vec[], int tam);

int main()
{

    int vec[TAM] = {7, 5, 8, 1, 3};
    int aux;

    printf("Vector sin ordenar\n\n");

    mostrarVectorInt(vec, TAM);



    for(int i = 0; i < TAM-1; i++){

        for(int j = i + 1; j < TAM; j++){

            if( vec[j] < vec[i]){

                aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;
            }
        }
    }

    printf("Vector Ordenado\n\n");

    mostrarVectorInt(vec, TAM);


    return 0;
}

void mostrarVectorInt(int vec[], int tam){

    for( int i=0; i < tam; i++){
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}
