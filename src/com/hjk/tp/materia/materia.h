#ifndef MAIN_MATERIA_H
#define MAIN_MATERIA_H

#include <stdlib.h>
#include <memory.h>

#define TAMANIO_ID_MATERIA 10
#define TAMANIO_NOMBRE_MATERIA 25

typedef struct list lista_correlativas; // TODO Juan

typedef struct materia {
    unsigned short id;
    char *nombre;
    lista_correlativas *pCorrelativas;
//    int cupo;
//    short habilitada
} materia;

materia* new_materia(unsigned short id, char *nombre); // TODO Hernan

#endif