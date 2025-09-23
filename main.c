//////////////////////////////////////
/////////// Bibliotecas //////////////
//////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "menu_inicial.h"
#include "clientes.h"
#include "funcionarios.h"
#include "quartos.h"
#include "servicos.h"
#include "restaurante.h"
#include "garagem.h"
#include "sobre.h"
#include "equipe.h"
#include "final.h"
#include "relatorio.h"

//////////////////////////////////////
/////////// Main /////////////////////
//////////////////////////////////////

int main(void){

    char op;
    do {
        op = tela_inicial();
        switch (op) {
            case '0':
                modulo_final();
            case '1':
                modulo_clientes();
                break;
            case '2':
                modulo_funcionarios();
            case '3':
                modulo_quartos();
                break;
            case '4':
                modulo_servicos();
                break;
            case '5':
                tela_equipe();
                break;
            case '6':
                tela_sobre();
                break;
            case '7':
                modulo_relatorios();
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0');

return 0;
}

void tela_op_invalida(void){
    system("clear||cls");
    printf("\n");
    printf(" __________________________________________________________________________________\n");
    printf("|                                                                                  |\n");
    printf("|                                 *OPCAO INVALIDA*                                 |\n");
    printf("|__________________________________________________________________________________|\n");
    printf("\n");
    getchar();
    printf("\n");
}