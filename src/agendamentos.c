#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"
#include "agendamentos.h"
#include "utilidades.h"
#include "telas.h"

typedef struct servicos Servicos;

void modulo_agendamentos(void){

    char op;

    do {
        op = tela_agendamentos();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                cad_agendamentos();
                break;
            case '2':
                edit_agendamentos();
                break;
            case '3':
                list_agendamentos();
                break;
            case '4':
                exclu_agendamentos();
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0'); 
}   


char tela_agendamentos(void){
    limpa_tela();

    char op;

    tela_menu_agendamentos();
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}


void cad_agendamentos(void){

    FILE *arq_agendamentos;
    Agendamentos* agendamento;
    agendamento = (Agendamentos*)malloc(sizeof(Agendamentos));

    tela_cad_agendamentos();

    printf("\nID do agendamento\n");
    ler_id(agendamento->id_agendamento, sizeof(agendamento->id_agendamento));
    ler_cpf(agendamento->cpf_funcionario, sizeof(agendamento->cpf_funcionario));
    ler_n_quarto(agendamento->n_quarto, sizeof(agendamento->n_quarto));
    printf("\nID do serviço\n");
    ler_id(agendamento->id_servico, sizeof(agendamento->id_servico));
    agendamento->status = True; // Pendente

    arq_agendamentos = fopen("./data/agendamentos.dat", "ab");
    if (arq_agendamentos == NULL) {
        printf("\t Erro ao abrir o arquivo agendamentos.\n");
        free(agendamento);
        enter();
        return;
    }
    fwrite(agendamento, sizeof(Agendamentos), 1, arq_agendamentos);
    fclose(arq_agendamentos);
    free(agendamento);
    printf("Agendamento cadastrado com sucesso!\n");
    enter();

}


void edit_agendamentos(void){

    FILE *arq_agendamentos;
    Agendamentos *agendamento;
    agendamento = (Agendamentos*)malloc(sizeof(Agendamentos));
    char id_agendamento_lido[7];
    int encontrado = False;
    

    tela_edit_agendamentos();
    ler_id(id_agendamento_lido, sizeof(id_agendamento_lido));
    
    arq_agendamentos = fopen("./data/agendamentos.dat", "r+b");
    if (arq_agendamentos == NULL) {
        printf("\t Erro ao abrir o arquivo agendamentos.\n");
        free(agendamento);
        enter();
        return;
    }

    while(fread(agendamento, sizeof(Agendamentos), 1, arq_agendamentos)){
        if(strcmp(agendamento->id_agendamento, id_agendamento_lido) == 0){
            encontrado = True;
            printf("Agendamento encontrado! Informe os novos dados:\n");

            switch_edit_agendamentos(agendamento);

            fseek(arq_agendamentos, (-1)*sizeof(Agendamentos), SEEK_CUR);
            fwrite(agendamento, sizeof(Agendamentos), 1, arq_agendamentos);

            printf("Agendamento atualizado com sucesso!\n");
            enter();
            break; //adicionado para previnir bug no windows
        }
    }

    fclose(arq_agendamentos);

    if (!encontrado) {
        printf("Agendamento não encontrado.\n");
        enter();
    }

    free(agendamento);


}


void list_agendamentos(void){

    FILE *arq_agendamentos;
    Agendamentos *agendamento;
    agendamento = (Agendamentos*)malloc(sizeof(Agendamentos));

    tela_list_agendamentos();
    
    arq_agendamentos = fopen("./data/agendamentos.dat", "rb");
    if (arq_agendamentos == NULL) {
        printf("\t Erro ao abrir o arquivo agendamentos.\n");
        enter();
        return;
    }

    printf("AGENDAMENTOS CADASTRADOS:\n\n");
    printf("%-10s    %-20s %-10s  %-10s  %-10s\n", "ID AGENDAMENTO", "CPF FUNCIONARIO", "N° QUARTO", "ID SERVICO", "STATUS");
    printf("-----------------------------------------------------------------------\n");
    while (fread(agendamento, sizeof(Agendamentos), 1, arq_agendamentos)) {
        if (agendamento->status != -1) {
            printf("%-10s        %-20s %-10s %-10s  %-10s\n", agendamento->id_agendamento, agendamento->cpf_funcionario, agendamento->n_quarto, agendamento->id_servico, agendamento->status ? "Pendente" : "Concluido");
        }
    }
    printf("-----------------------------------------------------------------------\n");

    fclose(arq_agendamentos);
    free(agendamento);
    enter();
}


void exclu_agendamentos(void){

    FILE *arq_agendamentos;
    Agendamentos* agendamento;
    agendamento = (Agendamentos*)malloc(sizeof(Agendamentos));
    char id_agendamento_lido[7];
    int encontrado = False;
    int escolha;

    tela_exclu_agendamentos();
    ler_id(id_agendamento_lido, sizeof(id_agendamento_lido));

    arq_agendamentos = fopen("./data/agendamentos.dat", "r+b");
    if(arq_agendamentos == NULL){
        printf("Erro ao abrir o arquivo!");
        enter();
        return;
    }

    while(fread(agendamento, sizeof(Agendamentos), 1, arq_agendamentos)){
        if(strcmp(agendamento->id_agendamento, id_agendamento_lido) == 0){
            printf("Agendamento encontrado:\n");
            escolha = confirma_exclusao();
            if (escolha) {
                encontrado = True;
                agendamento->status = -1; // Marcado como excluído
                fseek(arq_agendamentos, (-1)*sizeof(Agendamentos), SEEK_CUR);
                fwrite(agendamento, sizeof(Agendamentos), 1, arq_agendamentos);
            } else if (!escolha) {
                encontrado = -1;
            }
            break; //adicionado para previnir bug no windows
        }
    }
    
    fclose(arq_agendamentos);
    free(agendamento);

    switch (encontrado) {
        case 0:
            printf("Agendamento nao encontrado na base de dados!\n");
            enter();
            break;
        case 1:
            printf("Agendamento excluido com sucesso!\n");
            enter();
            break;
        case -1:
            printf("Exclusao cancelada pelo usuario.\n");
            enter();
            break;
    }

}


char menu_edit_agendamentos(void){
    limpa_tela();

    char op;

    tela_menu_edit_agendamentos();
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}


void switch_edit_agendamentos(Agendamentos*agendamento){
    
    char op;

    do{
        op = menu_edit_agendamentos();
        switch (op){
            case '0':
                tela_voltar();
                break;
            case '1':
                ler_id(agendamento->id_agendamento, 7);
                enter();
                break;
            case '2':
                ler_cpf(agendamento->cpf_funcionario, 18);
                enter();
                break;
            case '3':
                ler_n_quarto(agendamento->n_quarto, 7);
                enter();
                break;
            case '4':
                ler_id(agendamento->id_servico, 7);
                enter();
                break;
            case '5':
                ler_status(&agendamento->status, sizeof(agendamento->status));
                enter();
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while(op != '0');
}


