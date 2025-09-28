#include <stdio.h>
#include <stdlib.h>
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
    scanf("%c", &cpf);
    getchar();
    printf("\n");
    printf("Digite o nome do funcionario:");
    scanf("%c", &nome);
    getchar();
    printf("\n");
    printf("Digite o  telefone do funcionario:");
    scanf("%c", &cell);
    getchar();
    printf("\n");

    limpa_tela();
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#         {funcionario cadastrado com sucesso!}         #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("{Digite ENTER para continuar}");
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
    scanf("%c", &cpf);
    getchar();
    printf("\n");
    printf("Digite o nome do funcionario:");
    scanf("%c", &nome);
    getchar();
    printf("\n");
    printf("Digite o telefone do funcionario:");
    scanf("%c", &cell);
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
    printf("{Digite ENTER para continuar}");
    getchar();
    printf("\n");
}

void exib_funcionarios(void){
    limpa_tela();

    char cpf[18];
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
    scanf("%c",&cpf);
    getchar();
    printf("\n");
}

void exclu_funcionarios(void){
    limpa_tela();

    char cpf[18];
    char nome[55];
    char cell[18];

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
    scanf("%c", &cpf);
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
    printf("Digite ENTER para continuar");
    getchar();
    printf("\n");
}