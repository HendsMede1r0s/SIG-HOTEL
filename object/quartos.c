#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quartos.h"
#include "utilidades.h"

typedef struct quartos Quartos;

void modulo_quartos(void){

    char op;

    do {
        op = tela_quartos();
        switch (op) {
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
        }
    } while (op != '0'); 
}

char tela_quartos(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                                                    |\n");
    printf("|                              -Quartos-                             |\n");
    printf("|                                                                    |\n");
    printf("|────────────────────────────────────────────────────────────────────|\n");
    printf("|                                                                    |\n");
    printf("|        [1] -> Check-in                                             |\n");
    printf("|        [2] -> Quartos disponiveis                                  |\n");
    printf("|        [3] -> Check-out                                            |\n");
    printf("|        [4] -> Exibir quarto                                        |\n");
    printf("|        [5] -> Editar quarto                                        |\n");
    printf("|        [0] -> Voltar                                               |\n");
    printf("|                                                                    |\n");
    printf("└────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void check_in(void){
    limpa_tela();

    FILE *arq_quartos;
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
    input(quar.n_quarto, 7, "Digite o id do quarto: ");
    input(quar.cpf, 18, "Digite o CPF do hospede: ");
    input(quar.quan_pessoas, 5, "Digite a quantidade de pessoas no quarto: ");

    arq_quartos = fopen("./data/quartos.csv", "at");
    if (arq_quartos == NULL) {
        printf("\t Erro ao abrir o arquivo de quartos.\n");
        enter();
        return;
    }
    quar.status = 'U';
    fprintf(arq_quartos, "%s;%s;%s;%s\n", quar.n_quarto, quar.cpf, quar.quan_pessoas, &quar.status);
    fclose(arq_quartos);

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
    printf("Hospede com CPF %s alocado no quarto com id %s.", quar.cpf, quar.n_quarto);
    enter();
}

void list_quartos(void){
    limpa_tela();

    //FILE *arq_quartos;
    //FILE *arq_quar_disponiveis;
    //Quartos quar;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#             {Quartos -> Quartos disponiveis}             #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}

void check_out(void){
    limpa_tela();

    //FILE *arq_quartos;
    Quartos quar;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Quartos -> Check-out}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(quar.n_quarto_lido, 7, "Digite o id do quarto do hospede: ");

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
    printf("│#                {Quartos -> Exibir quarto}                #│\n");
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
    printf("│#                {Quartos -> Editar quarto}                #│\n");
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
            printf("Digite as novas informações do quarto com id %s .", quar.n_quarto_lido);
            input(quar.cpf, 18, "Digite o CPF do hospede:");
            input(quar.quan_pessoas, 5, "Digite o status do quarto: ");

            printf("Digite 'U' para quarto que está sendo usado e 'V' para um que está vazio: ");
            scanf("%c", &quar.op_quartos);

            if (quar.op_quartos == 'U') {
                quar.status = 'U';
            }else if (quar.op_quartos == 'V') {
                quar.status = 'V';
            }

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