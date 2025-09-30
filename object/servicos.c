#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicos.h"

void modulo_servicos(void){

    char op;

    do {
        op = tela_servicos();
        switch (op) {
            case '1':
                getchar();
                break;
        }
    } while (op != '0'); 
}

char tela_servicos(void){
    system("clear||cls");
    char op;
    printf("\n");
    printf("┌──────────────────────────────────────────────────────┐\n");
    printf("|                                                      |\n");
    printf("|                      -Serviços-                      |\n");
    printf("|                                                      |\n");
    printf("|──────────────────────────────────────────────────────|\n");
    printf("|                                                      |\n");
    printf("|       [1] -> Cadastrar Servico                       |\n");
    printf("|       [2] -> Editar Servico                          |\n");
    printf("|       [3] -> Listar Servicos                         |\n");
    printf("|       [4] -> Atribuir Servico ao funcionario         |\n");
    printf("|       [0] -> Voltar                                  |\n");
    printf("└──────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    return op;
}


void cad_servico(void){

}