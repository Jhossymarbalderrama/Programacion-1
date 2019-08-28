#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero=0;
    int contador=0;
    int acumulador=0;

    do{
        printf("Ingrese un Numero: ");
        fflush(stdin);
        scanf("%d", &numero);

        acumulador += numero;
        contador++;
    }while(contador<5);


    printf("La medida de los 5 valores Numericos Sumados es: %d", acumulador);

    return 0;
}
