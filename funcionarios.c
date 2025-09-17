#include <stdio.h>
#include <stdlib.h>
#include "funcionarios.h"

int tela_funcionarios(){
    system("clear||cls");
    int op_funcionarios;
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
    scanf("%d", &op_funcionarios);
    getchar();
    return op_funcionarios;
}


int area_funcionarios(){
    int op_funcionarios = 4;
    while (op_funcionarios != 0){
        op_funcionarios = tela_funcionarios();
        if (op_funcionarios == 1){
            printf("cadastrar funcionário");
            getchar();
        }
        else if (op_funcionarios == 2 ){
            printf("editar informações");
            getchar();
        }
        else if (op_funcionarios == 3){
            printf("Ver funcionarios");
            getchar();
        }
    }
    return 0;
}