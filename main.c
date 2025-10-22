//////////////////////////////////////
/////////// Bibliotecas //////////////
//////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "./include/menu_inicial.h"
#include "./include/hospedes.h"
#include "./include/funcionarios.h"
#include "./include/quartos.h"
#include "./include/servicos.h"
#include "./include/sobre.h"
#include "./include/equipe.h"
#include "./include/final.h"
#include "./include/relatorio.h"
#include "./include/leitura.h"
#include "./include/utilidades.h"

//////////////////////////////////////
//////////////// Main ////////////////
//////////////////////////////////////

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