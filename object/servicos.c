#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicos.h"
#include "utilidades.h"

void modulo_servicos(void){

    char op;

    do {
        op = tela_servicos();
        switch (op) {
            case '1':
                cad_servico();
                break;
            case '2':
                edit_servicos();
                break;
            case '3':
                list_servicos();
                break;
            case '4':
                atri_servico();
                break;
        }
    } while (op != '0'); 
}

char tela_servicos(void){
    limpa_tela();

    char op;
    printf("\n");
    printf("┌──────────────────────────────────────────────────────┐\n");
    printf("|                                                      |\n");
    printf("|                      -Serviços-                      |\n");
    printf("|                                                      |\n");
    printf("|──────────────────────────────────────────────────────|\n");
    printf("|                                                      |\n");
    printf("|       [1] -> Cadastrar Serviços                      |\n");
    printf("|       [2] -> Editar Serviços                         |\n");
    printf("|       [3] -> Listar Serviços                         |\n");
    printf("|       [4] -> Atribuir Servico ao funcionario         |\n");
    printf("|       [0] -> Voltar                                  |\n");
    printf("└──────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}


void cad_servico(void){
    limpa_tela();

    FILE *arq_servicos;
    char servi[55];

    printf("\n");
    printf("┌───────────────────────────────────────────────────────┐\n");
    printf("|#######################################################|\n");
    printf("|#                                                     #|\n");
    printf("|#           {Serviços -> Cadastrar Serviço}           #|\n");
    printf("|#                                                     #|\n");
    printf("|#######################################################|\n");
    printf("└───────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o serviço:");
    scanf("%s", servi);
    getchar();
    printf("\n");

    arq_servicos = fopen("./data/servicos.csv", "at");
    if(arq_servicos == NULL){
        printf("\t Erro ao abrir o arquivo serviços\n");
        printf("\t {Digite ENTER para continuar}\n");
        getchar();
        return;
    }
    fprintf(arq_servicos, "%s", servi);
    fclose(arq_servicos);

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Serviço Cadastrado}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("\nServiço Cadastrado: %s", servi);
    printf("\n");
    printf("\t {Digite ENTER para continuar}\n");
    getchar();
    printf("\n");

}


void edit_servicos(void){
    limpa_tela();
    return;
}


void list_servicos(void){
    limpa_tela();
    return;
}


void atri_servico(void){
    limpa_tela();
    return;
}