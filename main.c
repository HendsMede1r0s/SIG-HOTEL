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
    int opcao = 10;
    while(opcao != 0){
        opcao = tela_inicial();
        if (opcao == 1){
            area_clientes();
        }
        else if(opcao == 2){
            area_funcionarios();
        }
        else if(opcao == 3){
            area_quartos();
        }
        else if(opcao == 4){
            area_servicos();
        }
        else if(opcao == 5){
            tela_restaurante();
            printf("PRESSIONE ENTER PARA SAIR...");
            getchar();
        }
        else if(opcao == 6){
            tela_garagem();
            printf("PRESSIONE ENTER PARA SAIR...");
            getchar();
        }
        else if(opcao == 7){
            tela_equipe();
            printf("PRESSIONE ENTER PARA SAIR...");
            getchar();
        }
        else if(opcao == 8){
            tela_sobre();
            printf("PRESSIONE ENTER PARA SAIR...");
            getchar();
        }
        else if(opcao == 9){
            tela_relatorio();
            printf("PRESSIONE ENTER PARA SAIR...");
            getchar();
        }
    }
    tela_final();
    return 0;
}