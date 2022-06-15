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
    // ToDo Cambiar Order_By_Nombre a lista_cursos.
    cursada *lista_materias;
} estudiante;

estudiante *new_estudiante(unsigned long legajo, char *nombre, char* apellido, unsigned char edad);

void anotarse_materia(estudiante *pEstudiante, materia *pMateria);

void rendir_materia(estudiante *pEstudiante, materia *pMateria, char calificacion); // ToDo Recrear método.

void estudiante_destroy(estudiante *pEstudiante);

#endif //core_ESTUDIANTE_H
