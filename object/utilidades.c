#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"

void limpa_tela(void){

    system("clear||cls");
    
}

void input(char *variavel, int tamanho, char *mensagem){
    
    int len;
    printf("%s", mensagem);
    fgets(variavel, tamanho, stdin);
    printf("\n");
    len = strlen(variavel);
    if (len > 0 && variavel[len-1] == '\n') {
        variavel[len-1] = '\0';
    }
}

void enter(void){
    limpa_tela();
    printf("\n");
    printf("{Pressione ENTER para continuar...}");
    getchar();
    printf("\n");
}

void tela_op_invalida(void){
    limpa_tela();
    printf("\n");
    printf("┌──────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                                                                  |\n");
    printf("|                                 *OPCAO INVALIDA*                                 |\n");
    printf("|                                                                                  |\n");
    printf("└──────────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    getchar();
    printf("\n");
}