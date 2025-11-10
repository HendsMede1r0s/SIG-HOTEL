#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"
#include "validacoes.h"

void ler_nome(char *variavel, int tam) {
    
    do{
        input(variavel, tam, "Digite o nome: ");
        if(!valida_nome(variavel)){
            printf("Nome invalido! Tente novamente.");
            printf("\n");
        }
    } while(!valida_nome(variavel));

}

void ler_id(char *variavel, int tam) {
    int valida;
    do {
        input(variavel, tam, "Digite o id do serviço: ");
        valida = (valida_id(variavel));
        if (!valida) {
            printf("N° do ID inválido! Tente novamente.");
            printf("\n");
        }
    } while (!valida);

}

void ler_cpf(char *variavel, int tam){
    int valida;
    do {
        input(variavel, tam, "Digite o cpf: ");
        valida = (valida_cpf(variavel));
        if (!valida) {
            printf("CPF invalido! Tente novamente.");
            printf("\n");
        }
    } while (!valida);

}


void ler_cell(char *variavel, int tam){

    do{
        input(variavel, tam, "Digite o telefone: ");

        if(!valida_num(variavel)){
            printf("Numero invalido! Tente novamente.");
            printf("\n");
        }
    } while(!valida_num(variavel));
    
}


void ler_n_quarto(char *variavel, int tam){
    int valida;
    do {
        input(variavel, tam, "Digite o N° do quarto: ");
        valida = (valida_n_quarto(variavel));
        if (!valida) {
            printf("N° do quarto invalido! Tente novamente.");
            printf("\n");
        }
    } while (!valida);

}


void ler_quan_pessoas(char *variavel, int tam){

    do {
        input(variavel, tam, "Digite a quantidade de pessoas: ");
    } while (!is_numeric(variavel));

}