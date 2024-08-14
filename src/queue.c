#include "queue.h"
#include <stdlib.h>

void push(Queue *q, int pedido)
{
    Node *current = q->header;
    while (current->next != NULL)
    {
        current = current->next;
    }

    Node *new_node = calloc(1, sizeof(Node));
    new_node->pedido = pedido;
    new_node->prev = current;
    new_node->next = NULL;

    current->next = new_node;
}

int pop(Queue *q)
{
    Node *current = q->header;
    int pedido = current->pedido;

    q->header = current->next;
    free(current);
    return pedido;
}

int peek(Queue *q)
{
    return q->header->pedido;
}