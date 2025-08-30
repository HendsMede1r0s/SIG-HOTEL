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
int tela_funcionarios();
void tela_quartos(void);
void tela_servicos(void);
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
    int op_restaurante = 6;
    int op_lazer = 4;
    int op_garagem = 4;
    while(opcao != 0){
        opcao = tela_inicial();
        if (opcao == 1){
            tela_clientes();
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
            tela_funcionarios();
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
            tela_quartos();
            
        }
        else if(opcao == 4){
            tela_servicos();
            
        }
        else if(opcao == 5){
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
                else if(op_restaurante == 0){
                    opcao = 10;
                }
            }
        }
        else if(opcao == 6){
            while(op_lazer != 0){
                op_lazer = tela_lazer();
                if(op_lazer == 1){
                    printf("Piscina");
                }
                else if(op_lazer == 2){
                    printf("Espaco Kids");
                }
                else if(op_lazer == 3){
                    printf("Sala de Jogos");
                }
                else if(op_lazer == 0){
                    opcao = 10;
                }
            }
        }
        else if(opcao == 7){
            while(op_garagem != 0){
                op_garagem = tela_garagem();
                if(op_garagem == 1){
                    printf("Vagas");
                }
                else if(op_garagem == 2){
                    printf("Pegar Vaga");
                }
                else if(op_garagem == 3){
                    printf("Tirar Vaga");
                }
                else if(op_garagem == 0){
                    opcao = 10;
                }
            }
        }
        else if(opcao == 8){
            tela_equipe();
        }
        else if(opcao == 9){
            tela_sobre();
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
    printf("PRESSIONE ENTER PARA CONTINUAR...\n");
    printf("Digite uma opçao: ");
    scanf("%d", &op_cliente);
    getchar();
    return(op_cliente);
}

int tela_funcionarios(){
    system("clear||cls");
    int op_funcionarios;
    printf("\n");
    printf("___________________________________\n");
    printf("|                                  |\n");
    printf("|          Funcionarios            |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Cadastar              |\n");
    printf("|        2 - Editar informacoes    |\n");
    printf("|        3 - Ver Funcionario       |\n");
    printf("|        0 - Voltar                |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    printf("Digite uma opção: ");
    scanf("%d", &op_funcionarios);
    getchar();
    return op_funcionarios;
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
    getchar();
}

int tela_restaurante(void){
    system("clear||cls");
    int op_restaurante;
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
    getchar();
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    return(op_restaurante);
}


int tela_lazer(void){
    system("clear||cls");
    int op_lazer;
    printf("\n");
    printf(" ___________________________________\n");
    printf("|                                   |\n");
    printf("|           Area de Lazer           |\n");
    printf("|___________________________________|\n");
    printf("|                                   |\n");
    printf("|        1 - Piscina                |\n");
    printf("|        2 - Espaco Kids            |\n");
    printf("|        3 - Sala de Jogos          |\n");
    printf("|        0 - Voltar                 |\n");
    printf("|___________________________________|\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op_lazer);
    getchar();
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    return(op_lazer);
}

int tela_garagem(void){
    system("clear||cls");
    int op_garagem;
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
    printf("Escolha uma opcao: ");
    scanf("%d", &op_garagem);
    getchar();
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    return(op_garagem);
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
    getchar();
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
    getchar();
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
    getchar();
}