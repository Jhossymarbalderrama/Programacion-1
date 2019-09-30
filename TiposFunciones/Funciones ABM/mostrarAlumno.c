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

