#ifndef MAIN_MATERIA_H
#define MAIN_MATERIA_H

#include <stdlib.h>
#include <memory.h>

#define TAMANIO_ID_MATERIA 10
#define TAMANIO_NOMBRE_MATERIA 25

typedef struct list lista_correlativas;

typedef struct materia {
    unsigned short id;
    char *nombre;
    lista_correlativas *pCorrelativas;
//    int cupo;
//    short habilitada
} materia;

materia* crear_materia(char id[10], char nombre[25]); // TODO Hernan

#endif