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
    printf("\n");
    printf("___________________________________\n");
    printf("|                                  |\n");
    printf("|            Clientes              |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Cadastar              |\n");
    printf("|        2 - Editar informacoes    |\n");
    printf("|        3 - Ver clientes          |\n");
    printf("|        4 - Voltar                |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
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
    printf(" _______________________________________________________________________");
    printf("|                                                                       |");
    printf("|                               CARDÁPIO                                |");
    printf("|_______________________________________________________________________|");
    printf("|                                                                       |");
    printf("|                             CAFÉ DA MANHA                             |");
    printf("|                                                                       |");
    printf("|        1 - Pães variados (francês, integral, de forma)                |");
    printf("|        2 - Frios (presunto, peito de peru, queijo prato, muçarela)    |");
    printf("|        3 - Frutas frescas (mamão, melancia, banana, abacaxi)          |");
    printf("|        4 - Ovos mexidos / cozidos                                     |");
    printf("|        5 - Bolos (fubá, chocolate, cenoura)                           |");
    printf("|        6 - Tapioca feita na hora                                      |");
    printf("|        7 - Café, leite, achocolatado, chá                             |");
    printf("|        8 - Sucos naturais (laranja, melancia, abacaxi com hortelã)    |");
    printf("|_______________________________________________________________________|");
    printf("|                                                                       |");
    printf("|                            ALMOÇO / JANTAR                            |");
    printf("|                                                                       |");
    printf("|        Pratos principais:                                             |");
    printf("|                                                                       |");
    printf("|        1 - Filé de frango grelhado com ervas                          |");
    printf("|        2 - Bife acebolado / Filé mignon ao molho madeira              |");
    printf("|        3 - Peixe grelhado / ao molho de camarão                       |");
    printf("|        4 - Strogonoff de frango ou carne                              |");
    printf("|        5 - Lasanha à bolonhesa ou vegetariana                         |");
    printf("|        6 - Moqueca baiana (frutos do mar ou peixe)                    |");
    printf("|        7 - Escondidinho de carne seca                                 |");
    printf("|                                                                       |");
    printf("|        Acompanhamentos:                                               |");
    printf("|                                                                       |");
    printf("|        1 - Arroz branco / integral / à grega                          |");
    printf("|        2 - Feijão carioca / preto                                     |");
    printf("|        3 - Farofa caseira                                             |");
    printf("|        4 - Purê de batata / mandioca                                  |");
    printf("|        5 - Legumes salteados                                          |");
    printf("|        6 - Saladas variadas (folhas, tomate, cenoura e beterraba)     |");
    printf("|_______________________________________________________________________|");
    printf("|                                                                       |");
    printf("|                              SOBREMESAS                               |");
    printf("|                                                                       |");
    printf("|                                                                       |");
    printf("|        1 - Pudim de leite condensado                                  |");
    printf("|        2 - Mousse de maracujá / chocolate                             |");
    printf("|        3 - Doce de leite / goiabada com queijo                        |");
    printf("|        4 - Frutas da estação                                          |");
    printf("|        5 - Sorvete (2 ou 3 sabores)                                   |");
    printf("|_______________________________________________________________________|");
    printf("|                                                                       |");
    printf("|                               LANCHES                                 |");
    printf("|                                                                       |");
    printf("|        1 - Sanduíche natural (frango, atum, vegetariano)              |");
    printf("|        2 - Hambúrguer artesanal                                       |");
    printf("|        3 - Pão de queijo                                              |");
    printf("|        4 - Salgadinhos assados (empada, quiche)                       |");
    printf("|        5 - Batata frita                                               |");
    printf("|        6 - Tapioca recheada                                           |");
    printf("|_______________________________________________________________________|");
    printf("|                                                                       |");
    printf("|                               BEBIDAS                                 |");
    printf("|                                                                       |");
    printf("|        Não alcoólicas:                                                |");
    printf("|                                                                       |");
    printf("|        1 - Água mineral (com e sem gás)                               |");
    printf("|        2 - Refrigerantes (Coca-Cola, Guaraná, etc.)                   |");
    printf("|        3 - Sucos naturais e de polpa                                  |");
    printf("|        4 - Água de coco                                               |");
    printf("|        5 - Chá gelado / quente                                        |");
    printf("|        6 - Café expresso / coado                                      |");
    printf("|                                                                       |");
    printf("|        Alcoólicas:                                                    |");
    printf("|                                                                       |");
    printf("|        1 - Cervejas nacionais e artesanais                            |");
    printf("|        2 - Vinhos (tinto, branco, rosé)                               |");
    printf("|        3 - Caipirinha / Caipiroska                                    |");
    printf("|        4 - Drinks clássicos (Mojito, Gin tônica, Aperol Spritz)       |");
    printf("|        5 - Licor / Whisky / Rum (opcional)                            |");
    printf("|_______________________________________________________________________|");
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
    printf("|        0 - Voltar                   |\n");
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
    printf(" ____________________________________________________________________");
    printf("|                                                                    |");
    printf("|             UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE            |");
    printf("|                 CENTRO DE ENSINO SUPERIOR DO SERIDO                |");
    printf("|               DEPATARMENTO DE COMPUTAÇÃO E TECNOLOGIA              |");
    printf("|                  DISCIPLINA DCT1106 - PROGRAMAÇÃO                  |");
    printf("|          PROJETO SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS          |");
    printf("|--------------------------------------------------------------------|");
    printf("\n");
    printf("|           - SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS -             |");
    printf("|     Projeto proposto pelo professor de Sistemas de Informação      |");
    printf("|   da UFRN-CERES, @flgorgonio, com o intuido fazer um sistema de    |");
    printf("|              gestão designado a hotéis ou pousadas                 |");
    printf("|____________________________________________________________________|");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}

