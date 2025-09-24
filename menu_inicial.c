#include <stdio.h>
#include <stdlib.h>
#include "menu_inicial.h"

char tela_inicial(void){
    system("clear||cls");
    char op;
    printf("\n");
    printf(" __________________________________\n");
    printf("|                                  |\n");
    printf("|          Menu Principal          |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Clientes              |\n");
    printf("|        2 - Funcionarios          |\n");
    printf("|        3 - Quartos               |\n");
    printf("|        4 - Servicos              |\n");
    printf("|        5 - Equipe                |\n");
    printf("|        6 - Sobre                 |\n");
    printf("|        7 - Relatorios            |\n");
    printf("|        0 - Sair                  |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("Digite sua opcao: ");
    scanf("%c",&op);
    getchar();
    printf("\n");
    return op;
    
}