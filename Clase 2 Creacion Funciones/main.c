#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int sumar1(int a, int b);

int main()
{
    //Funcion de Suma
    int numero1;
    int numero2;
    int suma;

    printf("Ingrese un numero: ");
    scanf("%d", &numero1);

    printf("Ingrese otro numero: ");
    scanf("%d", &numero2);

    //suma = numero1 + numero2;
    //Usamos la Funcion creada
    suma = sumar1(numero1, numero2);

    printf("La suma de los numeros es %d\n", suma);


    /*
    char letra = 'H'

    letra = tolower(letra); //Mayuscula a Minuscula
    //letra = toupper(letra); //Minuscula a Mayuscula
    printf("%c\n", letra);
    */
    return 0;
}

int sumar1(int a, int b){
    int suma;

    suma = a + b;
    return suma;
}
