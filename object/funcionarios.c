#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.h"
#include "utilidades.h"

void modulo_funcionarios(void){

    char op;

    do {
        op = tela_funcionarios();
        switch (op) {
            case '1':
                cad_funcionarios();
                break;
            case '2':
                edit_funcionarios();
                break;
            case '3':
                exib_funcionarios();
                break;
            case '4':
                exclu_funcionarios();
                break;
        }
    } while (op != '0'); 
}

char tela_funcionarios(void){
    limpa_tela();

    char op;
    
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|                       -Funcionarios-                       |\n");
    printf("|                                                            |\n");
    printf("|────────────────────────────────────────────────────────────|\n");
    printf("|                                                            |\n");
    printf("|        [1] -> Cadastar                                     |\n");
    printf("|        [2] -> Editar informacoes                           |\n");
    printf("|        [3] -> Exibir funcionarios                          |\n");
    printf("|        [4] -> Excluir funcionarios                         |\n");
    printf("|        [0] -> Voltar                                       |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}


void cad_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;

    char cpf[18];
    char nome[55];
    char cell[18];

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#              {Funcionarios -> Cadastrar}              #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o CPF do funcionario:");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf("Digite o nome do funcionario:");
    scanf("%s", nome);
    getchar();
    printf("\n");
    printf("Digite o  telefone do funcionario:");
    scanf("%s", cell);
    getchar();
    printf("\n");

    arq_funcionarios = fopen("./data/funcionarios.csv", "at");
    if(arq_funcionarios == NULL){
        printf("\t Erro ao tentar abrir o arquivo de funcionarios.\n");
        printf("\t {Pressione ENTER para continuar...}\n");
        getchar();
        return;
    }
    fprintf(arq_funcionarios, "%s;%s;%s\n", cpf, nome, cell);
    fclose(arq_funcionarios);

    limpa_tela();
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#         {funcionario cadastrado com sucesso!}         #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("\nCPF: %s", cpf);
    printf("\nNOME: %s", nome);
    printf("\nTELEFONE: %s", cell);
    printf("\n");
    printf("\t {Pressione ENTER para continuar...}\n");
    getchar();
    printf("\n");
}


void edit_funcionarios(void){
    limpa_tela();

    char cpf[18];
    char nome[55];
    char cell[18];

    printf("\n");
    printf("┌──────────────────────────────────────────────────────────┐\n");
    printf("|##########################################################|\n");
    printf("|#                                                        #|\n");
    printf("|#                {Funcionarios -> Editar}                #|\n");
    printf("|#                                                        #|\n");
    printf("|##########################################################|\n");
    printf("└──────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite as novas informacoes do cliente!");
    printf("\n");
    printf("Digite o CPF do funcionario:");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf("Digite o nome do funcionario:");
    scanf("%s", nome);
    getchar();
    printf("\n");
    printf("Digite o telefone do funcionario:");
    scanf("%s", cell);
    getchar();
    printf("\n");

    limpa_tela();
    printf("┌────────────────────────────────────────────────────────┐\n");
    printf("|########################################################|\n");
    printf("|#                                                      #|\n");
    printf("|#                {Funcionario editado!}                #|\n");
    printf("|#                                                      #|\n");
    printf("|########################################################|\n");
    printf("└────────────────────────────────────────────────────────┘\n");

    printf("\n");
    printf("{Pressione ENTER para continuar...}");
    getchar();
    printf("\n");
}

void exib_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;

    char cpf[18];
    char cpf_lido[18];
    char nome[55];
    char cell[18];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────┐\n");
    printf("|########################################################|\n");
    printf("|#                                                      #|\n");
    printf("|#               {Funcionarios -> Exibir}               #|\n");
    printf("|#                                                      #|\n");
    printf("|########################################################|\n");
    printf("└────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o cpf do funcionario:");
    scanf("%s", cpf_lido);
    getchar();
    printf("\n");

    arq_funcionarios = fopen("./data/funcionarios.csv", "rt");
    if(arq_funcionarios == NULL){
        printf("\t Erro ao abrir o arquivo de funcionarios. \n");
        printf("\t {Pressione ENTER para continuar...}\n");
        getchar();
        return;
    }
    while(!feof(arq_funcionarios)){
        fscanf(arq_funcionarios, "%[^;]", cpf);
        fgetc(arq_funcionarios);
        fscanf(arq_funcionarios, "%[^;]", nome);
        fgetc(arq_funcionarios);
        fscanf(arq_funcionarios, "%[^\n]", cell);
        fgetc(arq_funcionarios);
        if(strcmp(cpf, cpf_lido) == 0) {
            printf("*FUNCIONARIO ENCONTRADO*");
            printf("\n");
            printf("\n CPF: %s\n", cpf);
            printf("\n NOME: %s\n", nome);
            printf("\n TELEFONE: %s", cell);
            printf("\n");
            printf("\t {Pressione ENTER para continuar...}\n");
            getchar();
            fclose(arq_funcionarios);
            return;
        }
    }
}

void exclu_funcionarios(void){
    limpa_tela();

    char cpf[18];
    //char nome[55];
    //char cell[18];

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#               {Funcionarios -> Excluir}               #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o cpf do funcionario:");
    scanf("%s", cpf);
    getchar();
    printf("\n");

    limpa_tela();
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#                {Funcionario excluido!}                #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("{Pressione ENTER para continuar...}");
    getchar();
    printf("\n");
}