#include <stdio.h>
#include "servicos.h"

int tela_servicos(void){
    system("clear||cls");
    int op_servicos;
    printf("\n");
    printf("___________________________________\n");
    printf("|                                  |\n");
    printf("|            Serviços              |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Serviços de quarto    |\n");
    printf("|        2 - Limpeza               |\n");
    printf("|        0 - Voltar                |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    printf("Digite uma opção: ");
    scanf("%d", &op_servicos);
    getchar();
    return op_servicos;
}