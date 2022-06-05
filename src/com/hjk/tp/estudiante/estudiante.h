
#ifndef core_ESTUDIANTE_H
#define core_ESTUDIANTE_H
#include "../materia/cursada.h"
#include "../materia/materia.h"

#define TAMANIO_NOMBRE_ESTUDIANTE 25
#define TAMANIO_APELLIDO_ESTUDIANTE 25
#define EDAD_MAXIMA 120
#define EDAD_MINIMA 1

typedef struct estudiante {
    long legajo; // El legajo debe ser unico. Se puede hacer autoincemental?
    char nombre[TAMANIO_NOMBRE_ESTUDIANTE];
    char apellido[TAMANIO_APELLIDO_ESTUDIANTE];
    short edad;
    cursada *lista_materias;
} estudiante;

estudiante *crear_estudiante(long legajo, char nombre[25], char apellido[25], short edad); // TODO Juan

void anotarse_materia(estudiante *estudiante, materia *materia);

void rendir_materia(estudiante *estudiante, materia *materia, char calificacion);

#endif //core_ESTUDIANTE_H
