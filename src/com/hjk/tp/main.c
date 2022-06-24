#include "config.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu/menu.h"
#include "com/hjk/tp/estudiante/registro.h"

int get_menu_option();

void handle_crear_materia(list *pLista_materias);

void handle_crear_estudiante(registro *pRegistro);

void handle_anotar_estudiante(registro *pRegistro, list *pLista_materias);

void handle_estudiante_rendir(registro *pRegistro, list *pLista_materias);

void handle_listar_registro(registro *pRegistro, list *pLista_materias);

void handle_consultar_materias(list *pLista_materias);

void handle_consultar_estudiantes(registro *pRegistro);

void handle_consultar_cursada(registro *pRegistro);

void handle_consultar_promedio_estudiante(registro *pRegistro);

void handle_crear_correlatividad(registro *pRegistro, list *pLista_materias);

void handle_materia_aprobada(registro *pRegistro, list *pLista_materias);

void realizar_consultas(registro *pRegistro, list *pLista_materias);

void abm_registros(registro *pRegistro, list *pLista_materias);

char *solicitar_dato(int longitud);

int solicitar_confirmacion();

estudiante *buscar_estudiante(registro *coleccion);

materia *buscar_materia(list *pLista_materias);

estudiante *solicitar_estudiante(registro *pRegistro);

materia *solicitar_materia(list *pLista_materias);

unsigned char solicitar_nota();

void estudiante_promedio_print(estudiante *pEstudiante);

int chequear_correcto_lista_estudiantes_y_materias(registro *pRegistro, list *pLista_materias);

// Autoincrementales
long siguiente_id_materia = 1;
long siguiente_legajo = 1;

int main() {

    setbuf(stdout, 0);

    registro *pRegistro = new_registro();
    list *pLista_materias = new_empty_list();

    menu_print_welcome();
    int running = 1;

    while (running) {
        switch (get_menu_option()) {
            case 1:
                realizar_consultas(pRegistro, pLista_materias);
                break;
            case 2:
                abm_registros(pRegistro, pLista_materias);
                break;
            case 0:
                running = 0;
                break;
            default:
                printf("Ninguna opcion configurada para ese valor.\n\n");
                break;
        }
        menu_print_main_options_boxed();
    }
    menu_print_end();
    return 0;
}

int get_menu_option() {
    fflush(stdin);
    char option[2];
    fgets(option, 2, stdin);

    printf("\n");

    return (int) strtol(option, NULL, 10);
}

char *solicitar_dato(int longitud) {
    if (longitud < 2) {
        longitud = 2;
    }

    fflush(stdin);
    char dato[longitud];
    fgets(dato, longitud, stdin);

    char *dato_reducido = malloc(strlen(dato));
    strcpy(dato_reducido, dato);

    return dato_reducido;
}

void realizar_consultas(registro *pRegistro, list *pLista_materias) {
    int running = 1;
    while (running) {
        menu_print_query_options();
        switch (get_menu_option()) {
            case 1:
                handle_consultar_materias(pLista_materias);
                break;
            case 2:
                handle_consultar_estudiantes(pRegistro);
                break;
            case 3:
                handle_consultar_promedio_estudiante(pRegistro);
                break;
            case 4:
                handle_consultar_cursada(pRegistro);
                break;
            case 5:
                handle_listar_registro(pRegistro, pLista_materias);
                break;
            case 6:
                handle_materia_aprobada(pRegistro, pLista_materias);
            case 0:
                running = 0;
                break;
            default:
                printf("Ninguna opcion configurada para ese valor.\n\n");
        }
    }
}

void abm_registros(registro *pRegistro, list *pLista_materias) {
    int running = 1;
    while (running) {
        menu_print_abm_options();
        switch (get_menu_option()) {
            case 1:
                handle_crear_materia(pLista_materias);
                break;
            case 2:
                handle_crear_estudiante(pRegistro);
                break;
            case 3:
                handle_anotar_estudiante(pRegistro, pLista_materias);
                break;
            case 4:
                handle_estudiante_rendir(pRegistro, pLista_materias);
                break;
            case 5:
                handle_crear_correlatividad(pRegistro, pLista_materias);
                break;
            case 0:
                running = 0;
                break;
            default:
                printf("Ninguna opcion configurada para ese valor.\n\n");
        }
    }
}

int comparar_materia(void *item_lista, void *dato) {
    if (item_lista == NULL || dato == NULL) {
        return 0;
    }

    if (item_lista == dato) {
        return 1;
    }

    return strcmp(((materia *) item_lista)->nombre, ((materia *) dato)->nombre) == 0;
}

