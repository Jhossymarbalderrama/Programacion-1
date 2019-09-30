
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

void mostrarAlumnos(eAlumno vec[], int tam);
