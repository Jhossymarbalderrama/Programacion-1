#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct {
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;

    int isEmpty;
}eAlumno;

/**< Muestra los Datos cargados de una Persona */
void mostrarAlumno(eAlumno x){
    printf(" %d%10s    %d    %c      %d     %d      %.2f   %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

/**< Muestra los Datos cargados de una Persona */
void mostrarAlumnos(eAlumno vec[], int tam)
{
    int flag = 0;
    printf("Legajo   Nombre   Edad  Sexo  Nota1 Nota2 Promedio FIngreso\n");
        for(int i=0; i < tam; i++){
            if(vec[i].isEmpty == 0){
                mostrarAlumno(vec[i]);
                system("pause");
                flag = 1;
            }
        }

        if(flag == 0){
            system("cls");
            printf("\nNo hay Alumnos que mostrar.");
        }
    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam);

/**< Marca de si esta dado de Alta en la Estructura */
void inicializacionAlumnos(eAlumno alumnos[], int tam){
    for(int i=0; i < tam ; i ++){
        alumnos[i].isEmpty = 1;
    }
}

/**< Buscador de Indice para Alta */
int buscarLibre(eAlumno alumnos[], int tam){
    int indice = -1;

    for(int i = 0; i < tam;i++){
        if(alumnos[i].isEmpty == 1){
            indice = i ;
            break;
        }
    }
    return indice;
}

/**< Buscador de Persona */
int buscarAlumno(int legajo, eAlumno alumnos[], int tam){
    int indice = -1;

    for(int i = 0; i < tam;i++){
        if(alumnos[i].isEmpty == 0 && alumnos[i].legajo == legajo){
            indice = i ;
            break;
        }
    }
    return indice;
}

/**< Temporal de Alta */
eAlumno newAlumno(int legajo, char nombre[],char sexo, int edad, int n1, int n2, eFecha fecha){
    eAlumno nuevoAlumno;
    nuevoAlumno.legajo = legajo;
    strcpy(nuevoAlumno.nombre, nombre);
    nuevoAlumno.edad = edad;
    nuevoAlumno.sexo = sexo;
    nuevoAlumno.nota1 = n1;
    nuevoAlumno.nota2 = n2;
    nuevoAlumno.promedio = (float) (n1 + n2) / 2;
    nuevoAlumno.fechaIngreso = fecha;

    nuevoAlumno.isEmpty = 0 ;
    return nuevoAlumno;
}