void handle_crear_materia(list *pLista_materias) {
    printf("Indique el nombre de la materia:");
    char *nombre_materia = solicitar_dato(50);

    materia *nueva_materia = new_materia(siguiente_id_materia, nombre_materia);
    if (!list_contains(pLista_materias, &comparar_materia, nueva_materia)) {
        list_add(pLista_materias, nueva_materia);
        printf(">>> Materia agregada con exito\n\n");
        siguiente_id_materia++;
        return;
    }

    printf(">>> La materia ya existia\n\n");
}

void handle_crear_estudiante(registro *pRegistro) {
    unsigned long legajo = siguiente_id_materia;
    char *nombre;
    char *apellido;
    unsigned char edad;

    printf("Indique el nombre del estudiante:");
    nombre = solicitar_dato(50);

    printf("Indique el apellido del estudiante:");
    apellido = solicitar_dato(50);

    printf("Indique la edad del estudiante:");
    edad = strtoul(solicitar_dato(1), NULL, 10);

    registro_agregar_alumno(pRegistro, new_estudiante(legajo, nombre, apellido, edad));
    siguiente_legajo++;

    printf(">>> Estudiante creado\n\n");
}

void handle_anotar_estudiante(registro *pRegistro, list *pLista_materias) {
    int resultado_chequeo = chequear_correcto_lista_estudiantes_y_materias(pRegistro, pLista_materias);

    if (resultado_chequeo == 0) {
        return;
    }

    estudiante *pEstudiante = buscar_estudiante(pRegistro);
    materia *pMateria = buscar_materia(pLista_materias);
    if (pEstudiante != NULL && pMateria != NULL) {
        anotarse_materia(pEstudiante, pMateria);
        printf(">>> Anotacion realizada con exito\n\n");
    }
}

int chequear_correcto_lista_estudiantes_y_materias(registro *pRegistro, list *pLista_materias) {
    if (pRegistro->listado_por_edad->generic_list->length == 0
        && pLista_materias->length == 0) {
        printf(">>> No hay estudiantes ni materias cargadas\n\n");
        return 0;
    }

    if (pRegistro->listado_por_edad->generic_list->length == 0) {
        printf(">>> No hay estudiantes cargados\n\n");
        return 0;
    }

    if (pLista_materias->length == 0) {
        printf(">>> No hay materias cargadas\n\n");
        return 0;
    }

    return 1;
}

estudiante *buscar_estudiante(registro *coleccion) {
    int salir = 0;
    estudiante *pEstudiante = solicitar_estudiante(coleccion);
    while (pEstudiante == NULL && salir != 1) {
        printf(">>> No se encontro el estudiante\n\n");
        printf("Desea intentar de nuevo? (s/n):");
        salir = !solicitar_confirmacion();
        if (salir == 0) {
            pEstudiante = solicitar_estudiante(coleccion);
        }
    }
    return pEstudiante;
}

materia *buscar_materia(list *pLista_materias) {
    int salir = 0;
    materia *pMateria = solicitar_materia(pLista_materias);
    while (pMateria == NULL && salir != 1) {
        printf(">>> No se encontro la materia\n\n");
        printf("Desea intentar de nuevo? (s/n):");
        salir = !solicitar_confirmacion();
        if (salir == 0) {
            pMateria = solicitar_materia(pLista_materias);
        }
    }
    return pMateria;
}

int solicitar_confirmacion() {
    fflush(stdin);
    char option[2];
    fgets(option, 2, stdin);
    int respuesta = strcmp(option, "s") == 0;

    return respuesta;
}

estudiante * solicitar_estudiante(registro *pRegistro) {
    printf("Indique el nombre del estudiante:");
    char *nombre_estudiante = solicitar_dato(100);
    return registro_buscar_por_nombre(pRegistro, nombre_estudiante);
}

int buscar_materia_por_nombre(void *data, void *other_data) {
    materia *materia = data;
    char *nombre = (char *) other_data;

    return strcmp(materia->nombre, nombre) == 0;
}

materia *solicitar_materia(list *pLista_materias) {
    printf("Indique el nombre de la materia:");
    char *nombre_materia = solicitar_dato(100);
    return list_search_data(pLista_materias, &buscar_materia_por_nombre, nombre_materia);
}

unsigned char solicitar_nota() {
    int salir = 0;
    printf("Indique la nota:");
    unsigned char nota = strtoul(solicitar_dato(1), NULL, 10);
    while ((nota <= 0 || nota > 10) && salir != 1) {
        printf(">>> La nota ingresada no es valida\n\n");
        printf("Desea intentar de nuevo? (s/n):");
        salir = !solicitar_confirmacion();
        if (salir == 0) {
            printf("Indique la nota:");
            nota = strtoul(solicitar_dato(1), NULL, 10);
        }
    }

    return nota;
}

