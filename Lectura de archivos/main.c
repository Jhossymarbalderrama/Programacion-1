#include <stdio.h>
#include <stdlib.h>

/*   Manejo de archivos en lenguaje c */
/*   Lectura de Archivos  */
/*   Flujo de datos FILE  */


/*   PROGRAMA -> CANAL < DISCO DURO -- Escritura  */

/*   PROGRAMA <- CANAL(FLUJO DE DATOS) <- DISCO_DURO  -- Lectura  */


int main()
{
//rb modo textual solo r pero para ser mas rapido lo pongo como rb "b" Binario
    FILE * flujo = fopen("Prueba.txt", "rb"); //https://osu.ppy.sh/beatmapsets/

    if(flujo == NULL){
        perror("Error en la apertura del Archivo");
        return 1;
    }

    fseek(flujo, 0, SEEK_END);
    int num_elementos = ftell(flujo);//ftell para ver donde esta mi Flujo de Datos
    rewind(flujo); //rewind (Revovinar el flujo al principio)

    //calloc = Crear una cadena o arreglo de caracteres en binario
    char * cadena = (char *) calloc(sizeof(char), num_elementos);

    if (cadena == NULL){
        perror("Error en reserva de memoria");
        return 2;
    }

    int num_elementos_leidos = fread(cadena, sizeof(char), num_elementos, flujo);
    if (num_elementos_leidos != num_elementos){
        perror("Error leyendo el archivo");
        return 3;
    }

    printf("%s", cadena);

    free(cadena); //Libero cadena en la memoria
/* seperacion de Numeros y Cadenas
   int numero;
   char cadena[10];

    while(feof(flujo) == 0){
        fscanf(flujo, "%d %s", &numero, &cadena);
        numero *= 10 ;
        printf("%d %s\n", numero,cadena);
    }
*/
    fclose(flujo);
    printf("\n\nSe ha leido el archivo correctamente ..");


    return 0;
}
