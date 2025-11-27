#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospedes.h"
#include "utilidades.h"
#include "tela_voltar_menu.h"
#include "leitura.h"

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


void cad_hospedes(void){//
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
    if (verifica_cpf_hospedes(hos->cpf)) {
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

typedef struct novo_hos Novo_hos;

struct novo_hos {
    char* cpf;
    char* nome;
    char* cell;
    Novo_hos* prox;
};

void list_hospedes(void){
    limpa_tela();

    FILE *arq_hospedes;
    Hospedes hos;
    Novo_hos* lista = NULL;
    Novo_hos* novo;
    Novo_hos* anter;
    Novo_hos* atual;

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

    lista = NULL;
    while (fread(&hos, sizeof(Hospedes), 1, arq_hospedes)) {
        //if (hos.nome[0] == '\0') {
        //    continue; // Pula registros com nome vazio
        //}

        novo = (Novo_hos*)malloc(sizeof(Novo_hos));

        novo->nome = malloc(strlen(hos.nome) + 1);
        novo->cell = malloc(strlen(hos.cell) + 1);
        novo->cpf = malloc(strlen(hos.cpf) + 1);

        strcpy(novo->nome, hos.nome);
        strcpy(novo->cell, hos.cell);
        strcpy(novo->cpf, hos.cpf);

        if (lista == NULL) {
            lista = novo;
            novo->prox = NULL;
        }
        else if (strcasecmp(novo->nome, lista->nome) < 0) {
            novo->prox = lista;
            lista = novo;
        }
        else {
            anter = lista;
            atual = lista->prox;

            while (atual != NULL && strcasecmp(novo->nome, atual->nome) > 0) {
                anter = atual;
                atual = atual->prox;
            }

            anter->prox = novo;
            novo->prox = atual;
        }
    }
    fclose(arq_hospedes);


    printf("%-15s %-30s %-15s\n", "NOME", "CPF", "TELEFONE");
    printf("--------------- ------------------------------ ---------------\n");

    atual = lista;
    while (atual != NULL){
        printf("%-15s %-30s %-15s\n", atual->nome, atual->cpf, atual->cell);
        atual = atual->prox;
    }
    printf("--------------- ------------------------------ ---------------\n");

    atual = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(atual->nome);
        free(atual->cell);
        free(atual->cpf);
        free(atual);
        atual = lista;
    }

    enter();

}


void busc_hospedes(void){
    limpa_tela();

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*)malloc(sizeof(Hospedes));
    int encontrado = False;
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
            encontrado = True;
            printf("\n*ENCONTRADO*\n");
            exib_hospede(hos);
            enter();
        }
    }

    fclose(arq_hospedes);
    free(hos);

    if (!encontrado) {
        printf("Hospede não encontrado na base de dados!");
        enter();
    }

}


void exclu_hospedes(void){
    limpa_tela();

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*)malloc(sizeof(Hospedes));
    char cpf_lido [18];
    int escolha;
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
        if ((strcmp(hos->cpf, cpf_lido) == 0) && (hos->status)) {
            
            exib_hospede(hos);
            escolha = confirma_exclusao();
            if (escolha) {
                hos->status = False;
                encontrado = True;
                fseek(arq_hospedes, (-1)*sizeof(Hospedes), SEEK_CUR);
                fwrite(hos, sizeof(Hospedes), 1, arq_hospedes);
            } else if (!escolha){
                encontrado = -1;
                free(hos);
            }
        }
    }

    fclose(arq_hospedes);
    free(hos);

    switch (encontrado) {
        case 0:
            printf("Hospede não encontrado na base de dados!");
            enter();
            break;
        case 1:
            printf("Hospede excluido com sucesso!");
            enter();
            break;
        case -1:
            printf("Exclusão cancelada!");
            enter();
            break;
    }

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


int verifica_cpf_hospedes(const char *cpf_a_verificar){
    //recebe um cpf e verifica se ele já esta cadastrado
    FILE *arq_hospedes;
    Hospedes *hos_lido;
    hos_lido = (Hospedes*)malloc(sizeof(Hospedes));

    arq_hospedes = fopen("./data/hospedes.dat", "rb");
    if (arq_hospedes == NULL) {
        free(hos_lido);
        return False;
    }

    while (fread(hos_lido, sizeof(Hospedes), 1, arq_hospedes)) {
        if (strcmp(hos_lido->cpf, cpf_a_verificar) == 0) {
        return True;
        break;
        }
    }
    
    fclose(arq_hospedes);
    free(hos_lido);
    return False;
}


char* pega_nome_hospede(const char *cpf_hospede){
    //recebe um cpf e retorna o nome do hospede
    FILE *arq_hospedes;
    Hospedes *hos_lido;
    hos_lido = (Hospedes*)malloc(sizeof(Hospedes));
    static char nome_hospede [55];

    arq_hospedes = fopen("./data/hospedes.dat", "rb");
    if (arq_hospedes == NULL) {
        strcpy(nome_hospede, "Erro ao abrir o arquivo!");
        return nome_hospede;
    }

    while (fread(hos_lido, sizeof(Hospedes), 1, arq_hospedes)) {
        if (strcmp(hos_lido->cpf, cpf_hospede) == 0) {
            strncpy(nome_hospede, hos_lido->nome, sizeof(nome_hospede) - 1);
            nome_hospede[sizeof(nome_hospede) - 1] = '\0';
            fclose(arq_hospedes);
            free(hos_lido);
            return nome_hospede;
        }
    }
    
    fclose(arq_hospedes);
    free(hos_lido);
    strcpy(nome_hospede, "Hospede nao encontrado!");
    return nome_hospede;
}