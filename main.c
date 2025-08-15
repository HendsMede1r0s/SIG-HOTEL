#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void tela_inicial(void);
void tela_sobre(void);
void tela_equipe(void);


int main(void){
    
}

void tela_sobre(void){
    setLocale(LC_ALL,"Portuguese");
    char op;
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
    printf("\t\t PRESSIONE ENTER PARA CONTINUAR");
}