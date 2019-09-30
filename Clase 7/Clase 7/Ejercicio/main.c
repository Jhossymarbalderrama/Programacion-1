#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main()
{
    char nombre[20];
    char apellido[20];
    char auxNombre[20];
    char auxApe[20];
    char nombreCompleto[100];
    int i=0;

    printf("Ingrese Nombre: ");
    gets(auxNombre);

    while(strlen(auxNombre) > 19){
        printf("Error. Nombre demasiado largo. Reingrese nombre: ");
        fflush(stdin);
        gets(auxNombre);
    }

    strcpy(nombre, auxNombre);

    printf("Ingrese Apellido: ");
    gets(auxApe);

    while(strlen(auxApe) > 19){
        printf("Error. Apellido demasiado largo. Reingrese apellido: ");
        fflush(stdin);
        gets(auxApe);
    }

    strcpy(apellido, auxApe);
/*
    strlwr(nombre);
    strlwr(apellido);

    nombre[0] = toupper(nombre[0]);
    apellido[0] = toupper(apellido[0]);
*/
    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombreCompleto);

    nombreCompleto[0] = toupper(nombreCompleto[0]);

    while(nombreCompleto[i] != '\0'){
        if(nombreCompleto[i] == ' '){
        nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
        }
        i++;
    }



    printf("Su nombre es %s",nombreCompleto);


    return 0;
}
