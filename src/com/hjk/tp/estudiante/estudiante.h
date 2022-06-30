#ifndef core_ESTUDIANTE_H
#define core_ESTUDIANTE_H

#include "../materia/cursada.h"
#include "../materia/materia.h"

typedef struct estudiante {
    unsigned long legajo;
    char *nombre;
    char *apellido;
    unsigned char edad;
    cursada *lista_materias;
} estudiante;

estudiante *new_estudiante(unsigned long legajo, const char *nombre, const char *apellido, unsigned char edad);

void anotarse_materia(estudiante *pEstudiante, materia *pMateria);

int rendir_materia(estudiante *pEstudiante, materia *pMateria, unsigned char calificacion);

void estudiante_print(estudiante *alumno);

void estudiante_destroy(estudiante *pEstudiante);

double calcular_promedio_estudiante(estudiante *pEstudiante);

int aprobo_materia(estudiante *pEstudiante, materia *pMateria);

#endif //core_ESTUDIANTE_H
