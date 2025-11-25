#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"
#include "utilidades.h"
#include "quartos.h"
#include "tela_voltar_menu.h"
#include "hospedes.h"
#include "reservas.h"
#include "servicos.h"
#include "agendamentos.h"
#include "funcionarios.h"

void modulo_relatorios(void){

    char op;

    do {
        op = tela_relatorios();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                relatorio_hospedes();
                break;
            case '2':
                relatorio_funcionarios();
                break;
            case '3':
                relatorio_quartos();
                break;
            case '4':
                relatorio_servicos();
                break;
            case '5':
                relatorio_reservas();
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0'); 
}


char tela_relatorios(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────┐\n");
    printf("|                                                |\n");
    printf("|                   RELATORIOS                   |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|       [1] -> Relatorio de hospedes             |\n");
    printf("|       [2] -> Relatorio de funcionarios         |\n");
    printf("|       [3] -> Relatorio de quartos              |\n");
    printf("|       [4] -> Relatorio de servicos             |\n");
    printf("|       [5] -> Relatorio de reservas             |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("|                                                |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opcao: ");
    scanf("%c", &op);
    getchar();
    return op;
}


char tela_relatorio_quartos(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────┐\n");
    printf("|                                                |\n");
    printf("|              RELATORIOS -> QUARTOS             |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|       [1] -> Quartos disponiveis               |\n");
    printf("|       [2] -> Quartos por andar                 |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("|                                                |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opcao: ");
    scanf("%c", &op);
    getchar();
    return op;
}


void quartos_disponiveis(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos *quar;
    quar = (Quartos*)malloc(sizeof(Quartos));
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Quartos disponiveis}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    
    arq_quartos = fopen("./data/quartos.dat", "rb");

    if (arq_quartos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        enter();
        return;
    }

    printf("Quartos disponiveis:\n");
    printf("\n");
    while (fread(quar, sizeof(Quartos), 1, arq_quartos)) {
        if (quar->status == 0) {
            printf("%s\n", quar->n_quarto);
            encontrado = True;
        }
    }
    
    enter();

    fclose(arq_quartos);
    free(quar);

    if (!encontrado) {
        printf("\nNenhum quarto disponível no momento.\n");
        enter();
    }

}


void quartos_por_andar(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos *quar;
    quar = (Quartos*)malloc(sizeof(Quartos));
    char n_andar_lido [5];
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Quartos por andar}                    #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(n_andar_lido, 7, "Digite o n° do andar: ");
    
    arq_quartos = fopen("./data/quartos.dat", "rb");
    if (arq_quartos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        enter();
        return;
    }

    while (fread(quar, sizeof(Quartos), 1, arq_quartos)) {
        if (strncmp(n_andar_lido, quar->n_quarto, 1) == 0) {
            printf("%s\n", quar->n_quarto);
            encontrado = True;
        }
    }
    
    fclose(arq_quartos);
    
    if (!encontrado) {
        printf("Nenhum quarto nesse andar!");
    }

    free(quar);
    enter();

}


void relatorio_quartos(void){

    char op;

    do{
        op = tela_relatorio_quartos();
        switch (op)
        {
        case '0':
            tela_voltar();
            break;
        case '1':
            quartos_disponiveis();
            break;
        case '2':
            quartos_por_andar();
            break;
        default:
            tela_op_invalida();
            break;
        }

    }while(op != '0');
}


char tela_relatorio_hospedes(void) {
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────┐\n");
    printf("|              RELATORIOS -> HOSPEDES            |\n");
    printf("|                                                |\n");
    printf("|       [1] -> Lista filtrada por nome           |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\nDigite uma opção: ");

    scanf("%c", &op);
    getchar();
    return op;
}


void relatorio_hospedes(void) {
    char op;

    do {
        op = tela_relatorio_hospedes();
        switch (op) {
        case '0':
            tela_voltar();
            break;
        case '1':
            relatorio_hospedes_filtrado();
            break;
        default:
            tela_op_invalida();
            break;
        }
    } while (op != '0');
}


void relatorio_hospedes_filtrado(void) {
    limpa_tela();

    FILE *arq_hospedes;
    Hospedes *hos;
    hos = (Hospedes*) malloc(sizeof(Hospedes));
    int encontrado = False;
    char filtro[10];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                 {Lista Filtrada por Nome}                #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");

    arq_hospedes = fopen("./data/hospedes.dat", "rb");

    if (arq_hospedes == NULL) {
        printf("Erro ao abrir o arquivo de hóspedes.\n");
        enter();
        free(hos);
        return;
    }

    printf("Digite a primeira letra(s) do nome: ");
    fgets(filtro, sizeof(filtro), stdin);
    filtro[strcspn(filtro, "\n")] = '\0';

    printf("\nHóspedes encontrados:\n");
    printf("---------------------------------------------\n");
    printf("%-20s %-15s %-10s\n", "Nome", "CPF", "Status");
    printf("---------------------------------------------\n");

    while (fread(hos, sizeof(Hospedes), 1, arq_hospedes)) {
        if (strncmp(hos->nome, filtro, strlen(filtro)) == 0) {
            printf("%-20s %-15s %c\n", hos->nome, hos->cpf, hos->status);
            encontrado = True;
        }
    }

    fclose(arq_hospedes);

    if (!encontrado) {
        printf("\nNenhum hóspede encontrado com esse filtro.\n");
    }

    free(hos);
    enter();

}


char tela_relatorio_funcionarios(void) {
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────┐\n");
    printf("|           RELATORIOS -> FUNCIONARIOS           |\n");
    printf("|                                                |\n");
    printf("|       [1] -> Lista filtrada por nome           |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\nDigite uma opção: ");

    scanf("%c", &op);
    getchar();
    return op;
}


void relatorio_funcionarios(void) {
    char op;

    do {
        op = tela_relatorio_funcionarios();
        switch (op) {
        case '0':
            tela_voltar();
            break;
        case '1':
            relatorio_funcionarios_filtrado();
            break;
        default:
            tela_op_invalida();
            break;
        }
    } while (op != '0');
}


void relatorio_funcionarios_filtrado(void) {
    limpa_tela();

    FILE *arq_funcionarios;
    Funcionarios *fun;
    fun = (Funcionarios*) malloc(sizeof(Funcionarios));
    int encontrado = False;
    char filtro[10];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                 {Lista Filtrada por Nome}                #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");

    arq_funcionarios = fopen("./data/funcionarios.dat", "rb");

    if (arq_funcionarios == NULL) {
        printf("Erro ao abrir o arquivo de funcionários.\n");
        enter();
        free(fun);
        return;
    }

    //printf("Digite a primeira letra(s) do nome: ");
    //fgets(filtro, sizeof(filtro), stdin);
    input(filtro, sizeof(filtro), "Digite a primeira letra(s) do nome: ");
    filtro[strcspn(filtro, "\n")] = '\0';

    printf("\nFuncionários encontrados:\n");
    printf("---------------------------------------------\n");
    printf("%-20s %-15s %-10s\n", "Nome", "CPF", "Status");
    printf("---------------------------------------------\n");

    while (fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)) {
        if (strncmp(fun->nome, filtro, strlen(filtro)) == 0) {
            printf("%-20s %-15s %d\n", fun->nome, fun->cpf, fun->status);
            encontrado = True;
        }
    }

    fclose(arq_funcionarios);

    if (!encontrado) {
        printf("\nNenhum funcionário encontrado com esse filtro.\n");
    }

    free(fun);
    enter();

}


