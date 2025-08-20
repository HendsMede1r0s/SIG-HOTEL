//////////////////////////////////////
/////////// Bibliotecas //////////////
//////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



//////////////////////////////////////
////////////// Funções ///////////////
//////////////////////////////////////


void tela_inicial(void);
void tela_clientes(void);
void tela_funcionarios(void);
void tela_quartos(void);
void tela_servicos(void);
void tela_restaurante(void);
void tela_lazer(void);
void tela_garagem(void);
void tela_equipe(void);
void tela_sobre(void);
void tela_final(void);


//////////////////////////////////////
///////////// Módulos ////////////////
//////////////////////////////////////



void tela_inicial(void){
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
    printf(" PRESSIONE ENTER PARA CONTINUAR...");
    getchar();  
}


void tela_clientes(void){
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
    scanf("%d", %op_cliente)
    printf("PRESSIONE ENTER PARA CONTINUAR...");
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

void tela_restaurante(void){
    system("clear|cls");
    printf("\n");
    printf(" _______________________________________________________________________\n");
    printf("|                                                                       |\n");
    printf("|                               CARDÁPIO                                |\n");
    printf("|_______________________________________________________________________|\n");
    printf("|                                                                       |\n");
    printf("|                             CAFÉ DA MANHA                             |\n");
    printf("|                                                                       |\n");
    printf("|        1 - Pães variados (francês, integral, de forma)                |\n");
    printf("|        2 - Frios (presunto, peito de peru, queijo prato, muçarela)    |\n");
    printf("|        3 - Frutas frescas (mamão, melancia, banana, abacaxi)          |\n");
    printf("|        4 - Ovos mexidos / cozidos                                     |\n");
    printf("|        5 - Bolos (fubá, chocolate, cenoura)                           |\n");
    printf("|        6 - Tapioca feita na hora                                      |\n");
    printf("|        7 - Café, leite, achocolatado, chá                             |\n");
    printf("|        8 - Sucos naturais (laranja, melancia, abacaxi com hortelã)    |\n");
    printf("|_______________________________________________________________________|\n");
    printf("|                                                                       |\n");
    printf("|                            ALMOÇO / JANTAR                            |\n");
    printf("|                                                                       |\n");
    printf("|        Pratos principais:                                             |\n");
    printf("|                                                                       |\n");
    printf("|        1 - Filé de frango grelhado com ervas                          |\n");
    printf("|        2 - Bife acebolado / Filé mignon ao molho madeira              |\n");
    printf("|        3 - Peixe grelhado / ao molho de camarão                       |\n");
    printf("|        4 - Strogonoff de frango ou carne                              |\n");
    printf("|        5 - Lasanha à bolonhesa ou vegetariana                         |\n");
    printf("|        6 - Moqueca baiana (frutos do mar ou peixe)                    |\n");
    printf("|        7 - Escondidinho de carne seca                                 |\n");
    printf("|                                                                       |\n");
    printf("|        Acompanhamentos:                                               |\n");
    printf("|                                                                       |\n");
    printf("|        1 - Arroz branco / integral / à grega                          |\n");
    printf("|        2 - Feijão carioca / preto                                     |\n");
    printf("|        3 - Farofa caseira                                             |\n");
    printf("|        4 - Purê de batata / mandioca                                  |\n");
    printf("|        5 - Legumes salteados                                          |\n");
    printf("|        6 - Saladas variadas (folhas, tomate, cenoura e beterraba)     |\n");
    printf("|_______________________________________________________________________|\n");
    printf("|                                                                       |\n");
    printf("|                              SOBREMESAS                               |\n");
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|        1 - Pudim de leite condensado                                  |\n");
    printf("|        2 - Mousse de maracujá / chocolate                             |\n");
    printf("|        3 - Doce de leite / goiabada com queijo                        |\n");
    printf("|        4 - Frutas da estação                                          |\n");
    printf("|        5 - Sorvete (2 ou 3 sabores)                                   |\n");
    printf("|_______________________________________________________________________|\n");
    printf("|                                                                       |\n");
    printf("|                               LANCHES                                 |\n");
    printf("|                                                                       |\n");
    printf("|        1 - Sanduíche natural (frango, atum, vegetariano)              |\n");
    printf("|        2 - Hambúrguer artesanal                                       |\n");
    printf("|        3 - Pão de queijo                                              |\n");
    printf("|        4 - Salgadinhos assados (empada, quiche)                       |\n");
    printf("|        5 - Batata frita                                               |\n");
    printf("|        6 - Tapioca recheada                                           |\n");
    printf("|_______________________________________________________________________|\n");
    printf("|                                                                       |\n");
    printf("|                               BEBIDAS                                 |\n");
    printf("|                                                                       |\n");
    printf("|        Não alcoólicas:                                                |\n");
    printf("|                                                                       |\n");
    printf("|        1 - Água mineral (com e sem gás)                               |\n");
    printf("|        2 - Refrigerantes (Coca-Cola, Guaraná, etc.)                   |\n");
    printf("|        3 - Sucos naturais e de polpa                                  |\n");
    printf("|        4 - Água de coco                                               |\n");
    printf("|        5 - Chá gelado / quente                                        |\n");
    printf("|        6 - Café expresso / coado                                      |\n");
    printf("|                                                                       |\n");
    printf("|        Alcoólicas:                                                    |\n");
    printf("|                                                                       |\n");
    printf("|        1 - Cervejas nacionais e artesanais                            |\n");
    printf("|        2 - Vinhos (tinto, branco, rosé)                               |\n");
    printf("|        3 - Caipirinha / Caipiroska                                    |\n");
    printf("|        4 - Drinks clássicos (Mojito, Gin tônica, Aperol Spritz)       |\n");
    printf("|        5 - Licor / Whisky / Rum (opcional)                            |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
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



//////////////////////////////////////////////////
///////////// Função Principal ///////////////////
/////////////////////////////////////////////////


int main (void){
    setlocale(LC_ALL, "Portuguese");
    char opcao;
    tela_inicial();
    printf("que Opção deseja acessar? ");
    opcao = getchar();
    switch (opcao) {
        case '1':
            tela_clientes();
            if(op_cliente != 0){
                tela_clientes();
            }
            else{
                tela_inicial();
                break;
            }
        case '2':
            tela_funcionarios();
            break;
        case '3':
            tela_quartos();
            break;
        case '4':
            tela_servicos();
            break;  
        case '5':
            tela_restaurante();
            break;
        case '6':
            tela_lazer();
            break;
        case '7':
            tela_garagem();
            break;
        case '8':
            tela_equipe();
            break;
        case '9':
            tela_sobre();
            break;
        case '0':
            tela_final();
            exit(0);
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }
    return 0;
}