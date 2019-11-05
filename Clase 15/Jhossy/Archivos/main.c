#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**< "Extensiones para Archivos"*/
/**< FILE* , Algo = FOPEN(path,modo);
    Example:

    FOPEN("archivo.txt",w o wb)

  -  w = wb //Al inicio
  -  r = rb //Lectura
  -  a = ab //Al final


  fread = leer;
        example: fread(destino,sizeof,cant,FILE);
        ARCHIVO ----> MEMORIA

  fwrite = escribir // 4 parametros
    *Origen
    *Tipo de dato
    *Int Cantidad.
    *Un puntero a FILE.

        example: fwrite(origen,sizeof,cant,FILE*);

        ARCHIVO <---- MEMORIA
 */


int main()
{
    FILE* f = fopen("archivo.txt","r");
    char mensaje[30] = "Esto es un mensaje";
    char auxChar;
    char cadena [30];

    if(f == NULL){
        printf("No se pudo abrir el Archivo.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    //fwrite(mensaje,sizeof(char),strlen(mensaje),f);
    /**< feof  lee el archivo con el tamanio de contenido que tiene
    while(!feof(f)){
        fgets(cadena,29,f);

        puts(cadena);
        printf("%s",cadena);
    }
    */

    /**< fgets Y fgetc */
    while(!feof(f)){
        auxChar = fgetc(f);
      //  printf("%c",cadena);
      fread(cadena,sizeof(char),29,f);

       printf("%s",cadena);
    }


    /**<  leo cadena y lo muestro en consola con puts.
    fscanf(f,"%s",cadena);

    puts(cadena);

    */

    //fprintf(f,"Hola Mundo. ");

    fclose(f);
    return 0;
}
