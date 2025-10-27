#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"

int validar_nome(char *nome){
    int tamanho = strlen(nome);
    int valido = (tamanho > 0);

    if(!valido){
        printf("NOME VAZIO!\n");
        return False;
    }

    for(int i = 0; i < tamanho; i++){
        if(!isalpha(nome[i]) && !isspace(nome[i])){
            printf("NOME INVALIDO!\n");
            return False;
        }
    }

    return True;
}

int ler_nome(char *nome, int tam) {
    
    do{
        input(nome, tam, "Digite o nome: ");
    } while(!validar_nome(nome));

    printf("Nome valido!\n");
    return True;
}





void ler_cpf(char *variavel, int tam){

    input(variavel, tam, "Digite o cpf: ");

}


void ler_cell(char *variavel, int tam){

    input(variavel, tam, "Digite o telefone: ");

}


void ler_n_quarto(char *variavel, int tam){

    input(variavel, tam, "Digite o ID do quarto: ");
    
}