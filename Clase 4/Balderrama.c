int getInRange(char* mensaje, char* mensajeError, int nroMin, int nroMax, int intentos, int retornoError){
    int numero;
    int contador=0;

    printf("%s", mensaje);
    scanf("%d", &numero);

    while(!(numero >= nroMin && numero <= nroMax)){
        //printf("Ingrese un Numero: ");
        printf("%s", mensajeError);
        scanf("%d", &numero);

        if(contador == intentos){
            return retornoError;
        }

        contador ++;
    }
    return numero;
}
