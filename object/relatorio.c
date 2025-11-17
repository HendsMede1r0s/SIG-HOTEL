#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "utilidades.h"
#include "tela_voltar_menu.h"
#include "hospedes.h"

void modulo_relatorios(void){

    char op;

    do {
        op = tela_relatorios();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                relatorio_hospede();
                break;
            case '2':
                relatorio_funcionario();
                break;
            case '3':
                printf("Relatorio de quartos");
                break;
            case '4':
                printf("Relatorio de servicos");
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0'); 
}

char tela_relatorios(void){
    limpa_tela();

    char op;
    printf("\n");
    printf("┌────────────────────────────────────────────────┐\n");
    printf("|                                                |\n");
    printf("|                   RELATORIOS                   |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|       [1] -> Relatorio de hospedes             |\n");
    printf("|       [2] -> Relatorio de funcionarios         |\n");
    printf("|       [3] -> Relatorio de quartos              |\n");
    printf("|       [4] -> Relatorio de servicos             |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("|                                                |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opcao: ");
    scanf("%c", &op);
    getchar();
    enter();
    return op;
}

void switch_relatorio_hospedes(void){
    
    char op;

    do {
        op = tela_relatorio_hospedes();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                filtrar_letra();
                break;
        }
    } while (op != '0');
}

char tela_relatorio_hospedes(void){
    limpa_tela();

    char op;
    printf("\n");
    printf("┌────────────────────────────────────────────────┐\n");
    printf("|                                                |\n");
    printf("|       RELATORIOS -> Relatorio de Hospedes      |\n");
    printf("|                                                |\n");
    printf("|       [1] -> Filtrar por letras                |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("|                                                |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opcao: ");
    scanf("%c", &op);
    getchar();
    enter();
    return op;

}