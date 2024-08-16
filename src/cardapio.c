#include "headers/cardapio.h"
#include <stdlib.h>
#include <stdio.h>

const char *cardapio[QTE_PRATOS] = { /*Entradas [0,4] - Principais [5,9] - Sobremesas [10,14]*/
        "Sopa de Cebola",
        "Salada Caesar",
        "Bruschetta",
        "Caraccio de Carne",
        "Camarao ao Alho",
        "Lasanha a Bolonhesa",
        "File Mignon com Fritas",
        "Frango Grelhado com Legumes",
        "Bacalhau a Gomes de Sa",
        "Risoto de Cogumelos",
        "Tiramisu",
        "Cheesecake de Frutas Vermelhas",
        "Mousse de Chocolate",
        "Pudim de Leite",
        "Sorvete de Baunilha com Calda de Morango"
};

void print_cardapio()
{
    for (unsigned int i = 0; i < QTE_PRATOS; i++)
    {
        printf("%d - %s\n", i + 1, cardapio[i]);
    }
}
