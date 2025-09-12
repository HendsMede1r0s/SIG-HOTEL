#include <stdio.h>
#include "lazer.h"

int tela_lazer(void){
    system("clear||cls");
    int op_lazer;
    printf("\n");
    printf(" ___________________________________\n");
    printf("|                                   |\n");
    printf("|           Area de Lazer           |\n");
    printf("|___________________________________|\n");
    printf("|                                   |\n");
    printf("|        1 - Piscina                |\n");
    printf("|        2 - Espaco Kids            |\n");
    printf("|        3 - Sala de Jogos          |\n");
    printf("|        0 - Voltar                 |\n");
    printf("|___________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    printf("Escolha uma opcao: ");
    scanf("%d", &op_lazer);
    getchar();
    return(op_lazer);
}