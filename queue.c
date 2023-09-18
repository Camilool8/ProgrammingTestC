/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (!q) return NULL;  // Si malloc devuelve NULL.

    q->head = NULL;
    q->tail = NULL;  // Añadiendo puntero al final.
    q->size = 0;  // Inicializar el tamaño a 0.

    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (!q) return;

    list_ele_t *current = q->head;
    list_ele_t *next;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    
    free(q);
}

bool q_insert_head(queue_t *q, int v)
{
    if (!q) return false;

    list_ele_t *newh = malloc(sizeof(list_ele_t));
    if (!newh) return false;  // Si malloc devuelve NULL.

    newh->value = v;
    newh->next = q->head;
    q->head = newh;
    if (q->size == 0) q->tail = newh;  // Actualizando el tail si la lista estaba vacía.
    q->size++;  // Actualizando el tamaño.

    return true;
}

bool q_insert_tail(queue_t *q, int v)
{
    if (!q) return false;

    list_ele_t *newt = malloc(sizeof(list_ele_t));
    if (!newt) return false;  // Si malloc devuelve NULL.

    newt->value = v;
    newt->next = NULL;
    if (q->size == 0) {
        q->head = newt;
        q->tail = newt;
    } else {
        q->tail->next = newt;
        q->tail = newt;
    }
    q->size++;  // Actualizando el tamaño.

    return true;
}

bool q_remove_head(queue_t *q, int *vp)
{
    if (!q || q->size == 0) return false;

    list_ele_t *temp = q->head;
    if (vp) *vp = temp->value;
    q->head = q->head->next;
    free(temp);

    q->size--;  // Actualizando el tamaño.
    if (q->size == 0) q->tail = NULL;  // Actualizando el tail si la lista está vacía ahora.

    return true;
}

int q_size(queue_t *q)
{
    if (!q) return 0;
    return q->size;
}

void q_reverse(queue_t *q)
{
    if (!q || q->size <= 1) return;

    list_ele_t *prev = NULL;
    list_ele_t *current = q->head;
    list_ele_t *next = NULL;
    q->tail = q->head;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    q->head = prev;
}
