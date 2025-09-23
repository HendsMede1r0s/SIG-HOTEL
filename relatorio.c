#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"

void modulo_relatorios(void){

    char op;

    do {
        op = tela_relatorios();
        switch (op) {
            case '1':
                getchar();
                break;
        }
    } while (op != '0'); 
}

void tela_relatorio(void){
    system("clear||cls");
    int op;
    printf("\n");
    printf(" ____________________________________________\n");
    printf("|                                            |\n");
    printf("|                 RELATORIOS                 |\n");
    printf("|                                            |\n");
    printf("|                                            |\n");
    printf("|      1 - Relatorio de hospedes             |\n");
    printf("|      2 - Relatorio de funcionarios         |\n");
    printf("|      3 - Relatorio de quartos               |\n");
    printf("|____________________________________________|\n");
    printf("\n");
    scanf("%d", &op);
    getchar();
    printf("\n");
    return op;
}