#ifndef LIST_
#define LIST_
#include "node.h"

typedef struct list
{
    Node *header;
} List;

void push_back(List *l, int pedido);
int pop_front(List *l);
int search_item(List *l, int pedido);
#endif