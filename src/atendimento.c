#include "atendimento.h"
#include <stdio.h>

void adicionar_peidido(List *l)
{
    printf("Qual item de nosso cardapio gostaria de pedir?\n");
    print_cardapio();
    printf("Favor informe o número a frente do prato que quer pedir.\n");

    int pedido = scanf("%d", &pedido);

    if (pedido > QTE_PRATOS || pedido <= 0)//pedido inválido
    {
        printf("Esse item não existe no nosso cardápio!");
        return;
    }
    
    printf("O prato selecionado foi: %s.\nSerá preparado em alguns instantes. Obrigado pela preferência\n", cardapio[--pedido]);

    push_back(l, pedido);
}

void remover_pedido(List *l)
{
    printf("Qual pedido gostaria de remover?\n");
    listar_pedidos_pendentes(l);
    printf("Favor informe o ID do pedido que queira remover.\n");

    int id_pedido = scanf("%d", &id_pedido);
    id_pedido--;

    Node *current = l->header;
    int index = 0;
    while (current->next != NULL && index < id_pedido)
    {
        index++;
        current = current->next;
    }

    if (index == id_pedido)
    {
        printf("O Pedido de ID: %d - %s foi removido.\n", id_pedido, cardapio[current->pedido]);
        remove_item(l, id_pedido);
    }
    else
    {
        printf("O ID informado não está disponível.\n");
    }
}

void processar_pedido(List *l, Queue *q)
{
    int pedido = pop_front(l);

    printf("Passando o pedido mais antigo:\n");
    printf("\t%s\n", cardapio[pedido]);
    printf("para a lista de processamento\n");

    push(q, pedido);
}

void listar_pedidos_pendentes(List *l)
{
    printf("Os pedidos ainda pendentes para serem processados são:\n\tID - Prato\n");

    int id_pedido = 0;
    Node *current = l->header;
    while (current != NULL)
    {
        printf("\t%d - %s\n", ++id_pedido, cardapio[current->pedido]);
        current = current->next;
    }
}

void listar_pedidos_processamento(Queue *q)
{
    printf("Os pedidos que estão sendo processados são:\n\tID - Prato");

    int id_pedido = 0;
    Node *current = q->header;
    while (current != NULL)
    {
        printf("\t%d - %s\n", ++id_pedido, cardapio[current->pedido]);
        current = current->next;
    }
}
