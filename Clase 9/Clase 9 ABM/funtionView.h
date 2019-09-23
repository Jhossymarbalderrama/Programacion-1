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
void mostrarAlumno(eAlumno x);

/**< Muestra los Datos cargados de una Persona */
void mostrarAlumnos(eAlumno vec[], int tam);

/**< Ordena los Datos cargados */
void ordenarAlumnos(eAlumno vec[], int tam);

/**< Marca de si esta dado de Alta en la Estructura */
void inicializacionAlumnos(eAlumno alumnos[], int tam);

/**< Buscador de Indice para Alta */
int buscarLibre(eAlumno alumnos[], int tam);

/**< Buscador de Persona */
int buscarAlumno(int legajo, eAlumno alumnos[], int tam);

/**< Temporal de Alta */
eAlumno newAlumno(int legajo, char nombre[],char sexo, int edad, int n1, int n2, eFecha fecha);
