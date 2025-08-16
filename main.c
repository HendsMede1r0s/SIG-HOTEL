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
void tela_equipe(void);
void tela_sobre(void);


//////////////////////////////////////
///////////// Módulos ////////////////
//////////////////////////////////////


int main(void){
    setlocale(LC_ALL,"Portuguese");
}


void tela_inicial(void){
    printf("___________________________________");
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
    printf("|        0 - Sair                  |");
    printf("|__________________________________|");


}


void tela_equipe(void){

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
    getchat();
}
