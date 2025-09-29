#include <stdio.h>
#include <stdlib.h>
#include "menu_inicial.h"
#include "utilidades.h"

char tela_inicial(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|                      -Menu Principal-                      |\n");
    printf("|                                                            |\n");
    printf("|────────────────────────────────────────────────────────────|\n");
    printf("|                                                            |\n");
    printf("|        [1] -> Clientes                                     |\n");
    printf("|        [2] -> Funcionarios                                 |\n");
    printf("|        [3] -> Quartos                                      |\n");
    printf("|        [4] -> Servicos                                     |\n");
    printf("|        [5] -> Equipe                                       |\n");
    printf("|        [6] -> Sobre                                        |\n");
    printf("|        [7] -> Relatorios                                   |\n");
    printf("|        [0] -> Sair                                         |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite sua opcao: ");
    scanf("%c",&op);
    getchar();
    printf("\n");
    return op;
    
}