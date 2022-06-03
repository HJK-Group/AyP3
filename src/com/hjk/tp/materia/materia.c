#include "materia.h"
#include "../estudiante/estudiante.c"

materia* crear_materia(char id[10], char nombre[25]) {

    materia* entidad_materia = (materia*) malloc(sizeof(materia));

    add_str(entidad_materia->id, id, TAMANIO_ID_MATERIA);
    add_str(entidad_materia->nombre, nombre, TAMANIO_NOMBRE_MATERIA);

    return entidad_materia;
}
