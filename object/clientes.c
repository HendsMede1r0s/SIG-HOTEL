#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "utilidades.h"

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
    char cpf [18];
    char nome [55];
    char cell [18];
    char n_quarto [7];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Clientes -> Cadastrar}                 #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o CPF do cliente:");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf("Digite o nome do cliente:");
    scanf("%s", nome);
    getchar();
    printf("\n");
    printf("Digite o telefone do cliente:");
    scanf("%s", cell);
    getchar();
    printf("\n");
    printf("Digite o numero do quarto do cliente:");
    scanf("%s", n_quarto);
    getchar();
    printf("\n");

    arq_clientes = fopen("./data/clientes.csv", "at");
    if (arq_clientes == NULL) {
        printf("\t Erro ao abrir o arquivo de clientes!\n");
        printf("\t {Pressione ENTER para continuar...}\n");
        getchar();
        return;
    }
    fprintf(arq_clientes, "%s;%s;%s;%s\n", cpf, nome, cell, n_quarto);
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
    printf("\nCPF: %s", cpf);
    printf("\nNOME: %s", nome);
    printf("\nTELEFONE: %s", cell);
    printf("\nID DO QUARTO: %s", n_quarto);
    printf("\n");
    printf("\t {Pressione ENTER para continuar...}\n");
    getchar();
    printf("\n");
}


void edit_clientes(void){
    limpa_tela();

    char cpf [18];
    char nome [55];
    char cell [18];
    char n_quarto [7];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Clientes -> Editar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite as novas informaçoes do cliente.");
    printf("\n");
    printf("Digite o CPF do cliente:");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf("Digite o nome do cliente:");
    scanf("%s", nome);
    getchar();
    printf("\n");
    printf("Digite o telefone do cliente:");
    scanf("%s", cell);
    getchar();
    printf("\n");
    printf("Digite o numero do quarto do cliente:");
    scanf("%s", n_quarto);
    getchar();
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
    printf("{Pressione ENTER para continuar...}");
    getchar();
    printf("\n");
}
    
void exib_clientes(void){
    limpa_tela();

    FILE *arq_clientes;
    char cpf_lido [18];
    char cpf [18];
    char nome [55];
    char cell [18];
    char n_quarto [7];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Clientes -> Exibir}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cpf_lido, 18, "Digite o CPF a ser pesquisado: ");
    printf("\n");

    arq_clientes = fopen("./data/clientes.csv", "rt");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        printf("{Pressione ENTER para continuar...}");
        getchar();
        return;
    }
    while (!feof(arq_clientes)){
        fscanf(arq_clientes, "%[^;]", cpf);
        fgetc(arq_clientes);
        fscanf(arq_clientes, "%[^;]", nome);
        fgetc(arq_clientes);
        fscanf(arq_clientes, "%[^;]", cell);
        fgetc(arq_clientes);
        fscanf(arq_clientes, "%[^\n]", n_quarto);
        fgetc(arq_clientes);

        if (strcmp(cpf, cpf_lido) == 0)
        {
            printf("\n*CLIENTE ENCONTRADO*\n");
            printf("CPF: %s\n", cpf);
            printf("NOME: %s\n", nome);
            printf("TELEFONE: %s\n", cell);
            printf("ID DO QUARTO: %s\n", n_quarto);
            printf("{Pressione ENTER para continuar...}");
            getchar();
            fclose(arq_clientes);
            return;
        }
     }
}

void exclu_clientes(void){
    limpa_tela();

    FILE *arq_clientes;
    FILE *arq_clientes_temp;
    char cpf [18];
    char cpf_lido [18];
    char nome [55];
    char cell [18];
    char n_quarto [7];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Clientes -> Excluir}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cpf_lido, 18, "Digite o CPF do clientes a ser excluido: ");
    printf("\n");

    arq_clientes = fopen("./data/clientes.csv", "rt");
    arq_clientes_temp = fopen("./data/clientes_temp.csv", "wt");
    if (arq_clientes == NULL || arq_clientes_temp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        printf("{Pressione ENTER para continuar...}");
        getchar();
        return;
    }

    while(fscanf(arq_clientes, "%[^;];%[^;];%[^;];%[^\n]\n", cpf, nome, cell, n_quarto) == 4) {
        if(strcmp(cpf, cpf_lido) != 0) {
            fprintf(arq_clientes_temp, "%s;%s;%s;%s\n", cpf, nome, cell, n_quarto);
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
    printf("Clientes com CPF %s foi excluido com sucesso!\n", cpf_lido);
    printf("{Pressione ENTER para continuar...}");
    getchar();
    printf("\n");
}