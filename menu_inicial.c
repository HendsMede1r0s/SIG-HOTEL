#include <stdio.h>
#include <stdlib.h>
#include "menu_inicial.h"

int tela_inicial(void){
    system("clear||cls");
    int opcao;
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
    printf("|        5 - Restaurante           |\n");
    printf("|        6 - Garagem               |\n");
    printf("|        7 - Equipe                |\n");
    printf("|        8 - Sobre                 |\n");
    printf("|        9 - Relatorios            |\n");
    printf("|        0 - Sair                  |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("Digite sua opcao: ");
    scanf("%d",&opcao);
    return opcao;
    getchar();  
}