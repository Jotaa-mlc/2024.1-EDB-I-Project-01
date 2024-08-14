#include "list.h"
#include <stdlib.h>

void push_back(List *l, int pedido)
{
    Node *current = l->header;
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

int pop_front(List *l)
{
    Node *current = l->header;
    int pedido = current->pedido;

    l->header = current->next;
    free(current);
    return pedido;
}

int remove_item(List *l, int pos)
{
    int pedido;
    Node *current = l->header;
    Node *next = NULL;
    Node *prev = NULL;

    if (pos == 0)
    {
        l->header = current->next;
    }

    for (int i = 0; i < pos; i++)
    {
        if (current == NULL)
        {
            return -1;
        }
        
        prev = current;
        current = current->next;
        next = current->next;
    }

    pedido = current->pedido;

    if (prev != NULL)
    {
        prev->next = next;
    }

    if (next != NULL)
    {
        next->prev = prev;
    }

    free(current);
    return pedido;
}