#include <stdio.h>
#include <stdlib.h>
#include "sobre.h"
#include "utilidades.h"

void tela_sobre(void){
    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────────────┐\n");
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
    printf("|                                                                    |\n");
    printf("└────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("{Pressione ENTER para continuar...}");
    getchar();
}