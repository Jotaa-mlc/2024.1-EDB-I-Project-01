#ifndef ATENDIMENTO_
#define ATENDIMENTO_
#include "cardapio.h"
#include "list.h"
#include "queue.h"

void adicionar_pedido(List *l);
void remover_pedido(List *l);
void processar_pedido(List *l, Queue *q);
void listar_pedidos_pendentes(List *l);
void listar_pedidos_processamento(Queue *q);
#endif