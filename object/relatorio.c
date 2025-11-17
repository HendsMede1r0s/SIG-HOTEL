#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "utilidades.h"
#include "quartos.h"
#include "tela_voltar_menu.h"

void modulo_relatorios(void){

    char op;

    do {
        op = tela_relatorios();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                printf("Relatorio de hospedes");
                break;
            case '2':
                printf("Relatorio de funcionarios");
                break;
            case '3':
                relatorio_quartos();
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
    return op;
}


char tela_relatorio_quartos(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────┐\n");
    printf("|                                                |\n");
    printf("|              RELATORIOS -> QUARTOS             |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|       [1] -> Quartos disponiveis               |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("|                                                |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opcao: ");
    scanf("%c", &op);
    getchar();
    return op;
}


void dispo_quartos(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos *quar;
    quar = (Quartos*)malloc(sizeof(Quartos));
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Quartos disponiveis}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    
    arq_quartos = fopen("./data/quartos.dat", "rb");

    if (arq_quartos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        enter();
        return;
    }

    printf("Quartos disponiveis:\n");
    printf("\n");
    while (fread(quar, sizeof(Quartos), 1, arq_quartos)) {
        if (quar->status == 0) {
            printf("%s\n", quar->n_quarto);
            encontrado = True;
        }
    }
    
    enter();

    fclose(arq_quartos);
    free(quar);

    if (!encontrado) {
        printf("\nNenhum quarto disponível no momento.\n");
        enter();
    }

}


void relatorio_quartos(void){

    char op;

    do{
        op = tela_relatorio_quartos();
        switch (op)
        {
        case '0':
            tela_voltar();
            break;
        case '1':
            dispo_quartos();
            break;
        default:
            tela_op_invalida();
            break;
        }

    }while(op != '0');
}