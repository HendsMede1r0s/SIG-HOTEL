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
    scanf("%c", &op);
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
    if (verifica_cpf(hos->cpf)) {
        printf("CPF já cadastrado no sistema!");
        enter();
        free(hos);
        return;
    }
    ler_nome(hos->nome, 55);
    ler_cell(hos->cell, 18);

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
    enter();
    free(hos);
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
            exib_hospede(hos);
            enter();
            switch_edit_hospedes(hos);
            encontrado = True;

            fseek(arq_hospedes, (-1)*sizeof(Hospedes), SEEK_CUR);
            fwrite(hos, sizeof(Hospedes), 1, arq_hospedes);

            limpa_tela();
            exib_hospede(hos);
            enter();
        }

    }

    fclose(arq_hospedes);
    free(hos);
    
    if (!encontrado) {
        printf("Não encontrado no banco de dados.\n");
        enter();
    }
    
    

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

    printf("%-15s %-30s %-15s\n", "CPF", "NOME", "TELEFONE");
    printf("--------------- ------------------------------ ---------------\n");
    while (fread(hos, sizeof(Hospedes), 1, arq_hospedes)){
        if (hos->status) {
            printf("%-15s %-30s %-15s\n", hos->cpf, hos->nome, hos->cell);
        }
    }
    printf("--------------- ------------------------------ ---------------\n");

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
    enter();

}


void exib_hospede(Hospedes *hos){
    printf("\n");
    printf("CPF: %s\n", hos->cpf);
    printf("NOME: %s\n", hos->nome);
    printf("TELEFONE: %s\n", hos->cell);
    printf("STATUS: %s\n", hos->status ? "Ativo" : "Excluido");
}


char menu_edit_hospedes(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│                                                            │\n");
    printf("│                          -Hospedes-                        │\n");
    printf("│                                                            │\n");
    printf("│────────────────────────────────────────────────────────────│\n");
    printf("│                                                            │\n");
    printf("│        [1] -> CPF                                          │\n");
    printf("│        [2] -> Nome                                         │\n");
    printf("│        [3] -> Telefone                                     │\n");
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


void switch_edit_hospedes(Hospedes *hos){

    char op;

    do {
        op = menu_edit_hospedes();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                ler_cpf(hos->cpf, 18);
                break;
            case '2':
                ler_nome(hos->nome, 55);
                break;
            case '3':
                ler_cell(hos->cell, 18);
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0');
}


int verifica_cpf(const char *cpf_a_verificar){
    //recebe um cpf e verifica se ele já esta cadastrado
    FILE *arq_hospedes;
    Hospedes *hos_lido;
    hos_lido = (Hospedes*)malloc(sizeof(Hospedes));
    int encontrado = 0;

    arq_hospedes = fopen("./data/hospedes.dat", "rb");
    if (arq_hospedes == NULL) {
        free(hos_lido);
        return False;
    }

    while (fread(hos_lido, sizeof(Hospedes), 1, arq_hospedes) == 1) {
        if (strcmp(hos_lido->cpf, cpf_a_verificar) == 0) {
        encontrado = 1;
        break;
        }
    }
    
    fclose(arq_hospedes);
    free(hos_lido);
    return encontrado;
}