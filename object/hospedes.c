#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospedes.h"
#include "utilidades.h"
#include "telas.h"
#include "leitura.h"
#include "relatorio.h"

typedef struct hospedes Hospedes;
typedef struct novo_hos Novo_hos;

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

    char op;

    tela_menu_hospedes();
    printf("Digite uma opçao: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return(op);
}


void cad_hospedes(void){

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*)malloc(sizeof(Hospedes));

    tela_busc_hospedes();
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
    printf("*Hóspede cadastrado com sucesso!*\n");
    exib_hospede(hos);
    free(hos);
    enter();
}


void edit_hospedes(void){

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*)malloc(sizeof(Hospedes));
    char cpf_lido [18];
    int encontrado = False;

    tela_edit_hospedes();
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
            break; //adicionado para previnir bug no windows
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

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*)malloc(sizeof(Hospedes));
    Novo_hos *lista = NULL;  // Cabeça da lista encadeada (inicialmente vazia)
    Novo_hos *novo;
    Novo_hos *anter;
    Novo_hos *atual;

    tela_list_hospedes();

    arq_hospedes = fopen("./data/hospedes.dat", "rb");
    if (arq_hospedes == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    lista = NULL;

    // Aloca e copia strings do arquivo para a lista
    while (fread(hos, sizeof(Hospedes), 1, arq_hospedes)) {

        novo = (Novo_hos*)malloc(sizeof(Novo_hos));

        // Aloca e copia strings do arquivo para a lista
        novo->nome = malloc(strlen(hos->nome) + 1); // Aloca memória para nome (+1 para \0)
        novo->cell = malloc(strlen(hos->cell) + 1); // Aloca memória para telefone
        novo->cpf = malloc(strlen(hos->cpf) + 1); // Aloca memória para CPF

        strcpy(novo->nome, hos->nome); // Copia nome do arquivo para o nó
        strcpy(novo->cell, hos->cell); // Copia telefone do arquivo para o nó
        strcpy(novo->cpf, hos->cpf); // Copia CPF do arquivo para o nó
        novo->status = hos->status; // Copia status do hóspede

        // Caso 1: Lista está vazia (primeira inserção)
        if (lista == NULL) {
            lista = novo; // Novo nó se torna a cabeça da lista
            novo->prox = NULL; // Próximo nó é NULL (fim da lista)
        }
        
        // Caso 2: Inserção no início (antes da cabeça)
        else if (strcasecmp(novo->nome, lista->nome) < 0) {
            novo->prox = lista; // Novo nó aponta para o antigo primeiro nó
            lista = novo; // Novo nó se torna a nova cabeça da lista
        }
        
        // Caso 3: Inserção no meio ou fim da lista
        else {
            anter = lista; // Começa pela cabeça da lista
            atual = lista->prox; // Próximo nó para comparação

            // Percorre a lista para encontrar a posição correta ou o fim
            while (atual != NULL && strcasecmp(novo->nome, atual->nome) > 0) {
                anter = atual; // Avança o anterior
                atual = atual->prox; // Avança o atual
            }
            
            // Insere o novo nó entre anter e atual
            anter->prox = novo; // Nó anterior aponta para o novo
            novo->prox = atual; // Novo nó aponta para o atual (pode ser NULL)
        }
    }
    fclose(arq_hospedes);


    printf("%-15s %-30s %-15s\n", "NOME", "CPF", "TELEFONE");
    printf("--------------- ------------------------------ ---------------\n");

    atual = lista; // Começa pela cabeça da lista
    while (atual != NULL){
        printf("%-15s %-30s %-15s\n", atual->nome, atual->cpf, atual->cell);
        atual = atual->prox; // Avança para próximo nó
    }
    printf("--------------- ------------------------------ ---------------\n");

    // Liberar memória
    atual = lista; // Começa pela cabeça para liberar memória
    while (lista != NULL) {
        lista = lista->prox; // Avança cabeça para próximo elemento
        free(atual->nome);
        free(atual->cell);
        free(atual->cpf);
        free(atual);
        atual = lista; // Atualiza ponteiro para próximo nó a ser liberado
    }
    enter();

}


void busc_hospedes(void){

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*)malloc(sizeof(Hospedes));
    int encontrado = False;
    char cpf_lido [18];

    tela_busc_hospedes();
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
            break; //adicionado para previnir bug no windows
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

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*)malloc(sizeof(Hospedes));
    char cpf_lido [18];
    int escolha;
    int encontrado = False;

    tela_exclu_hospedes();
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
                break; //adicionado para previnir bug no windows
            } else if (!escolha){
                encontrado = -1;
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
    // " ? " é um operador condicional que funciona como um if simplificado
    // Exibe "Ativo" se hos->status for True (1) e "Excluido" se for False (0)
}


char menu_edit_hospedes(void){

    char op;

    tela_menu_edit_hospedes();
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
                exib_hospede(hos);
                enter();
                break;
            case '2':
                ler_nome(hos->nome, 55);
                exib_hospede(hos);
                enter();
                break;
            case '3':
                ler_cell(hos->cell, 18);
                exib_hospede(hos);
                enter();
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