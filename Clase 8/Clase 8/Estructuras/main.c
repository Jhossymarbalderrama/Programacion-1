#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;

     struct{
        int dia;
        int mes;
        int anio;
    }fechaingreso;
}eAlumno;

int main()
{
    eAlumno alumno1;
    //eAlumno alumno2;

    printf("Ingrese Nombre: ");
    gets(alumno1.nombre);

    printf("Ingrese Legajo: ");
    scanf("%d",&alumno1.legajo);

    printf("Ingrese Edad: ");
    scanf("%d",&alumno1.edad);

    printf("Ingrese Sexo: ");
    fflush(stdin);
    scanf("%c",&alumno1.sexo);

    printf("Ingrese Nota Parcial 1: ");
    scanf("%d",&alumno1.nota1);

    printf("Ingrese Nota Parcial 2: ");
    scanf("%d",&alumno1.nota2);

    printf("Ingrese el Dia de Ingreso:");
    scanf("%d",&alumno1.fechaingreso.dia);

    printf("Ingrese el Mes de Ingreso:");
    scanf("%d",&alumno1.fechaingreso.mes);

    printf("Ingrese el Aneo de Ingreso:");
    scanf("%d",&alumno1.fechaingreso.anio);

    alumno1.promedio = (float) (alumno1.nota1 + alumno1.nota2) / 2 ;

    printf("\n Nombre: %s\nLegajo: %d\nEdad: %d\nSexo: %c\nNota 1: %d\nNota 2: %d\nPromedio : %.2f\nFecha: %02d/%d02d/%04d\n"
           ,alumno1.nombre
           ,alumno1.legajo
           ,alumno1.edad
           ,alumno1.sexo
           ,alumno1.nota1
           ,alumno1.nota2
           ,alumno1.promedio
           ,alumno1.fechaingreso.dia
           ,alumno1.fechaingreso.mes
           ,alumno1.fechaingreso.anio);

    return 0;
}
