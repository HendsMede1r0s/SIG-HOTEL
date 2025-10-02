#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "utilidades.h"

typedef struct clientes Clientes;

void modulo_clientes(void){

    char op;

    do {
        op = tela_clientes();
        switch (op) {
            case '1':
                cad_clientes();
                break;
            case '2':
                edit_clientes();
                break;
            case '3':
                exib_clientes();
                break;
            case '4':
                exclu_clientes();
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
    printf("│        [3] -> Exibir clientes                              │\n");
    printf("│        [4] -> Excluir clientes                             │\n");   
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

void cad_clientes(void){
    limpa_tela();

    FILE *arq_clientes;
    Clientes cli;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Clientes -> Cadastrar}                 #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cli.cpf, 18, "Digite o CPF do cliente:");
    input(cli.nome, 55, "Digite o nome do cliente:");
    input(cli.cell, 18, "Digite o telefone do cliente:");
    input(cli.n_quarto, 7, "Digite o numero do quarto do cliente:");

    arq_clientes = fopen("./data/clientes.csv", "at");
    if (arq_clientes == NULL) {
        printf("\t Erro ao abrir o arquivo de clientes!\n");
        enter();
        return;
    }
    fprintf(arq_clientes, "%s;%s;%s;%s\n", cli.cpf, cli.nome, cli.cell, cli.n_quarto);
    fclose(arq_clientes);

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#            {Clientes cadastrado com sucesso!}            #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("\nCPF: %s", cli.cpf);
    printf("\nNOME: %s", cli.nome);
    printf("\nTELEFONE: %s", cli.cell);
    printf("\nID DO QUARTO: %s", cli.n_quarto);
    enter();
}


void edit_clientes(void){
    limpa_tela();

    FILE *arq_clientes;
    FILE *arq_clientes_temp;
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
    input(cli.cpf_lido, 18, "Digite o CPF do cliente que deseja editar: ");

    arq_clientes = fopen("./data/clientes.csv", "rt");
    arq_clientes_temp = fopen("./data/clientes_temp.csv", "wt");
    if (arq_clientes == NULL || arq_clientes_temp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while (fscanf(arq_clientes, "%[^;];%[^;];%[^;]%[^\n]\n", cli.cpf, cli.nome, cli.cell, cli.n_quarto) == 4) {
        if(strcmp(cli.cpf, cli.cpf_lido) != 0) {
            fprintf(arq_clientes_temp, "%s;%s;%s;%s\n", cli.cpf, cli.nome, cli.cell, cli.n_quarto);
        }
        else {
            printf("*Digite as novas informaçoes do cliente com CPF %s*\n", cli.cpf_lido);
            input(cli.nome, 55, "Digite o nome do cliente: ");
            input(cli.cell, 18, "Digite o novo numero de telefone do cliente: ");
            input(cli.n_quarto, 7, "Digite o id do quarto do cliente: ");
            fprintf(arq_clientes_temp, "%s;%s;%s;%s\n", cli.cpf_lido, cli.nome, cli.cell, cli.n_quarto);
        }
        
    }

    fclose(arq_clientes);
    fclose(arq_clientes_temp);
    remove("./data/clientes.csv");
    rename("./data/clientes_temp.csv", "./data/clientes.csv");
    

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
    printf("Cliente com CPF %s editado com sucesso!\n", cli.cpf_lido);
    printf("CPF: %s\n", cli.cpf_lido);
    printf("NOME: %s\n", cli.nome);
    printf("TELEFONE: %s\n", cli.cell);
    printf("ID DO QUARTO: %s\n", cli.n_quarto);
    enter();
}
    
void exib_clientes(void){
    limpa_tela();

    FILE *arq_clientes;
    Clientes cli;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Clientes -> Exibir}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cli.cpf_lido, 18, "Digite o CPF a ser pesquisado: ");

    arq_clientes = fopen("./data/clientes.csv", "rt");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }
    while (fscanf(arq_clientes, "%[^;];%[^;];%[^;];%[^\n]\n", cli.cpf, cli.nome, cli.cell, cli.n_quarto) == 4) {
        if (strcmp(cli.cpf, cli.cpf_lido) == 0) {
            printf("\n*CLIENTE ENCONTRADO*\n");
            printf("CPF: %s\n", cli.cpf);
            printf("NOME: %s\n", cli.nome);
            printf("TELEFONE: %s\n", cli.cell);
            printf("ID DO QUARTO: %s\n", cli.n_quarto);
            enter();
            fclose(arq_clientes);
            return;
        }
     }
}

void exclu_clientes(void){
    limpa_tela();

    FILE *arq_clientes;
    FILE *arq_clientes_temp;
    Clientes cli;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Clientes -> Excluir}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cli.cpf_lido, 18, "Digite o CPF do clientes a ser excluido: ");

    arq_clientes = fopen("./data/clientes.csv", "rt");
    arq_clientes_temp = fopen("./data/clientes_temp.csv", "wt");
    if (arq_clientes == NULL || arq_clientes_temp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while(fscanf(arq_clientes, "%[^;];%[^;];%[^;];%[^\n]\n", cli.cpf, cli.nome, cli.cell, cli.n_quarto) == 4) {
        if(strcmp(cli.cpf, cli.cpf_lido) != 0) {
            fprintf(arq_clientes_temp, "%s;%s;%s;%s\n", cli.cpf, cli.nome, cli.cell, cli.n_quarto);
        }
    }
    
    fclose(arq_clientes);
    fclose(arq_clientes_temp);
    remove("./data/clientes.csv");
    rename("./data/clientes_temp.csv", "./data/clientes.csv");

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
    printf("Clientes com CPF %s foi excluido com sucesso!\n", cli.cpf_lido);
    enter();
}