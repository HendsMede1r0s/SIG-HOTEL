#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // ver se tem letra e espaco
#include "funcionarios.h"
#include "utilidades.h"
#include "tela_voltar_menu.h"
#include "leitura.h"

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
                busc_funcionarios();
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
    ler_cpf(fun->cpf, 18);
    
    if (verifica_cpf_funcionarios(fun->cpf)) {
        printf("CPF já cadastrado!");
        enter();
        free(fun);
        return;
    }

    ler_nome(fun->nome, 55);
    ler_cell(fun->cell, 18);
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

    fclose(arq_funcionarios);
    free(fun);
    enter();
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
    ler_cpf(cpf_lido, 18);

    arq_funcionarios = fopen("./data/funcionarios.dat", "r+b");
    if(arq_funcionarios == NULL){
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while(fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)){
        if(strcmp(cpf_lido, fun->cpf) == 0){
            exib_funcionario(fun);
            enter();
            switch_edit_funcionarios(fun);
            encontrado = True;

            fseek(arq_funcionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
            fwrite(fun, sizeof(Funcionarios), 1, arq_funcionarios);

            limpa_tela();
            exib_funcionario(fun);
            enter();
        }
    }

    fclose(arq_funcionarios);

    if(!encontrado){
        printf("Funcionario não encotrado no banco de dados!");
        enter();
    }

    free(fun);

}


void busc_funcionarios(void){
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
            printf("*ENCONTRADO*\n");
            exib_funcionario(fun);
            enter();
        }
    }

    fclose(arq_funcionarios);
    free(fun);
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
        printf("%-15s %-30s %-15s\n", "CPF", "NOME", "TELEFONE");
        printf("--------------- ------------------------------ ---------------\n");
        while(fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)){
            if(fun->status == 1){
                printf("%-15s %-30s %-15s\n", fun->cpf, fun->nome, fun->cell);
            }
        printf("--------------- ------------------------------ ---------------\n");
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


void exib_funcionario(Funcionarios *fun){
    printf("\n");
    printf("CPF: %s\n", fun->cpf);
    printf("NOME: %s\n", fun->nome);
    printf("TELEFONE: %s\n", fun->cell);
    printf("STATUS: %s\n", fun->status ? "Ativo" : "Excluido");
}


char menu_edit_funcionarios(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|                       -Funcionarios-                       |\n");
    printf("|                                                            |\n");
    printf("|────────────────────────────────────────────────────────────|\n");
    printf("|                                                            |\n");
    printf("|        [1] -> CPF                                          |\n");
    printf("|        [2] -> Nome                                         |\n");
    printf("|        [3] -> Cell                                         |\n");
    printf("|        [0] -> Voltar                                       |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o numero do que deseja editar: ");
    scanf("%c", &op);
    getchar();
    return op;
}



void switch_edit_funcionarios(Funcionarios *fun){

    char op;

    do{
        op = menu_edit_funcionarios();
        switch (op){
            case '0':
                tela_voltar();
                break;
            case '1':
                ler_cpf(fun->cpf, 18);
                break;
            case '2':
                ler_nome(fun->nome, 55);
                break;
            case '3':
                ler_cell(fun->cell, 18);
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while(op != '0');
}


int verifica_cpf_funcionarios(const char *cpf_a_verificar){
    //recebe um cpf e verifica se ele já esta cadastrado
    FILE *arq_funcionarios;
    Funcionarios *fun_lido;
    fun_lido = (Funcionarios*)malloc(sizeof(Funcionarios));
    int encontrado = 0;

    arq_funcionarios = fopen("./data/funcionarios.dat", "rb");
    if (arq_funcionarios == NULL) {
        free(fun_lido);
        return False;
    }

    while (fread(fun_lido, sizeof(Funcionarios), 1, arq_funcionarios) == 1) {
        if (strcmp(fun_lido->cpf, cpf_a_verificar) == 0) {
        encontrado = 1;
        break;
        }
    }
    
    fclose(arq_funcionarios);
    free(fun_lido);
    return encontrado;
}
