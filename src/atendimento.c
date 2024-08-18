#include "headers/atendimento.h"
#include <stdio.h>
#include <stdlib.h>

void adicionar_pedido(List *l)
{
    printf("Qual item de nosso cardapio gostaria de pedir?\n");
    print_cardapio();
    printf("Favor informe o número a frente do prato que quer pedir.\n");
    char buffer[10] = {0};
    int pedido = atoi(fgets(buffer, 4, stdin));

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
    if (l->header != NULL)
    {
        printf("Qual pedido gostaria de remover?\n");
        listar_pedidos_pendentes(l);
        printf("Favor informe o ID do pedido que queira remover.\n");

        char buffer[10] = {0};
        int id_pedido = atoi(fgets(buffer, 4, stdin));
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
            printf("O Pedido de ID: %d - %s foi removido.\n", id_pedido + 1, cardapio[current->pedido]);
            remove_item(l, id_pedido);
        }
        else
        {
            printf("O ID informado não está disponível.\n");
        }
    }
    else
    {
        printf("Não há pedidos a serem retirados.\n");
    }
}

void processar_pedido(List *l, Queue *q)
{
    if (l->header != NULL)
    {
        int pedido = pop_front(l);

        printf("Passando o pedido mais antigo:\n");
        printf("\t%s\n", cardapio[pedido]);
        printf("para a lista de processamento\n");

        push(q, pedido);
    }
    else
    {
        printf("Não há mais pedidos aguardando processamento.\n");
    }
}

void listar_pedidos_pendentes(List *l)
{
    if (l->header != NULL)
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
    else
    {
        printf("Não existem pedidos pendentes de processamento.\n");
    }
       
}

void listar_pedidos_processamento(Queue *q)
{
    if (q->header != NULL)
    {
        printf("Os pedidos que estão sendo processados são:\n\tID - Prato\n");

        int id_pedido = 0;
        Node *current = q->header;
        while (current != NULL)
        {
            printf("\t%d - %s\n", ++id_pedido, cardapio[current->pedido]);
            current = current->next;
        }
    }
    else
    {
        printf("Não existem pedidos em processamento no momento.\n");
    }    
}
