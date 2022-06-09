#include <string.h>
#include "estudiante.h"
#include "com/hjk/tp/materia/cursada.h"
#include "com/hjk/tp/materia/curso.h"

int add_str(char *dest, char *src, int dest_size);
int add_edad(estudiante *dest, short edad);

estudiante *new_estudiante(unsigned long legajo, char *nombre, char *apellido, unsigned char edad) {
    estudiante *entidad = (estudiante *) malloc(sizeof(estudiante));
    entidad->legajo = legajo;
    entidad->nombre = (char *) malloc(sizeof(char) * (strlen(nombre) + 1));
    strcpy(entidad->nombre, nombre);
    entidad->apellido = (char *) malloc(sizeof(char) * (strlen(apellido) + 1));
    strcpy(entidad->apellido, apellido);
    add_edad(entidad, edad);
    entidad->lista_materias = new_empty_cursada();
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

int add_edad(estudiante *dest, short edad) {
    if (edad < EDAD_MINIMA || edad > EDAD_MAXIMA){
        return -1;
    }
    dest->edad = edad;
    return 0;
}

void anotarse_materia(estudiante *estudiante, materia *materia ) {
    cursada_add(estudiante->lista_materias, materia);
}

void rendir_materia(estudiante *alumno, materia *materia, char calificacion) {
    curso *actual = (curso *) list_get_by_data(alumno->lista_materias, &buscar_curso, materia);
    if (actual == NULL) {
        return;
    }

    actual->calificacion = calificacion;
}
