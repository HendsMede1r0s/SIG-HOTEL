#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // ver se tem letra e espaco
#include "funcionarios.h"
#include "utilidades.h"
#include "tela_voltar_menu.h"
#include "leitura.h"

typedef struct funcionarios Funcionarios;

void modulo_funcionarios(void){

    char op;

    do {
        op = tela_funcionarios();
        switch (op) {
            case '0':
                tela_voltar();
                break;
            case '1':
                cad_funcionarios();
                break;
            case '2':
                edit_funcionarios();
                break;
            case '3':
                list_funcionarios();
                break;
            case '4':
                busc_funcionarios();
                break;
            case '5':
                exclu_funcionarios();
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while (op != '0'); 
}


char tela_funcionarios(void){
    limpa_tela();

    char op;
    
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|                       -Funcionarios-                       |\n");
    printf("|                                                            |\n");
    printf("|────────────────────────────────────────────────────────────|\n");
    printf("|                                                            |\n");
    printf("|        [1] -> Cadastar                                     |\n");
    printf("|        [2] -> Editar informacoes                           |\n");
    printf("|        [3] -> Listar funcionarios                          |\n");
    printf("|        [4] -> Buscar funcionarios                          |\n");
    printf("|        [5] -> Excluir funcionarios                         |\n");
    printf("|        [0] -> Voltar                                       |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}


void cad_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#              {Funcionarios -> Cadastrar}              #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
    ler_cpf(fun->cpf, 18);
    
    if (verifica_cpf_funcionarios(fun->cpf)) {
        printf("CPF já cadastrado!");
        enter();
        free(fun);
        return;
    }

    ler_nome(fun->nome, 55);
    ler_cell(fun->cell, 18);
    fun->status = True;

    arq_funcionarios = fopen("./data/funcionarios.dat", "ab");
    if(arq_funcionarios == NULL){
        printf("\t Erro ao tentar abrir o arquivo de funcionarios.\n");
        enter();
        return;
    }
    fwrite(fun, sizeof(Funcionarios), 1, arq_funcionarios);
    
    
    limpa_tela();
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#         {funcionario cadastrado com sucesso!}         #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");

    fclose(arq_funcionarios);
    free(fun);
    enter();
}


void edit_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    char cpf_lido[18];
    int encontrado = False;

    printf("\n");
    printf("┌──────────────────────────────────────────────────────────┐\n");
    printf("|##########################################################|\n");
    printf("|#                                                        #|\n");
    printf("|#                {Funcionarios -> Editar}                #|\n");
    printf("|#                                                        #|\n");
    printf("|##########################################################|\n");
    printf("└──────────────────────────────────────────────────────────┘\n");
    printf("\n");
    ler_cpf(cpf_lido, 18);

    arq_funcionarios = fopen("./data/funcionarios.dat", "r+b");
    if(arq_funcionarios == NULL){
        printf("Erro ao abrir o arquivo!\n");
        enter();
        return;
    }

    while(fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)){
        if(strcmp(cpf_lido, fun->cpf) == 0){
            exib_funcionario(fun);
            enter();
            switch_edit_funcionarios(fun);
            encontrado = True;

            fseek(arq_funcionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
            fwrite(fun, sizeof(Funcionarios), 1, arq_funcionarios);

            limpa_tela();
            exib_funcionario(fun);
            enter();
        }
    }

    fclose(arq_funcionarios);

    if(!encontrado){
        printf("Funcionario não encotrado no banco de dados!");
        enter();
    }

    free(fun);

}


void busc_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    char cpf_lido[18];
    int encontrado = False;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────┐\n");
    printf("|########################################################|\n");
    printf("|#                                                      #|\n");
    printf("|#               {Funcionarios -> Exibir}               #|\n");
    printf("|#                                                      #|\n");
    printf("|########################################################|\n");
    printf("└────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cpf_lido, 18, "Digite o CPF do funcionario:");

    arq_funcionarios = fopen("./data/funcionarios.dat", "rb");
    if(arq_funcionarios == NULL){
        printf("\t Erro ao abrir o arquivo de funcionarios. \n");
        enter();
        return;
    }
    while(fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)){
        if(strcmp(cpf_lido, fun->cpf) == 0){
            encontrado = True;
            printf("*ENCONTRADO*\n");
            exib_funcionario(fun);
            enter();
        }
    }

    fclose(arq_funcionarios);
    free(fun);

    if (!encontrado) {
        printf("Funcionario não encontrado do banco de dados!");
        enter();
    }
    
}

typedef struct novo_fun Novo_fun;

struct novo_fun {
    char* cpf;
    char* nome;
    char* cell;
    Novo_fun* prox;
};


void list_funcionarios(void) {
    limpa_tela();

    FILE *arq_funcionarios;
    Funcionarios fun;
    Novo_fun* lista = NULL;
    Novo_fun* novo;
    Novo_fun* anter;
    Novo_fun* atual;

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#         {Funcionarios -> Listar funcionarios}         #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");

    arq_funcionarios = fopen("./data/funcionarios.dat", "rb");
    if (arq_funcionarios == NULL) {
        printf("Erro ao abrir o arquivo!");
        enter();
        return;
    }

    lista = NULL;
    while (fread(&fun, sizeof(Funcionarios), 1, arq_funcionarios)) {
        //Verificar se o registro é válido
        if (fun.nome[0] == '\0') {
            continue; // Pula registros vazios
        }


        novo = (Novo_fun*)malloc(sizeof(Novo_fun));
        
        // Alocar e copiar strings
        novo->nome = malloc(strlen(fun.nome) + 1);
        novo->cell = malloc(strlen(fun.cell) + 1);
        novo->cpf = malloc(strlen(fun.cpf) + 1);
        
        strcpy(novo->nome, fun.nome);
        strcpy(novo->cell, fun.cell);
        strcpy(novo->cpf, fun.cpf);

        // LÓGICA DE INSERÇÃO ORDENADA
        if (lista == NULL) {
            lista = novo;
            novo->prox = NULL;
        } 
        else if (strcasecmp(novo->nome, lista->nome) < 0) {
            novo->prox = lista;
            lista = novo;
        } 
        else {
            anter = lista;
            atual = lista->prox;
            
            while ((atual != NULL) && strcasecmp(atual->nome, novo->nome) < 0) {
                anter = atual;
                atual = atual->prox;
            }
            
            anter->prox = novo;
            novo->prox = atual;
        }
    }
    fclose(arq_funcionarios);

    // Exibir lista
    printf("%-15s %-30s %-15s\n", "NOME", "CPF", "TELEFONE");
    printf("--------------- ------------------------------ ---------------\n");
    
    atual = lista;
    while (atual != NULL) {
        printf("%-15s %-30s %-15s\n", atual->nome, atual->cpf, atual->cell);
        atual = atual->prox;
    }
    printf("--------------- ------------------------------ ---------------\n");

    // Liberar memória
    atual = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(atual->nome);
        free(atual->cell);
        free(atual->cpf);
        free(atual);
        atual = lista;
    }
    
    enter();
}


