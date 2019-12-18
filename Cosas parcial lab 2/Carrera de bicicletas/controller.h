#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#endif // CONTROLLER_H_INCLUDED
//int filtroMenores(void* elemento);

int cargarArchivo(LinkedList* lista, char* path);
int controller_saveAsText(char* path, LinkedList* e);

//int archivoMayores(LinkedList* lista);
//int filtroMachos(void* elemento);
//int archivosNoMachos(LinkedList* lista);
//int filtroCallejeros(void* elemento);


void getTiempo(void* elemento);
int setTiempo(LinkedList* lista);


//int filtroTipo(void* elemento);
int filtroTipoBMX(void* elemento);
int filtroTipoPLAYERA(void* elemento);
int filtroTipoMTB(void* elemento);
int filtroTipoPASEO(void* elemento);
int archivoTipo(LinkedList* lista);
int menuFiltro(void);

//int ordenadoXTipoYTiempo(LinkedList* lista);
int ordenadoXTipoYTiempo(void* bicicleta1, void* bicicleta2);

