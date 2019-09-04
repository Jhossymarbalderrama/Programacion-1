#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "FuntionSuma.h"
#include "FuntionResta.h"
#include "FuntionMultiplicacion.h"
#include "FuntionDivision.h"
#include "FuntionFactorial.h"

char menu(void);//Funcion

int main()
{
    char seguir = 'n';

    do{
        switch(menu()){
        case 'a':
            printf("\n----- Usted eligio Sumar ----- \n\n");
            //Linea de Codigo segun la Opcion
            //Suma
            int numS1;
            int numS2;
            int suma;

            printf("Ingrese un numero: ");
            scanf("%d", &numS1);

            printf("Ingrese otro numero: ");
            scanf("%d", &numS2);

            suma = funtionSuma(numS1, numS2);

            printf("\nLa suma de %d y %d es %d .\n", numS1, numS2, suma);
            system("pause");

            break;
        case 'b':
            printf("\n----- Usted eligio restar ----- \n\n");
            //Linea de Codigo segun la Opcion
            //Resta
            int numR1;
            int numR2;
            int resta;

            printf("Ingrese un numero: ");
            scanf("%d", &numR1);

            printf("Ingrese otro numero: ");
            scanf("%d", &numR2);

            resta = funtionResta(numR1, numR2);

            printf("\nLa resta de %d y %d es %d .\n", numR1, numR2, resta);
            system("pause");

            break;
        case 'c':
            printf("\n----- Usted eligio multiplicar -----\n\n");
            //Linea de Codigo segun la Opcion
            //multiplicar
            int numM1;
            int numM2;
            int multiplicacion;

            printf("Ingrese un numero: ");
            scanf("%d", &numM1);

            printf("Ingrese otro numero: ");
            scanf("%d", &numM2);

            multiplicacion = funtionMultiplicacion(numM1, numM2);

            printf("\nLa multiplicacion de %d por %d es %d .\n", numM1, numM2, multiplicacion);

            system("pause");
            break;
        case 'd':
            printf("\n----- Usted eligio dividir----- \n\n");
            //Linea de Codigo segun la Opcion
            //Division
            int numD1;
            int numD2;
            int division;

            printf("Ingrese un numero: ");
            scanf("%d", &numD1);

            printf("Ingrese otro numero: ");
            scanf("%d", &numD2);

            division = funtionDivision(numD1, numD2);

            if(division == 0){
                perror("Error.");
            }else{
                printf("\nLa division de %d / %d es %d .\n", numD1, numD2, division);
            }

            system("pause");
            break;
        case 'e':
            printf("\n----- Usted eligio Factorial----- \n\n");
            //Linea de Codigo segun la Opcion
            //Factorial
            int numF1;
            int factorial;

            printf("Ingrese un numero: ");
            scanf("%d", &numF1);

            factorial = funtionFactorial(numF1);

            printf("\nEl factorial de %d es %d .\n",numF1 , factorial);

            system("pause");
            break;
        case 'f':
            printf("\nUsted eligio Salir\n");
            printf("Confirma salida? ");
            seguir = getche();
            printf("\n");
            system("pause");

            break;
        default:
            printf("\n\nOpcion Invalida\n\n");
            system("pause");
            break;
        }

    }while(seguir == 'n');

}


char menu(void){
     char opcion;

     system("cls");
     printf("----- Menu de Operaciones -----\n");
     printf("a- Sumar\n");
     printf("b- Restar\n");
     printf("c- Multiplicar\n");
     printf("d- Dividir\n");
     printf("e- Factorial\n");
     printf("f- Salir\n");
     printf("\n");
     printf("Ingrese opcion: ");
     opcion = getche();

     return(opcion);
}

