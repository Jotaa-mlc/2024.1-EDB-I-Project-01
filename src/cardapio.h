#ifndef CARDAPIO_
#define CARDAPIO_

const unsigned int qte_pratos = 15;
const unsigned int max_name_length = 50;
const char cardapio[qte_pratos][max_name_length] = {
        //Entradas [0,4]
        "Sopa de Cebola",
        "Salada Caesar",
        "Bruschetta",
        "Caraccio de Carne",
        "Camarao ao Alho",
        //Principais [5,9]
        "Lasanha a Bolonhesa",
        "File Mignon com Fritas",
        "Frango Grelhado com Legumes",
        "Bacalhau a Gomes de Sa",
        "Risoto de Cogumelos",
        //Sobremesas [10,14]
        "Tiramisu",
        "Cheesecake de Frutas Vermelhas",
        "Mousse de Chocolate",
        "Pudim de Leite",
        "Sorvete de Baunilha com Calda de Morango",
};

void print_cardapio();

#endif