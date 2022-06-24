#ifndef core_ESTUDIANTE_H
#define core_ESTUDIANTE_H

#define EDAD_MINIMA 1
#define EDAD_MAXIMA 130
#define NOTA_APROBADA 4

#include "../materia/cursada.h"
#include "../materia/materia.h"

typedef struct estudiante {
    unsigned long legajo;
    char *nombre;
    char *apellido;
    unsigned char edad;
    // ToDo Cambiar lista_materias a lista_cursos.
    cursada *lista_materias;
} estudiante;

estudiante *new_estudiante(unsigned long legajo, char *nombre, char* apellido, unsigned char edad);

void anotarse_materia(estudiante *pEstudiante, materia *pMateria);

int rendir_materia(estudiante *pEstudiante, materia *pMateria, char calificacion);

void estudiante_print(estudiante *alumno);

void estudiante_destroy(estudiante *pEstudiante);

double calcular_promedio_estudiante(estudiante *pEstudiante);

int aprobo_materia(estudiante *pEstudiante, materia *pMateria);


#endif //core_ESTUDIANTE_H