void exclu_funcionarios(void){
    limpa_tela();

    FILE *arq_funcionarios;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    char cpf_lido[18];
    int escolha;
    int encontrado = False;

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#               {Funcionarios -> Excluir}               #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
    input(cpf_lido, 18, "Digite o CPF do funcionario a ser excluido:");

    arq_funcionarios = fopen("./data/funcionarios.dat", "r+b");
    if(arq_funcionarios == NULL){
        printf("Erro ao abrir o arquivo!");
        enter();
        return;
    }

    while(fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)){
        if((strcmp(cpf_lido, fun->cpf) == 0) && (fun->status)) {
            
            exib_funcionario(fun);
            escolha = confirma_exclusao();
            if (escolha) {
                fun->status = False;
                encontrado = True;
                fseek(arq_funcionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
                fwrite(fun, sizeof(Funcionarios), 1, arq_funcionarios);
            } else if (!escolha) {
                encontrado = -1;
                free(fun);
            }
        }
    }

    fclose(arq_funcionarios);
    free(fun);

    switch (encontrado) {
        case 0:
            printf("Funcionario não encontrado na base de dados!");
            enter();
            break;
        case 1:
            printf("Funcionario excluido com sucesso!");
            enter();
            break;
        case -1:
            printf("Exclusão cancelada!");
            enter();
            break;
    }
    
}


