#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.h"
#include "utilidades.h"

typedef struct funcionarios Funcionarios;

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
    Funcionarios fun;

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#              {Funcionarios -> Cadastrar}              #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(fun.cpf, 18, "Digite o cpf do funcionario:");
    input(fun.nome, 55, "Digite o nome do funcionario:");
    input(fun.cell, 18, "Digite o telefone do funcionario:");

    arq_funcionarios = fopen("./data/funcionarios.csv", "at");
    if(arq_funcionarios == NULL){
        printf("\t Erro ao tentar abrir o arquivo de funcionarios.\n");
        enter();
        return;
    }
    fprintf(arq_funcionarios, "%s;%s;%s\n", fun.cpf, fun.nome, fun.cell);
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
    printf("CPF: %s", fun.cpf);
    printf("NOME: %s", fun.nome);
    printf("TELEFONE: %s", fun.cell);
    enter();
}


void edit_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    FILE *arq_funcionarios_temp;
    Funcionarios fun;

    printf("\n");
    printf("┌──────────────────────────────────────────────────────────┐\n");
    printf("|##########################################################|\n");
    printf("|#                                                        #|\n");
    printf("|#                {Funcionarios -> Editar}                #|\n");
    printf("|#                                                        #|\n");
    printf("|##########################################################|\n");
    printf("└──────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(fun.cpf_lido, 18, "Digite o CPF do funcionario que deseja editar:");

    arq_funcionarios = fopen("./data/funcionarios.csv", "rt");
    arq_funcionarios_temp = fopen("./data/funcionarios_temp.csv", "wt");
    if(arq_funcionarios == NULL || arq_funcionarios_temp == NULL){
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while(fscanf(arq_funcionarios, "%[^;];%[^;];%[^\n]\n", fun.cpf, fun.nome, fun.cell)== 3){
        if(strcmp(fun.cpf, fun.cpf_lido)!= 0){
            fprintf(arq_funcionarios_temp, "%s,%s,%s\n", fun.cpf, fun.nome, fun.cell);
        }
        else{
            printf("*Digite as novas informaçoes do funcionario com CPF: %s\n*", fun.cpf_lido);
            input(fun.nome, 55, "Digite o nome do funcionario: ");
            input(fun.cell, 18, "Digite o telefone do funcionario: ");
            fprintf(arq_funcionarios_temp, "%s;%s;%s", fun.cpf_lido, fun.nome, fun.cell);
        }
    }

    fclose(arq_funcionarios);
    fclose(arq_funcionarios_temp);
    remove("./data/funcionarios.csv");
    rename("./data/funcionarios_temp.csv", "./data/funcionarios.csv");

    limpa_tela();
    printf("┌────────────────────────────────────────────────────────┐\n");
    printf("|########################################################|\n");
    printf("|#                                                      #|\n");
    printf("|#                {Funcionario editado!}                #|\n");
    printf("|#                                                      #|\n");
    printf("|########################################################|\n");
    printf("└────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Funcionario com CPF %s foi editado com sucesso!\n", fun.cpf_lido);
    printf("CPF: %s\n", fun.cpf_lido);
    printf("NOME: %s\n", fun.nome);
    printf("TELEFONE: %s\n", fun.cell);
    enter();
}

void exib_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    Funcionarios fun;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────┐\n");
    printf("|########################################################|\n");
    printf("|#                                                      #|\n");
    printf("|#               {Funcionarios -> Exibir}               #|\n");
    printf("|#                                                      #|\n");
    printf("|########################################################|\n");
    printf("└────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(fun.cpf_lido, 18, "Digite o CPF do funcionario:");

    arq_funcionarios = fopen("./data/funcionarios.csv", "rt");
    if(arq_funcionarios == NULL){
        printf("\t Erro ao abrir o arquivo de funcionarios. \n");
        enter();
        return;
    }
    while(fscanf(arq_funcionarios, "%[^;];%[^;];%[^\n]\n", fun.cpf, fun.nome, fun.cell) == 3){
        if(strcmp(fun.cpf, fun.cpf_lido) == 0){
            printf("*FUNCIONARIO ENCONTRADO!*\n");
            printf("CPF: %s\n", fun.cpf);
            printf("NOME: %s\n", fun.nome);
            printf("TELEFONE: %s\n", fun.cell);
            enter();
            return;
        }
    }
    fclose(arq_funcionarios);
    enter();
}

void exclu_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    FILE *arq_funcionarios_temp;
    Funcionarios fun;

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#               {Funcionarios -> Excluir}               #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(fun.cpf_lido, 18, "Digite o CPF do funcionario a ser excluido:");

    arq_funcionarios = fopen("./data/funcionarios.csv", "rt");
    arq_funcionarios_temp = fopen("./data/funcionarios_temp.csv", "wt");
    if(arq_funcionarios == NULL || arq_funcionarios_temp == NULL){
        printf("Erro ao abrir o arquivo!");
        enter();
        return;
    }

    while(fscanf(arq_funcionarios, "%[^;];%[^;];%[\n]\n", fun.cpf, fun.nome, fun.cell) == 3){
        if(strcmp(fun.cpf, fun.cpf_lido) != 0){
            fprintf(arq_funcionarios_temp, "%s;%s;%s\n", fun.cpf, fun.nome, fun.cell);
        }
    }

    fclose(arq_funcionarios);
    fclose(arq_funcionarios_temp);
    remove("./data/funcionarios.csv");
    rename("./data/funcionarios_temp.csv", "./data/funcionarios.csv");

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
    printf("Funcionario com CPF %s foi excluido com sucesso!\n", fun.cpf_lido);
    enter();
}