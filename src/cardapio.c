#include "cardapio.h"
#include <stdlib.h>
#include <stdio.h>

extern const unsigned int qte_pratos;
extern const unsigned int max_name_length;
extern const char **cardapio;

void print_cardapio()
{
    for (unsigned int i = 0; i < qte_pratos; i++)
    {
        printf("%d - %s\n", i + 1, cardapio[i]);
    }
}
