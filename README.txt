Nombre del Estudiante:

ID del Estudiante:

Fecha:

---------------------

Descripción General:

Este laboratorio implementa una cola que soporta tanto operaciones FIFO (First-In, First-Out) como LIFO (Last-In, First-Out) usando una lista enlazada de forma eficiente.

---------------------

Diseño e Implementación:

1. Estructura de la Cola (`queue_t`):
   - La estructura principal ha sido extendida para incluir un puntero `tail` y un entero `size`. El puntero `tail` nos permite realizar inserciones en la cola en tiempo O(1), mientras que `size` nos permite saber el tamaño de la cola también en tiempo O(1).

2. Función q_new:
   - Se ha modificado para inicializar los nuevos campos `tail` y `size`.

3. Función q_free:
   - Se ha mejorado para liberar cada elemento individual de la lista enlazada antes de liberar la estructura principal de la cola.

4. Función q_insert_head:
   - Si la cola está vacía (es decir, `head` es NULL), se actualiza `tail` para que apunte al nuevo elemento. De lo contrario, se sigue la inserción normal en la cabeza.

5. Función q_insert_tail:
   - Gracias al puntero `tail`, podemos insertar al final de la lista en tiempo O(1). Si la cola está vacía, `head` y `tail` se actualizan para apuntar al nuevo elemento.

6. Función q_remove_head:*
   - Se han añadido comprobaciones para manejar colas vacías y actualizar el puntero `tail` si es necesario. Además, se libera la memoria del elemento eliminado.

7. Función q_size:
   - Simplemente devuelve el valor de `size`.

8. Función q_reverse:
   - Se implementó invirtiendo los punteros de la lista enlazada. Se tomó especial cuidado para actualizar los punteros `head` y `tail` al final del proceso.

---

Desafíos y Aprendizajes:

El principal desafío fue garantizar que las funciones operaran en tiempo O(1) que se requeria. Aprendí la importancia de la eficiencia y cómo pequeñas optimizaciones en la estructura de datos pueden llevar a mejoras significativas en el rendimiento.

