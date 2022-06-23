#ifndef core_REGISTRO_H
#define core_REGISTRO_H

#include "estudiante.h"
#include "com/hjk/tp/list/ordered.h"

typedef struct ordered_list listado;

typedef struct registro {
    listado *listado_por_nombre;
    listado *listado_por_edad;
} registro;

typedef enum {
    Order_By_Nombre,
    Order_By_Edad
} registro_order_by;

registro *new_registro();

void registro_agregar_alumno(registro *registro, estudiante *alumno);

estudiante *registro_buscar_por_nombre(registro *registro, char *nombre);

listado *registro_buscar_por_edad(registro *registro, short desde, short hasta);

int registro_remover_estudiante(registro *registro, estudiante *alumno);

void listar_registro(registro *listado_alumnos, int number_records, registro_order_by orderBy);

void listado_destroy(listado *pListado);

void registro_destroy(registro *registro);

void print_estudiante(void *alumno);

#endif //core_REGISTRO_H
