#ifndef employeeLibrary
#define employeeLibrary
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
#endif // employeeLibrary

/**< Funciones */
/**< 2.1 */void inicializarEmpleados(eEmpleados empleados[], int tam);
int menu();/**< Menu de Opciones */
/**< 2.2 */int altaEmpleado(eEmpleados empleado[],int tam, int id);/**< Alta de Empleado */
int buscarLibre(eEmpleados empleados[], int tam);/**<  Busco un Indice Libre*/
/**< 2.2 */eEmpleados newEmpleado(int id, char name[], char lastname[], float salary, int sector);/**< Alta del Nuevo Empleado*/
/**< 2.4 */int bajaEmpleado(eEmpleados empleado[], int tam);/**< Baja de Empleado */
int buscarEmpleado(int id, eEmpleados empleado[], int tam);/**< Busco Empleado */
/**< 2.6 */void mostrarEmpleados(eEmpleados empleado[], int tam);/**< Muestro los Empleados */
/**< 2.5 */void odenarEmpleados(eEmpleados empleado[], int tam);/**< Ordeno Empleados */
int modificarEmpleado(eEmpleados empleado[], int tam);/**< Modificacion de Empleado */
int menuModificar();/**< Menu de Modificaciones */
int ahiEmpleado(eEmpleados empleado[], int tam);/**< Permiso de opciones 2, 3, 4 */
int menuInformes();/**< Menu Informes */
void informes(eEmpleados empleados[], int tam);/**< Informes */
void totalPromedio(eEmpleados empleados[],int tam);/**< Total y Promedio de Salarios */
void empleadosSalarioPromedio(eEmpleados empleados[],int tam);/**< Empleados Salario Promedio */
