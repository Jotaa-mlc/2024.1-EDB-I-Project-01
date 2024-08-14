#ifndef NODE_DEFINITION
#define NODE_DEFINITION

struct node
{
    int pedido;
    struct node *next;
    struct node *prev;
};

typedef struct node Node;
#endif