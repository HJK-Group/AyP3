#ifndef MAIN_MATERIA_H
#define MAIN_MATERIA_H

#include <stdlib.h>
#include <memory.h>

#define TAMANIO_ID_MATERIA 10
#define TAMANIO_NOMBRE_MATERIA 25

typedef struct materia{
    char id[TAMANIO_ID_MATERIA];
    char nombre[TAMANIO_NOMBRE_MATERIA];
    void* lista_correlativas; //TODO determinar dato o puntero
} materia;

materia* crear_materia(char id[10], char nombre[25]); // TODO Hernan

#endif