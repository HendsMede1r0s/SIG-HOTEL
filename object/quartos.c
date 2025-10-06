#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quartos.h"
#include "utilidades.h"
#include "tela_voltar_menu.h"

typedef struct quartos Quartos;

void modulo_quartos(void){

    char op;

    do {
        op = tela_quartos();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                check_in();
                break;
            case '2':
                list_quartos();
                break;
            case '3':
                check_out();
                break;
            case '4':
                exib_quartos();
                break;
            case '5':
                edit_quartos();
                break;
            case '6':
                cad_quartos();
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0'); 
}

char tela_quartos(void){
    limpa_tela();
    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────────────┐\n");
    printf("|                              -Quartos-                             |\n");
    printf("├────────────────────────────────────────────────────────────────────┤\n");
    printf("| [1] -> Check-in                                                    |\n");
    printf("| [2] -> Quartos disponíveis                                         |\n");
    printf("| [3] -> Check-out                                                   |\n");
    printf("| [4] -> Exibir quartos                                              |\n");
    printf("| [5] -> Editar quartos                                              |\n");
    printf("| [6] -> Cadastrar quartos                                           |\n");
    printf("| [0] -> Voltar                                                      |\n");
    printf("└────────────────────────────────────────────────────────────────────┘\n");

    printf("Digite uma opção: ");
    scanf(" %c", &op);
    getchar();

    return op;
}

void check_in(void){
    limpa_tela();

    FILE *arq_quartos;
    FILE *arq_quartos_temp;
    Quartos quar;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Quartos -> Checkin}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(quar.n_quarto_lido, 7, "Digite o id do quarto: ");

    arq_quartos = fopen("./data/quartos.csv", "rt");
    arq_quartos_temp = fopen("./data/quartos_temp.csv", "wt");
    if (arq_quartos == NULL || arq_quartos_temp == NULL) {
        printf("\t Erro ao abrir o arquivo de quartos.\n");
        enter();
        return;
    }
    while(fscanf(arq_quartos, "%[^;];%[^;];%[^;];%c\n", quar.n_quarto, quar.cpf, quar.quan_pessoas , &quar.status) == 4) {
        if (strcmp(quar.n_quarto, quar.n_quarto_lido) != 0) {
            fprintf(arq_quartos_temp, "%s;%s;%s;%s\n", quar.n_quarto_lido, quar.cpf, quar.quan_pessoas, &quar.status);

        }else if (strcmp(quar.n_quarto, quar.n_quarto_lido) == 0) {
            input(quar.cpf, 18, "Digite o CPF do hospede: ");
            input(quar.quan_pessoas, 5, "Digite a quantidade de pessoas no quarto: ");
            quar.status = 'O';
            fprintf(arq_quartos_temp, "%s;%s;%s;%s\n", quar.n_quarto_lido, quar.cpf, quar.quan_pessoas, &quar.status);
        }
        
    }

    fclose(arq_quartos);
    fclose(arq_quartos_temp);
    remove("./data/quartos.csv");
    rename("./data/quartos_temp.csv", "./data/quartos.csv");

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#             {Cliente hospedado com sucesso!}             #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Hospede com CPF %s alocado no quarto com id %s.\n", quar.cpf, quar.n_quarto);
    printf("Numero de pessoas hospedadas: %s\n", quar.quan_pessoas);
    enter();
}

void list_quartos(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos quar;
    int encontrou = 0;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#             {Quartos -> Quartos disponiveis}             #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    
    arq_quartos = fopen("./data/quartos.csv", "rt");

    if (arq_quartos == NULL) {
        printf("Erro ao abrir o arquivo de quartos.\n");
        enter();
        return;
    }

    while (fscanf(arq_quartos, "%[^;];%[^;];%[^;];%c\n", quar.n_quarto, quar.cpf, quar.quan_pessoas, &quar.status) == 4) {
        if (quar.status == 'V') {
            printf("Quarto %s disponível.\n", quar.n_quarto);
            encontrou = 1;
        }
    }

    if (encontrou != 1) {
        printf("Nenhum quarto disponível no momento.\n");
    }

    fclose(arq_quartos);
    enter();
}

