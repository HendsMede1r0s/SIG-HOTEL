#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "utilidades.h"
#include "tela_voltar_menu.h"

typedef struct clientes Clientes;

void modulo_clientes(void){

    char op;

    do {
        op = tela_clientes();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                cad_clientes();
                break;
            case '2':
                edit_clientes();
                break;
            case '3':
                list_clientes();
                break;
            case '4':
                busc_clientes();
                break;
            case '5':
                exclu_clientes();
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0'); 
}

char tela_clientes(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│                                                            │\n");
    printf("│                          -Clientes-                        │\n");
    printf("│                                                            │\n");
    printf("│────────────────────────────────────────────────────────────│\n");
    printf("│                                                            │\n");
    printf("│        [1] -> Cadastar                                     │\n");
    printf("│        [2] -> Editar informacoes                           │\n");
    printf("│        [3] -> Listar clientes                              │\n");
    printf("│        [4] -> Buscar clientes                              │\n");
    printf("│        [5] -> Excluir clientes                             │\n");
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


void cad_clientes(void){
    limpa_tela();

    FILE *arq_clientes;
    Clientes *cli;
    cli = (Clientes*)malloc(sizeof(Clientes));

    //malloc puxa a memoria do tamanho do struct
    //atribui o endereço disso para a variavel tipo ponteiro cli

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Clientes -> Cadastrar}                 #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cli->cpf, 18, "Digite o CPF do cliente: ");
    input(cli->nome, 55, "Digite o nome do cliente: ");
    input(cli->cell, 18, "Digite o numero telefone do cliente: ");
    input(cli->n_quarto, 7, "Digite o ID do quarto do cliente: ");

    cli->status = True;
    arq_clientes = fopen("./data/clientes.dat", "ab");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    fwrite(cli, sizeof(Clientes), 1, arq_clientes);

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#             {Cliente cadastrado com sucesso!}            #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("CPF: %s\n", cli->cpf);
    printf("NOME: %s\n", cli->nome);
    printf("TELEFONE: %s\n", cli->cell);
    printf("NUMERO DO QUARTO: %s\n", cli->n_quarto);

    fclose(arq_clientes);
    free(cli);
    enter();
}


void edit_clientes(void){
    limpa_tela();

    Clientes cli;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Clientes -> Editar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                    {Cliente editado!}                    #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Cliente com CPF %s editado com sucesso!\n", cli.cpf);
    printf("CPF: %s\n", cli.cpf);
    printf("NOME: %s\n", cli.nome);
    printf("TELEFONE: %s\n", cli.cell);
    printf("ID DO QUARTO: %s\n", cli.n_quarto);
    enter();
}


void list_clientes(void){
    limpa_tela();

    FILE *arq_clientes;
    Clientes *cli;
    cli = (Clientes*)malloc(sizeof(Clientes));

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Clientes -> Listar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");

    arq_clientes = fopen("./data/clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while(fread(cli, sizeof(Clientes), 1, arq_clientes)){
        printf("\n");
        printf("CPF: %s\n", cli->cpf);
        printf("NOME: %s\n", cli->nome);
        printf("TELEFONE: %s\n", cli->cell);
        printf("NUMERO DO QUARTO: %s\n", cli->n_quarto);  
    }
    fclose(arq_clientes);
    free(cli);
    enter();
}


void busc_clientes(void){
    limpa_tela();

    FILE *arq_clientes;
    Clientes *cli;
    cli = (Clientes*)malloc(sizeof(Clientes));
    char cpf_lido [18];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Clientes -> Buscar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cpf_lido, 18, "Digite o CPF a ser pesquisado: ");

    arq_clientes = fopen("./data/clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while (fread(cli, sizeof(Clientes), 1, arq_clientes)) {
        if ((strcmp(cpf_lido, cli->cpf) == 0) && (cli->status)) {
            printf("\n*CLIENTE ENCONTRADO*\n");
            printf("CPF: %s\n", cli->cpf);
            printf("NOME: %s\n", cli->nome);
            printf("TELEFONE: %s\n", cli->cell);
            printf("ID DO QUARTO: %s\n", cli->n_quarto);
            fclose(arq_clientes);
            free(cli);
            enter();
            return;
        }
    }
    printf("\n*CLIENTE COM CPF %s NAO ENCONTRADO*\n", cpf_lido);
    fclose(arq_clientes);
    free(cli);
    enter();
}


void exclu_clientes(void){
    limpa_tela();

    FILE *arq_clientes;
    Clientes *cli;
    cli = (Clientes*)malloc(sizeof(Clientes));
    char cpf_lido [18];
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Clientes -> Excluir}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cpf_lido, 18, "Digite o CPF do cliente a ser excluido: ");

    arq_clientes = fopen("./data/clientes.dat", "r+b");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while (fread(cli, sizeof(Clientes), 1, arq_clientes) && (!encontrado)) {
        if (strcmp(cli->cpf, cpf_lido) == 0) {
            cli->status = False;
            encontrado = True;
            fseek(arq_clientes, (-1)*sizeof(Clientes), SEEK_CUR);
            fwrite(cli, sizeof(Clientes), 1, arq_clientes);
        }
    }

    fclose(arq_clientes);
    free(cli);

    if (!encontrado) {
        printf("Cliente não encontrado no banco de dados.\n");
        enter();
        return;
    }

    if (encontrado) {
        limpa_tela();
        printf("\n");
        printf("┌────────────────────────────────────────────────────────────┐\n");
        printf("│############################################################│\n");
        printf("│#                                                          #│\n");
        printf("│#                    {Cliente excluido!}                   #│\n");
        printf("│#                                                          #│\n");
        printf("│############################################################│\n");
        printf("└────────────────────────────────────────────────────────────┘\n");
        printf("\n");
        printf("Clientes com CPF %s foi excluido com sucesso!\n", cpf_lido);
        enter();
    }
}