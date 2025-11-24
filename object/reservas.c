#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservas.h"
#include "utilidades.h"
#include "leitura.h"
#include "hospedes.h"
#include "funcionarios.h"
#include "tela_voltar_menu.h"

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
                //editar info
                break;
            case '3':
                list_reservas();
                break;
            case '4':
                //Buscar
                break;
            case '5':
                //Cancelar
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0');
}


char tela_reservas(void){
    limpa_tela();

    char op;
    
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|                         -Reservas-                         |\n");
    printf("|                                                            |\n");
    printf("|────────────────────────────────────────────────────────────|\n");
    printf("|                                                            |\n");
    printf("|        [1] -> Cadastrar reserva                            |\n");
    printf("|        [2] -> Editar informacoes                           |\n");
    printf("|        [3] -> Listar reservas                              |\n");
    printf("|        [4] -> Buscar reserva                               |\n");
    printf("|        [5] -> Cancelar reservas                            |\n");
    printf("|        [0] -> Voltar                                       |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}


void cad_reserva(void){
    limpa_tela();

    FILE *arq_reservas;
    Reservas *res;
    res = (Reservas*)malloc(sizeof(Reservas));

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Reservas -> Cadastrar}                 #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    ler_n_quarto(res->n_quarto, 7);
    printf("hospede:\n");
    ler_cpf(res->cpf_hospede, 18);
    printf("funcionario:\n");
    ler_cpf(res->cpf_funcionario, 18);
    printf("data reserva:\n");
    ler_data(res->data_reserva, 14);
    printf("data atendimento:\n");
    ler_data(res->data_atendimento, 14);
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
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#              {Reserva efetuada com sucesso!}             #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    enter();

}


void list_reservas(void){
    limpa_tela();

    FILE *arq_reservas;
    Reservas *res;
    res = (Reservas*)malloc(sizeof(Reservas));
    char data_reserva_formatado [14];
    char data_atendimento_formatado [14];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Hospedes -> Listar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    
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
            strncpy(data_reserva_formatado, pega_data(res->data_reserva), sizeof(data_reserva_formatado) - 1);
            data_reserva_formatado[sizeof(data_reserva_formatado) - 1] = '\0';
            strncpy(data_atendimento_formatado, pega_data(res->data_atendimento), sizeof(data_atendimento_formatado) - 1);
            data_atendimento_formatado[sizeof(data_atendimento_formatado) - 1] = '\0';

            printf("%-4s    %-18s   %-18s   %-14s  %-14s\n", res->n_quarto, res->cpf_hospede, res->cpf_funcionario, data_reserva_formatado, data_atendimento_formatado);
        }
    }
    printf("------  ------------------   ------------------   --------------  --------------\n");
    fclose(arq_reservas);
    free(res);
    enter();
}