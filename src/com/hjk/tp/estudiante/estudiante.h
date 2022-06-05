
#ifndef MAIN_ESTUDIANTE_H
#define MAIN_ESTUDIANTE_H

#include "../list/list.h"; // se podria llegar a crear una lista de materias dentro de materias.
#include "../materia/materia.h"

#define TAMANIO_NOMBRE_ESTUDIANTE 25
#define TAMANIO_APELLIDO_ESTUDIANTE 25
#define EDAD_MAXIMA 120
#define EDAD_MINIMA 1

typedef struct estudiante {
    unsigned long int legajo; // El legajo debe ser unico. Se puede hacer autoincemental?
    char nombre[TAMANIO_NOMBRE_ESTUDIANTE];
    char apellido[TAMANIO_APELLIDO_ESTUDIANTE];
    unsigned char edad;
    cursada_list *lista_cursada; // TODO generar el wrapper de la lista con materias (Kevin)
} estudiante;

estudiante *crear_estudiante(long long legajo, char nombre[25], char apellido[25], short edad);

void anotarse_materia(estudiante *estudiante, materia *materia); // TODO Kevin

void rendir_materia(estudiante *estudiante, materia *materia, unsigned char calificacion); //TODO Juan

#endif //MAIN_ESTUDIANTE_H



