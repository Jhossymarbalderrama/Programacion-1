#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

/** Estructura de Datos*/
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

int menu();

/** Controles */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);
int menuModificacion();

/** Empleados */
Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);

void employee_delete();
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int mostrarEmpleado(Employee* e);
int sortByID(void*, void*);
int sortByName(void*, void*);
int sortByHoras(void*, void*);
int sortBySueldo(void*, void*);

/** Linked Lis*/

int borraElementosDelLinkedLins(LinkedList* pArrayListEmployee);
int mostrarEmpleadoEspecifico(LinkedList* lista);
int eliminaLinkedList(LinkedList* lista);
int insertaUnElemento(LinkedList* lista);
int mostrarEmpleadoExpesificoYLoElimino(LinkedList* lista);
int controller_isEmpty(LinkedList* lista);
LinkedList* controller_CloneList(LinkedList* lista);
LinkedList* controller_SubList(LinkedList* lista);
int controller_Contains(LinkedList* lista);
int controller_ContainsAll(LinkedList* lista, LinkedList* lista2);
int controller_ll_set(LinkedList* lista);

int main()
{
    char rta = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleados2 = NULL;
    listaEmpleados2 = ll_newLinkedList();
    int flag = 0;
    int flag2 = 0;

    if( listaEmpleados == NULL)
    {
        printf("--- No se pudo asignar Memoria. ---\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    do
    {
        switch(menu())
        {

        case 1:
            if(flag == 0)
            {

                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("Empleados cargados con exito\n");
                }
                flag = 1;
            }
            else
            {
                printf("Los empleados ya han sido cargados.\n");
            }
            break;
        case 2:
            if(flag == 0)
            {
                if(controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("Empleados cargados con exito\n");
                }
                flag = 1;
            }
            else
            {
                printf("Los empleados ya han sido cargados.\n");
            }
            break;
        case 3:
            if(flag)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("--- No hay empleados cargados. ---\n");
            }
            break;
        case 4:
            if(flag)
            {
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("Modificacion exitosa\n");
                }
                else if(controller_editEmployee(listaEmpleados) == -1)
                {
                    printf("--- Se cancelo la modificacion. ---\n");
                }
                else
                {
                    printf("--- Error. No se pudo completar la modificacion ---\n");
                }
            }
            else
            {
                printf("--- No hay empleados cargados. ---\n");
            }
            break;
        case 5:
            if(flag)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 6:
            if(flag)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 7:
            if(flag)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 8:
            if(flag)
            {
                if(controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("Empleados Guardados en modo texto con exito\n");
                }
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 9:
            if(flag)
            {
                if(controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("Empleados Guardados en modo binario con exito\n");
                }
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 10:
            if(borraElementosDelLinkedLins(listaEmpleados))
            {
                printf("Elementos Borrados.Enter para continuar\n");
            }
            break;
        case 11:
            if(mostrarEmpleadoEspecifico(listaEmpleados))
            {
                printf("Elemento Mostrado con exito\n");
            }
            break;
        case 12:
            if(eliminaLinkedList(listaEmpleados))
            {
                printf("La lista se a Eliminado con exito.\n");
            }
            break;
        case 13:
            if(controller_ll_set(listaEmpleados)){
                printf("Se agrego o modifico un elemento.\n");
            }else{
                printf("Error. A ocurrido un error\n");
            }
            break;
        case 14:

            if(mostrarEmpleadoExpesificoYLoElimino(listaEmpleados))
            {
                printf("Eliminacion del Empleado con Exito.\n");
            }
            break;
        case 15:
            if(controller_isEmpty(listaEmpleados))
            {
                printf("La Lista se encuentra vacia.\n");
            }
            else
            {
                printf("La Lista contiene Datos.\n");
            }
            break;
        case 16:
            if(flag)
            {
                int listar = 0;
                listaEmpleados2 = controller_CloneList(listaEmpleados);
                flag2 = 1;
                printf("Lista clonada con exito.\n\n");
                printf("Desea Listar las 2 Listas ? (1 Si / 0 No): ");
                scanf("%d",&listar);
                if(listar)
                {
                    printf("\n        ----------  LISTA CLON  ----------\n");
                    controller_ListEmployee(listaEmpleados2);
                    printf("\n        ----------  LISTA ORIGINAL  ----------\n");
                    controller_ListEmployee(listaEmpleados);
                }

            }
            break;
        case 17:
            if(flag)
            {
                int listar = 0;
                listaEmpleados2 = controller_SubList(listaEmpleados);
                flag2 = 1;
                printf("Lista clonada con exito.\n");
                printf("Desea Listar las 2 Listas ? (1 Si / 0 No): ");
                scanf("%d",&listar);
                if(listar)
                {
                    printf("\n        ----------  LISTA CLON  ----------\n");
                    controller_ListEmployee(listaEmpleados2);
                    printf("\n        ----------  LISTA ORIGINAL  ----------\n");
                    controller_ListEmployee(listaEmpleados);
                }
            }
            break;
        case 18:
            if(flag2)
            {
                if(controller_Contains(listaEmpleados2) == 0)
                {
                    printf("El elemento no se encuentra en la lista.\n");
                }
                else
                {
                    printf("El elemento se encuentra en la lista.\n");
                }
            }
            else
            {
                printf("Primero debe clonar la lista 1.\n");
            }
            break;
        case 19:
            if(flag2)
            {
                if(controller_ContainsAll(listaEmpleados,listaEmpleados2))
                {
                    printf("La lista 1 contiene todos los elementos de la lista 2\n");
                }
                else
                {
                    printf("La lista 1 NO contiene todos los elementos de la lista 2\n");
                }
            }
            else
            {
                printf("Primero debe clonar la lista 1.\n");
            }
            break;
        case 20:
            insertaUnElemento(listaEmpleados);
            break;
        case 21:
            printf("Confirma salida? s/n ");
            fflush(stdin);
            rta = getchar();
            break;
        default:
            printf("opcion invalida.\n");
            break;

        }

        system("pause");
        system("cls");

    }
    while(rta != 's');
    return 0;
}

int menu()
{
    int opcion;

    printf("------------   MENU DE INICIO   ------------\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");

    /** Opciones que utilizan funciones LinkedList*/
    printf("    ----- Opcione con funciones faltantes de Linked List-----\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n\n");
    printf("10. Borrar todos los Elementos de la lista.\n");
    printf("11. Busco un Elemento de la Lista.\n");
    printf("12. Eliminar Lista.\n");
    printf("13. Insertar un Elemento en un index especificado.\n");
    printf("14. Mostrar y Eliminar empleado en una Posicion especificado.\n");
    printf("15. La lista esta cargada?.\n");
    printf("16. Clonar la lista de Empleados.\n");
    printf("17. Crear una nueva lista con el rango de empleados elegido.\n");
    printf("18. Una vez copiada la lista 2, saber si se copio un empleado en especifico.\n");
    printf("19. Verificar  si todos los elementos de la lista 2 se encuentran en la lista 1.\n");
    printf("20. Agrego un Nodo en la posicion indexNode.\n");
    printf("21. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f;
    char buffer[4][100];
    int cant;
    Employee* aux = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {

        f = fopen(path, "r");

        if( f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            return todoOk;
        }
        fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3]);

        while(!feof(f))
        {
            cant = fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3]);

            if( cant == 4)
            {
                aux = employee_newParametros(buffer[0], buffer[1], buffer[2],buffer[3]);
                if( aux != NULL)
                {
                    ll_add(pArrayListEmployee,aux);

                }
            }
            else
            {
                break;
            }
        }

        todoOk = 1;
    }

    int tam;
    tam = ll_len(pArrayListEmployee);
    printf("%d ",tam);
    return todoOk;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f;
    int cant;
    Employee* aux = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {

        f = fopen(path, "rb");

        if( f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            return todoOk;
        }


        while(!feof(f))
        {
            aux = employee_new();
            if(aux != NULL)
            {
                cant =  fread( aux, sizeof(Employee),    1,  f );

                if(cant == 1)
                {
                    ll_add(pArrayListEmployee,aux);
                }

            }
            else
            {
                break;
            }
        }
        fclose(f);
        todoOk = 1;
    }

    int tam;
    tam = ll_len(pArrayListEmployee);
    printf("%d ",tam);
    return todoOk;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char buffer[4][20];
    Employee* filtro = NULL;
    int flagFor = 0;

    if(pArrayListEmployee != NULL)
    {

        printf("--------------  Alta de Empleados  --------------\n\n");
        printf("Ingrese ID:");
        fflush(stdin);
        gets(buffer[0]);

        for(int i = 0 ; i < ll_len(pArrayListEmployee) ; i++)
        {
            filtro = (Employee*) ll_get(pArrayListEmployee,i);
            if(filtro->id == atoi(buffer[0]))
            {
                printf("La ID ingresada ya se encuentra en uso\n");
                flagFor = 1;
                break;
            }
        }
        if(flagFor == 1 )
        {
            while(filtro->id == atoi(buffer[0]))
            {
                printf("Reingrese un ID valido:");
                fflush(stdin);
                gets(buffer[0]);
            }
        }

        printf("Ingrese nombre:");
        fflush(stdin);
        gets(buffer[1]);

        printf("Ingrese horas trabajadas:");
        fflush(stdin);
        gets(buffer[2]);
        while(atoi(buffer[2])< 0)
        {
            printf("ERROR. las horas no pueden ser menores a 0.\nReingrese:");
            fflush(stdin);
            gets(buffer[2]);
        }
        printf("Ingrese Sueldo:");
        fflush(stdin);
        gets(buffer[3]);
        while(atoi(buffer[3])< 0)
        {
            printf("ERROR. el sueldo no puede ser menor a 0.\nReingrese:");
            fflush(stdin);
            gets(buffer[3]);
        }

        ll_add(pArrayListEmployee,employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3])); /** Todo ok. Agreago al Nuevo Empleado*/

        todoOk = 1;

    }

    return todoOk;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char buffer[1][20];

    Employee* filtro = NULL;
    Employee* aux = NULL;

    char flagFor = 'n';
    int nuevoID;
    char nuevoNombre[30];
    int nuevasHoras;
    int nuevoSueldo;

    if(pArrayListEmployee != NULL)
    {

        printf("--------------   Modificacion de Empleado   --------------\n\n");
        printf("Ingrese ID:");
        fflush(stdin);
        gets(buffer[0]);
        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            filtro = (Employee*) ll_get(pArrayListEmployee,i);
            if(filtro->id == atoi(buffer[0]))
            {
                printf("ID   NOMBRE   HorasTrabajadas   SUELDO\n\n");
                mostrarEmpleado(filtro);
                printf("--Confirma? \n (S / N)--\nElija opcion: ");
                flagFor = getchar();
                break;

            }
        }
        if(flagFor == 's')
        {
            switch(menuModificacion())
            {

            case 1:
                printf("Ingrese nuevo ID: ");
                scanf("%d",&nuevoID);
                for(int i = 0; i< ll_len(pArrayListEmployee); i++)
                {
                    aux = (Employee*) ll_get(pArrayListEmployee,i);
                    if(aux->id == nuevoID)
                    {
                        while(aux->id == nuevoID)
                        {
                            printf("ERROR. La ID  ingresada ya se encuentra cargado en el sistema.\n Reingrese: ");
                            scanf("%d",&nuevoID);
                        }
                    }

                }
                filtro->id = nuevoID;
                break;
            case 2:
                printf("Ingrese nuevo Nombre: ");
                fflush(stdin);
                gets(nuevoNombre);
                strcpy(filtro->nombre,nuevoNombre);
                break;
            case 3:
                printf("Ingrese nueva cantidad de horas: ");
                scanf("%d",&nuevasHoras);
                while(nuevasHoras<0)
                {
                    printf("ERROR. Las horas no pueden ser menores a cero.\n Reingrese:");
                    scanf("%d",&nuevasHoras);
                }
                filtro->horasTrabajadas = nuevasHoras;
                break;
            case 4:
                printf("Ingrese nuevo Sueldo: ");
                scanf("%d",&nuevoSueldo);
                while(nuevoSueldo<0)
                {
                    printf("ERROR. El sueldo no puede ser menor a cero.\n Reingrese:");
                    scanf("%d",&nuevoSueldo);
                }
                filtro->sueldo = nuevoSueldo;
                break;
            case 5:
                todoOk = -1;
                return todoOk;
                break;
            default:
                printf("Opcion invalida.");
                break;
            }

        }
        else
        {
            todoOk = -1;
            return todoOk;
        }

        todoOk = 1;

    }


    return todoOk;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char buffer[1][20];
    Employee* filtro = NULL;
    int flagFor = 0;
    int indice;

    if(pArrayListEmployee != NULL)
    {

        printf("----------  Baja de Empleado  ----------\n\n");
        printf("Ingrese ID:");
        fflush(stdin);
        gets(buffer[0]);
        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            filtro = (Employee*) ll_get(pArrayListEmployee,i);
            if(filtro->id == atoi(buffer[0]))
            {
                printf("Confirma? (1 Si / 0 Cancelar).\nElija opcion: ");
                scanf("%d",&flagFor);
                indice = i;
                break;

            }
        }
        if(flagFor == 1)
        {
            ll_remove(pArrayListEmployee,indice);
            printf("Empleado dado de baja exitosamente\n\n");
        }
        else
        {
            printf("--- Se cancelo la operacion ---\n\n");
        }
        todoOk = 1;

    }

    return todoOk;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* aux;
    int flag = 0;
    if(pArrayListEmployee != NULL)
    {

        printf("   ID                NOMBRE    Horas Trab.     SUELDO\n\n");
        for( int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            aux = (Employee*) ll_get(pArrayListEmployee,i);
            mostrarEmpleado(aux);
            flag = 1;
        }
        if(flag == 0)
        {
            printf("No hay empleados cargados para mostrar\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int opcion;
    char rta = 'n';
    int orden;

    if(pArrayListEmployee != NULL)
    {
        printf("----------   MENU ORDENAMIENTO DE  EMPLEADOS   ---------\n\n");
        printf("1- Ordenar por ID.\n");
        printf("2- Ordenar por Nombre.\n");
        printf("3- Ordenar por Horas Trabajadas.\n");
        printf("4- Ordenar por Sueldo.\n");
        printf("5- <-- Volver al menu.\n");
        printf("Elija opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {

        case 1:
            printf("Ordena de forma descendente o ascendente?\n1 ascendente 0 descendente: ");
            scanf("%d",&orden);
            ll_sort(pArrayListEmployee,sortByID,orden);
            break;
        case 2:
            printf("Ordena de forma descendente o ascendente?\n1 ascendente 0 descendente: ");
            scanf("%d",&orden);
            ll_sort(pArrayListEmployee,sortByName,orden);
            break;
        case 3:
            printf("Ordena de forma descendente o ascendente?\n1 ascendente 0 descendente: ");
            scanf("%d",&orden);
            ll_sort(pArrayListEmployee,sortByHoras,orden);
            break;
        case 4:
            printf("Ordena de forma descendente o ascendente?\n1 ascendente 0 descendente: ");
            scanf("%d",&orden);
            ll_sort(pArrayListEmployee,sortBySueldo,orden);
            break;
        case 5:
            printf("Confirma? s/n ");
            fflush(stdin);
            rta = getchar();
            if(rta == 's')
            {
                break;
            }
            break;

        default:
            printf("Opcion incorrecta.\n");
            system("pause");
            break;
        }

        todoOk = 1;
    }
    return todoOk;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    int todoOk = 0;
    int cant;
    FILE* f;
    Employee* aux = NULL;

    if(pArrayListEmployee!= NULL && path != NULL )
    {

        f = fopen(path,"w");
        if(f == NULL)
        {
            return todoOk;
        }
        fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            aux = ll_get(pArrayListEmployee,i);
            cant = fprintf(f,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
            if(cant < 1)
            {
                return todoOk;
            }
        }
        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    FILE* f;

    if(pArrayListEmployee!= NULL && path != NULL )
    {

        f = fopen(path,"wb");
        if(f == NULL)
        {
            return todoOk;
        }
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            cant = fwrite( ll_get(pArrayListEmployee,i), sizeof(Employee),   1, f);
            if(cant < 1)
            {
                return todoOk;
            }
        }
        fclose(f);
        todoOk = 1;
    }

    return todoOk;

}

int menuModificacion()
{

    int opcion;

    printf("---------- Menu Modificacion de Empleados ----------\n\n");
    printf("1- Modificar ID.\n");
    printf("2- Modificar Nombre.\n");
    printf("3- Modificar Horas Trabajadas.\n");
    printf("4- Modificar Sueldo.\n");
    printf("5- <--- Volver al menu.\n");
    printf("Elija opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int mostrarEmpleado( Employee* e)
{
    int todoOk = 0;

    if( e != NULL)
    {
        printf("%5d %22s    %5d hs      %6d\n", e->id, e->nombre, e->horasTrabajadas,e->sueldo);
        todoOk = 1;
    }

    return todoOk;
}

Employee* employee_new()
{
    Employee* nuevo = (Employee*) malloc( sizeof(Employee));
    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->horasTrabajadas = 0;
        nuevo->sueldo = 0;
    }
    return nuevo;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevo = employee_new();
    int id;
    int horasTrabajadas;
    int sueldo;

    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);

    if( nuevo != NULL)
    {
        if(employee_setId(nuevo, id) &&
                employee_setNombre(nuevo, nombreStr)&&
                employee_setHorasTrabajadas(nuevo,horasTrabajadas)&&
                employee_setSueldo(nuevo, sueldo))
        {
            // printf("Empleado creado correctamente\n");
        }
        else
        {
            nuevo = NULL;
        }
    }

    return nuevo;
}


int employee_setId(Employee* this,int id)
{

    int todoOk = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if( this != NULL && nombre != NULL && strlen(nombre) < 128)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk = 0;
    if( this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;
    if( this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int sortByID(void* empleado1, void* empleado2)
{

    int retorno = 0;

    if(empleado1 != NULL && empleado2 != NULL)
    {

        if(((Employee*)empleado1)->id > ((Employee*)empleado2)->id)
        {
            retorno =  1;
        }
        if(((Employee*)empleado1)->id < ((Employee*)empleado2)->id)
        {
            retorno =  -1;
        }

    }
    else
    {
        return -2;
    }
    return retorno;
}

int sortByName(void* empleado1, void* empleado2)
{

    int retorno = -2;

    Employee* emp1;
    Employee* emp2;

    emp1 = (Employee*)empleado1;
    emp2 = (Employee*)empleado2;

    if(empleado1 != NULL && empleado2 != NULL)
    {

        retorno = strcmp(emp1->nombre, emp2->nombre);

    }
    return retorno;
}


int sortByHoras(void* empleado1, void* empleado2)
{

    int retorno = 0;

    if(empleado1 != NULL && empleado2 != NULL)
    {

        if(((Employee*)empleado1)->horasTrabajadas > ((Employee*)empleado2)->horasTrabajadas)
        {
            retorno =  1;
        }
        if(((Employee*)empleado1)->horasTrabajadas < ((Employee*)empleado2)->horasTrabajadas)
        {
            retorno =  -1;
        }

    }
    else
    {
        return -2;
    }
    return retorno;
}


int sortBySueldo(void* empleado1, void* empleado2)
{
    int retorno = 0;

    if(empleado1 != NULL && empleado2 != NULL)
    {

        if(((Employee*)empleado1)->sueldo > ((Employee*)empleado2)->sueldo)
        {
            retorno =  1;
        }
        if(((Employee*)empleado1)->sueldo < ((Employee*)empleado2)->sueldo)
        {
            retorno =  -1;
        }

    }
    else
    {
        return -2;
    }
    return retorno;
}

int borraElementosDelLinkedLins(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    if(pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarEmpleadoEspecifico(LinkedList* lista)
{

    int todoOk = 0;
    int id;
    int posicion = 0;
    Node* aux = NULL;

    if(lista != NULL)
    {
        printf("Ingrese ID del empleados que desea mostrar: ");
        scanf("%d",&id);
        // id = id-1;

        aux = test_getNode(lista,id-1);

        if( mostrarEmpleado(aux->pElement))
        {
            posicion = ll_indexOf(lista,aux->pElement);
            printf("El empleado se encuentra en la posicion %d",posicion);
            todoOk = 1;
        }
    }
    return todoOk;
}

int eliminaLinkedList(LinkedList* lista)
{
    int todoOk = 0;

    if(lista != NULL)
    {
        todoOk = ll_deleteLinkedList(lista);
        todoOk = 1;
    }

    return todoOk;
}

int insertaUnElemento(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    char buffer[4][20];
    Employee* filtro = NULL;
    int flagFor = 0;
    int posicion = 0;

    if(pArrayListEmployee != NULL)
    {

        printf("--------------  Alta de Empleados  --------------\n\n");
        printf("Ingrese ID:");
        fflush(stdin);
        gets(buffer[0]);

        for(int i = 0 ; i < ll_len(pArrayListEmployee) ; i++)
        {
            filtro = (Employee*) ll_get(pArrayListEmployee,i);
            if(filtro->id == atoi(buffer[0]))
            {
                printf("La ID ingresada ya se encuentra en uso\n");
                flagFor = 1;
                break;
            }
        }
        if(flagFor == 1 )
        {
            while(filtro->id == atoi(buffer[0]))
            {
                printf("Reingrese un ID valido:");
                fflush(stdin);
                gets(buffer[0]);
            }
        }

        printf("Ingrese nombre:");
        fflush(stdin);
        gets(buffer[1]);

        printf("Ingrese horas trabajadas:");
        fflush(stdin);
        gets(buffer[2]);
        while(atoi(buffer[2])< 0)
        {
            printf("ERROR. las horas no pueden ser menores a 0.\nReingrese:");
            fflush(stdin);
            gets(buffer[2]);
        }
        printf("Ingrese Sueldo:");
        fflush(stdin);
        gets(buffer[3]);
        while(atoi(buffer[3])< 0)
        {
            printf("ERROR. el sueldo no puede ser menor a 0.\nReingrese:");
            fflush(stdin);
            gets(buffer[3]);
        }


        printf("Ingrese la posicion donde se ubicara los Datos: ");
        scanf("%d",&posicion);

        ll_push(pArrayListEmployee,posicion-1,employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]));


        todoOk = 1;

    }

    return todoOk;
}

int mostrarEmpleadoExpesificoYLoElimino(LinkedList* lista)
{
    int todoOk = 0;
    Node* elemento;
    int posicion = 0;

    if(lista != NULL)
    {
        do
        {
            printf("Ingrese posicion del Empleado: ");
            scanf("%d",&posicion);
        }
        while(posicion > ll_len(lista) || posicion < 0);

        elemento = test_getNode(lista,posicion -1);
        mostrarEmpleado(elemento->pElement);
        ll_pop(lista,posicion-1);
    }
    return todoOk;
}

int controller_isEmpty(LinkedList* lista)
{

    int retorno;

    if(lista != NULL)
    {
        retorno = ll_isEmpty(lista);
    }

    return retorno;
}

LinkedList* controller_CloneList(LinkedList* lista)
{


    LinkedList* lista2 = NULL;

    if(lista != NULL)
    {

        lista2 = ll_clone(lista);
    }

    return lista2;
}

LinkedList* controller_SubList(LinkedList* lista)
{

    int desde;
    int hasta;
    LinkedList* lista2 = NULL;

    if(lista != NULL)
    {

        printf("Ingrese desde que elemento quire copiar a la nueva lista.\nDesde: ");
        scanf("%d",&desde);
        printf("Hasta: ");
        scanf("%d",&hasta);
        lista2 = ll_subList(lista,desde,hasta);
    }

    return lista2;
}

int controller_Contains(LinkedList* lista)
{

    int todoOk = 0;
    int indice;
    Node* aux = NULL;

    if(lista != NULL)
    {

        printf("Ingrese indice:");
        scanf("%d",&indice);
        while(indice < 0)
        {
            printf("Error. El indice no puede ser menor a cero. Reingrese:");
            scanf("%d",&indice);
        }

        aux = test_getNode(lista,indice);

        if(aux != NULL)
        {

            if(ll_contains(lista,aux->pElement) == 1)
            {
                todoOk = 1;
            }
            else
            {
                todoOk = 0;
            }
        }
    }

    return todoOk;
}

int controller_ContainsAll(LinkedList* lista, LinkedList* lista2)
{
    int todoOk = 0;

    if(lista != NULL && lista2 != NULL)
    {
        if(ll_containsAll(lista,lista2))
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int controller_ll_set(LinkedList* pArrayListEmployee){
    int todoOk = 0;
    char buffer[4][20];
    Employee* filtro = NULL;
    int flagFor = 0;
    int posicion = 0;

    if(pArrayListEmployee != NULL)
    {

        printf("--------------  Alta de Empleados  --------------\n\n");
        printf("Ingrese ID:");
        fflush(stdin);
        gets(buffer[0]);

        for(int i = 0 ; i < ll_len(pArrayListEmployee) ; i++)
        {
            filtro = (Employee*) ll_get(pArrayListEmployee,i);
            if(filtro->id == atoi(buffer[0]))
            {
                printf("La ID ingresada ya se encuentra en uso\n");
                flagFor = 1;
                break;
            }
        }
        if(flagFor == 1 )
        {
            while(filtro->id == atoi(buffer[0]))
            {
                printf("Reingrese un ID valido:");
                fflush(stdin);
                gets(buffer[0]);
            }
        }

        printf("Ingrese nombre:");
        fflush(stdin);
        gets(buffer[1]);

        printf("Ingrese horas trabajadas:");
        fflush(stdin);
        gets(buffer[2]);
        while(atoi(buffer[2])< 0)
        {
            printf("ERROR. las horas no pueden ser menores a 0.\nReingrese:");
            fflush(stdin);
            gets(buffer[2]);
        }
        printf("Ingrese Sueldo:");
        fflush(stdin);
        gets(buffer[3]);
        while(atoi(buffer[3])< 0)
        {
            printf("ERROR. el sueldo no puede ser menor a 0.\nReingrese:");
            fflush(stdin);
            gets(buffer[3]);
        }


        printf("Ingrese la posicion donde se ubicara los Datos: ");
        scanf("%d",&posicion);

        ll_set(pArrayListEmployee,posicion-1,employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]));

        todoOk = 1;

    }
    return todoOk;
}
