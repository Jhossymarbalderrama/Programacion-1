#include "employeeLibrary.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/**< Inicializo Empleado */
/** \brief Para indicar que todas las posiciones en la matriz están vacías,
 *         esta función coloca el indicador (está vacío) en verdadero en todas las posiciones de la matriz.
 * \param  Lista de empleados * Puntero a la matriz de empleados.
 * \return Devuelve (-1) si error [longitud inválida o puntero nulo] - (0) si está bien
 */
void inicializarEmpleados(eEmpleados empleados[], int tam)
{
    /**< Falta el Return */
    for(int i=0; i < tam; i++)
    {
        empleados[i].isEmpty = 1;
    }
}

/** \brief Menu principal de Opciones.
 * \param
 * \return  return opcion
 */

/**< Menu Opciones */
int menu()
{
    int opcion;
    system("cls");
    printf("***-- Sistema de Administracion para Empleados --***\n");
    printf("\n----- Menu de Opciones -----\n");
    printf("1- Alta de Empleado.\n");
    printf("2- Baja de Empleado.\n");
    printf("3- Modificar de Empleado.\n");
    printf("4- Informes\n");
    printf("5- Salir.\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


/**< Alta de Empleado */
/** \brief Pido los Datos del Nuevo Empleado, los guardo en una temporal para validar y luego
 *          de la validacion si esta todo Ok, lo agrego a la lista de Empleados.
 * \param eEmpleados empleado[],int tam, int id / Lista de Empleados, Tamaño y la Id.
 * \return Int Return TodoOk .
 */

int  altaEmpleado(eEmpleados empleado[],int tam, int id)
{
    int todoOk = 0;
    int indice;
    char name[51];
    char lastname[51];
    float salary;
    int sector;
    //int isEmpty;

    system("cls");
    printf("----- Alta de Empleados -----\n\n");

    indice = buscarLibre(empleado, tam);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas Empleados\n");
        //system("pause");
    }
    else
    {
        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(name);

        printf("Ingrese Apellido: ");
        fflush(stdin);
        gets(lastname);

        printf("Ingrese su Salario: ");
        scanf("%f",&salary);

        printf("Ingrese Sector: ");
        scanf("%d",&sector);

        /**< Esta todo Ok Cargo la Estructura */
        empleado[indice] = newEmpleado(id, name, lastname, salary, sector);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Busco un Indice vacio.
 * \param eEmpleados empleados[], int tam
 * \return return Indice.
 */

/**< Busco un Indice Libre */
int buscarLibre(eEmpleados empleados[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( empleados[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/**< Alta de un nuevo Empleado */
/** \brief Agregar en una lista existente de empleados los valores recibidos como
 *          parámetros en la primera posición vacía.
 * \param int id, char name[], char lastname[], float salary, int sector
 * \return newEmpleado.
 */

eEmpleados newEmpleado(int id, char name[], char lastname[], float salary, int sector)
{
    eEmpleados newEmpleado;
    newEmpleado.id = id;
    strcpy(newEmpleado.name,name);
    strcpy(newEmpleado.lastName, lastname);
    newEmpleado.salary = salary;
    newEmpleado.sector = sector;
    newEmpleado.isEmpty = 0;

    return newEmpleado;
}


/**< Funcion que solo Muestra un Empleado */
/** \brief Muestro los Datos del Empleado
 * \param eEmpleados x
 * \return
 */

void mostrarEmpleado(eEmpleados x)
{
    printf(" %2d      %10s     %10s      %6.2f        %2d \n\n",
           x.id,
           x.name,
           x.lastName,
           x.salary,
           x.sector
          );
}


/**< Baja de Empleado */
/** \brief Baja de Empleado por ID.
 * \param  eEmpleados empleado[], int tam
 * \return todoOk
 */

int bajaEmpleado(eEmpleados empleado[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(ahiEmpleado(empleado,tam))
    {
        system("cls");
        printf("----- Baja de Empleados -----\n\n");

        printf("Ingrese ID del Empleado: ");
        scanf("%d", &id);

        indice = buscarEmpleado(id, empleado, tam);

        if( indice == -1 )
        {
            printf("\nNo tenemos registrado ese ID\n");
            //system("pause");
        }
        else
        {
            printf("\n ID        1-NOMBRE      2-APELLIDO    3-SALARIO     4-SECTOR \n\n");
            mostrarEmpleado(empleado[indice]);
            printf("\nConfirma eliminacion? (S / N): ");
            fflush(stdin);
            confirma = getche();
            if( confirma == 's')
            {
                empleado[indice].isEmpty = 1;
                printf("\n\nSe ha eliminado al Empleado\n");
                todoOk = 1;
            }
            else
            {
                printf("\n\nSe ha cancelado la baja\n");
            }
            system("pause");
        }
    }
    else
    {
        system("cls");
        printf("No hay ningun empleado cargado...\n");
        printf("Ingrese un Empleado\n");
        system("pause");
    }
    return todoOk;
}

/**< Busco Empleado */
/** \brief Busco Empleado Por ID.
 * \param  int id, eEmpleados empleado[], int tam
 * \return indice (Empleado)
 */
int buscarEmpleado(int id, eEmpleados empleado[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( empleado[i].isEmpty == 0 && empleado[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


/**< Funcion que Muestra todos los Empleados */
/** \brief Muestro todos los empleados que tengo Registrados y Activos.
 * \param eEmpleados empleado[], int tam
 * \return
 */

void mostrarEmpleados(eEmpleados empleado[], int tam)
{
    int flag = 0;
    system("cls");
    printf("------- Lista de Empleados -------\n\n");

    printf(" ID          NOMBRE       APELLIDO       SALARIO       SECTOR \n\n");
    for(int i=0; i < tam; i++)
    {
        if( empleado[i].isEmpty == 0)
        {
            mostrarEmpleado(empleado[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("\n---No hay Empleados que mostrar---");
    }

    //system("pause");
    printf("\n\n");
}


/** \brief  Ordena Una lista de Empleados Activos por Apellido y Sector
 * \param   eEmpleados empleado[], int tam
 * \return
 */

void odenarEmpleados(eEmpleados empleado[], int tam)
{
    eEmpleados auxEmpleado;

    system("cls");
    for(int i = 0; i < tam-1 ; i++)
    {
        for(int j = i+1 ; j < tam ; j++)
        {
            if((empleado[i].isEmpty == 0) && (strcmp(empleado[i].lastName,empleado[j].lastName)== 1))
            {
                auxEmpleado = empleado[i];
                empleado[i] = empleado[j];
                empleado[j] = auxEmpleado;
            }
        }
    }
    mostrarEmpleados(empleado,tam);
}


/** \brief Funcion Modificacion de Empleados por ID.
 * \param eEmpleados empleado[], int tam
 * \return  return todoOk
 */

/**< Funcion Modificacion de Empleado */
int modificarEmpleado(eEmpleados empleado[], int tam)
{
    int todoOk = 0;
    int indice;
    char exit = 'n';
    char name[51];
    char lastName[51];
    float salario;
    int Sector;

    if(ahiEmpleado(empleado,tam))
    {

        system("cls");
        printf("----- Modificacion de Empleado -----\n\n");

        printf("Ingrese ID del Empleado: ");
        scanf("%d", &indice);

        indice = buscarEmpleado(indice,empleado,tam);

        if( indice == -1 )
        {
            printf("\nNo tenemos registrado ese legajo\n");
            //system("pause");
        }
        else
        {
            printf("\n ID        1-NOMBRE      2-APELLIDO    3-SALARIO     4-SECTOR \n\n");
            mostrarEmpleado(empleado[indice]);

            do
            {
                switch(menuModificar())
                {
                case 1:
                    /**< Mod Nombre */
                    printf("Ingrese Nuevo Nombre: ");
                    fflush(stdin);
                    gets(name);
                    strcpy(empleado[indice].name, name);
                    printf("\nSe actualizo el Nombre.\n");
                    todoOk = 1;
                    exit = getchar();
                    break;
                case 2:
                    /**< Mod Apellido */
                    printf("Ingrese Nuevo Apellido: ");
                    fflush(stdin);
                    gets(lastName);
                    strcpy(empleado[indice].lastName,lastName);
                    printf("\nSe actualizo la Apellido.\n");
                    todoOk = 1;
                    exit = getchar();
                    break;
                case 3:
                    /**< Mod Salario */
                    printf("Ingrese Nuevo Salario: ");
                    scanf("%f",&salario);
                    empleado[indice].salary = salario;
                    printf("\nSe Actualizo el Salario del Empleado.\n");
                    todoOk = 1;
                    exit = getchar();
                    break;
                case 4:
                    /**< Mod Sector */
                    printf("Ingrese Nuevo Sector: ");
                    scanf("%d",&Sector);
                    empleado[indice].sector = Sector;
                    printf("\nSe Actualizo el Sector del Empleado.\n");
                    todoOk = 1;
                    exit = getchar();
                    break;
                case 5:
                    exit = getchar();
                    break;
                default:
                    printf("Opcion invalida\n");
                }
            }
            while(exit == 'n');
        }
    }
    else
    {
        system("cls");
        printf("No hay ningun empleado cargado...\n");
        printf("Ingrese un Empleado\n");
        system("pause");
    }
    return todoOk;
}

/** \brief Menu Opciones Modificacion de Empleados
 * \param
 * \return return Opcion
 */

/**< Menu Modificaciones de Empleado */
int menuModificar()
{
    int opcion;
    printf("----- Que desea Modificar ? -----\n\n");
    printf("1- Nombre.\n");
    printf("2- Apellido.\n");
    printf("3- Salario.\n");
    printf("4- Sector.\n");
    printf("5- Volver a Menu Principal.\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;

}


/** \brief Recorro empleados[] si tiene datos
 * \param eEmpleados empleado[], int tam
 * \return cont() //Si tiene datos retorna con 1, si esta vacio es 0.
 */

int ahiEmpleado(eEmpleados empleado[], int tam)
{
    int cont = 0;

    for(int i = 0 ; i < tam ; i++)
    {
        if(empleado[i].isEmpty == 0)
        {
            cont = 1;
        }
    }
    return cont;
}


/** \brief  Informes - Llamados a Opciones.
 * \param   eEmpleados empleados[], int tam
 * \return
 */

void informes(eEmpleados empleados[], int tam)
{

    char exit = 'n';

    if(ahiEmpleado(empleados,tam))
    {
        system("cls");
        printf("----- Informes -----\n\n");
        do
        {
            switch(menuInformes())
            {
            case 1:
                mostrarEmpleados(empleados,tam);
                break;
            case 2:
                odenarEmpleados(empleados,tam);
                break;
            case 3:
                totalPromedio(empleados,tam);
                break;
            case 4:
                empleadosSalarioPromedio(empleados,tam);
                break;
            case 5:
                exit = getchar();
                break;
            default:
                printf("Opcion invalida\n");
            }
        }
        while(exit == 'n');
    }
    else
    {
        system("cls");
        printf("No hay ningun empleado cargado...\n");
        printf("Ingrese un Empleado\n");
        system("pause");
    }

}

/** \brief  Menu de Informes
 * \param
 * \return return Opcion
 */
int menuInformes()
{
    int opcion;
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("1- Lista de Empleados.\n");
    printf("2- Lista Ordeando por Apellido y Sector.\n");
    printf("3- Total y Promedio de los Salarios.\n");
    printf("4- Cuantos empleados superan el Salario Promedio.\n");
    printf("5- <--- Volver.\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;

}


/** \brief  Empleados - Total y Promedio de los Salarios
 * \param   eEmpleados empleados[],int tam
 * \return
 */
void totalPromedio(eEmpleados empleados[],int tam)
{

    int cont = 0;
    float total = 0;
    float promedio = 0;

    for(int i = 0 ; i < tam ; i++)
    {
        if(empleados[i].isEmpty == 0)
        {
            cont++;
            total = total+empleados[i].salary;
        }
    }
    promedio = (float) total / cont;

    system("cls");
    printf("---- Total y Promedio de Salarios ----\n");
    printf("\nLa suma total de  los Salarios es : %.2f ",total);
    printf("\nEl promedio es : %.2f ",promedio);
    printf("\n");

}

void empleadosSalarioPromedio(eEmpleados empleados[],int tam)
{


    int cont = 0;
    float total = 0;
    float promedio = 0;
    int contPromedio = 0;

    for(int i = 0 ; i < tam ; i++)
    {
        if(empleados[i].isEmpty == 0)
        {
            cont++;
            total = total+empleados[i].salary;
        }
    }
    promedio = (float) total / cont;

    system("cls");
    printf("---- Empleados que superan el salario Promedio ----\n");
    printf("\nEl promedio de los Salarios es : %.2f ",promedio);
    printf("\nEmpleados :\n\n");
    for(int i = 0; i < tam ; i++)
    {
        if(empleados[i].isEmpty == 0 && empleados[i].salary > promedio)
        {
            contPromedio++;
            mostrarEmpleado(empleados[i]);
        }
    }
    printf("Los empleados que lo superan son : %d",contPromedio);
    printf("\n");
}
