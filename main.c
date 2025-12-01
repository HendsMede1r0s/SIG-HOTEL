//////////////////////////////////////
/////////// Bibliotecas //////////////
//////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "./include/telas.h"
#include "./include/hospedes.h"
#include "./include/funcionarios.h"
#include "./include/quartos.h"
#include "./include/servicos.h"
#include "./include/reservas.h"
#include "./include/sobre.h"
#include "./include/equipe.h"
#include "./include/relatorio.h"
#include "./include/leitura.h"
#include "./include/utilidades.h"
#include "./include/agendamentos.h"

//////////////////////////////////////
//////////////// Main ////////////////
//////////////////////////////////////

char tela_inicial(void);

int main(void){

    char op;
    do {
        op = tela_inicial();
        switch (op) {
            case '0':
                tela_final();
                break;
            case '1':
                modulo_hospedes();
                break;
            case '2':
                modulo_funcionarios();
                break;
            case '3':
                modulo_quartos();
                break;
            case '4':
                modulo_servicos();
                break;
            case '5':
                modulo_reservas();
                break;
            case '6':
                modulo_agendamentos();
                break;
            case '7':
                tela_equipe();
                break;
            case '8':
                tela_sobre();
                break;
            case '9':
                modulo_relatorios();
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0');

return 0;
}

//////////////////////////////////////
/////////// Funções //////////////////
//////////////////////////////////////

char tela_inicial(void){

    char op;

    tela_menu_inicial();
    printf("Digite sua opcao: ");
    scanf("%c",&op);
    getchar();
    printf("\n");
    return op;
}