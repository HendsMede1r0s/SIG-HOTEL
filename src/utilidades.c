#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"
#include "quartos.h"

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
    printf("\n");
    printf("{Pressione ENTER para continuar...}");
    getchar();
    printf("\n");
}


int confirma_exclusao(void){

    char escolha;

    printf("\nDeseja prosseguir?\n");
    printf("Digite 'S' para confirmar ou 'N' para cancelar: ");
    scanf("%c", &escolha);
    getchar();
    printf("\n");
    if (escolha == 's' || escolha == 'S') {
        return True;
    } else {
        return False;
    }

}


char* formata_data(char *data){

    char dia [4];
    char mes [4];
    char ano [6];
    static char data_formatada [14];

    strncpy(dia, data, 2);
    dia[2] = '\0';
    strncpy(mes, data + 2, 2); //+2 pra pular dia
    mes[2] = '\0';
    strncpy(ano, data + 4, 4); //+4 pra pular dia e mes
    ano[4] = '\0';
    sprintf(data_formatada, "%s/%s/%s", dia, mes, ano);
    
    return data_formatada;
}


void upper(char *str){
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}


void limpa_quarto(Quar_lista* l){
    Quar_lista* temp = l->prox; // Começa do primeiro nó após cabeça
    Quar_lista* next; // Ponteiro auxiliar
    while (temp != NULL) { // Enquanto houver nós
        next = temp->prox; // Guarda referência do próximo nó
        free(temp); // Libera nó atual
        temp = next; // Avança para próximo nó
    }
    l->prox = NULL; // Lista vazia novamente
}


void deleta_quarto(Quar_lista* l){
    limpa_quarto(l); // Limpa todos os nós
    free(l); // Libera a cabeça da lista
}

//char* duplica(char *string){
//    int n = strlen(string) + 1;
//    char *dup = malloc(n * sizeof(char));
//    strcpy(dup, string);
//    return dup;
//}
//
//
//static char* ler_linha(void){
//    char linha[255];
//    scanf("%25[^\n]", linha);
//    return duplica(linha);
//}