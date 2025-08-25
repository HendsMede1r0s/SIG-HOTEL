//////////////////////////////////////
/////////// Bibliotecas //////////////
//////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



//////////////////////////////////////
////////////// Funções ///////////////
//////////////////////////////////////


int tela_inicial(void);
int tela_clientes(void);
void tela_funcionarios(void);
void tela_quartos(void);
void tela_servicos(void);
int tela_restaurante(void);
void tela_lazer(void);
void tela_garagem(void);
void tela_equipe(void);
void tela_sobre(void);
void tela_final(void);


//////////////////////////////////////////////////
///////////// Função Principal ///////////////////
/////////////////////////////////////////////////

int main(void){
    int opcao = 1;
    int opcao_clientes = 4;
    int op_restaurante = 6;
    while(opcao != 0){
        opcao = tela_inicial();
        if (opcao == 1){
            tela_clientes();
            while(opcao_clientes != 0){
                opcao_clientes = tela_clientes();
                if (opcao_clientes == 1)
                    printf("Cadastro de clientes");
                else if (opcao_clientes == 2)
                    printf("Editar informações de clientes");
                else if (opcao_clientes == 3)
                    printf("Ver clientes cadastrados");
                
            }
        }
        else if(opcao == 2){

        }
        else if(opcao == 3){
            
        }
        else if(opcao == 4){
            
        }
        else if(opcao == 5){
            tela_restaurante();
            while(op_restaurante != 0){
                op_restaurante = tela_restaurante();
                if(op_restaurante == 1){
                    printf("Café da manha");
                }
                else if(op_restaurante == 2){
                    printf("Almoço");
                }
                else if(op_restaurante == 3){
                    printf("Jantar");
                }
                else if(op_restaurante == 4){
                    printf("Sobremesas");
                }
                else if(op_restaurante == 5){
                    printf("Bebidas");
                }
            }
        }
        else if(opcao == 6){
            
        }
        else if(opcao == 7){
            
        }
        else if(opcao == 8){
            
        }
        else if(opcao == 9){
            
        }
    }
    return 0;
}

//////////////////////////////////////
///////////// Módulos ////////////////
//////////////////////////////////////



int tela_inicial(void){
    int opcao;
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


int tela_clientes(){
    system("clear||cls");
    int op_cliente;
    printf("\n");
    printf("___________________________________\n");
    printf("|                                  |\n");
    printf("|            Clientes              |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Cadastar              |\n");
    printf("|        2 - Editar informacoes    |\n");
    printf("|        3 - Ver clientes          |\n");
    printf("|        0 - Voltar                |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("Digite uma opçao: ");
    scanf("%d", &op_cliente);
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    return(op_cliente);
}

void tela_funcionarios(void){
    system("clear||cls");
    printf("\n");
    printf("___________________________________\n");
    printf("|                                  |\n");
    printf("|          Funcionarios            |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Cadastar              |\n");
    printf("|        2 - Editar informacoes    |\n");
    printf("|        3 - Ver Funcionario       |\n");
    printf("|        4 - Voltar                |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}

void tela_quartos(void){
    system("clear||cls");
    printf("\n");
    printf("___________________________________\n");
    printf("|                                  |\n");
    printf("|             Quartos              |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Adicionar Quarto      |\n");
    printf("|    2 - Ver quartos disponiveis   |\n");
    printf("|        3 - Voltar                |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}

void tela_servicos(void){
    system("clear||cls");
    printf("\n");
    printf("___________________________________\n");
    printf("|                                  |\n");
    printf("|            Serviços              |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Serviços de quarto    |\n");
    printf("|        2 - Limpeza               |\n");
    printf("|        3 - Voltar                |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}

int tela_restaurante(void){
    int op_restaurante;
    system("clear|cls");
    printf("\n");
    printf(" _______________________________________________________________________\n");
    printf("|                                                                       |\n");
    printf("|                              RESTAURANTE                              |\n");
    printf("|_______________________________________________________________________|\n");
    printf("|                                                                       |\n");
    printf("|           1 - Cafe da manha                                           |\n");
    printf("|           2 - Almoco                                                  |\n");
    printf("|           3 - Jantar                                                  |\n");
    printf("|           4 - Sobremesas                                              |\n");
    printf("|           5 - Bebidas                                                 |\n");
    printf("|           0 - Sair                                                    |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf("%d",&op_restaurante);
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    return(op_restaurante);
    getchar();
}


void tela_lazer(void){
    system("clear|cls");
    printf("\n");
    printf(" ___________________________________\n");
    printf("|                                   |\n");
    printf("|           Area de Lazer           |\n");
    printf("|___________________________________|\n");
    printf("|                                   |\n");
    printf("|        1 - Piscina                |\n");
    printf("|        2 - Espaço Kids            |\n");
    printf("|        3 - Sala de Jogos          |\n");
    printf("|        0 - Voltar                 |\n");
    printf("|___________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}

void tela_garagem(void){
    system("clear|cls");
    printf("\n");
    printf(" ___________________________________\n");
    printf("|                                   |\n");
    printf("|              Garagem              |\n");
    printf("|___________________________________|\n");
    printf("|                                   |\n");
    printf("|        1 - Vagas                  |\n");
    printf("|        2 - Pegar Vaga             |\n");
    printf("|        3 - Tirar Vaga             |\n");
    printf("|        0 - Voltar                 |\n");
    printf("|___________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
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
    printf("\n");
    printf("|           - SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS -             |\n");
    printf("|     Projeto proposto pelo professor de Sistemas de Informação      |\n");
    printf("|   da UFRN-CERES, @flgorgonio, com o intuido fazer um sistema de    |\n");
    printf("|              gestão designado a hotéis ou pousadas                 |\n");
    printf("|____________________________________________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}

void tela_equipe(void){
    system("clear|cls");
    printf("\n");
    printf(" _____________________________________________________________________\n");
    printf("|                                                                     |\n");
    printf("|             UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE             |\n");
    printf("|                 CENTRO DE ENSINO SUPERIO DO SERIDÓ                  |\n");
    printf("|               DEPARTAMENTO DE COMPUTAÇÃO E TECNOLOGIA               |\n");
    printf("|                  DISCIPLINA DCT1106 - PROGRAMAÇÃO                   |\n");
    printf("|          PROJETO SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS           |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("\n");
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
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}


void tela_final(void){
    system("clear|cls");
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
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR");
    getchar();
}