void handle_estudiante_rendir(registro *pRegistro, list *pLista_materias) {
    int resultado_chequeo = chequear_correcto_lista_estudiantes_y_materias(pRegistro, pLista_materias);

    if (resultado_chequeo == 0) {
        return;
    }

    estudiante *pEstudiante = buscar_estudiante(pRegistro);
    materia *pMateria = buscar_materia(pLista_materias);
    unsigned char nota = solicitar_nota();

    int inscripcion_completa = 0;
    if (pEstudiante != NULL && pMateria != NULL && &nota != NULL) {
        inscripcion_completa = rendir_materia(pEstudiante, pMateria, nota);
    }

    switch (inscripcion_completa) {
        case 0:
            printf(">>> La materia %s no esta registrada en este estudiante\n\n", pMateria->nombre);
            break;
        case 1:
            printf(">>> Anotacion realizada con exito\n\n");
            break;
    }
}

void handle_listar_registro(registro *pRegistro, list *pLista_materias) {
    int resultado_chequeo = chequear_correcto_lista_estudiantes_y_materias(pRegistro, pLista_materias);

    if (resultado_chequeo == 0) {
        return;
    }

    printf("################ Estudiantes #################\n");

    int salir = 0;
    printf("Desea imprimir por Nombre [0] o Edad [1]:");
    unsigned char modo_impresion = strtoul(solicitar_dato(1), NULL, 10);
    printf("\n");

    switch (modo_impresion) {
        case 0:
            listar_registro(pRegistro, 0, 0);
            break;
        case 1:
            printf(">>> Indique por favor entre que edades quiere imprimir\n");
            printf("Comenzando desde:");
            short edad_desde = strtoul(solicitar_dato(2), NULL, 10);

            printf("Hasta la edad de:");
            short edad_hasta = strtoul(solicitar_dato(2), NULL, 10);

            printf("La cantidad de registros de (indique 0 para ver todos):");
            short cantidad_records = strtoul(solicitar_dato(2), NULL, 10);

            ordered_list *lista_filtrada_por_edad = registro_buscar_por_edad(pRegistro, edad_desde, edad_hasta);

            ordered_list_print(lista_filtrada_por_edad, &print_estudiante, cantidad_records);
            break;
        default:
            listar_registro(pRegistro, 0, modo_impresion);
            break;
    }
}

void handle_consultar_materias(list *pLista_materias) {
    materia *materia = solicitar_materia(pLista_materias);
    if (materia == NULL) {
        printf(">>> Materia no encontrada\n\n");
        return;
    }

    materia_print(materia);
}

void handle_consultar_estudiantes(registro *pRegistro) {
    estudiante *pEstudiante = solicitar_estudiante(pRegistro);
    if (pEstudiante == NULL) {
        printf(">>> Estudiante no encontrado\n\n");
        return;
    }

    estudiante_print(pEstudiante);
}

void handle_consultar_promedio_estudiante(registro *pRegistro) {
    estudiante *pEstudiante = solicitar_estudiante(pRegistro);
    if (pEstudiante == NULL) {
        printf(">>> Estudiante no encontrado\n\n");
        return;
    }

    estudiante_promedio_print(pEstudiante);
}

void estudiante_promedio_print(estudiante * pEstudiante){
    printf("El promedio de la cursada de %s es de %d pts",pEstudiante->nombre, calcular_promedio_estudiante(pEstudiante));
}


void handle_consultar_cursada(registro *pRegistro) {

}

void handle_materia_aprobada(registro *pRegistro, list *pLista_materias) {
    int resultado_chequeo = chequear_correcto_lista_estudiantes_y_materias(pRegistro, pLista_materias);

    if (resultado_chequeo == 0) {
        return;
    }

    printf("############# Aprobacion materia #############\n");

    estudiante *pEstudiante = buscar_estudiante(pRegistro);
    materia *pMateria = buscar_materia(pLista_materias);

    int estado_materia = aprobo_materia(pEstudiante, pMateria);

//    curso *materia_encontrada = list_search_data(pEstudiante->lista_materias, &curso_materia_equals, pMateria);
//
    switch (estado_materia) {
        case -1:
            printf(">>> El estudiante no esta anotado en esa materia\n\n");
            break;
        case 0:
            printf(">>> El estudiante no aprobo esta materia\n\n");
            break;
        case 1:
            printf(">>> La materia fue aprobada con mas de %i\n\n", NOTA_APROBADA);
            break;
    }
}

void handle_crear_correlatividad(registro *pRegistro, list *pLista_materias) {
    if (pLista_materias->length <= 1) {
        printf(">>> No hay suficientes materias cargadas para crear correlatividad\n\n");
        return;
    }

    printf("############## Correlatividad ################\n");
    printf(">>> Principal\n");
    materia *pMateria = buscar_materia(pLista_materias);
    printf(">>> Correlativa\n");
    materia *pCorrelativa = buscar_materia(pLista_materias);

    materia_add_correlativas(pMateria, pCorrelativa);

    printf("\n");
}