#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
/*
Escribir un programa que realice las siguientes accciones:
    *Limpie la Pantalla
    *Asigne a 2 variables numero1 y numero2 valores distintos de cero
    *Efectue el producto de dichas variables
    *muestre el resultado pos pantalla
    *obtenga el cuadrado de numero1 y lo muestre por pantalla

*/

int sumar1(int a, int b); //Funcion

int main()
{
    //tps 1 menu de opciones
    char opcion;
    char seguir='n';

    do{

        system("cls");
        printf("-----Menu de Opciones------ \n\n");
        printf("a- Sumar\n");
        printf("b- Resta\n");
        printf("c- Multiplicacion\n");
        printf("d- Division\n");
        printf("e- Factorial\n");
        printf("f- Salir\n\n");
        printf("Ingrese Opciones: ");
        opcion = getche();

        switch(opcion){
        case 'a':
            printf("\nUsted eligio Sumar\n");
                //Linea de Codigo segun la Opcion
                    //Suma
                    int numero1;
                    int numero2;
                    int suma;

                    printf("Ingrese un numero: ");
                    scanf("%d", &numero1);

                    printf("Ingrese otro numero: ");
                    scanf("%d", &numero2);

                    suma = sumar1(numero1, numero2);

                    printf("La suma de los numeros es %d\n", suma);
            system("pause");
            break;
        case 'b':
            printf("\nUsted eligio Restar\n");
                //Linea de Codigo segun la Opcion
                        int numeroResta1;
                        int numeroResta2;
                        int resta;

                        printf("Ingrese un numero: ");
                        scanf("%d", &numeroResta1);

                        printf("Ingrese otro numero: ");
                        scanf("%d", &numeroResta2);

                        resta = numeroResta1-numeroResta2;

                        printf("La resta de los numeros es %d\n", resta);
            system("pause");
            break;
        case 'c':
            printf("\nUsted eligio Multiplicar\n");
                //Linea de Codigo segun la Opcion

                        int multip1;
                        int multip2;
                        int multiplicacion;

                        printf("Ingrese un numero: ");
                        scanf("%d", &multip1);

                        printf("Ingrese otro numero: ");
                        scanf("%d", &multip2);

                        multiplicacion = multip1*multip2;

                        printf("La resta de los numeros es %d\n", multiplicacion);
            system("pause");
            break;
        case 'd':
            printf("\nUsted eligio Dividir\n");
                //Linea de Codigo segun la Opcion
            system("pause");
            break;
        case 'e':
        printf("\nUsted eligio Factorial\n");
        //Linea de Codigo segun la Opcion
        system("pause");
        break;
        case 'f':
            printf("\nUsted eligio Salir\n");
            printf("Confirma salida?\n");
            seguir = getche();
                //Linea de Codigo segun la Opcion
            //seguir= 'n';
            system("pause");
            break;
        default:
            printf("\n\nOpcion Invalida\n\n");
            system("pause");
            break;
        }

    }while(seguir == 'n');

    //return =0;
    //4 maneras para levantar caracteres Char
    ////char x;
    //*scanf("%c", &x);
    //*x = getchar();
    //*x = getch();
    //*x = getche ();

}

int sumar1(int a, int b){
    int suma;

    suma = a + b;
    return suma;
}

