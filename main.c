//////////////////////////////////////
/////////// Bibliotecas //////////////
//////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "clientes.h"
#include "funcionarios.h"
#include "quartos.h"
#include "servicos.h"
#include "restaurante.h"
#include "lazer.h"
#include "garagem.h"




//////////////////////////////////////
////////////// Funções ///////////////
//////////////////////////////////////


int tela_inicial(void);
int tela_clientes(void);
int tela_funcionarios();
int tela_quartos(void);
int tela_servicos(void);
int tela_restaurante(void);
int tela_lazer(void);
int tela_garagem(void);
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
    int op_restaurante = 6;
    int op_lazer = 4;
    int op_garagem = 4;
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
            }
            
        }
        else if(opcao == 5){
            op_restaurante = 6;
            while(op_restaurante != 0){
                op_restaurante = tela_restaurante();
                if(op_restaurante == 1){
                    printf("Café da manha");
                    getchar();
                }
                else if(op_restaurante == 2){
                    printf("Almoço");
                    getchar();
                }
                else if(op_restaurante == 3){
                    printf("Jantar");
                    getchar();
                }
                else if(op_restaurante == 4){
                    printf("Sobremesas");
                    getchar();
                }
                else if(op_restaurante == 5){
                    printf("Bebidas");
                    getchar();
                }
                else if(op_restaurante == 0){
                    opcao = 10;
                }
            }
        }
        else if(opcao == 6){
            op_lazer = 4;
            while(op_lazer != 0){
                op_lazer = tela_lazer();
                if(op_lazer == 1){
                    printf("Piscina");
                    getchar();
                }
                else if(op_lazer == 2){
                    printf("Espaco Kids");
                    getchar();
                }
                else if(op_lazer == 3){
                    printf("Sala de Jogos");
                    getchar();
                }
                else if(op_lazer == 0){
                    opcao = 10;
                }
            }
        }
        else if(opcao == 7){
            op_garagem = 4;
            while(op_garagem != 0){
                op_garagem = tela_garagem();
                if(op_garagem == 1){
                    printf("Vagas");
                    getchar();
                }
                else if(op_garagem == 2){
                    printf("Pegar Vaga");
                    getchar();
                }
                else if(op_garagem == 3){
                    printf("Tirar Vaga");
                    getchar();
                }
                else if(op_garagem == 0){
                    opcao = 10;
                }
            }
        }
        else if(opcao == 8){
            tela_equipe();
            printf("PRESSIONE ENTER PARA SAIR...");
            getchar();
        }
        else if(opcao == 9){
            tela_sobre();
            printf("PRESSIONE ENTER PARA SAIR...");
            getchar();
        }
    }
    tela_final();
    return 0;
}

//////////////////////////////////////
///////////// Módulos ////////////////
//////////////////////////////////////



int tela_inicial(void){
    system("clear||cls");
    int opcao;
    printf("\n");
    printf(" __________________________________\n");
    printf("|                                  |\n");
    printf("|          Menu Principal          |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Clientes              |\n");
    printf("|        2 - Funcionarios          |\n");
    printf("|        3 - Quartos               |\n");
    printf("|        4 - Servicos              |\n");
    printf("|        5 - Restaurante           |\n");
    printf("|        6 - Areas de Lazer        |\n");
    printf("|        7 - Garagem               |\n");
    printf("|        8 - Equipe                |\n");
    printf("|        9 - Sobre                 |\n");
    printf("|        0 - Sair                  |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("Digite sua opcao: ");
    scanf("%d",&opcao);
    return opcao;
    getchar();  
}


void tela_sobre(void){
    system("clear||cls");
    printf("\n");
    printf(" ____________________________________________________________________\n");
    printf("|                                                                    |\n");
    printf("|             UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE            |\n");
    printf("|                 CENTRO DE ENSINO SUPERIOR DO SERIDO                |\n");
    printf("|               DEPATARMENTO DE COMPUTAÇÃO E TECNOLOGIA              |\n");
    printf("|                  DISCIPLINA DCT1106 - PROGRAMAÇÃO                  |\n");
    printf("|          PROJETO SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS          |\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|                                                                    |\n");
    printf("|           - SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS -             |\n");
    printf("|     Projeto proposto pelo professor de Sistemas de Informação      |\n");
    printf("|   da UFRN-CERES, @flgorgonio, com o intuido fazer um sistema de    |\n");
    printf("|              gestão designado a hotéis ou pousadas                 |\n");
    printf("|____________________________________________________________________|\n");
    printf("\n");
    getchar();
}

void tela_equipe(void){
    system("clear||cls");
    printf("\n");
    printf(" _____________________________________________________________________\n");
    printf("|                                                                     |\n");
    printf("|             UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE             |\n");
    printf("|                 CENTRO DE ENSINO SUPERIO DO SERIDÓ                  |\n");
    printf("|               DEPARTAMENTO DE COMPUTAÇÃO E TECNOLOGIA               |\n");
    printf("|                  DISCIPLINA DCT1106 - PROGRAMAÇÃO                   |\n");
    printf("|          PROJETO SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS           |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                                                                     |\n");
    printf("|           - SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS -              |\n");
    printf("|                                                                     |\n");
    printf("|                      PROJETO DESENVOLVIDO POR:                      |\n");
    printf("|                                                                     |\n");
    printf("|        NOME:   Henderson Emanuel                                    |\n");
    printf("|        EMAIL:  hendersonbernardo2018@gmail.com                      |\n");
    printf("|        GITHUB: https://github.com/HendsMede1r0s                     |\n");
    printf("|                                                                     |\n");
    printf("|        NOME:   Leonardo Relva                                       |\n");
    printf("|        EMAIL:  leonardo.relva.111@ufrn.edu.br                       |\n");
    printf("|        GITHUB: https://github.com/leonardorelva-ufrn                |\n");
    printf("|_____________________________________________________________________|\n");
    printf("\n");
    getchar();
}


void tela_final(void){
    system("clear||cls");
    printf("\n");
    printf(" __________________________________________________________________________________\n");
    printf("|                                                                                  |\n");
    printf("|                                   TELA FINAL                                     |\n");
    printf("|                                                                                  |\n");
    printf("|                                                                                  |\n");
    printf("|         Obrigado por utilizar o Sistema de Gestão para hotéis e pousadas.        |\n");
    printf("|                              Tenha um ótimo dia!                                 |\n");
    printf("|__________________________________________________________________________________|\n");
    printf("\n");
    getchar();
}