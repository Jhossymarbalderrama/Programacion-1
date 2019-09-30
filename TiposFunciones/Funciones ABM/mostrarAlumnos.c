
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
