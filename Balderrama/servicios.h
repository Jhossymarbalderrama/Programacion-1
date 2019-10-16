#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    float precio;
}eServicio;//lavado pulido encerado completo

#endif // SERVICIOS_H_INCLUDED

void mostrarServicios (eServicio servicios[], int tam);
void mostrarServicio (eServicio servicios);
int cargarDescServicio(int id, eServicio servicios[], int tam, char desc[]);
int buscarIdServicio(int id, eServicio servicios[], int tam);
