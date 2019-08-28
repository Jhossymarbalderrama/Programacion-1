/* Ayuda :  #include <string.h>
            para poder Usar la Funcion "strcpy(char1 , char2);" // paso lo de Char2 a char1

Pedir Nombre/Sexo/Nota mientras el Usuario quiera

   Informar: *Nombre y el sexo mayor nota y de la menor
             *Promedio de notas totales
             *promedio de notas de mujeres

             char : caracteres
             int : numericos
             float : promedios totales
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre;
    char sexo;
    char seguir;
    int nota=0;
    //*Nombre y el sexo mayor nota y de la menor

    //*Promedio de notas totales
    int acumNotas=0;
    int contador=0;
    float promedio=0;
    //*promedio de notas de mujeres


    do{
        //Pido Nombre
        printf("Ingrese su Nombre: "); //Pido el Nombre
        fflush(stdin);
        scanf("%c", &nombre); //Asigno el Valor del Printf(C(Character)) a Nombre


        //Validacion de Sexo
        do{
            printf("Ingrese su Sexo(f o m): ");
            fflush(stdin);
            scanf("%c", &sexo);
        }while(!(sexo == 'f' || sexo == 'm'));


        //Pido Nota
        do{
            printf("Ingrese su Nota(entre 0-10): ");
            fflush(stdin);
            scanf("%d", &nota);

        }while(!(nota<=10 && nota>=0));

        //Informar :
        contador ++;


        printf("Quiere continuar?: ");
        fflush(stdin);
        scanf("%c",&seguir);
    }while(seguir == 's');



    /*
    printf("Quiere continuar?: ");
    fflush(stdin);
    //scanf("%c", &seguir);
    seguir = getchar();//Seteo la tecla asignada para la condicion en este caso "S" con el getchar()
    seguir = getche();//deja el Char que fue seteado en la pantalla con getch()
    */

    return 0;
}


/* tps 1 menu de opciones
    #include <stdlib.h>

    char opcion;
    char seguir='n';

    do{

        system("cls");
        printf("-----Menu de Opciones------ \n\n");
        printf("a- Sumar\n");
        printf("b- Resta\n");
        printf("c- Multiplicacion\n");
        printf("d- Division\n");
        printf("e- Salir\n\n");
        printf("Ingrese Opciones: ");
        opcion = getche();

        switch(opcion){
        case 'a':
            printf("Usted eligio Sumar\n");
                //Linea de Codigo segun la Opcion
            system("pause");
            break;
        case 'b':
            printf("Usted eligio Restar\n");
                //Linea de Codigo segun la Opcion
            system("pause");
            break;
        case 'c':
            printf("Usted eligio Multiplicar\n");
                //Linea de Codigo segun la Opcion
            system("pause");
            break;
        case 'd':
            printf("Usted eligio Dividir\n");
                //Linea de Codigo segun la Opcion
            system("pause");
            break;
        case 'e':
            printf(\n"Usted eligio Salir\n");
            printf("Confirma salida?");
            seguir = getche();
                //Linea de Codigo segun la Opcion
            //seguir= 'n';
            system("pause");
            break;
        default:
            printf(\n"Opcion Invalida\n\n");
            system("pause");
            break;
        }

    }while(seguir == 'n');

    return =0;
    //4 maneras para levantar caracteres Char
    char x;
    //*scanf("%c", &x);
    //*x = getchar();
    //*x = getch();
    //*x = getche ();
*/
