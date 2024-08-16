#ifndef QUEUE_
#define QUEUE_
#include "node.h"

typedef struct queue
{
    Node *header;
} Queue;

Queue *initialize_queue();
void destruct_queue(Queue *l);
void push(Queue *q, int pedido);
int pop(Queue *q);
int peek(Queue *q);
#endif