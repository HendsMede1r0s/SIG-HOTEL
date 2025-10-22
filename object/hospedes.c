#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospedes.h"
#include "utilidades.h"
#include "leitura.h"
#include "tela_voltar_menu.h"

typedef struct hospedes Hospedes;

void modulo_hospedes(void){

    char op;

    do {
        op = tela_hospedes();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                cad_hospedes();
                break;
            case '2':
                edit_hospedes();
                break;
            case '3':
                list_hospedes();
                break;
            case '4':
                busc_hospedes();
                break;
            case '5':
                exclu_hospedes();
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0'); 
}

char tela_hospedes(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│                                                            │\n");
    printf("│                          -Hospedes-                        │\n");
    printf("│                                                            │\n");
    printf("│────────────────────────────────────────────────────────────│\n");
    printf("│                                                            │\n");
    printf("│        [1] -> Cadastar                                     │\n");
    printf("│        [2] -> Editar informacoes                           │\n");
    printf("│        [3] -> Listar hospedes                              │\n");
    printf("│        [4] -> Buscar hospedes                              │\n");
    printf("│        [5] -> Excluir hospedes                             │\n");
    printf("│        [0] -> Voltar                                       │\n");
    printf("│                                                            │\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opçao: ");
    scanf(" %c", &op);
    getchar();
    printf("\n");
    return(op);
}


void cad_hospedes(void){
    limpa_tela();

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*)malloc(sizeof(Hospedes));

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Hospedes -> Cadastrar}                 #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    ler_cpf(hos->cpf, 18);
    ler_nome(hos->nome, 55);
    ler_cell(hos->cell, 18);
    ler_n_quarto(hos->n_quarto,7);

    hos->status = True;
    arq_hospedes = fopen("./data/hospedes.dat", "ab");
    if (arq_hospedes == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    fwrite(hos, sizeof(Hospedes), 1, arq_hospedes);
    fclose(arq_hospedes);

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#             {Hospede cadastrado com sucesso!}            #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    exib_hospede(hos);
    

    free(hos);
    enter();
}


void edit_hospedes(void){
    limpa_tela();

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*)malloc(sizeof(Hospedes));
    char cpf_lido [18];
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Hospedes -> Editar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    ler_cpf(cpf_lido, 18);

    arq_hospedes = fopen("./data/hospedes.dat", "r+b");
    if (arq_hospedes == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while (fread(hos, sizeof(Hospedes), 1, arq_hospedes)) {
        if (strcmp(hos->cpf, cpf_lido) == 0) {
            encontrado = True;

            fseek(arq_hospedes, (-1)*sizeof(Hospedes), SEEK_CUR);
            fwrite(hos, sizeof(Hospedes), 1, arq_hospedes);

            limpa_tela();
            exib_hospede(hos);
            enter();
        }

    }

    fclose(arq_hospedes);
    
    if (!encontrado) {
        printf("Não encontrado no banco de dados.\n");
        enter();
    }
    
    free(hos);

}


void list_hospedes(void){
    limpa_tela();

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*)malloc(sizeof(Hospedes));

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Hospedes -> Listar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");

    arq_hospedes = fopen("./data/hospedes.dat", "rb");
    if (arq_hospedes == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while(fread(hos, sizeof(Hospedes), 1, arq_hospedes)){
        exib_hospede(hos);
    }

    fclose(arq_hospedes);
    free(hos);
    enter();
}


void busc_hospedes(void){
    limpa_tela();

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*)malloc(sizeof(Hospedes));
    char cpf_lido [18];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Hospedes -> Buscar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    ler_cpf(cpf_lido, 18);

    arq_hospedes = fopen("./data/hospedes.dat", "rb");
    if (arq_hospedes == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while (fread(hos, sizeof(Hospedes), 1, arq_hospedes)) {
        if ((strcmp(hos->cpf, cpf_lido) == 0) && (hos->status)) {
            printf("\n*ENCONTRADO*\n");
            exib_hospede(hos);
            enter();
        }
    }

    fclose(arq_hospedes);
    free(hos);
}


void exclu_hospedes(void){
    limpa_tela();

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*)malloc(sizeof(Hospedes));
    char cpf_lido [18];
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Hospedes -> Excluir}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    ler_cpf(cpf_lido, 18);

    arq_hospedes = fopen("./data/hospedes.dat", "r+b");
    if (arq_hospedes == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while (fread(hos, sizeof(Hospedes), 1, arq_hospedes) && (!encontrado)) {
        if (strcmp(hos->cpf, cpf_lido) == 0) {
            exib_hospede(hos);
            hos->status = False;
            encontrado = True;
            fseek(arq_hospedes, (-1)*sizeof(Hospedes), SEEK_CUR);
            fwrite(hos, sizeof(Hospedes), 1, arq_hospedes);
        }
    }

    fclose(arq_hospedes);

    if (!encontrado) {
        printf("Hospede não encontrado no banco de dados.\n");
        enter();
    }

    if (encontrado) {
        limpa_tela();
        printf("\n");
        printf("┌────────────────────────────────────────────────────────────┐\n");
        printf("│############################################################│\n");
        printf("│#                                                          #│\n");
        printf("│#                    {Hospede excluido!}                   #│\n");
        printf("│#                                                          #│\n");
        printf("│############################################################│\n");
        printf("└────────────────────────────────────────────────────────────┘\n");
        printf("\n");
        printf("Hospede com CPF %s foi excluido com sucesso!\n", cpf_lido);
        enter();
    }

}


void exib_hospede(Hospedes *hos){
    printf("\n");
    printf("CPF: %s\n", hos->cpf);
    printf("NOME: %s\n", hos->nome);
    printf("TELEFONE: %s\n", hos->cell);
    printf("ID DO QUARTO: %s\n", hos->n_quarto);
    printf("STATUS: %s\n", hos->status ? "Ativo" : "Excluido");
}