#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicos.h"
#include "utilidades.h"
#include "tela_voltar_menu.h"

typedef struct servicos Servicos;

void modulo_servicos(void){

    char op;

    do {
        op = tela_servicos();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                cad_servico();
                break;
            case '2':
                list_servicos();
                break;
            case '3':
                exclu_servicos();
                break;
            default:
                tela_op_invalida();
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
    printf("|       [2] -> Listar serviços                         |\n");
    printf("|       [3] -> Apagar servico                          |\n");
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
    Servicos* servi;
    servi = (Servicos*)malloc(sizeof(Servicos));

    printf("\n");
    printf("┌───────────────────────────────────────────────────────┐\n");
    printf("|#######################################################|\n");
    printf("|#                                                     #|\n");
    printf("|#           {Serviços -> Cadastrar Serviço}           #|\n");
    printf("|#                                                     #|\n");
    printf("|#######################################################|\n");
    printf("└───────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(servi->servi, 55, "Digite o novo serviço:");

    arq_servicos = fopen("./data/servicos.dat", "ab");
    if(arq_servicos == NULL){
        printf("\t Erro ao abrir o arquivo serviços\n");
        enter();
        return;
    }
    fwrite(servi, sizeof(Servicos), 1, arq_servicos);
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
    printf("Serviço: %s", servi->servi);
    free(servi);
    enter();
}

void list_servicos(void){
    limpa_tela();

    FILE *arq_servicos;
    Servicos *servi;
    servi = (Servicos*)malloc(sizeof(Servicos));

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|############################################################|\n");
    printf("|#                                                          #|\n");
    printf("|#               {Serviço -> Listar Serviços}               #|\n");
    printf("|#                                                          #|\n");
    printf("|############################################################|\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    
    arq_servicos = fopen("./data/servicos.dat", "rb");
    if(arq_servicos == NULL){
        printf("\t Erro ao abrir o arquivo serviços.\n");
        enter();
        return;
    }

    printf("SERVICOS CADASTRADOS:\n");
    while (fread(servi, sizeof(Servicos), 1, arq_servicos)) {
        printf("%s\n", servi->servi);
    }

    fclose(arq_servicos);
    free(servi);
    enter();
}


void exclu_servicos(void){
    limpa_tela();

    FILE *arq_servicos;
    FILE *arq_servicos_temp;
    Servicos* servi;
    servi = (Servicos*)malloc(sizeof(Servicos));
    char servi_lido[55];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|############################################################|\n");
    printf("|#                                                          #|\n");
    printf("|#                   {Serviço -> Excluir}                   #|\n");
    printf("|#                                                          #|\n");
    printf("|############################################################|\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(servi_lido, 55, "Informe o seriço a ser removido: ");

    arq_servicos = fopen("./data/servicos.dat", "rb");
    arq_servicos_temp = fopen("./data/servicos_temp.dat", "wb");
    if(arq_servicos == NULL || arq_servicos_temp == NULL){
        printf("Erro ao abrir o arquivo!");
        enter();
        return;
    }

    while(fread(servi, sizeof(Servicos), 1, arq_servicos)){
        if(strcmp(servi_lido, servi->servi) != 0){
            fwrite(servi->servi, sizeof(Servicos), 1, arq_servicos_temp);
        }
    }

    fclose(arq_servicos);
    fclose(arq_servicos_temp);
    remove("./data/servicos.dat");
    rename("./data/servicos_temp.dat", "./data/servicos.dat");
    free(servi);

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