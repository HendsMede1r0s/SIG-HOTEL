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
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#              {Funcionarios -> Cadastrar}              #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(fun->cpf, 18, "Digite o cpf do funcionario:");
    input(fun->nome, 55, "Digite o nome do funcionario:");
    input(fun->cell, 18, "Digite o telefone do funcionario:");

    arq_funcionarios = fopen("./data/funcionarios.dat", "ab");
    if(arq_funcionarios == NULL){
        printf("\t Erro ao tentar abrir o arquivo de funcionarios.\n");
        enter();
        return;
    }
    fwrite(fun, sizeof(Funcionarios), 1, arq_funcionarios);
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
    printf("\nCPF: %s", fun->cpf);
    printf("\nNOME: %s", fun->nome);
    printf("\nTELEFONE: %s", fun->cell);
    enter();
    free(fun);
}


void edit_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    FILE *arq_funcionarios_temp;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios))
    char cpf_lido[18];

    printf("\n");
    printf("┌──────────────────────────────────────────────────────────┐\n");
    printf("|##########################################################|\n");
    printf("|#                                                        #|\n");
    printf("|#                {Funcionarios -> Editar}                #|\n");
    printf("|#                                                        #|\n");
    printf("|##########################################################|\n");
    printf("└──────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cpf_lido, 18, "Digite o CPF do funcionario que deseja editar:");

    arq_funcionarios = fopen("./data/funcionarios.dat", "rb")
    arq_funcionarios_temp = fopen("./data/funcionarios_temp.dat", "wb");
    if(arq_funcionarios == NULL || arq_funcionarios_temp == NULL){
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while(fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)){
        if(strcmp(cpf_lido, fun->cpf) == 0){
            printf("*Digite as novas informaçoes do funcionario com CPF: %s\n*", cpf_lido);
            input(fun->nome, 55, "Digite o nome do funcionario: ");
            input(fun->cell, 18, "Digite o telefone do funcionario: ");
            input(fun->cell, 18, "Digite o telefone do funcionario: ");
            fprintf(arq_funcionarios_temp, "%s;%s;%s\n", cpf_lido, fun->nome, fun->cell);
        }
    }

    fclose(arq_funcionarios);
    fclose(arq_funcionarios_temp);
    remove("./data/funcionarios.dat");
    rename("./data/funcionarios_temp.dat", "./data/funcionarios.dat");

    limpa_tela();
    printf("┌────────────────────────────────────────────────────────┐\n");
    printf("|########################################################|\n");
    printf("|#                                                      #|\n");
    printf("|#                {Funcionario editado!}                #|\n");
    printf("|#                                                      #|\n");
    printf("|########################################################|\n");
    printf("└────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Funcionario com CPF %s foi editado com sucesso!\n", cpf_lido);
    printf("CPF: %s\n", cpf_lido);
    printf("NOME: %s\n", fun->nome);
    printf("TELEFONE: %s\n", fun->cell);
    free(fun);
    enter();
}

void exib_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    char cpf_lido[18];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────┐\n");
    printf("|########################################################|\n");
    printf("|#                                                      #|\n");
    printf("|#               {Funcionarios -> Exibir}               #|\n");
    printf("|#                                                      #|\n");
    printf("|########################################################|\n");
    printf("└────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cpf_lido, 18, "Digite o CPF do funcionario:");

    arq_funcionarios = fopen("./data/funcionarios.dat", "rb");
    if(arq_funcionarios == NULL){
        printf("\t Erro ao abrir o arquivo de funcionarios. \n");
        enter();
        return;
    }
    while(fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)){
        if(strcmp(cpf_lido, fun->cpf) == 0){
            printf("Funcionario encontrado!\n");
            printf("CPF: %s\n", fun->cpf);
            printf("NOME: %s\n", fun->nome);
            printf("Telefone: %s\n", fun->cell);
        }
    }

    fclose(arq_funcionarios);
    free(fun);
    enter();
}

void exclu_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    FILE *arq_funcionarios_temp;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    char cpf_lido

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#               {Funcionarios -> Excluir}               #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cpf_lido, 18, "Digite o CPF do funcionario a ser excluido:");

    arq_funcionarios = fopen("./data/funcionarios.dat", "rb");
    arq_funcionarios_temp = fopen("./data/funcionarios_temp.dat", "rb");
    if(arq_funcionarios == NULL || arq_funcionarios_temp == NULL){
        printf("Erro ao abrir o arquivo!");
        enter();
        return;
    }

    while(fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)){
        if(strcmp(cpf_lido, fun->cpf) !=){
            fprintf(arq_funcionarios_temp, "%s;%s;%s\n", fun->cpf, fun->nome, fun->cell);
        }
    }

    fclose(arq_funcionarios);
    fclose(arq_funcionarios_temp);
    remove("./data/funcionarios.dat");
    rename("./data/funcionarios_temp.dat", "./data/funcionarios.dat");

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
    printf("Funcionario com CPF %s foi excluido com sucesso!\n", cpf_lido);
    free(fun);
    enter();
}