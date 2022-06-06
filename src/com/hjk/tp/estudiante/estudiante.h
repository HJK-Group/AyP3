#ifndef core_ESTUDIANTE_H
#define core_ESTUDIANTE_H

#define EDAD_MINIMA 1
#define EDAD_MAXIMA 130

#include "../materia/cursada.h"
#include "../materia/materia.h"

typedef struct estudiante {
    unsigned long legajo;
    char *nombre;
    char *apellido;
    unsigned char edad;
    cursada *lista_materias;
} estudiante;

estudiante *new_estudiante(unsigned long legajo, char *nombre, char* apellido, unsigned char edad);

void anotarse_materia(estudiante *estudiante, materia *materia);

void rendir_materia(estudiante *estudiante, materia *materia, char calificacion);

#endif //core_ESTUDIANTE_H