void tela_equipe(void){
    system("clear|cls");
    printf("\n");
    printf(" _____________________________________________________________________");
    printf("|                                                                     |");
    printf("|             UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE             |");
    printf("|                 CENTRO DE ENSINO SUPERIO DO SERIDÓ                  |");
    printf("|               DEPARTAMENTO DE COMPUTAÇÃO E TECNOLOGIA               |");
    printf("|                  DISCIPLINA DCT1106 - PROGRAMAÇÃO                   |");
    printf("|          PROJETO SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS           |");
    printf("|---------------------------------------------------------------------|");
    printf("\n");
    printf("|           - SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS -              |");
    printf("|                                                                     |");
    printf("|                      PROJETO DESENVOLVIDO POR:                      |");
    printf("|                                                                     |");
    printf("|        NOME:   Henderson Emanuel                                    |");
    printf("|        EMAIL:  hendersonbernardo2018@gmail.com                      |");
    printf("|        GITHUB: https://github.com/HendsMede1r0s                     |");
    printf("|                                                                     |");
    printf("|        NOME:   Leonardo Relva                                       |");
    printf("|        EMAIL:  leonardo.relva.111@ufrn.edu.br                       |");
    printf("|        GITHUB: https://github.com/leonardorelva-ufrn                |");
    printf("|_____________________________________________________________________|");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}



//////////////////////////////////////////////////
///////////// Função Principal ///////////////////
/////////////////////////////////////////////////


int main(void){
    setlocale(LC_ALL,"Portuguese");

    tela_inicial();
    int num; 
    printf("Digite o número da opção desejada: ");
    scanf("%d", &num);
    if (num == 1)
        tela_clientes();
    else if (num == 2)
        tela_funcionarios();
    else if (num == 3)
        tela_quartos();
    else if (num == 4)
        tela_servicos();
    else if (num == 5)
        tela_restaurante();
    else if (num == 6)
        tela_lazer();
    else if (num == 7)
        tela_garagem(); 
    else if (num == 8)
        tela_equipe();
    else if (num == 9)
        tela_sobre();
    else if (num == 0) {
        printf("Saindo do programa...\n");
        exit(0);
    }
    return(0);
}
