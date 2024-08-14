#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "atendimento.h"

void print_main_menu()
{
    printf("/-----------------------------------------------\\\n");
    printf("|              1 - Adicionar Pedido             |\n");
    printf("|               2 - Remover Pedido              |\n");
    printf("|              3 - Processar Pedido             |\n");
    printf("|          4 - Listar Pedidos Pendentes         |\n");
    printf("|      5 - Listar Pedidos em Processamento      |\n");
    printf("|             6 - Ecerrar o Programa            |\n");
    printf("\\-----------------------------------------------/\n");
}

int sair()//confirmação de saida
{
    char resposta = ' ';
    printf("Certeza que deseja deixar o programa?\nDigite 's' para confirmar\n");

    scanf("\n%c", &resposta);
    resposta = tolower(resposta);
    if(resposta == 's')
        return 1;
    else
        return 0;
}

int main()
{
    List pedidos;
    pedidos.header = NULL; //inicializando a lista de pedidos

    Queue pedidos_procesando;
    pedidos_procesando.header = NULL; //inicializando a lista de pedidos a serem processados

    int logout = 0;
    char buffer[10] = {0};
    int cmd;

    while (!logout)
    {
        print_main_menu();

        cmd = atoi(fgets(buffer, 4, stdin));
        //scanf("%d", &cmd);

        switch (cmd)
        {
            case 1://Adicionar Pedido
                adicionar_peidido(&pedidos);
                break;
            
            case 2://Remover Pedido
                remover_pedido(&pedidos);
                break;
            
            case 3://Processar Pedido
                processar_pedido(&pedidos, &pedidos_procesando);
                break;
            
            case 4://Listar Pedidos Pendentes
                listar_pedidos_pendentes(&pedidos);
                break;
            
            case 5://Listar Pedidos em Processamento
                listar_pedidos_processamento(&pedidos_procesando);
                break;
            
            case 6://sair do programa
                logout = sair();
                break;
            
            default:
                printf("Comando inválido!\nFavor insira um comando descrito no menu.\n");
                break;
        }
        printf("\n\n");
    }
    return 0;
}