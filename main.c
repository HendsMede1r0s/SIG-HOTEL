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
    printf("----------------------------------------------------------");
    printf("--                                                      --");
    printf("--      UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE     --");
    printf("--          CENTRO DE ENSINO SUPERIOR DO SERIDO         --");
    printf("--        DEPATARMENTO DE COMPUTAÇÃO E TECNOLOGIA       --");
    printf("--           DISCIPLINA DCT1106 - PROGRAMAÇÃO           --");
    printf("--   PROJETO SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS   --");
    printf("--                                                      --");
    printf("----------------------------------------------------------");
    print("\n");
    printf("         SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS         ");
    printf("Projeto proposto pelo professor de Sistemas de Informação da UFRN-CERES, @flgorgonio, com o intuido fazer um sistema de gestão designado a hotéis ou pousadas");
    printf("----------------------------------------------------------");
    printf("\n");
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR...");
}