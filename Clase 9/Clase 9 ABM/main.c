#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funtionView.h"
#define TAM 1

int altaAlumno(eAlumno alumnos[],int tam);
int bajarAlumno(eAlumno alumnos[],int tam);
void modificarAlumno(eAlumno alumnos[],int tam);

int menuAlumno();
int menu();

int main()
{
    eAlumno lista[TAM];
    char seguir = 'n';

    inicializacionAlumnos(lista,TAM);

    do{

        switch(menu()){
            case 1:
                altaAlumno(lista, TAM);
                break;
            case 2:
                bajarAlumno(lista,TAM);
                break;
            case 3:
                modificarAlumno(lista,TAM);
                break;
            case 4:
                //printf("----- Listar Alumnos -----");
                mostrarAlumnos(lista, TAM);
                break;
            case 5:
                printf("----- Ordenar Alumnos -----");
                //aca va el alta alumno
                break;
            case 6:
                printf("----- Informes Alumnos -----");
                break;
            case 7:
                printf("Confirmar salida? ");
                fflush(stdin);
                seguir = getch();
                break;
            default :
                printf("Opcion Invalida");
                break;
        }

    }while(seguir == 'n');

    return 0;
}

int menu(){

int opcion;

    system("cls");
    printf("Menu de Opciones \n\n");
    printf("1- Alta Alumno\n");
    printf("2- Baja Alumno\n");
    printf("3- Modificar Alumno\n");
    printf("4- Listar Alumno\n");
    printf("5- Ordenar Alumno\n");
    printf("6- Informes\n");
    printf("7- Salir\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

return opcion;
}

int altaAlumno(eAlumno alumnos[],int tam){
    int todoOk = 0;
    int indice;
    int esta;
    int legajo;
    int edad;
    int n1;
    int n2;
    char sexo;
    char nombre[20];
    //float promedio;
    eFecha fecha;
    //eAlumno nuevoAlumno;

    indice = buscarLibre(alumnos, tam);

    system("cls");
    printf("----- Alta de Personas -----\n");

    if(indice == -1){
        printf("Sistema Completo. No se pueden agregar mas alumnos\n");
        system("pause");
    }
    else{
        printf("Ingrese Legajo: ");
        scanf("%d",&legajo);
        esta = buscarAlumno(legajo,alumnos,tam);

        if(esta != -1){
            printf("Legajo ya registrado\n");
            mostrarAlumno(alumnos[esta]);

            system("pause");
        }
        else{
            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese edad: ");
            scanf("%d", &edad);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &sexo);

            printf("Ingrese nota parcial 1: ");
            scanf("%d", &n1);

            printf("Ingrese nota parcial 2: ");
            scanf("%d", &n2);

            printf("Ingrese fecha ingreso: dd/mm/aaaa ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

            alumnos[indice] =  newAlumno(legajo, nombre, sexo, edad, n1, n2,fecha);
        }
    }
    return todoOk;
}

int bajarAlumno(eAlumno alumnos[],int tam){

    int todoOka = 0;
    int indice;
    int legajo;
    char confirma;

    system("cls");
    printf("\n----- Baja Alumno -----\n");
    printf("Ingrese Legajo : ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, alumnos,tam);


    if(indice == -1){
        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else{
        mostrarAlumno(alumnos[indice]);
        printf("\nConfirma Eliminacion?: ");
        fflush(stdin);
        confirma = getche();
        if(confirma == 's'){
            alumnos[indice].isEmpty = 1;
            printf("\nSe ha Eliminado el Alumno\n");
            todoOka = 1;
        }
        else{

            printf("\nSe ha cancelado la baja.\n");
        }
        system("pause");
    }
    return todoOka;
}

void modificarAlumno(eAlumno alumnos[],int tam){
    int indice;
    int legajo;
    //char confirma;

    system("cls");
    printf("\n----- Modificacion Alumno -----\n");
    printf("Ingrese Legajo : ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, alumnos,tam);

    if(indice == -1){
        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else{
        mostrarAlumno(alumnos[indice]);
        switch(menuAlumno()){
        case 1:
            system("pause");
            break;
        case 2:
            system("pause");
            break;
        case 3:
            system("pause");
            break;
        case 4:
            system("pause");
            break;
        case 5:
            system("pause");
            break;
        case 6:
            system("pause");
            break;
        case 7:
            printf("Confirmar salida? ");
            fflush(stdin);
            system("pause");
            break;
        default :
            printf("Opcion Invalida");
            break;
        }

        system("pause");
    }
}

int menuAlumno(){
    int opcion;
    system("cls");
    printf("Modificacion de Alumno \n\n");
    printf("1- Nombre\n");
    printf("2- Edad\n");
    printf("3- Sexo\n");
    printf("4- Nota 1\n");
    printf("5- Nota 2\n");
    printf("7- Cancelar\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
