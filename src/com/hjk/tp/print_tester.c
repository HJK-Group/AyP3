#include "estudiante/registro.h"

void print_alumno(void *alumno) {
    estudiante_print((estudiante *) alumno);
}

int main() {

    registro *un_registro = new_registro();
    estudiante *un_estudiante = new_estudiante(1, "Hernan", "Rubio", 21);
    estudiante *otro_estudiante = new_estudiante(2, "Kevin", "Tubio", 25);
    estudiante *tercer_estudiante = new_estudiante(3, "Juan", "Calvinio", 29);

    registro_agregar_alumno(un_registro, un_estudiante);
    registro_agregar_alumno(un_registro, otro_estudiante);
    registro_agregar_alumno(un_registro, tercer_estudiante);

    //listar_registro(un_registro, 2, Order_By_Nombre);

    ordered_list *listado_filtrado = registro_buscar_por_edad(un_registro, 25, 29);
    ordered_list_print(listado_filtrado, &print_alumno, 0);
}
