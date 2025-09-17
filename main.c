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
////////////// Funções ///////////////
//////////////////////////////////////


int tela_inicial(void);
int tela_clientes(void);
int tela_funcionarios();
int tela_quartos(void);
int tela_servicos(void);
int tela_restaurante(void);
void tela_garagem(void);
void tela_equipe(void);
void tela_sobre(void);
void tela_final(void);


//////////////////////////////////////////////////
///////////// Função Principal ///////////////////
/////////////////////////////////////////////////

int main(void){
    int opcao = 10;
    int op_clientes = 4;
    int op_funcionarios = 4;
    int op_quartos = 5;
    int op_servicos = 6;
    while(opcao != 0){
        opcao = tela_inicial();
        if (opcao == 1){
            op_clientes = 4;
            while(op_clientes != 0){
                op_clientes = tela_clientes();
                if (op_clientes == 1){
                    printf("Cadastro de clientes");
                    getchar();
                }
                else if (op_clientes == 2){
                    printf("Editar informações de clientes");
                    getchar();
                }
                else if (op_clientes == 3){
                    printf("Ver clientes cadastrados");
                    getchar();
                }
                
            }
        }
        else if(opcao == 2){
            op_funcionarios = 4;
            while (op_funcionarios != 0){
                op_funcionarios = tela_funcionarios();
                if (op_funcionarios == 1){
                    printf("cadastrar funcionário");
                    getchar();
                }
                else if (op_funcionarios == 2 ){
                    printf("editar informações");
                    getchar();
                }
                else if (op_funcionarios == 3){
                    printf("Ver funcionarios");
                    getchar();
                }

            }

        }
        else if(opcao == 3){
            op_quartos = 5;
            while (op_quartos != 0){
                op_quartos = tela_quartos();
                if (op_quartos == 1){
                    printf("Adionar Quarto");
                    getchar();
                }
                else if (op_quartos == 2){
                    printf("Ver quartos");
                    getchar();
                }
            }
        }
        else if(opcao == 4){
            op_servicos = 6;
            while (op_servicos != 0){
                op_servicos = tela_servicos();
                if (op_servicos == 1){
                    printf("Serviço de quarto");
                    getchar();
                }
                else if (op_servicos == 2){
                    printf("Limpeza");
                    getchar();
                }
                else if(op_servicos == 3){
                    printf("Area de Lazer");
                    getchar();
                }
            }
            
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
            printf("PRESSIONE ENTER PARA SAIR...")
            getchar();
        }
    }
    tela_final();
    return 0;
}