char tela_relatorio_reservas(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────┐\n");
    printf("|             RELATORIOS -> RESERVAS             |\n");
    printf("|                                                |\n");
    printf("|       [1] -> Listar reservas ampliado          |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\nDigite uma opção: ");

    scanf("%c", &op);
    getchar();
    return op;
}


void list_reservas_ampliado(void){
    limpa_tela();

    FILE *arq_reservas;
    Reservas *res;
    res = (Reservas*)malloc(sizeof(Reservas));
    char data_reserva_formatado [14];
    char data_atendimento_formatado [14];
    char nome_hospede [55];
    char nome_funcionario [55];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Hospedes -> Listar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    
    arq_reservas = fopen("./data/reservas.dat", "rb");
    if (arq_reservas == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    printf("%-4s  %-18s   %-18s   %-14s  %-14s\n", "Quarto", "Hospede", "Funcionario", "Data Reserva", "Data Atendimento");
    printf("------  ------------------   ------------------   --------------  --------------\n");
    while (fread(res, sizeof(Reservas), 1, arq_reservas)) {
        if (res->status) {
            // Formata as datas para exibição
            strncpy(data_reserva_formatado, formata_data(res->data_reserva), sizeof(data_reserva_formatado) - 1);
            data_reserva_formatado[sizeof(data_reserva_formatado) - 1] = '\0';
            strncpy(data_atendimento_formatado, formata_data(res->data_atendimento), sizeof(data_atendimento_formatado) - 1);
            data_atendimento_formatado[sizeof(data_atendimento_formatado) - 1] = '\0';
            
            // Pega os nomes do hospede e funcionario
            strncpy(nome_hospede, pega_nome_hospede(res->cpf_hospede), sizeof(nome_hospede) - 1);
            nome_hospede[sizeof(nome_hospede) - 1] = '\0';
            strncpy(nome_funcionario, pega_nome_funcionario(res->cpf_funcionario), sizeof(nome_funcionario) - 1);
            nome_funcionario[sizeof(nome_funcionario) - 1] = '\0';

            printf("%-4s    %-18s   %-18s   %-14s  %-14s\n", res->n_quarto, nome_hospede, nome_funcionario, data_reserva_formatado, data_atendimento_formatado);
        }
    }
    printf("------  ------------------   ------------------   --------------  --------------\n");
    fclose(arq_reservas);
    free(res);
    enter();
}


void relatorio_reservas(void){
    char op;

    do {
        op = tela_relatorio_reservas();
        switch (op) {
        case '0':
            tela_voltar();
            break;
        case '1':
            list_reservas_ampliado();
            break;
        default:
            tela_op_invalida();
            break;
        }
    } while (op != '0');
}


char tela_relatorio_servicos(void) {
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────┐\n");
    printf("|             RELATORIOS -> SERVIÇOS             |\n");
    printf("|                                                |\n");
    printf("|       [1] -> Listar Servicos por Quarto        |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\nDigite uma opção: ");

    scanf("%c", &op);
    getchar();
    return op;
}


void relatorio_servicos (void) {
    char op;

    do {
        op = tela_relatorio_servicos();
        switch (op) {
        case '0':
            tela_voltar();
            break;
        case '1':
            relatorio_servicos_quarto();
            break;
        default:
            tela_op_invalida();
            break;
        }
    } while (op != '0');
}


void relatorio_servicos_quarto (void) {
    limpa_tela();

    FILE *arq_agendamentos, *arq_funcionarios, *arq_servicos;
    Quartos *quartos;
    quartos = (Quartos*)malloc(sizeof(Quartos));
    Funcionarios *fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    Servicos *servicos;
    servicos = (Servicos*)malloc(sizeof(Servicos));
    Agendamentos *agendamentos;
    agendamentos = (Agendamentos*)malloc(sizeof(Agendamentos));

    int encontrado = False;
    
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#               {Listar Serviços por Quarto}               #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");

    arq_agendamentos = fopen("./data/agendamentos.dat", "rb");

    if (arq_agendamentos == NULL) {
        printf("Erro ao abrir agendamentos!\n");
        free(quartos); free(fun); free(servicos); free(agendamentos);
        enter();
        return;
    }

    input(quartos->n_quarto, sizeof(quartos->n_quarto), "Digite o número do quarto: ");

    printf("\nServiços realizados no quarto %s:\n", quartos->n_quarto);
    printf("------------------------------------------------------------\n");
    printf("%-20s %-30s\n", "Funcionário", "Serviço");
    printf("------------------------------------------------------------\n");
    while (fread(agendamentos, sizeof(Agendamentos), 1, arq_agendamentos)) {
        if (strcmp(agendamentos->n_quarto, quartos->n_quarto) == 0) {
            
            // Pega o nome do funcionário
            arq_funcionarios = fopen("./data/funcionarios.dat", "rb");
            if (arq_funcionarios != NULL) {
                while (fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)) {
                    if (strcmp(fun->cpf, agendamentos->cpf_funcionario) == 0) {
                        break;
                    }
                }
                fclose(arq_funcionarios);
            }

            // Pega o nome do serviço
            arq_servicos = fopen("./data/servicos.dat", "rb");
            if (arq_servicos != NULL) {
                while (fread(servicos, sizeof(Servicos), 1, arq_servicos)) {
                    if (strcmp(servicos->id, agendamentos->id_servico) == 0) {
                        break;
                    }
                }
                fclose(arq_servicos);
            }

            printf("%-20s %-30s\n", fun->nome, servicos->servi);
            encontrado = True;
        }
    }

    fclose(arq_agendamentos);

    if (!encontrado) {
        printf("Nenhum serviço encontrado para esse quarto!\n");
    }

    free(fun);
    free(servicos);
    free(quartos);
    enter();

}