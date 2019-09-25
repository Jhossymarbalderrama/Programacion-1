#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 10

/**< Estructura - Datos Empleado*/
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmpleados;

void inicializarEmpleados(eEmpleados empleados[], int tam);
int buscarEmpleado(int id, eEmpleados empleado[], int tam);
void mostrarEmpleados(eEmpleados vec[], int tam);
int buscarLibre(eEmpleados empleados[], int tam);
int altaEmpleado(eEmpleados empleado[],int tam, int id);
int bajaEmpleado(eEmpleados empleado[], int tam);
int modificarEmpleado(eEmpleados empleado[], int tam);

int hardcodeoEmpleados(eEmpleados empleados[], int tam, int cantidad);

int menu();/**< Menu de Opciones */
int menuModificar();

int main()
{
    eEmpleados lista[TAM];
    int id = 1;
    char salir = 'n';

    inicializarEmpleados(lista, TAM);

    /**< HardCodeo de Datos */
    id = id + hardcodeoEmpleados(lista, TAM, 10);
    do
    {
        switch(menu())
        {
        case 1:
            if(altaEmpleado(lista, TAM, id))
            {
                id++;
            }
            break;
        case 2:
            bajaEmpleado(lista,TAM);
            break;
        case 3:
            modificarEmpleado(lista,TAM);
            break;
        case 4:
            mostrarEmpleados(lista,TAM);
            break;
        case 5:
            printf("\nCorfirma Salida?");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

/**< Contador de Empleados */
void inicializarEmpleados(eEmpleados empleados[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        empleados[i].isEmpty = 1;
    }
}


/**< Busco Empleado */
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


/**< Funcion que solo Muestra un Empleado */
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


/**< Funcion que Muestra todos los Empleados */
void mostrarEmpleados(eEmpleados vec[], int tam)
{
    int flag = 0;
    system("cls");
    printf("------- Lista de Empleados -------\n\n");

    printf(" ID          NOMBRE       APELLIDO       SALARIO       SECTOR \n\n");
    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("\n---No hay alumnos que mostrar---");
    }
    //system("pause");
    printf("\n\n");
}


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


/**< Alta de Empleado */
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


/**< Baja de Empleado */
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
            printf("\n\nSe ha eliminado el alumno\n");
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


/**< Menu Opciones */
int menu()
{
    int opcion;
    system("cls");
    printf("----- Menu de Opciones -----\n\n");
    printf("1- Alta de Empleado.\n");
    printf("2- Baja de Empleado.\n");
    printf("3- Modificar de Empleado.\n");
    printf("4- Lista de Empleados.\n");
    printf("5- Salir.\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
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
