#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"
#include "utilidades.h"
#include "quartos.h"
#include "tela_voltar_menu.h"
#include "hospedes.h"
#include "funcionarios.h"

void modulo_relatorios(void){

    char op;

    do {
        op = tela_relatorios();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                relatorio_hospedes();
                break;
            case '2':
                relatorio_funcionarios();
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
    printf("|       [2] -> Quartos por andar                 |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("|                                                |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opcao: ");
    scanf("%c", &op);
    getchar();
    return op;
}


void quartos_disponiveis(void){
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


void quartos_por_andar(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos *quar;
    quar = (Quartos*)malloc(sizeof(Quartos));
    char n_andar_lido [5];
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Quartos por andar}                    #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(n_andar_lido, 7, "Digite o n° do andar: ");
    
    arq_quartos = fopen("./data/quartos.dat", "rb");
    if (arq_quartos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        enter();
        return;
    }

    while (fread(quar, sizeof(Quartos), 1, arq_quartos)) {
        if (strncmp(n_andar_lido, quar->n_quarto, 1) == 0) {
            printf("%s\n", quar->n_quarto);
            encontrado = True;
        }
    }
    
    fclose(arq_quartos);
    
    if (!encontrado) {
        printf("Nenhum quarto nesse andar!");
    }

    free(quar);
    enter();

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
            quartos_disponiveis();
            break;
        case '2':
            quartos_por_andar();
            break;
        default:
            tela_op_invalida();
            break;
        }

    }while(op != '0');
}

char tela_relatorio_hospedes(void) {
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────┐\n");
    printf("|              RELATORIOS -> HOSPEDES            |\n");
    printf("|                                                |\n");
    printf("|       [1] -> Lista filtrada por nome           |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\nDigite uma opção: ");

    scanf("%c", &op);
    getchar();
    return op;
}

void relatorio_hospedes(void) {
    char op;

    do {
        op = tela_relatorio_hospedes();
        switch (op) {
        case '0':
            tela_voltar();
            break;
        case '1':
            relatorio_hospedes_filtrado();
            break;
        default:
            tela_op_invalida();
            break;
        }
    } while (op != '0');
}

void relatorio_hospedes_filtrado(void) {
    limpa_tela();

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*) malloc(sizeof(Hospedes));
    int encontrado = False;
    char filtro[10];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                 {Lista Filtrada por Nome}                #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");

    arq_hospedes = fopen("./data/hospedes.dat", "rb");

    if (arq_hospedes == NULL) {
        printf("Erro ao abrir o arquivo de hóspedes.\n");
        enter();
        free(hos);
        return;
    }

    printf("Digite a primeira letra(s) do nome: ");
    fgets(filtro, sizeof(filtro), stdin);
    filtro[strcspn(filtro, "\n")] = '\0';

    printf("\nHóspedes encontrados:\n");
    printf("---------------------------------------------\n");
    printf("%-20s %-15s %-10s\n", "Nome", "CPF", "Status");
    printf("---------------------------------------------\n");

    while (fread(hos, sizeof(Hospedes), 1, arq_hospedes)) {
        if (strncmp(hos->nome, filtro, strlen(filtro)) == 0) {
            printf("%-20s %-15s %c\n", hos->nome, hos->cpf, hos->status);
            encontrado = True;
        }
    }

    fclose(arq_hospedes);

    if (!encontrado) {
        printf("\nNenhum hóspede encontrado com esse filtro.\n");
    }

    free(hos);
    enter();

}

char tela_relatorio_funcionarios(void) {
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────┐\n");
    printf("|           RELATORIOS -> FUNCIONARIOS           |\n");
    printf("|                                                |\n");
    printf("|       [1] -> Lista filtrada por nome           |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\nDigite uma opção: ");

    scanf("%c", &op);
    getchar();
    return op;
}

void relatorio_funcionarios(void) {
    char op;

    do {
        op = tela_relatorio_funcionarios();
        switch (op) {
        case '0':
            tela_voltar();
            break;
        case '1':
            relatorio_funcionarios_filtrado();
            break;
        default:
            tela_op_invalida();
            break;
        }
    } while (op != '0');
}

void relatorio_funcionarios_filtrado(void) {
    limpa_tela();

    FILE *arq_funcionarios;
    Funcionarios *fun;
    fun = (Funcionarios*) malloc(sizeof(Funcionarios));
    int encontrado = False;
    char filtro[10];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                 {Lista Filtrada por Nome}                #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");

    arq_funcionarios = fopen("./data/funcionarios.dat", "rb");

    if (arq_funcionarios == NULL) {
        printf("Erro ao abrir o arquivo de funcionários.\n");
        enter();
        free(fun);
        return;
    }

    printf("Digite a primeira letra(s) do nome: ");
    fgets(filtro, sizeof(filtro), stdin);
    filtro[strcspn(filtro, "\n")] = '\0';

    printf("\nFuncionários encontrados:\n");
    printf("---------------------------------------------\n");
    printf("%-20s %-15s %-10s\n", "Nome", "CPF", "Status");
    printf("---------------------------------------------\n");

    while (fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)) {
        if (strncmp(fun->nome, filtro, strlen(filtro)) == 0) {
            printf("%-20s %-15s %d\n", fun->nome, fun->cpf, fun->status);
            encontrado = True;
        }
    }

    fclose(arq_funcionarios);

    if (!encontrado) {
        printf("\nNenhum funcionário encontrado com esse filtro.\n");
    }

    free(fun);
    enter();

}