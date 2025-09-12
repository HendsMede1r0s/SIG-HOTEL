#include <stdio.h>
#include "quartos.h"

int tela_quartos(){
    system("clear||cls");
    int op_quartos;
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
    scanf("%d", &op_quartos);
    getchar();
    return op_quartos;
}