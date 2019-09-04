#include <stdio.h>
#include <stdlib.h>

        /*ARRAY*/

/*
    char int y float son : escalares(Guardan 1 solo Valor)
*/


int main()
{
    char sexos[5]; //Ingresar 5 sexos f o m
    int contM;
    int contF;

    printf("----- Ingrese 5 Sexos -----\n");
    for(int i = 0 ; i < 5 ; i++){
        printf("Ingrese un Sexo (f o m): ");
        fflush(stdin)
        scanf("%s",sexos);

        if(sexos == "f"){
            contF + 1;
        }
        if(sexos == "m"){
            contM + 1;
        }

    }

    printf("\nLa cantidad de Femenino es %d y Masculino %d .",contF , contM);

/*
    int vector[5];
    int i;

    for(i=0;i<5;i++){
        printf("Ingrese valor a cargar en el vector: ");
        scanf("%d ",&vector[i]);

    while(vector[i] <= 0){
        printf("Error. Ingrese un numero positivo: ");
        scanf("%d ",&vector[i]);
    }
    }

    for (i=0;i<5;i++){
        printf("%d ",&vector);
    }
*/
    return 0;
}
