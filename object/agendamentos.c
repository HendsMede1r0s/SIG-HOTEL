#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"
#include "agendamentos.h"
#include "utilidades.h"
#include "tela_voltar_menu.h"

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

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|                   -Agendamentos-                           |\n");
    printf("|                                                            |\n");
    printf("|────────────────────────────────────────────────────────────|\n");
    printf("|                                                            |\n");
    printf("|       [1] -> Cadastrar Agendamentos                        |\n");
    printf("|       [2] -> Editar Agendamentos                           |\n");
    printf("|       [3] -> Listar Agendamentos                           |\n");
    printf("|       [4] -> Apagar Agendamento                            |\n");
    printf("|       [0] -> Voltar                                        |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void cad_agendamentos(void){
    limpa_tela();

    FILE *arq_agendamentos;
    Agendamentos* agendamento;
    agendamento = (Agendamentos*)malloc(sizeof(Agendamentos));

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|               {Agendamentos -> Cadastrar}                  |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(agendamento->id_agendamento, sizeof(agendamento->id_agendamento), "Informe o ID do agendamento: ");
    input(agendamento->cpf_funcionario, sizeof(agendamento->cpf_funcionario), "Informe o CPF do funcionário: ");
    input(agendamento->n_quarto, sizeof(agendamento->n_quarto), "Informe o número do quarto: ");
    input(agendamento->id_servico, sizeof(agendamento->id_servico), "Informe o ID do serviço: ");
    input(agendamento->status, sizeof(agendamento->status), "Informe o status: ");

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
    limpa_tela();

    FILE *arq_agendamentos;
    Agendamentos *agendamento;
    agendamento = (Agendamentos*)malloc(sizeof(Agendamentos));
    char id_agendamento_lido[7];
    int encontrado = False;
    

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|               {Agendamentos -> Editar}                     |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
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
            input(agendamento->cpf_funcionario, sizeof(agendamento->cpf_funcionario), "Informe o CPF do funcionário: ");
            input(agendamento->n_quarto, sizeof(agendamento->n_quarto), "Informe o número do quarto: ");
            input(agendamento->id_servico, sizeof(agendamento->id_servico), "Informe o ID do serviço: ");
            input(agendamento->status, sizeof(agendamento->status), "Informe o status: ");

            fseek(arq_agendamentos, (-1)*sizeof(Agendamentos), SEEK_CUR);
            fwrite(agendamento, sizeof(Agendamentos), 1, arq_agendamentos);

            printf("Agendamento atualizado com sucesso!\n");
            enter();
            break;
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
    limpa_tela();

    FILE *arq_agendamentos;
    Agendamentos *agendamento;
    agendamento = (Agendamentos*)malloc(sizeof(Agendamentos));

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|               {Agendamentos -> Listar}                     |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    
    arq_agendamentos = fopen("./data/agendamentos.dat", "rb");
    if (arq_agendamentos == NULL) {
        printf("\t Erro ao abrir o arquivo agendamentos.\n");
        enter();
        return;
    }

    printf("AGENDAMENTOS CADASTRADOS:\n\n");
    printf("%-10s %-20s %-10s %-10s %-10s\n", "ID AGENDAMENTO", "CPF FUNCIONARIO", "N° QUARTO", "ID SERVICO", "STATUS");
    printf("------------------------------------------------------------\n");
    while (fread(agendamento, sizeof(Agendamentos), 1, arq_agendamentos)) {
        printf("%-10s %-20s %-10s %-10s %-10s\n", agendamento->id_agendamento, agendamento->cpf_funcionario, agendamento->n_quarto, agendamento->id_servico, agendamento->status);
    }
    printf("------------------------------------------------------------\n");

    fclose(arq_agendamentos);
    free(agendamento);
    enter();
}

void exclu_agendamentos(void){
    limpa_tela();

    FILE *arq_agendamentos;
    FILE *arq_agendamentos_temp;
    Agendamentos* agendamento;
    agendamento = (Agendamentos*)malloc(sizeof(Agendamentos));
    char id_agendamento_lido[7];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|               {Agendamentos -> Excluir}                    |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(id_agendamento_lido, sizeof(id_agendamento_lido), "Informe o ID do agendamento a ser excluído: ");

    arq_agendamentos = fopen("./data/agendamentos.dat", "rb");
    arq_agendamentos_temp = fopen("./data/agendamentos_temp.dat", "wb");
    if(arq_agendamentos == NULL || arq_agendamentos_temp == NULL){
        printf("Erro ao abrir o arquivo!");
        enter();
        return;
    }

    while(fread(agendamento, sizeof(Agendamentos), 1, arq_agendamentos)){
        if(strcmp(agendamento->id_agendamento, id_agendamento_lido) != 0){
            fwrite(agendamento, sizeof(Agendamentos), 1, arq_agendamentos_temp);
        }
    }

    fclose(arq_agendamentos);
    fclose(arq_agendamentos_temp);
    remove("./data/agendamentos.dat");
    rename("./data/agendamentos_temp.dat", "./data/agendamentos.dat");
    free(agendamento);

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|               {Agendamento Excluido}                       |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    enter();
}


