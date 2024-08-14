#include <stdio.h>


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
    int logout = 0;
    int cmd;

    while (!logout)
    {
        print_main_menu();

        scanf("%d", &cmd);

        switch (cmd)
        {
            case 1://Adicionar Pedido
                
                break;
            
            case 2://Remover Pedido
                
                break;
            
            case 3://Processar Pedido
                
                break;
            
            case 4://Listar Pedidos Pendentes
                
                break;
            
            case 5://Listar Pedidos em Processamento
                
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