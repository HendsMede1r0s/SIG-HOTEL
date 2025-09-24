#include <stdio.h>
#include <stdlib.h>
#include "funcionarios.h"

void modulo_funcionarios(void){

    char op;

    do {
        op = tela_funcionarios();
        switch (op) {
            case '1':
                getchar();
                break;
        }
    } while (op != '0'); 
}

char tela_funcionarios(void){
    system("clear||cls");
    char op;
    printf("\n");
    printf("___________________________________\n");
    printf("|                                  |\n");
    printf("|          Funcionarios            |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Cadastar              |\n");
    printf("|        2 - Editar informacoes    |\n");
    printf("|        3 - Ver Funcionario       |\n");
    printf("|        0 - Voltar                |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...\n");
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    return op;
}