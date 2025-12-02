#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"
#include "validacoes.h"

void ler_nome(char *variavel, int tam) {
    int valida;

    do{
        input(variavel, tam, "Digite o nome: ");
        valida = valida_nome(variavel);
        upper(variavel);
        if(!valida){
            printf("Nome invalido! Tente novamente.");
            printf("\n");
        }
    } while(!valida);

}


void ler_letras(char *variavel, int tam, char *mensagem) {
    int valida;

    do{
        input(variavel, tam, "Digite o texto: ");
        valida = valida_nome(variavel);
        if(!valida){
            printf("Texto invalido! Tente novamente.");
            printf("\n");
        }
    } while(!valida);
    
}


void ler_id(char *variavel, int tam) {
    int valida;

    do {
        input(variavel, tam, "Digite o id: ");
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
    int valida;

    do{
        input(variavel, tam, "Digite o telefone: ");
        valida = valida_num(variavel);
        if(!valida){
            printf("Telefone invalido! Tente novamente.");
            printf("\n");
        }
    } while(!valida);
    
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
    int valida;

    do {
        input(variavel, tam, "Digite a quantidade de pessoas: ");
        valida = (is_numeric(variavel));
        if (!valida) {
            printf("Quantidade invalida! Tente novamente.");
            printf("\n");
        }
    } while (!valida);

}


void ler_data(char *variavel, int tam){
    int valida;

    do{
        input(variavel, tam, "Digite a data (DDMMAAAA): ");
        valida = valida_data(variavel);
        if(!valida){
            printf("Data invalida! Tente novamente usando apenas numeros.");
            printf("\n");
        }
    } while(!valida);
    
}


void ler_status(int *variavel){
    int valida;

    do {
        char buffer[10];
        input(buffer, sizeof(buffer), "Digite o status (1-Pendente / 0-Concluído): ");
        if (is_numeric(buffer)) {
            *variavel = atoi(buffer);
            valida = (*variavel == 0 || *variavel == 1);
        } else {
            valida = 0;
        }
        if (!valida) {
            printf("Status invalido! Tente novamente.");
            printf("\n");
        }
    } while (!valida);
}