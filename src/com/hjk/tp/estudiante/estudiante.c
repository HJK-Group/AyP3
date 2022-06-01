#include "estudiante.h"

int add_str(char *dest, char *src, int dest_size);
int add_edad(estudiante *dest, int edad);

estudiante *crear_estudiante(long long legajo, char nombre[], char apellido[], short edad) {
    estudiante *entidad = (estudiante *) malloc(sizeof(estudiante));
    entidad->legajo = legajo;
    add_str(entidad->nombre, nombre, TAMANIO_NOMBRE_ESTUDIANTE);
    add_str(entidad->apellido, apellido, TAMANIO_APELLIDO_ESTUDIANTE);
    add_edad(entidad, edad);
    entidad->lista_materias = new_empty_list();
    return entidad;
}

int add_str(char *dest, char *src, int dest_size) {
    int src_size = strlen(src);
    if (src_size > dest_size) {
        strncpy(dest, src, dest_size);
        dest[dest_size - 1] = '\0';
    } else {
        strcpy(dest, src);
    }
    return 0;
}

int add_edad(estudiante *dest, int edad) {
    if (edad < EDAD_MINIMA || edad > EDAD_MAXIMA) {
        return -1;
    }
    dest->edad = edad;
    return 0;
}

