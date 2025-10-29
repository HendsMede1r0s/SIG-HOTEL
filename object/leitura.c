#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"
#include "validacoes.h"

void ler_nome(char *variavel, int tam) {
    
    do{
        input(variavel, tam, "Digite o nome: ");
    } while(!valida_nome(variavel));

}


void ler_cpf(char *variavel, int tam){

    do {
        input(variavel, tam, "Digite o cpf: ");
    } while (!valida_cpf(variavel));

}


void ler_cell(char *variavel, int tam){

    do{
        input(variavel, tam, "Digite o telefone: ");

        if(!valida_num(variavel)){
            printf("NUMERO INVALIDO!\n");
        }
    } while(!valida_num(variavel));
    
}


void ler_n_quarto(char *variavel, int tam){

    do {
        input(variavel, tam, "Digite o ID do quarto: ");
    } while (!valida_id(variavel));

}


void ler_quan_pessoas(char *variavel, int tam){

    do {
        input(variavel, tam, "Digite a quantidade de pessoas: ");
    } while (!is_numeric(variavel));

}