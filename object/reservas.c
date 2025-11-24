#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservas.h"
#include "utilidades.h"
#include "leitura.h"
#include "tela_voltar_menu.h"

typedef struct reservas Reservas;

void modulo_reservas(void){

    char op;

    do {
        op = '1';
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
                //Listar
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
    ler_cpf(res->cpf_hospede, 18);
    ler_cpf(res->cpf_funcionario, 18);
    ler_data(res->data_reserva, 14);
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