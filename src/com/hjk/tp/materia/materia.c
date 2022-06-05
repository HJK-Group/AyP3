#include "materia.h"
#include "../estudiante/estudiante.c"

materia* new_materia(unsigned short id, char *nombre) {
    materia* entidad_materia = (materia*) malloc(sizeof(materia));

    add_str(entidad_materia->id, id, TAMANIO_ID_MATERIA);
    add_str(entidad_materia->nombre, nombre, TAMANIO_NOMBRE_MATERIA);
    //TODO agregar lista de correlativas

    return entidad_materia;
}
