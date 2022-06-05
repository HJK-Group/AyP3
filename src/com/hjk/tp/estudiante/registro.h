#ifndef core_REGISTRO_H
#define core_REGISTRO_H

#include "estudiante.h"
#include "com/hjk/tp/list/ordered.h"

typedef struct ordered_list listado;

typedef struct registro {
    listado *listado_por_nombre;
    listado *listado_por_edad;
} registro;

registro *new_registro();

void registro_agregar_alumno(registro *registro, estudiante *alumno);

estudiante *registro_buscar_por_nombre(registro *registro, char *nombre);

listado *registro_buscar_por_edad(registro *registro, short desde, short hasta);

int registro_remover_estudiante(registro *registro, estudiante *alumno);

void listar_registro(registro *registro);

void borrar_registro(registro *registro);

#endif //core_REGISTRO_H
