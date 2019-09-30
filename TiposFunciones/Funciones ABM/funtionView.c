
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
