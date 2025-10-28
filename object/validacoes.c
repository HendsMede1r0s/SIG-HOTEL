#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"

int valida_letra(char letra){
    if (letra >= 'A' && letra <= 'Z') {
        return True;
    } else if (letra >= 'a' && letra <= 'z') {
        return True;
    } else {
        return False;
    }
}


int valida_num(char num){
    if (num >= '0' && num <= '9') {
        return True;
    } else {
        return False;
    }
}


char* remove_char_especial(char* texto){
    if (texto == NULL) {
        return NULL;
    }

    size_t tam = strlen(texto);
    char* limpo = (char*)malloc(tam + 1);
    if (limpo == NULL) {
        perror("Falha na alocação de memória");
        return NULL;
    }

    int i, j = 0;
    for (i = 0; i < tam; i++) {
        if (valida_num(texto[i])) {
            limpo[j++] = texto[i];
        }
    }
    limpo[j] = '\0'; // Finaliza a nova string
    return limpo;
}//gerado pelo Google Gemini(2.5 Flash)

// Verifica se todos os caracteres da string são dígitos
int is_numeric(const char *num){
    if (num == NULL) {
        return False;
    }
    for (int i = 0; num[i] != '\0'; i++) {
        if (!valida_num(num[i])) {
            return False;
        }
    }
    return True;
}


int valida_cpf(char *CPF_original){
    char *CPF;

    // 1. Remove caracteres especiais
    CPF = remove_char_especial(CPF_original);
    if (CPF == NULL) {
        return False; // Erro na alocação
    }

    // 2. Verifica se a string limpa contém apenas dígitos (embora removeCaractEsp
    //    já faça isso, mantemos a lógica de 'is_numeric' para validar caracteres não removidos)
    if (!is_numeric(CPF)) {
        free(CPF);
        return False;
    }

    size_t tam = strlen(CPF);

    // 3. Verifica tamanho e CPFs com dígitos repetidos
    if (tam != 11) {
        free(CPF);
        return False;
    }

    // A verificação de CPFs repetidos é simplificada usando 'strcmp' em C
    if (strcmp(CPF, "00000000000") == 0 ||
        strcmp(CPF, "11111111111") == 0 ||
        strcmp(CPF, "22222222222") == 0 ||
        strcmp(CPF, "33333333333") == 0 ||
        strcmp(CPF, "44444444444") == 0 ||
        strcmp(CPF, "55555555555") == 0 ||
        strcmp(CPF, "66666666666") == 0 ||
        strcmp(CPF, "77777777777") == 0 ||
        strcmp(CPF, "88888888888") == 0 ||
        strcmp(CPF, "99999999999") == 0)
    {
        free(CPF);
        return False;
    }

    // Variáveis para cálculo
    int dig10, dig11, sm, i, r, num, peso;

    // --- Cálculo do 1º Dígito Verificador (dig10) ---
    sm = 0;
    peso = 10;
    for (i = 0; i < 9; i++) {
        // Conversão de char para int: '5' - '0' = 5
        num = CPF[i] - '0';
        sm = sm + (num * peso);
        peso = peso - 1;
    }

    r = 11 - (sm % 11);
    if ((r == 10) || (r == 11))
        dig10 = 0;
    else
        dig10 = r;

    // --- Cálculo do 2º Dígito Verificador (dig11) ---
    sm = 0;
    peso = 11;
    for (i = 0; i < 10; i++) {
        num = CPF[i] - '0';
        sm = sm + (num * peso);
        peso = peso - 1;
    }

    r = 11 - (sm % 11);
    if ((r == 10) || (r == 11))
        dig11 = 0;
    else
        dig11 = r;

    // Verificação dos dígitos
    // Pega os dígitos informados (índice 9 e 10) e converte para int
    int cpf_dig10 = CPF[9] - '0';
    int cpf_dig11 = CPF[10] - '0';

    if (dig10 == cpf_dig10 && dig11 == cpf_dig11) {
        free(CPF);
        return True;
    } else {
        free(CPF);
        return False;
    }
}


int valida_id(char *ID){
    if (ID == NULL) {
        return False;
    }

    size_t tam = strlen(ID);
    if (tam != 3) {
        return False;
    }

    if (!valida_letra(ID[0])) {
        return False;
    } else if (!valida_num(ID[1])) {
        return False;
    } else if (!valida_num(ID[2])) {
        return False;
    }

    return True;
}


int valida_nome(char *nome){
    int tamanho = strlen(nome);
    int valido = (tamanho > 0);

    if(!valido){
        printf("\nNOME VAZIO!\n");
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