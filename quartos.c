#include <stdio.h>
#include <stdlib.h>
#include "quartos.h"

void modulo_quartos(void){

    char op;

    do {
        op = tela_quartos();
        switch (op) {
            case '1':
                getchar();
                break;
        }
    } while (op != '0'); 
}

char tela_quartos(void){
    system("clear||cls");
    char op;
    printf("\n");
    printf("___________________________________\n");
    printf("|                                  |\n");
    printf("|             Quartos              |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Adicionar Quarto      |\n");
    printf("|        2 - Quartos disponiveis   |\n");
    printf("|        0 - Voltar                |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    printf("Digite uma opção; ");
    scanf("%c", &op);
    getchar();
    return op;
}