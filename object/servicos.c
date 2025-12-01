#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"
#include "servicos.h"
#include "utilidades.h"
#include "telas.h"

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
                cad_servicos();
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

    char op;

    tela_menu_servicos();
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}


void cad_servicos(void){

    FILE *arq_servicos;
    Servicos* servi;
    servi = (Servicos*)malloc(sizeof(Servicos));

    tela_cad_servicos();
    input(servi->servi, 55, "Digite o novo serviço: ");
    ler_id(servi->id, 7);
    if (verifica_id(servi->id)) {
        printf("ID já cadastrado no sistema!");
        enter();
        free(servi);
        return;
    }

    arq_servicos = fopen("./data/servicos.dat", "ab");
    if(arq_servicos == NULL){
        printf("\t Erro ao abrir o arquivo serviços\n");
        enter();
        return;
    }
    fwrite(servi, sizeof(Servicos), 1, arq_servicos);
    fclose(arq_servicos);
    free(servi);

    printf("Servico cadastrado com sucesso!\n");
    enter();
}


void list_servicos(void){

    FILE *arq_servicos;
    Servicos *servi;
    servi = (Servicos*)malloc(sizeof(Servicos));

    tela_list_servicos();
    
    arq_servicos = fopen("./data/servicos.dat", "rb");
    if(arq_servicos == NULL){
        printf("\t Erro ao abrir o arquivo serviços.\n");
        enter();
        return;
    }

    printf("SERVICOS CADASTRADOS:\n\n");
    printf("%-15s %-15s\n","ID", "SERVICO");
    printf("--------------- ---------------\n");
    while (fread(servi, sizeof(Servicos), 1, arq_servicos)) {
        printf("%-15s %-15s\n",servi->id, servi->servi);
    }
    printf("--------------- ---------------\n");

    fclose(arq_servicos);
    free(servi);
    enter();
}


void exclu_servicos(void){

    FILE *arq_servicos;
    FILE *arq_servicos_temp;
    Servicos* servi;
    servi = (Servicos*)malloc(sizeof(Servicos));
    char servi_lido[55];

    tela_exclu_servicos();
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

//Verifica ID existente
int verifica_id(const char *id_a_verificar) {
    FILE *arq_servicos;
    Servicos *id_lido;
    id_lido = (Servicos*)malloc(sizeof(Servicos));

    arq_servicos = fopen("./data/servicos.dat", "rb");
    if (arq_servicos == NULL) {
        free(id_lido);
        return False;
    }

    while (fread(id_lido, sizeof(Servicos), 1, arq_servicos) == 1) {
        if (strcmp(id_lido->id, id_a_verificar) == 0) {
            return True;
            break;
        }
    }

    fclose(arq_servicos);
    free(id_lido);
    return False;
}