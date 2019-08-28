#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1=0;
    int numero2=0;
    int total;

    printf("Ingrese un valor Numero: ");
    fflush(stdin);
    scanf("%d", &numero1);

    printf("Ingrese otro valor Numero: ");
    fflush(stdin);
    scanf("%d", &numero2);

    total = numero1 + numero2;

    printf("La suma de los Valores es: %d",total);
    return 0;
}
