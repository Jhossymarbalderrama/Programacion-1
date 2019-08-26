/* LABORATORIO 1
    Code Blocks 16.01
    YouTube = ejercicios en Sistema utnfra
    UTN FRA = http://www.utnfravirtual.org.ar/

    laboratorio 1 = tener parciales y tps aprobados
    1 tp , se entrega el 6 de septiembre


    Guia de Ejercicios PDF

    /*Practicar hasta el Ejercicio 57*/
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Welcome //Ejercicio sacado de los tps del Curso de Ingreso
        Realizar el Algoritmo que permita el ingreso de dos Datos, una letra y un numero entre -100 y 100 (Validar)
        hasta que el usuario quiera e informar al terminar el Ingreso por printf.

        a)La cantidad de numeros pares.
        b)La cantidad de numeros impares.
        c)La cantidad de Ceros.
        d)El promedio de todos los numeors positivos ingresados.
        e)La suma de todos lo numeros negativos.
        f)Elnumero y la letra del maximo y el minimo.
    */
/* //Welcome //Ejercicio sacado de los tps del Curso de Ingreso
    char letra[1];
    char letraMax;
    char letraMin;
    char seguir;
    int numero; //validar -100 a 100
    int acumuladorNeg = 0;
    int acumuladorPos = 0;
    int contPos = 0;
    int contPares = 0;
    int contImpares = 0;
    int contCeros = 0;
    int maximo;
    int minimo;
    int flag = 0;
    float promedio;

    do{
        printf("Ingrese la Letra: ");
        fflush(stdin);
        scanf("%c", letra);

        printf("ingrese un numero -100 y 100: ");
        scanf("%d", &numero);

        while(! (numero >= -100 && numero <= 100)){
            printf("Error. Ingrese un numero -100 y 100")
            scanf("%d", &numero);
        }
        //
        if(numero % 2 == 0){
            contPares ++;
        }
        else{
            contImpares++;
        }
        //
        if(numero > 0){
            acumuladorPos += numero;
            contPos++;
        }
        else if (numero < 0){
            acumuladorNeg += numero ;
        }
        else{
            contCeros ++;
        }

        if(numero > maximo || flag ==0){
            maximo = numero;
            letraMax = letra;
        }

        if(numero < maximo || flag ==0){
            minimo = numero;
            letraMin = letra;
            flag = 1;//hago el flag valor 1 en el segundo if  para que termine
        }

        printf("Quiere continuar?: ");
        fflush(stdin);
        scanf("%c",&seguir);

    }while(seguir == "s");

    if(contPos != 0){
       promedio = (float) acumuladorPos / contPos;
    }
*/







/* //Ejercicio Clase

    int numero;
    int acumulador = 0;
    //int contador = 0;
    float promedio;

    //int i;
    //para Inicializar una variable en el for tener que activar en opciones  la version 1999 de c (Settings/Compiler)
    for(int i = 0 ;i < 5 ; i++){

        printf("Ingresar un numero: ");
        scanf("%d", &numero);

        acumulador += numero;
    }
    //(float) Casteo el resultado de la Division para que no me de Entero
    promedio = (float) acumulador / 5; // si pongo 5 es Entero y me daria resultado en entero , si pongo 5.0 es Flotante y meda Decimanles

    printf("La suma de los numeros es %d y el promedio es %.2f\n", acumulador,promedio);

*/





    /* //Ejemplo de Pedidio de datos y costrarlos
        char nombre[20];
        int edad;

        printf("Ingrese su nombre: ");
        scanf("%s", nombre);
        //algo mejor que el fflush "buffer" es el - Getc -

        printf("Ingrese su Edad: ");
        //fflush(stdin);  // borra el por si tengo datos -buffer (de entrada)
        scanf("%d", edad);

        printf("Usted se llama %s y tiene %d anios\n", nombre , edad);

     */


   /*- Ejercicio aparte - pedidio de un numero al Usuario.*/

    //int numero;

    //printf("Ingrese un numero:"); //estas 2 lineas seria como en javascrip al pedir al usuario por prompt
    //scanf("%d", &numero);
    /*
     %d = Decimal
     %h = HexaDecimal
     %b = Binario
     %o = Octal
    */

    //printf("Usted ingreso el numero %d\n", numero);

    /* Ejercicio aparte*/





/* Introduccion
        //Introduccio Clase 1
        int numero = 2019;
        int numero2 = 21;
        char letra = 'A';
        char nombre[20] = "Juan";
        float precio = 123.75;

        //O se puede crear y despues asignar el valor al Int
        //numero = 2019;
        //numero2 = 21;

        //printf("Hello world!\n");

        //ejercicio 1 ejemplo
        //printf("Estamos en el Anio  %d y el dia de hoy es %d\n", numero, numero2);


        //ejercicio 2
        //printf("Estamos en el Anio  %d y el dia de hoy es %c\n", numero, letra);

        //Ejercicio 3 Guardar un Nombre
        //printf("Su nombre es %s\n", nombre);

        //Ejercicio 4
        printf("El precio es %.1f\n", precio); //de 1 hasta el 5 rendondea hasta abajo
        printf("El precio es %.2f\n", precio); //de 6  en adelante rendondea hasta arrriba
        printf("El precio es %.3f\n", precio);
        printf("El precio es %.4f\n", precio);
        printf("El precio es %.5f\n", precio);

Final Introduccion*/

    return 0; //Al fnal
}
