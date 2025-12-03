#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"
#include "utilidades.h"
#include "leitura.h"
#include "quartos.h"
#include "telas.h"
#include "hospedes.h"
#include "reservas.h"
#include "servicos.h"
#include "agendamentos.h"
#include "funcionarios.h"

typedef struct novo_agendamento Novo_agendamento;

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

// Relatórios de Quartos

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
    printf("|       [3] -> Listar todos os quartos           |\n");
    printf("|       [0] -> Voltar                            |\n");
    printf("|                                                |\n");
    printf("└────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opcao: ");
    scanf("%c", &op);
    getchar();
    return op;
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
        case '3':
            listar_todos_os_quartos();
            break;
        default:
            tela_op_invalida();
            break;
        }

    }while(op != '0');
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


void listar_todos_os_quartos(void){
    limpa_tela();

    FILE *arq_quartos;
    Quartos *quar;
    quar = (Quartos*)malloc(sizeof(Quartos));
    Quar_lista *lista = NULL; // Cabeça de lista
    Quar_lista *novo_quar; // Novo nó
    Quar_lista *anter; // Nó anterior para inserção no fim
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Lista de Todos os Quartos}            #│\n");
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

    while (fread(quar, sizeof(Quartos), 1, arq_quartos)) {
        // Criar novo nó
        novo_quar = (Quar_lista*)malloc(sizeof(Quar_lista));
        //stdup serve como malloc + strcpy
        novo_quar->n_quarto = strdup(quar->n_quarto);
        novo_quar->cpf = strdup(quar->cpf);
        novo_quar->quan_pessoas = strdup(quar->quan_pessoas);
        novo_quar->status = quar->status;
        novo_quar->prox = NULL; //Novo nó aponta para NULL
        encontrado = True;

        // Inserir na lista direta
        if (lista == NULL) {
            // Inserção no início
            novo_quar->prox = lista; // Novo nó aponta para a lista atual (NULL)
            lista = novo_quar; // Novo nó se torna a cabeça
        }
        else {
            // Inserção no fim
            anter = lista; // Começa da cabeça
            while (anter->prox != NULL) { // Percorre até o último nó
                anter = anter->prox; // Avança para o próximo nó
            }
            anter->prox = novo_quar; // Último nó aponta para o novo nó
        }
    }

    fclose(arq_quartos);
    if (!encontrado) {
        printf("Nenhum quarto cadastrado no sistema.\n");
        deleta_quarto(lista); // Libera memória da lista
        free(quar); // Libera memória do quarto
        enter();
        return;
    }
    
    // Exibir lista
    printf("%-7s %-18s %-5s %-5s\n", "QUARTO", "CPF", "QUANTIDADE", "STATUS");
    printf("------- ------------------ ---------- ----------\n");
    Quar_lista* atual = lista;
    while (atual != NULL) {
        printf("%-7s %-18s %-5s      %-8s\n", atual->n_quarto, atual->cpf, atual->quan_pessoas, atual->status ? "OCUPADO" : "VAZIO");
        atual = atual->prox;
    }
    printf("------- ------------------ ---------- ----------\n");
    // " ? " é um operador ternário que funciona como um if simplificado
    // Se atual->status for verdadeiro (diferente de 0), imprime "OCUPADO", caso contrário, imprime "VAZIO".

    // Liberar memória
    deleta_quarto(lista);
    free(quar);
    enter();
}


// Relatórios de Hóspedes

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

    ler_letras(filtro, sizeof(filtro), "Digite a(s) primeira letra(s) do nome: ");
    filtro[strcspn(filtro, "\n")] = '\0';

    printf("\nHóspedes encontrados:\n");
    printf("--------------------------------\n");
    printf("%-20s %-15s\n", "Nome", "CPF");
    printf("--------------------------------\n");

    while (fread(hos, sizeof(Hospedes), 1, arq_hospedes)) {
        if ((strncmp(hos->nome, filtro, strlen(filtro)) == 0) && (hos->status)) {
            printf("%-20s %-15s\n", hos->nome, hos->cpf);
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

// Relatórios de Funcionários
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

    ler_letras(filtro, sizeof(filtro), "Digite a(s) primeira letra(s) do nome: ");
    filtro[strcspn(filtro, "\n")] = '\0';

    printf("\nFuncionários encontrados:\n");
    printf("--------------------------\n");
    printf("%-20s %-15s\n", "Nome", "CPF");
    printf("--------------------------\n");

    while (fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)) {
        if ((strncmp(fun->nome, filtro, strlen(filtro)) == 0) && (fun->status)) {
            printf("%-20s %-15s\n", fun->nome, fun->cpf);
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

// Relatórios de Reservas
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
            strncpy(data_reserva_formatado, formata_data(res->data_reserva), 11);
            data_reserva_formatado[11] = '\0';
            strncpy(data_atendimento_formatado, formata_data(res->data_atendimento), 11);
            data_atendimento_formatado[11] = '\0';
            
            // Pega os nomes do hospede e funcionario
            strncpy(nome_hospede, pega_nome_hospede(res->cpf_hospede), sizeof(nome_hospede));
            strncpy(nome_funcionario, pega_nome_funcionario(res->cpf_funcionario), sizeof(nome_funcionario));

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

// Relatórios de Serviços
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
    Funcionarios *fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    Servicos *servicos;
    servicos = (Servicos*)malloc(sizeof(Servicos));
    Agendamentos *agendamentos;
    agendamentos = (Agendamentos*)malloc(sizeof(Agendamentos));

    Novo_agendamento *lista = NULL;
    Novo_agendamento *novo;
    Novo_agendamento *temp;
    Novo_agendamento *atual;


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
        enter();
        return;
    }

    // Lista Dinâmica Invertida
    lista = NULL;
    int encontrado = False;

    // Percorre os agendamentos procurando os serviços do quarto informado
    while (fread(agendamentos, sizeof(Agendamentos), 1, arq_agendamentos)) {
        // Verifica se o agendamento é para o quarto informado
            
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
        // Cria um novo nó na lista
        novo = (Novo_agendamento*)malloc(sizeof(Novo_agendamento));
        // Aloca e copia os dados
        novo->nome_func = malloc(strlen(fun->nome) + 1);
        novo->nome_servico = malloc(strlen(servicos->servi) + 1);
        novo->status = agendamentos->status;
        strcpy(novo->nome_func, fun->nome);
        strcpy(novo->nome_servico, servicos->servi);
        novo->prox = lista; // Novo nó aponta para a lista atual
        lista = novo; // Novo nó se torna a nova cabeça da lista

        encontrado = True;
    }

    fclose(arq_agendamentos);

    if (!encontrado) {
        printf("Nenhum serviço encontrado para esse quarto!\n");
    } else {
        printf("---------------------------------------------------------------\n");
        printf("%-20s %-30s %-8s\n", "Funcionário", "Serviço", "Status");
        printf("---------------------------------------------------------------\n");
        
        // Percorre a lista para exibir (já está na ordem inversa)
        atual = lista;
        while (atual->prox != NULL) {
            printf("%-20s %-30s %-10s\n", atual->nome_func, atual->nome_servico, atual->status ? "Pendente" : "Concluido");
            atual = atual->prox;
        }
        printf("---------------------------------------------------------------\n");
    }

    // Libera a memória alocada para a lista
    atual = lista;
    while (atual != NULL) {
        temp = atual; // Armazena o nó atual
        atual = atual->prox; // Move para o próximo nó
        free(temp->nome_func);
        free(temp->nome_servico);
        free(temp);
    }

    enter();

}