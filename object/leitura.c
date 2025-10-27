#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "validacoes.h"

void ler_nome(char *variavel, int tam){

    input(variavel, tam, "Digite o nome: ");

}


void ler_cpf(char *variavel, int tam){
    do {
        input(variavel, tam, "Digite o cpf: ");
    } while (!valida_cpf(variavel));
    

}


void ler_cell(char *variavel, int tam){

    input(variavel, tam, "Digite o telefone: ");

}


void ler_n_quarto(char *variavel, int tam){

    input(variavel, tam, "Digite o ID do quarto: ");
    
}