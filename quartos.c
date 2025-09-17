#include <stdio.h>
#include <stdlib.h>
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


int area_quartos(){
    int op_quartos = 5;
    while (op_quartos != 0){
        op_quartos = tela_quartos();
        if (op_quartos == 1){
            printf("Adionar Quarto");
            getchar();
        }
        else if (op_quartos == 2){
            printf("Ver quartos");
            getchar();
        }
    }
    return 0;
}