#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicos.h"
#include "utilidades.h"

typedef struct servicos Servicos;

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
    printf("|       [4] -> Atribuir Serviço ao funcionario         |\n");
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
    Servicos servi;

    printf("\n");
    printf("┌───────────────────────────────────────────────────────┐\n");
    printf("|#######################################################|\n");
    printf("|#                                                     #|\n");
    printf("|#           {Serviços -> Cadastrar Serviço}           #|\n");
    printf("|#                                                     #|\n");
    printf("|#######################################################|\n");
    printf("└───────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(servi.servi, 55, "Digite o novo serviço:");

    arq_servicos = fopen("./data/servicos.csv", "at");
    if(arq_servicos == NULL){
        printf("\t Erro ao abrir o arquivo serviços\n");
        enter();
        return;
    }
    fprintf(arq_servicos, "%s\n", servi.servi);
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
    printf("Serviço: %s", servi.servi);
    enter();
}


void edit_servicos(void){
    limpa_tela();

    FILE *arq_servicos;
    FILE *arq_servicos_temp;

    Servicos servi;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|############################################################|\n");
    printf("|#                                                          #|\n");
    printf("|#               {Serviço -> Editar Serviços}               #|\n");
    printf("|#                                                          #|\n");
    printf("|############################################################|\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(servi.servi_lido, 55, "Digite o servico que deseja editar:");

    arq_servicos = fopen("./data/servicos.csv", "rt");
    arq_servicos_temp = fopen("./data/servicos_temp.csv", "wt");
    if(arq_servicos == NULL || arq_servicos_temp == NULL){
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while(fscanf(arq_servicos, "%[^\n]\n") == 1){
        if(strcmp(servi.servi, servi.servi_lido) != 0){
            fprintf(arq_servicos_temp, "%s\n", servi.servi);
        }
        else{
            input(servi.servi, 55, "Digite o serviço: ");
            fprintf(arq_servicos_temp, "%s", servi.servi);
        }
    }

    fclose(arq_servicos);
    fclose(arq_servicos_temp);
    remove("./data/servicos.csv");
    rename("./data/servicos_temp.csv", "./data/servicos.csv");

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|############################################################|\n");
    printf("|#                                                          #|\n");
    printf("|#                    {Serviço Editado!}                    #|\n");
    printf("|#                                                          #|\n");
    printf("|############################################################|\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Serviço editado: %s", servi.servi);
    enter();
}


void list_servicos(void){
    limpa_tela();

    FILE *arq_servicos;
    Servicos servi;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|############################################################|\n");
    printf("|#                                                          #|\n");
    printf("|#               {Serviço -> Listar Serviços}               #|\n");
    printf("|#                                                          #|\n");
    printf("|############################################################|\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    
    arq_servicos = fopen("./data/servicos.csv", "rt");
    if(arq_servicos == NULL){
        printf("\t Erro ao abrir o arquivo serviços.\n");
        printf("\t {Digite ENTER para continuar}\n");
        return;
    }
    while(!feof(arq_servicos)){
        fscanf(arq_servicos, "%[^;]", servi.servi);
        fgetc(arq_servicos);
        
    }
    fclose(arq_servicos);
    return;
}


void exclu_servicos(void){
    limpa_tela();

    FILE *arq_servicos;
    FILE *arq_servicos_temp;
    Servicos servi;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|############################################################|\n");
    printf("|#                                                          #|\n");
    printf("|#                   {Serviço -> Excluir}                   #|\n");
    printf("|#                                                          #|\n");
    printf("|############################################################|\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(servi.servi_lido, 55, "Informe o seriço a ser removido: ");

    arq_servicos = fopen("./data/servicos.csv", "rt");
    arq_servicos_temp = fopen("./data/servicos_temp.csv", "wt");
    if(arq_servicos == NULL || arq_servicos_temp == NULL){
        printf("Erro ao abrir o arquivo!");
        enter();
        return;
    }

    while(fscanf(arq_servicos, "%[\n]\n", servi.servi) == 1){
        if(strcmp(servi.servi, servi.servi_lido) != 0){
            fprintf(arq_servicos_temp, "%s\n", servi.servi);
        }
    }

    fclose(arq_servicos);
    fclose(arq_servicos_temp);
    remove("./data/servicos.csv");
    rename("./data/servicos_temp.csv", "./data/servicos.csv");

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|############################################################|\n");
    printf("|#                                                          #|\n");
    printf("|#                    {Serviço Excluido}                    #|\n");
    printf("|#                                                          #|\n");
    printf("|############################################################|\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    enter();
}


void atri_servico(void){
    limpa_tela();

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────┐\n");
    printf("|#############################################################|\n");
    printf("|#                                                           #|\n");
    printf("|#       {Serviços -> Atribuir serviço ao funcionario}       #|\n");
    printf("|#                                                           #|\n");
    printf("|#############################################################|\n");
    printf("└─────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    enter();
}