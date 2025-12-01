#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservas.h"
#include "utilidades.h"
#include "leitura.h"
#include "telas.h"

typedef struct reservas Reservas;

void modulo_reservas(void){

    char op;

    do {
        op = tela_reservas();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                cad_reserva();
                break; 
            case '2':
                edit_reserva();
                break;
            case '3':
                list_reservas();
                break;
            case '4':
                busc_reservas();
                break;
            case '5':
                cancel_reservas();
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0');
}


char tela_reservas(void){

    char op;
    
    tela_menu_reservas();
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}


void cad_reserva(void){

    FILE *arq_reservas;
    Reservas *res;
    res = (Reservas*)malloc(sizeof(Reservas));

    tela_cad_reservas();
    ler_n_quarto(res->n_quarto, sizeof(res->n_quarto));
    printf("hospede:\n");
    ler_cpf(res->cpf_hospede, sizeof(res->cpf_hospede));
    printf("funcionario:\n");
    ler_cpf(res->cpf_funcionario, sizeof(res->cpf_funcionario));
    printf("data reserva:\n");
    ler_data(res->data_reserva, sizeof(res->data_reserva));
    printf("data atendimento:\n");
    ler_data(res->data_atendimento, sizeof(res->data_atendimento));

    res->status = True;
    arq_reservas = fopen("./data/reservas.dat", "ab");
    if (arq_reservas == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    fwrite(res, sizeof(Reservas), 1, arq_reservas);
    fclose(arq_reservas);
    free(res);

    limpa_tela();
    printf("\n");
    printf("*Reserva efetuada com sucesso!*\n");
    enter();

}


void edit_reserva(void){

    FILE *arq_reservas;
    Reservas *res;
    char n_quarto_lido[7];
    int encontrado = False;
    res = (Reservas*)malloc(sizeof(Reservas));

    tela_edit_reservas();
    ler_n_quarto(n_quarto_lido, sizeof(n_quarto_lido));

    arq_reservas = fopen("./data/reservas.dat", "r+b");
    if (arq_reservas == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while (fread(res, sizeof(Reservas), 1, arq_reservas)) {
        if (strcmp(res->n_quarto, n_quarto_lido) == 0) {
            exib_reserva(res);
            enter();
            switch_edit_reserva(res);
            encontrado = True;

            fseek(arq_reservas, (-1)*sizeof(Reservas), SEEK_CUR);
            fwrite(res, sizeof(Reservas), 1, arq_reservas);

            limpa_tela();
            exib_reserva(res);
            enter();
            break; //adicionado para previnir bug no windows
        }

    }

    fclose(arq_reservas);
    free(res);
    
    if (!encontrado) {
        printf("Não encontrado no banco de dados.\n");
        enter();
    }

}


void list_reservas(void){

    FILE *arq_reservas;
    Reservas *res;
    res = (Reservas*)malloc(sizeof(Reservas));
    char data_reserva_formatado [14];
    char data_atendimento_formatado [14];

    tela_list_reservas();
    
    arq_reservas = fopen("./data/reservas.dat", "rb");
    if (arq_reservas == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    printf("%-4s  %-18s   %-18s   %-14s  %-14s\n", "Quarto", "CPF Hospede", "CPF Funcionario", "Data Reserva", "Data Atendimento");
    printf("------  ------------------   ------------------   --------------  --------------\n");
    while (fread(res, sizeof(Reservas), 1, arq_reservas)) {
        if (res->status) {
            // Formata as datas para exibição
            strncpy(data_reserva_formatado, formata_data(res->data_reserva), sizeof(data_reserva_formatado) - 1);
            data_reserva_formatado[sizeof(data_reserva_formatado) - 1] = '\0';
            strncpy(data_atendimento_formatado, formata_data(res->data_atendimento), sizeof(data_atendimento_formatado) - 1);
            data_atendimento_formatado[sizeof(data_atendimento_formatado) - 1] = '\0';

            printf("%-4s    %-18s   %-18s   %-14s  %-14s\n", res->n_quarto, res->cpf_hospede, res->cpf_funcionario, data_reserva_formatado, data_atendimento_formatado);
        }
    }
    printf("------  ------------------   ------------------   --------------  --------------\n");
    fclose(arq_reservas);
    free(res);
    enter();
}


void busc_reservas(void){

    FILE *arq_reservas;
    Reservas *res;
    char n_quarto_lido[7];
    int encontrado = False;
    res = (Reservas*)malloc(sizeof(Reservas));

    tela_busc_reservas();
    ler_n_quarto(n_quarto_lido, sizeof(n_quarto_lido));

    arq_reservas = fopen("./data/reservas.dat", "rb");
    if (arq_reservas == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while (fread(res, sizeof(Reservas), 1, arq_reservas)) {
        if (strcmp(res->n_quarto, n_quarto_lido) == 0) {
            encontrado = True;
            printf("\n*ENCONTRADO*\n");
            exib_reserva(res);
            enter();
            break; //adicionado para previnir bug no windows
        }
    }

    fclose(arq_reservas);
    free(res);

    if (!encontrado) {
        printf("Reserva não encontrada na base de dados!");
        enter();
    }

}


void cancel_reservas(void){

    FILE *arq_reservas;
    Reservas *res;
    char n_quarto_lido[7];
    int escolha;
    int encontrado = False;
    res = (Reservas*)malloc(sizeof(Reservas));

    tela_cancel_reservas();
    ler_n_quarto(n_quarto_lido, sizeof(n_quarto_lido));

    arq_reservas = fopen("./data/reservas.dat", "r+b");
    if (arq_reservas == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while (fread(res, sizeof(Reservas), 1, arq_reservas)) {
        if (strcmp(res->n_quarto, n_quarto_lido) == 0) {
            exib_reserva(res);
            escolha = confirma_exclusao();
            if (escolha) {

                res->status = False; // Marca a reserva como cancelada
                encontrado = True;
                fseek(arq_reservas, (-1)*sizeof(Reservas), SEEK_CUR);
                fwrite(res, sizeof(Reservas), 1, arq_reservas);

            } else if (!escolha) {
                encontrado = -1;
            }
            break; //adicionado para previnir bug no windows
        }
    }

    fclose(arq_reservas);
    free(res);

    switch (encontrado) {
        case 0:
            printf("Hospede não encontrado na base de dados!");
            enter();
            break;
        case 1:
            printf("Hospede excluido com sucesso!");
            enter();
            break;
        case -1:
            printf("Exclusão cancelada!");
            enter();
            break;
    }

}


void exib_reserva(Reservas *res){
    char data_reserva_formatado [14];
    char data_atendimento_formatado [14];

    // Formata as datas para exibição
    strncpy(data_reserva_formatado, formata_data(res->data_reserva), sizeof(data_reserva_formatado) - 1);
    data_reserva_formatado[sizeof(data_reserva_formatado) - 1] = '\0';
    strncpy(data_atendimento_formatado, formata_data(res->data_atendimento), sizeof(data_atendimento_formatado) - 1);
    data_atendimento_formatado[sizeof(data_atendimento_formatado) - 1] = '\0';

    printf("\n");
    printf("Número do Quarto: %s\n", res->n_quarto);
    printf("CPF do Hóspede: %s\n", res->cpf_hospede);
    printf("CPF do Funcionário: %s\n", res->cpf_funcionario);
    printf("Data da Reserva: %s\n", data_reserva_formatado);
    printf("Data do Atendimento: %s\n", data_atendimento_formatado);
    printf("Status: %s\n", res->status ? "Ativa" : "Cancelada");
    // " ? " é um operador condicional que funciona como um if simplificado
    // Exibe "Ativa" se res->status for True (1) e "Cancelada" se for False (0)
}


char menu_edit_reserva(void){

    char op;
    
    tela_menu_edit_reserva();
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}


void switch_edit_reserva(Reservas *res){

    char op;

    do {
        op = menu_edit_reserva();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                ler_n_quarto(res->n_quarto, 7);
                exib_reserva(res);
                enter();
                break;
            case '2':
                ler_cpf(res->cpf_hospede, 18);
                exib_reserva(res);
                enter();
                break;
            case '3':
                ler_cpf(res->cpf_funcionario, 18);
                exib_reserva(res);
                enter();
                break;
            case '4':
                ler_data(res->data_reserva, 14);
                exib_reserva(res);
                enter();
                break;
            case '5':
                ler_data(res->data_atendimento, 14);
                exib_reserva(res);
                enter();
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0');
}


