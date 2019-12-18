#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "menu.h"
#include "controller.h"
#include "bicicleta.h"
#include <time.h>

int main()
{
    srand (time(NULL));
    char rta = 'n';
    int flag = 0;
    LinkedList* lista = ll_newLinkedList();
    char archivo[20];
    char extension[10] = ".csv";

    do
    {
        switch(menu())
        {
        case 1:

            if(!flag)
            {
                printf("Ingrese nombre del archivo: ");
                fflush(stdin);
                gets(archivo);
                strcat(archivo,extension);
                if(cargarArchivo(lista,archivo))
                {
                    printf("%d Datos cargados con exito.\n",ll_len(lista));
                    flag = 1;
                }
            }
            else
            {
                printf("Un archivo ya se encuentra cargado.\n");
            }

            break;
        case 2:
            if(flag)
            {
                listarBicicletas(lista);
            }
            else
            {
                printf("Primero hay que cargar los cachorros.\n");
            }
            break;
        case 3:
            if(flag)
            {

              if(setTiempo(lista)){
                    printf("Se asigno los tiempos.\n");
               }else{
                    printf("No se pudo asignar los tiempos.\n");
               }

            }
            else
            {
                printf("Primero hay que cargar el Archivo.\n");
            }
            break;
        case 4:
            if(flag)
            {
                if(archivoTipo(lista)){
                    printf("El Archivo fue creado Exitosamente.\n");
                }
            }
            else
            {
                printf("Primero hay que cargar el Archivo.\n");
            }
            break;
        case 5:
            if(flag)
            {
                ll_sort(lista,ordenadoXTipoYTiempo,0);
                listarBicicletas(lista);
                /**
                if(ordenadoXTipoYTiempo(lista)){
                    printf("Primero hay que cargar el Archivo.\n");
                }
                */
            }
            break;
        case 6:
            printf("Confirma salida? s/n:");
            fflush(stdin);
            rta = getchar();
            break;
        default:

            printf("Opcion incorrecta\n\n");
        }

        system("pause");
        system("cls");

    }
    while(rta != 's');



    return 0;
}
