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
void inicializarEmpleados(eEmpleados empleados[], int tam){
    /**< Falta el Return */
    for(int i=0; i < tam; i++)
    {
        empleados[i].isEmpty = 1;
    }
}

/**< Funcion HardCodeo */
int hardcodeoEmpleados(eEmpleados empleados[], int tam, int cantidad)
{

    int cont = 0;

    eEmpleados listaAuxiliar[]=
    {
        { 1, "Juan","Balderrama",25000,2},
        { 2, "Ana", "Perez",25000,2},
        { 3, "Alicia", "Martinez",25000,1},
        { 4, "Miguel", "Mesa",25000,3},
        { 5, "Gaston","Hernandez",25000,2},
        { 6, "Amalia", "Lopez",25000,1},
        { 7, "Sofia", "Escudo",25000,1},
        { 8, "Diego", "Falopa",25000,5},
        { 9, "Fernando","Fernandez",25000,4},
        { 10, "Clara","Letra",25000,5}
    };

    if( cantidad <= tam && cantidad < 11)
    {
        for( int i=0; i < cantidad; i++)
        {
            empleados[i] = listaAuxiliar[i];
            cont++;
        }
    }
    return cont;
}

/**< Menu Opciones */
int menu()
{
    int opcion;
    system("cls");
    printf("----- Menu de Opciones -----\n\n");
    printf("1- Alta de Empleado.\n");
    printf("2- Baja de Empleado.\n");
    printf("3- Modificar de Empleado.\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Lista de Empleados.\n");
    printf("6- Salir.\n\n");
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
        mostrarEmpleado(empleado[indice]);
        printf("\nConfirma eliminacion?: ");
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
        //system("pause");
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
   // system("cls");
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


void odenarEmpleados(eEmpleados empleado[], int tam){
    eEmpleados auxEmpleado;
    for(int i ; i < tam-1 ; i++){
        for(int j = i+1 ;j < tam ; j++){
            if(empleado[i].lastName < empleado[j].lastName){
                auxEmpleado = empleado[i];
                empleado[i] = empleado[j];
                empleado[j] = auxEmpleado;
            }
        }
    }
}

/**< Luego Eliminar Modificacion para TP2 */
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

    system("cls");
    printf("----- Modificacion de Empleado -----\n\n");

    printf("Ingrese ID del Empleado: ");
    scanf("%d", &indice);

    indice = buscarEmpleado(indice,empleado,tam);
    printf("\n ID        1-NOMBRE      2-APELLIDO    3-SALARIO     4-SECTOR \n\n");
    mostrarEmpleado(empleado[indice]);
    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else
    {
        do{
            switch(menuModificar()){
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
        }while(exit == 'n');
    }
    return todoOk;
}

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
