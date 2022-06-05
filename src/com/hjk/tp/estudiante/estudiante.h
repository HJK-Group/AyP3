#ifndef core_ESTUDIANTE_H
#define core_ESTUDIANTE_H

#include "../materia/cursada.h"
#include "../materia/materia.h"

typedef struct estudiante {
    unsigned long legajo; // El legajo debe ser unico. Se puede hacer autoincemental?
    char *nombre;
    char *apellido;
    unsigned char edad;
    cursada *lista_materias;
} estudiante;

estudiante *new_estudiante(unsigned long legajo, char *nombre, char* apellido, unsigned char edad); // TODO Juan

void anotarse_materia(estudiante *estudiante, materia *materia);

void rendir_materia(estudiante *estudiante, materia *materia, char calificacion);

#endif //core_ESTUDIANTE_H
