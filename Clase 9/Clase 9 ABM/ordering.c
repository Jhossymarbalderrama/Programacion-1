
void ordenarAlumnos(eAlumno vec[], int tam){

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++){
        for(int j= i+1; j <tam; j++){
            if( vec[i].legajo > vec[j].legajo){
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
}
