#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quartos.h"
#include "utilidades.h"

void modulo_quartos(void){

    char op;

    do {
        op = tela_quartos();
        switch (op) {
            case '1':
                check_in();
                break;
            case '2':
                exib_quartos();
                break;
            case '3':
                check_out();
                break;
            case '4':
                pesq_quartos();
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
    printf("|        [4] -> Pesquisar quarto                                     |\n");
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
    char n_quarto [7];
    char cpf [18];
    char status [10];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Quartos -> Checkin}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o id do quarto:");
    scanf("%s", n_quarto);
    getchar();
    printf("\n");
    printf("Digite o CPF do hospede:");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf("Digite o status do quarto:");
    scanf("%s", status);
    getchar();
    printf("\n");

    arq_quartos = fopen("./data/quartos.csv", "at");
    if (arq_quartos == NULL) {
        printf("\t Erro ao abrir o arquivo de clientes.\n");
        printf("\t {Digite ENTER para continuar}\n");
        getchar();
        return;
    }
    fprintf(arq_quartos, "%s;%s;%s;\n", n_quarto, cpf, status);
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
    printf("{Digite ENTER para continuar}");
    getchar();
    printf("\n");
}

void exib_quartos(void){
    limpa_tela();

    //file

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

    char n_quarto [7];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Quartos -> Check-out}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o id do quarto do hospede:");
    scanf("%s", n_quarto);
    getchar();
    printf("\n");

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#            {Check-out realizado com sucesso!}            #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("{Digite ENTER para continuar}");
    getchar();
    printf("\n");
}

void pesq_quartos(void){
    limpa_tela();

    FILE *arq_quartos;
    char n_quarto [7];
    char n_quarto_lido [7];
    char cpf [18];
    char status [10];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#               {Quartos -> Pesquisar quarto}              #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o id do quarto que quer procurar:");
    scanf("%s", n_quarto_lido);
    getchar();
    printf("\n");

    arq_quartos = fopen("./data/quartos.csv", "rt");
    if (arq_quartos == NULL) {
        printf("\t Erro ao abrir o arquivo de clientes.\n");
        printf("\t {Digite ENTER para continuar}\n");
        getchar();
        return;
    }
    while(!feof(arq_quartos)) {
        fscanf(arq_quartos, "%[^;]", n_quarto);
        fgetc(arq_quartos);
        fscanf(arq_quartos, "%[^;]", cpf);
        fgetc(arq_quartos);
        fscanf(arq_quartos, "%[^;]", status);
        fgetc(arq_quartos);
        if (strcmp(n_quarto, n_quarto_lido) == 0) {
            printf("*CLIENTE ENCONTRADO*");
            printf("\n");
            printf("\nID DO QUARTO: %s\n", n_quarto);
            printf("\nCPF: %s\n", cpf);
            printf("\nSTATUS: %s\n", status);
            printf("\n");
            printf("\t {Digite ENTER para continuar}\n");
            getchar();
            fclose(arq_quartos);
            return;
        }
    }
}

void edit_quartos(void){
    limpa_tela();

    char n_quarto [7];
    char cpf [18];
    char status [10];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                {Quartos -> Editar quarto}                #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o id do quarto:");
    scanf("%s", n_quarto);
    getchar();
    printf("\n");
    printf("*Digite as novas informações*");
    printf("\n");
    printf("Digite o CPF do hospede:");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf("Digite o status do quarto:");
    scanf("%s", status);
    getchar();
    printf("\n");

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#            {Cadastro atualizado com sucesso!}            #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("{Digite ENTER para continuar}");
    getchar();
    printf("\n");
}