#include <stdio.h>
#include <stdlib.h>
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

int tela_servicos(void){
    system("clear||cls");
    int op;
    printf("\n");
    printf("___________________________________\n");
    printf("|                                  |\n");
    printf("|            Serviços              |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Serviços de quarto    |\n");
    printf("|        2 - Limpeza               |\n");
    printf("|        3 - Area de Lazer         |\n");
    printf("|        0 - Voltar                |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    printf("Digite uma opção: ");
    scanf("%d", &op);
    getchar();
    return op;
}