#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Funcion de Strcpy
int main()
{
    /*
    char nombre[10];
    char auxCad[100];
    //int cant;

    printf("Ingrese Nombre: ");
    gets(auxCad);

    while(strlen(auxCad) > 9){
        printf("Error. Nombre demasiado largo. Reingrese nombre: ");
        gets(auxCad);
    }

    strcpy(nombre, auxCad);

    printf("%s\n",nombre);
    */


    /*
    char n1[10] = "juan";
    char n2[20] = "Juan";
    int x;


    x = strcmp(n1, n2); //STRCMP Comparacion de nombres en Vectores

    printf("%d\n", x);
    */



    char n1[10] = "Juan";
    char n2[20] = "ALBERTO";

    n2[0] = toupper(n2[0]);

    printf("%s",n2);
    return 0;

}
