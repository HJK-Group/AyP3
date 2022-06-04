#ifndef MAIN_MATERIA_H
#define MAIN_MATERIA_H

#include <stdlib.h>
#include <memory.h>

#define TAMANIO_ID_MATERIA 10
#define TAMANIO_NOMBRE_MATERIA 25
#define NOTA_MAXIMA_MATERIA 10
#define NOTA_MINIMA_MATERIA 0

typedef struct materia{
    char id[TAMANIO_ID_MATERIA];
    char nombre[TAMANIO_NOMBRE_MATERIA];
    int nota;
//    int cupo;
//    lista_correlativas
//    short habilitada
} materia;

materia* crear_materia(char id[10], char nombre[25]); // TODO Hernan

#endif