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
    printf(" __________________________________");
    printf("|                                  |");
    printf("|          Menu Principal          |");
    printf("|__________________________________|");
    printf("|                                  |");
    printf("|        1 - Clientes              |");
    printf("|        2 - Funcionários          |");
    printf("|        3 - Quartos               |");
    printf("|        4 - Serviços              |");
    printf("|        5 - Restaurante           |");
    printf("|        6 - Áreas de Lazer        |");
    printf("|        7 - Garagem               |");
    printf("|        8 - Equipe                |");
    printf("|        9 - Sobre                 |");
    printf("|        0 - Sair                  |");
    printf("|__________________________________|");
    printf("\n");
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR...");
    getchar();  
}


void tela_clientes(void){
    system("clear||cls");
    printf("\n");
    printf("___________________________________");
    printf("|                                  |");
    printf("|            Clientes              |");
    printf("|__________________________________|");
    printf("|                                  |");
    printf("|        1 - Cadastar              |");
    printf("|        2 - Editar informações    |");
    printf("|        3 - Ver clientes          |");
    printf("|__________________________________|");
    printf("\n");
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}

void tela_funcionarios(void){
    system("clear||cls");
    printf("\n");
    printf("___________________________________");
    printf("|                                  |");
    printf("|          Funcionários            |");
    printf("|__________________________________|");
    printf("|                                  |");
    printf("|        1 - Cadastar              |");
    printf("|        2 - Editar informações    |");
    printf("|        3 - Ver Funcionário       |");
    printf("|__________________________________|");
    printf("\n");
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}

void tela_quartos(void){
    system("clear||cls");
    printf("\n");
    printf("___________________________________");
    printf("|                                  |");
    printf("|             Quartos              |");
    printf("|__________________________________|");
    printf("|                                  |");
    printf("|        1 - Adicionar Quarto      |");
    printf("|    2 - Ver quartos disponiveis   |");
    printf("|__________________________________|");
    printf("\n");
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}

void tela_servicos(void){
    system("clear||cls");
    printf("\n");
    printf("___________________________________");
    printf("|                                  |");
    printf("|            Serviços              |");
    printf("|__________________________________|");
    printf("|                                  |");
    printf("|        1 - Serviços de quarto    |");
    printf("|        2 - Limpeza               |");
    printf("|__________________________________|");
    printf("\n");
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}

void tela_restaurante(void){
    system("clear|cls");
    printf("\n");
    printf(" ___________________________________");
    printf("|                                   |");
    printf("|            Restaurante            |");
    printf("|___________________________________|");
    printf("|                                   |");
    printf("|                                   |");
    printf("|___________________________________|");
    printf("\n");
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}


void tela_lazer(void){
    system("clear|cls");
    printf("\n");
    printf(" ___________________________________");
    printf("|                                   |");
    printf("|           Área de Lazer           |");
    printf("|___________________________________|");
    printf("|                                   |");
    printf("|        1 - Piscina                |");
    printf("|        2 - Espaço Kids            |");
    printf("|        3 - Sala de Jogos          |");
    printf("|        0 - Sair                   |");
    printf("|___________________________________|");
    printf("\n");
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR...");
    getchar();
}

void tela_garagem(void){
    system("clear|cls");
    printf("\n");
    printf(" ___________________________________");
    printf("|                                   |");
    printf("|              Garagem              |");
    printf("|___________________________________|");
    printf("|                                   |");
    printf("|        1 - Vagas                  |");
    printf("|        2 - Pegar Vaga             |");
    printf("|        3 - Tirar Vaga             |");
    printf("|        0 - Sair                   |");
    printf("|___________________________________|");
    printf("\n");
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR...");
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
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR...");
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
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR...");
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