void exib_funcionario(Funcionarios *fun){
    printf("\n");
    printf("CPF: %s\n", fun->cpf);
    printf("NOME: %s\n", fun->nome);
    printf("TELEFONE: %s\n", fun->cell);
    printf("STATUS: %s\n", fun->status ? "Ativo" : "Excluido");
}


char menu_edit_funcionarios(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|                       -Funcionarios-                       |\n");
    printf("|                                                            |\n");
    printf("|────────────────────────────────────────────────────────────|\n");
    printf("|                                                            |\n");
    printf("|        [1] -> CPF                                          |\n");
    printf("|        [2] -> Nome                                         |\n");
    printf("|        [3] -> Cell                                         |\n");
    printf("|        [0] -> Voltar                                       |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o numero do que deseja editar: ");
    scanf("%c", &op);
    getchar();
    return op;
}


void switch_edit_funcionarios(Funcionarios *fun){

    char op;

    do{
        op = menu_edit_funcionarios();
        switch (op){
            case '0':
                tela_voltar();
                break;
            case '1':
                ler_cpf(fun->cpf, 18);
                break;
            case '2':
                ler_nome(fun->nome, 55);
                break;
            case '3':
                ler_cell(fun->cell, 18);
                break;
            default:
                tela_op_invalida();
                break;
        }
    } while(op != '0');
}


int verifica_cpf_funcionarios(const char *cpf_a_verificar){
    //recebe um cpf e verifica se ele já esta cadastrado
    FILE *arq_funcionarios;
    Funcionarios *fun_lido;
    fun_lido = (Funcionarios*)malloc(sizeof(Funcionarios));

    arq_funcionarios = fopen("./data/funcionarios.dat", "rb");
    if (arq_funcionarios == NULL) {
        free(fun_lido);
        return False;
    }

    while (fread(fun_lido, sizeof(Funcionarios), 1, arq_funcionarios) == 1) {
        if (strcmp(fun_lido->cpf, cpf_a_verificar) == 0) {
        return True;
        break;
        }
    }
    
    fclose(arq_funcionarios);
    free(fun_lido);
    return False;
}


char* pega_nome_funcionario(const char *cpf_funcionario){
    //recebe um cpf e retorna o nome do hospede
    FILE *arq_funcionarios;
    Funcionarios *fun_lido;
    fun_lido = (Funcionarios*)malloc(sizeof(Funcionarios));
    static char nome_funcionario [55];

    arq_funcionarios = fopen("./data/funcionarios.dat", "rb");
    if (arq_funcionarios == NULL) {
        strcpy(nome_funcionario, "Erro ao abrir o arquivo!");
        return nome_funcionario;
    }

    while (fread(fun_lido, sizeof(Funcionarios), 1, arq_funcionarios)) {
        if (strcmp(fun_lido->cpf, cpf_funcionario) == 0) {
            strncpy(nome_funcionario, fun_lido->nome, sizeof(nome_funcionario) - 1);
            nome_funcionario[sizeof(nome_funcionario) - 1] = '\0';
            fclose(arq_funcionarios);
            free(fun_lido);
            return nome_funcionario;
        }
    }
    
    fclose(arq_funcionarios);
    free(fun_lido);
    strcpy(nome_funcionario, "Hospede nao encontrado!");
    return nome_funcionario;
}
