### *Limitaciones del Sistema:*

- Lista enlazada:
  - Operaciones O(N)
  - Al crecer mucho la cantidad de estudiantes, al Sistema le costará buscarlos por la búsqueda lineal que lleva implementada.
- Paginado:
  - Solo es posible ir en una dirección en el paginado, ya que por la implementación de la lista enlazada, no es posible volver hacia "atrás".

### *Validaciones complejas:*

- No se duplican los datos en memoria.
- Se asegura de copiar todos los datos en memoria heap (evita SEGMENTATION_FAULT).
- Pruebas unitarias para cada compenente del Sistema.
- Funciones destroy para todos los struct creados y utilizados.

### *Añadidos por fuera del Sistema:*

- Paginado para lista enlazada de genéricos.
- Lista enlazada de genéricos:
  - Se pueden manipular structs de cualquier tipo.
- Lista ordenada de genéricos con comparador.
- Impresión genérica de listas.
- Funciones contains para listas.
- Implementación de funciones compare y print.