#include <stdio.h>
#include <stdlib.h>

void mostrarVectorInt(int vec[], int tam);
void mostrarVectorChar(char vec[], int tam);
void mostrarVectorFloat(float vec[], int tam);

int main()
{
    int numeros [] = {23, 24, 43, 54, 28, 21, 66, 88, 32, 50};
    char x[] = {'a', 'e', 'i', 'o', 'u'};
    float reales[] = {2.2 , 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 , 10.10};


    mostrarVectorInt(numeros , 10);
    mostrarVectorChar(x , 5);
    mostrarVectorFloat(reales, 9);


    return 0;
}

void mostrarVectorInt(int vec[], int tam){

    for(int i = 0 ; i < tam ; i++){
        printf("%d ", vec[i]);
    }

    printf("\n\n");
}
void mostrarVectorChar(char vec[], int tam){
    for(int i = 0 ; i < tam ; i++){
        printf("%c ", vec[i]);
    }
    printf("\n\n");
}
void mostrarVectorFloat(float vec[], int tam){
    for(int i = 0 ; i < tam ; i++){
        printf("%.2f ", vec[i]);
    }
    printf("\n\n");
}
