#include "headers/queue.h"
#include <stdlib.h>

Queue *initialize_queue()
{
    Queue *l = calloc(1, sizeof(Queue));

    if (!l)
        return NULL;

    l->header = NULL;
    return l;
}

void destruct_queue(Queue *l)
{
    Node *current = l->header;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    free(l);
}

void push(Queue *q, int pedido)
{
    Node *current = q->header;
    Node *next = current;
    while (next != NULL)
    {
        current = next;
        next = current->next;
    }

    Node *new_node = calloc(1, sizeof(Node));
    new_node->pedido = pedido;
    new_node->prev = current;
    new_node->next = NULL;

    if (current != NULL)
    {
        current->next = new_node;
    }
    else
    {
        q->header = new_node;
    }
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