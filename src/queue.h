#ifndef QUEUE_
#define QUEUE_
#include "node.h"

typedef struct queue
{
    Node *header;
} Queue;

void push(Queue *q, int pedido);
int pop(Queue *q);
int peek(Queue *q);
#endif