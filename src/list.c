#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void push_back(List *l, int item, int pos)
{
    if (l == NULL)
    {
        printf("Lista Não iniciada!\n");
        return;
    }

    Node *prev = NULL;
    Node *current = l->header;

    if (current == NULL)//Lista vazia
    {
        Node *new_node = malloc(sizeof(Node));
        new_node->data = item;
        new_node->prev = NULL;
        new_node->next = NULL;

        l->header = new_node;
        return;
    }
    
    for (int i = 0; i < pos; i++)
    {
        if (current->next == NULL && (pos - i > 1))
        {
            printf("Posição inválida para a lista!\n");
            return;
        }
        
        prev = current;
        current = current->next;
    }
    
    Node *new_node = malloc(sizeof(Node));
    new_node->data = item;
    new_node->prev = prev;
    new_node->next = current;

    if (prev == NULL)//inserção no inicio da lista
    {
        l->header = new_node;
    }
    else
    {
        prev->next = new_node;
    }

    if (current != NULL)//atualiza o link, se não for o ultimo item
    {
        current->prev = new_node;
    }
}

void remove_item(List *l, int pos)
{
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
            printf("Posição invalida para remoção!");
            return;
        }
        
        prev = current;
        current = current->next;
        next = current->next;
    }

    if (prev != NULL)
    {
        prev->next = next;
    }

    if (next != NULL)
    {
        next->prev = prev;
    }

    free(current);
}

int search_item(List *l, int item)
{
    Node *current = l->header;
    int i = 0;
    while (current != NULL)
    {
        if (current->data == item)
        {
            return i;
        }

        current = current->next;
        i++;
    }

    return -1;
}

void print_list(List *l)
{
    Node *current = l->header;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}
