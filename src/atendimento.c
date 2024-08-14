#include "atendimento.h"
#include <stdio.h>

extern const unsigned int qte_pratos;
extern const unsigned int max_name_length;
extern const char **cardapio;

void adicionar_peidido(List *l)
{
    printf("Qual item de nosso cardapio gostaria de pedir?\n");
    print_cardapio();
    printf("Favor informe o número a frente do prato que quer pedir.\n");

    int pedido = scanf("%d", &pedido);

    if (pedido > qte_pratos || pedido <= 0)//pedido inválido
    {
        printf("Esse item não existe no nosso cardápio!");
        return -1;
    }
    
    printf("O prato selecionado foi: %s.\nSerá preparado em alguns instantes. Obrigado pela preferência\n", cardapio[--pedido]);

    push_back(l, pedido);
}

