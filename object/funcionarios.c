#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // ver se tem letra e espaco
#include "funcionarios.h"
#include "utilidades.h"
#include "tela_voltar_menu.h"
#include "leitura.h"
#define True 1;
#define False 0;

typedef struct funcionarios Funcionarios;

void modulo_funcionarios(void){

    char op;

    do {
        op = tela_funcionarios();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                cad_funcionarios();
                break;
            case '2':
                edit_funcionarios();
                break;
            case '3':
                list_funcionarios();
                break;
            case '4':
                exib_funcionarios();
                break;
            case '5':
                exclu_funcionarios();
                break;
            default:
                tela_op_invalida();
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
    printf("|        [3] -> Listar funcionarios                          |\n");
    printf("|        [4] -> Buscar funcionarios                          |\n");
    printf("|        [5] -> Excluir funcionarios                         |\n");
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
    input(fun->cpf, 18, "Digite o cpf do funcionario: ");
    verifica_nome(fun->nome, 55);
    input(fun->cell, 18, "Digite o telefone do funcionario: ");
    fun->status = True;

    arq_funcionarios = fopen("./data/funcionarios.dat", "ab");
    if(arq_funcionarios == NULL){
        printf("\t Erro ao tentar abrir o arquivo de funcionarios.\n");
        enter();
        return;
    }
    fwrite(fun, sizeof(Funcionarios), 1, arq_funcionarios);
    
    
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
    printf("\nSTATUS: %i", fun->status);
    printf("\n");

    fclose(arq_funcionarios);
    enter();
    free(fun);
}


void edit_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    char cpf_lido[18];
    int encontrado = False;

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

    arq_funcionarios = fopen("./data/funcionarios.dat", "r+b");
    if(arq_funcionarios == NULL){
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while(fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)){
        if(strcmp(cpf_lido, fun->cpf) == 0){
            encontrado = True;
            printf("*Digite as novas informaçoes do funcionario com CPF: %s*\n", cpf_lido);
            input(fun->nome, 55, "Digite o nome do funcionario: ");
            input(fun->cell, 18, "Digite o telefone do funcionario: ");

            fseek(arq_funcionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
            fwrite(fun, sizeof(Funcionarios), 1, arq_funcionarios);

            limpa_tela();
            printf("*NOVOS DADOS*\n");
            printf("Funcionario editado!");
            enter();
        }
    }

    fclose(arq_funcionarios);

    if(!encontrado){
        printf("Funcionario não encotrado no banco de dados!");
        enter();;
    }

    free(fun);

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


void list_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#         {Funcionarios -> Listar funcionarios}         #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");

    arq_funcionarios = fopen("./data/funcionarios.dat", "rb");
    if(arq_funcionarios == NULL){
        printf("Erro ao abrir o arquivo!");
        enter();
        return;
    }
    else{
        printf("NOME \t\t CPF \t\t\t TELEFONE");
        while(fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)){
            printf("\n%s\t\t",fun->nome);
            printf("%s\t\t",fun->cpf);
            printf("%s\t\t",fun->cell);
            printf("\n");
    }
    
    }

    fclose(arq_funcionarios);
    free(fun);
    enter();
}

void exclu_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    char cpf_lido[18];
    int encontrado = False;

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

    arq_funcionarios = fopen("./data/funcionarios.dat", "r+b");
    if(arq_funcionarios == NULL){
        printf("Erro ao abrir o arquivo!");
        enter();
        return;
    }

    while(fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)){
        if(strcmp(cpf_lido, fun->cpf) == 0){
            fun->status = False;
            encontrado = True;
            fseek(arq_funcionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
            fwrite(fun, sizeof(Funcionarios), 1, arq_funcionarios);
        }
    }

    fclose(arq_funcionarios);

    if(!encontrado){
        printf("Cliente não encontrado no banco de dados");
        enter();
    }

    if(encontrado){
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
    
}

int verifica_nome(char *nome, int tam){

    input(nome, tam, "Digite o nome: ");
    int tam = strlen(nome)

    if(tam == 0){
        return 0;
    }

    for(int i = 0; i < tam; i++){
        if(!isalpha(nome[i]) && isspace(nome[i])){
            return 0;
        }
    }

    return 1;
}