void check_out(void){
    limpa_tela();

    FILE *arq_quartos;
    FILE *arq_quartos_temp;
    Quartos quar;
    int encontrou = 0;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Quartos -> Check-out}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(quar.n_quarto_lido, 7, "Digite o ID do quarto para check-out: ");

    arq_quartos = fopen("./data/quartos.csv", "rt");
    arq_quartos_temp = fopen("./data/quartos_temp.csv", "wt");
    if (arq_quartos == NULL || arq_quartos_temp == NULL) {
        printf("Erro ao abrir o arquivo de quartos.\n");
        enter();
        return;
    }

        while (fscanf(arq_quartos, "%[^;];%[^;];%[^;];%c\n", quar.n_quarto, quar.cpf, quar.quan_pessoas, &quar.status) == 4) {
        if (strcmp(quar.n_quarto, quar.n_quarto_lido) == 0) {
            quar.status = 'V';
            strcpy(quar.cpf, "-----");
            strcpy(quar.quan_pessoas, "0");
            encontrou = 1;
        }
        fprintf(arq_quartos_temp, "%s;%s;%s;%c\n", quar.n_quarto, quar.cpf, quar.quan_pessoas, quar.status);
    }

    fclose(arq_quartos);
    fclose(arq_quartos_temp);
    remove("./data/quartos.csv");
    rename("./data/quartos_temp.csv", "./data/quartos.csv");

    limpa_tela();
    if (encontrou)
        printf("Check-out do quarto %s realizado com sucesso!\n", quar.n_quarto_lido);
    else
        printf("Quarto %s não encontrado.\n", quar.n_quarto_lido);
    enter();

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#            {Check-out realizado com sucesso!}            #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    enter();
}

void exib_quartos(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos quar;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                {Quartos -> Exibir quartos}               #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(quar.n_quarto_lido, 7, "Digite o id do quarto que quer procurar: ");

    arq_quartos = fopen("./data/quartos.csv", "rt");
    if (arq_quartos == NULL) {
        printf("\t Erro ao abrir o arquivo de quartos.\n");
        enter();
        return;
    }
    while(fscanf(arq_quartos, "%[^;];%[^;];%[^;];%c\n", quar.n_quarto, quar.cpf, quar.quan_pessoas , &quar.status) == 4) {
        if (strcmp(quar.n_quarto, quar.n_quarto_lido) == 0) {
            printf("*QUARTO ENCONTRADO*");
            printf("\n");
            printf("\nID DO QUARTO: %s\n", quar.n_quarto);
            printf("\nCPF: %s\n", quar.cpf);
            printf("\nQUANTIDADE DE HOSPEDES: %s\n", quar.quan_pessoas);
            printf("\nSTATUS: %c\n", quar.status);
            enter();
            fclose(arq_quartos);
            return;
        }
        
    }
    printf("*QUARTO NÃO ENCONTRADO!*");
    enter();
}

void edit_quartos(void){
    limpa_tela();

    FILE *arq_quartos;
    FILE *arq_quartos_temp;
    Quartos quar;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                {Quartos -> Editar quartos}               #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(quar.n_quarto_lido, 7, "Digite o id do quarto que deseja editar: ");

    arq_quartos = fopen("./data/quartos.csv", "rt");
    arq_quartos_temp = fopen("./data/quartos_temp.csv", "wt");
    if (arq_quartos == NULL || arq_quartos_temp == NULL) {
        printf("\t Erro ao abrir o arquivo de quartos.\n");
        enter();
        return;
    }
    
    while(fscanf(arq_quartos, "%[^;];%[^;];%[^;];%c\n", quar.n_quarto, quar.cpf, quar.quan_pessoas, &quar.status) == 4) {
        if(strcmp(quar.n_quarto, quar.n_quarto_lido) != 0) {
            fprintf(arq_quartos_temp, "%s;%s;%s;%s\n", quar.n_quarto, quar.cpf, quar.quan_pessoas, &quar.status);

        }else if(strcmp(quar.n_quarto, quar.n_quarto_lido) == 0) {
            printf("Digite as novas informações do quarto com id %s.\n", quar.n_quarto_lido);
            input(quar.cpf, 18, "Digite o CPF do hospede:");
            input(quar.quan_pessoas, 5, "Digite a quantidade de pessoas no quarto: ");
            fprintf(arq_quartos_temp, "%s;%s;%s;%s\n", quar.n_quarto_lido, quar.cpf, quar.quan_pessoas, &quar.status);
        }
    }

    fclose(arq_quartos);
    fclose(arq_quartos_temp);
    remove("./data/quartos.csv");
    rename("./data/quartos_temp.csv", "./data/quartos.csv");

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#            {Cadastro atualizado com sucesso!}            #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    enter();
    printf("\nID DO QUARTO: %s\n", quar.n_quarto);
    printf("\nCPF: %s\n", quar.cpf);
    printf("\nQUANTIDADE DE HOSPEDES: %s\n", quar.quan_pessoas);
    printf("\nSTATUS: %c\n", quar.status);
    enter();
}

void cad_quartos(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos quar;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#              {Quartos -> Cadastrar quartos}              #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(quar.n_quarto, 7, "Digite o ID do quarto: ");

    arq_quartos = fopen("./data/quartos.csv", "at");
    if (arq_quartos == NULL) {
        printf("Erro ao abrir o arquivo de quartos.\n");
        enter();
        return;
    }

    strcpy(quar.cpf, "-----");
    strcpy(quar.quan_pessoas, "0");
    quar.status = 'V';

    fprintf(arq_quartos, "%s;%s;%s;%s\n", quar.n_quarto, quar.cpf, quar.quan_pessoas, &quar.status);
    fclose(arq_quartos);

    printf("Quarto com ID %s cadastrado no sistema.", quar.n_quarto);

}