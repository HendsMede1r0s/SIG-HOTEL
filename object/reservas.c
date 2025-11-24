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
                //cadastrar reserva
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

