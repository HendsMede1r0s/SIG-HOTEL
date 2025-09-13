#include <stdio.h>
#include <stdlib.h>
#include "garagem.h"

int tela_garagem(void){
    system("clear||cls");
    int op_garagem;
    printf("\n");
    printf(" ___________________________________\n");
    printf("|                                   |\n");
    printf("|              Garagem              |\n");
    printf("|___________________________________|\n");
    printf("|                                   |\n");
    printf("|        1 - Vagas                  |\n");
    printf("|        2 - Pegar Vaga             |\n");
    printf("|        3 - Tirar Vaga             |\n");
    printf("|        0 - Voltar                 |\n");
    printf("|___________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    printf("Escolha uma opcao: ");
    scanf("%d", &op_garagem);
    getchar();
    return(op_garagem);
}