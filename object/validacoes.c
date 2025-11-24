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

int valida_digito(char num){
    if (num >= '0' && num <= '9') {
        return True;
    } else {
        return False;
    }
}


int valida_num(char *num){
    if(num == NULL){
        return False;
    }

    int tamanho = strlen(num);

    // SEM O DD
    if(tamanho != 9){
        return False;
    }

    for(int i = 0; i < tamanho; i++){
        if(!isdigit(num[i])){
            return False;
        }
    }

    return True;
}


// Verifica se todos os caracteres da string são dígitos
int is_numeric(const char *num){
    if (num == NULL) {
        return False;
    }
    for (int i = 0; num[i] != '\0'; i++) {
        if (!valida_digito(num[i])) {
            return False;
        }
    }
    return True;
}


int valida_cpf(char *CPF){

    if (CPF == NULL) {
        return False; // Erro na alocação
    }

    // 2. Verifica se a string limpa contém apenas dígitos (embora removeCaractEsp
    //    já faça isso, mantemos a lógica de 'is_numeric' para validar caracteres não removidos)
    if (!is_numeric(CPF)) {
        return False;
    }

    size_t tam = strlen(CPF);

    // 3. Verifica tamanho e CPFs com dígitos repetidos
    if (tam != 11) {
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
        return True;
    } else {
        return False;
    }
}


int valida_n_quarto(char *num){
    if (num == NULL) {
        return False;
    }

    size_t tam = strlen(num);
    if (tam != 3) {
        return False;
    }

    if (!valida_letra(num[0])) {
        return False;
    } else if (!valida_digito(num[1])) {
        return False;
    } else if (!valida_digito(num[2])) {
        return False;
    }

    return True;
}


int valida_nome(char *nome){
    int tamanho = strlen(nome);
    int valido = (tamanho > 0);

    if(!valido){
        return False;
    }

    for(int i = 0; i < tamanho; i++){
        if(!isalpha(nome[i]) && !isspace(nome[i])){
            return False;
        }
    }

    return True;
}

int valida_id(char *num){
    if (num == NULL) {
        return False;
    }

    size_t tam = strlen(num);
    if (tam != 4) {
        return False;
    }

    if (!is_numeric(num)) {
        return False;
    }

    return True;
}


int valida_data(char *data){

    char pega_dia [4];
    char pega_mes [4];
    char pega_ano [6];
    int dia = 0;
    int mes = 0;
    int ano = 0;

    if (data == NULL) {
        return False;
    }

    if (strlen(data) != 8) {
        return False;
    }

    if (data[2] == '/' || data[5] == '/') {
        return False;
    }


    strncpy(pega_dia, data, 2); // copia os dois primeiros caracteres para o dia
    strncpy(pega_mes, data + 2, 2); // +2 para pular dia
    strncpy(pega_ano, data + 4, 4); // +4 para pular dia e mes

    sscanf(pega_dia, "%d", &dia); //tranforma o conteudo das strings em inteiros
    sscanf(pega_mes, "%d", &mes);
    sscanf(pega_ano, "%d", &ano);

        if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) ///verifica se os numeros sao validos
        {
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //ano e bissexto
            {
                return True;
            }
            if (dia <= 28 && mes == 2) //feveireiro
            {
                return True;
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) ///verifica os meses de 30 dias
            {
                return True
            }
            if ((dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) ///verifica os meses de 31 dias
            {
                return True;
            }
            else
            {
                return False;
            }
      }
       else
           {
                return False;
           }
           
} //adaptado de: https://www.vivaolinux.com.br/script/Funcao-para-validacao-de-datas