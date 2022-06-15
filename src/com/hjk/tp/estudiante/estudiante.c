#include <string.h>
#include "estudiante.h"
#include "com/hjk/tp/materia/cursada.h"
#include "com/hjk/tp/materia/curso.h"
#include "com/hjk/tp/utils/utils.h"

int add_edad(estudiante *dest, short edad);

estudiante *new_estudiante(unsigned long legajo, char *nombre, char *apellido, unsigned char edad) {
    estudiante *entidad = malloc(sizeof(estudiante));
    entidad->legajo = legajo;
    entidad->nombre = new_string(nombre);
    entidad->apellido = new_string(apellido);
    add_edad(entidad, edad);
    entidad->lista_materias = new_empty_cursada();
    return entidad;
}

int add_edad(estudiante *dest, short edad) {
    if (edad < EDAD_MINIMA || edad > EDAD_MAXIMA){
        return -1;
    }

    dest->edad = edad;
    return 0;
}

void anotarse_materia(estudiante *pEstudiante, materia *pMateria ) {
    if (pEstudiante == NULL || pEstudiante->lista_materias == NULL || pMateria == NULL) {
        return;
    }

    if (pMateria->pCorrelativas->length == 0 && !cursada_contains(pEstudiante->lista_materias, pMateria)) {
        cursada_add(pEstudiante->lista_materias, pMateria);
        return;
    }

    return;
}

void rendir_materia(estudiante *pEstudiante, materia *pMateria, char calificacion) {
    curso *actual = (curso *) list_get_data(pEstudiante->lista_materias, pMateria, sizeof(materia));
    if (actual == NULL) {
        return;
    }

    actual->calificacion = calificacion;
}

void estudiante_destroy(estudiante *pEstudiante) {
    if (pEstudiante == NULL) {
        return;
    }

    free(pEstudiante->nombre);
    free(pEstudiante->apellido);
    cursada_destroy(pEstudiante->lista_materias);
    free(pEstudiante);
}
