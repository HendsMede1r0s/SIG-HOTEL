#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quartos.h"
#include "utilidades.h"
#include "tela_voltar_menu.h"
#include "leitura.h"

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
                busc_quartos();
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
    printf("| [4] -> Buscar quartos                                              |\n");
    printf("| [5] -> Editar quartos                                              |\n");
    printf("| [6] -> Cadastrar quartos                                           |\n");
    printf("| [0] -> Voltar                                                      |\n");
    printf("└────────────────────────────────────────────────────────────────────┘\n");

    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();

    return op;
}

void check_in(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos *quar;
    quar = (Quartos*)malloc(sizeof(Quartos));
    char n_quarto_lido [7];
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Quartos -> Checkin}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    ler_n_quarto(n_quarto_lido, 7);

    arq_quartos = fopen("./data/quartos.dat", "r+b");
    if (arq_quartos == NULL) {
        printf("\t Erro ao abrir o arquivo.\n");
        enter();
        return;
    }

    while (fread(quar, sizeof(Quartos), 1, arq_quartos)) {
        if ((strcmp(n_quarto_lido, quar->n_quarto) == 0) && (quar->status == 0)) {
            quar->status = True;
            encontrado = True;

            ler_cpf(quar->cpf, 18);
            ler_quan_pessoas(quar->quan_pessoas, 5);

            fseek(arq_quartos, (-1)*sizeof(Quartos), SEEK_CUR);
            fwrite(quar, sizeof(Quartos), 1, arq_quartos);

            limpa_tela();
            printf("*CHECK-IN REALIDO!*");
            exib_quarto(quar);
        }
    }

    enter();
    fclose(arq_quartos);

    if (!encontrado) {
        printf("\nQuarto indisponivel.\n");
        enter();
    }

    free(quar);
}

void list_quartos(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos *quar;
    quar = (Quartos*)malloc(sizeof(Quartos));
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#             {Quartos -> Quartos disponiveis}             #│\n");
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

    while (fread(quar, sizeof(Quartos), 1, arq_quartos)) {
        if (quar->status == 0) {
            printf("Quarto %s disponivel!\n", quar->n_quarto);
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

void check_out(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos *quar;
    quar = (Quartos*)malloc(sizeof(Quartos));
    char n_quarto_lido [7];
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Quartos -> Check-out}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    ler_n_quarto(n_quarto_lido, 7);

    arq_quartos = fopen("./data/quartos.dat", "r+b");
    if (arq_quartos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        enter();
        return;
    }

    while (fread(quar, sizeof(Quartos), 1, arq_quartos)) {
        if (strcmp(n_quarto_lido, quar->n_quarto) == 0) {
            exib_quarto(quar);
            enter();

            encontrado = True;
            quar->status = False;

            strcpy(quar->cpf, "-");
            strcpy(quar->quan_pessoas, "0");

            fseek(arq_quartos, (-1)*sizeof(Quartos), SEEK_CUR);
            fwrite(quar, sizeof(Quartos), 1, arq_quartos);

            printf("*CHECK-OUT REALIZADO COM SUCESSO!\n*");
            exib_quarto(quar);
        }
    }

    fclose(arq_quartos);

    if (!encontrado) {
        printf("\nQuarto não encontrado no banco de dados\n");
        enter();
    }

    free(quar);
}

void busc_quartos(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos *quar;
    quar = (Quartos*)malloc(sizeof(Quartos));
    char n_quarto_lido [7];
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                {Quartos -> Buscar quartos}               #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    ler_n_quarto(n_quarto_lido, 7);

    arq_quartos = fopen("./data/quartos.dat", "rb");
    if (arq_quartos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        enter();
        return;
    }
    
    while (fread(quar, sizeof(Quartos), 1, arq_quartos)) {
        if (strcmp(n_quarto_lido, quar->n_quarto) == 0) {
            encontrado = True;
            printf("\n");
            printf("*QUARTO ENCOTRADO!*\n");
            exib_quarto(quar);
            enter();
            return;
        }
    }

    if (!encontrado) {
        printf("*QUARTO NÃO ENCONTRADO!*");
        enter(); 
    }

    fclose(arq_quartos);
    free(quar);
}

void edit_quartos(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos *quar;
    quar = (Quartos*)malloc(sizeof(Quartos));
    char n_quarto_lido [7];
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                {Quartos -> Editar quartos}               #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    ler_n_quarto(n_quarto_lido,7);

    arq_quartos = fopen("./data/quartos.dat", "r+b");
    if (arq_quartos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        enter();
        return;
    }
    
    while (fread(quar, sizeof(Quartos), 1, arq_quartos)) {
        if (strcmp(n_quarto_lido, quar->n_quarto) == 0) {
            exib_quarto(quar);
            enter();
            switch_edit_quartos(quar);
            encontrado = True;

            fseek(arq_quartos, (-1)*sizeof(Quartos), SEEK_CUR);
            fwrite(quar, sizeof(Quartos), 1, arq_quartos);

            limpa_tela();
            exib_quarto(quar);
            enter();
        }
    }

    fclose(arq_quartos);

    if (!encontrado) {
        printf("Não encontrado no banco de dados.\n");
        enter();
    }
    
    free(quar);
}

void cad_quartos(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos *quar;
    quar = (Quartos*)malloc(sizeof(Quartos));

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#              {Quartos -> Cadastrar quartos}              #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    ler_n_quarto(quar->n_quarto, 7);

    arq_quartos = fopen("./data/quartos.dat", "ab");
    if (arq_quartos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        enter();
        return;
    }

    strcpy(quar->cpf, "-");
    strcpy(quar->quan_pessoas, "0");
    quar->status = False;

    fwrite(quar, sizeof(Quartos), 1, arq_quartos);

    printf("*QUARTO CADASTRADO*");
    exib_quarto(quar);
    enter();

    fclose(arq_quartos);
    free(quar);

}


void exib_quarto(Quartos *quar){
    printf("\n");
    printf("ID DO QUARTO: %s\n", quar->n_quarto);
    printf("CPF: %s\n", quar->cpf);
    printf("QUANTIDADE DE PESSOAS: %s\n", quar->quan_pessoas);
    printf("STATUS: %s\n", quar->status ? "OCUPADO" : "VAZIO");
}


char menu_edit_quartos(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│                                                            │\n");
    printf("│                          -Hospedes-                        │\n");
    printf("│                                                            │\n");
    printf("│────────────────────────────────────────────────────────────│\n");
    printf("│                                                            │\n");
    printf("│        [1] -> ID do quarto                                 │\n");
    printf("│        [2] -> CPF                                          │\n");
    printf("│        [3] -> Quan. de pessoas                             │\n");
    printf("│        [0] -> Voltar                                       │\n");
    printf("│                                                            │\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o numero do que deseja editar: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}


void switch_edit_quartos(Quartos *quar){
    char op;

    do {
        op = menu_edit_quartos();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                ler_n_quarto(quar->n_quarto, 7);
                break;
            case '2':
                ler_cpf(quar->cpf, 18);
                break;
            case '3':
                ler_quan_pessoas(quar->quan_pessoas, 5);
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0');
}