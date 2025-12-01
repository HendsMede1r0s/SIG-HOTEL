#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionarios.h"
#include "utilidades.h"
#include "telas.h"
#include "leitura.h"

typedef struct funcionarios Funcionarios;
typedef struct novo_fun Novo_fun;

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

    char op;
    
    tela_menu_funcionarios();
    printf("Digite uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}


void cad_funcionarios(void){

    FILE *arq_funcionarios;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));

    tela_cad_funcionarios();
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
    printf("*Funcionario cadastrado com sucesso!*\n");
    fclose(arq_funcionarios);
    free(fun);
    enter();
}


void edit_funcionarios(void){

    FILE *arq_funcionarios;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    char cpf_lido[18];
    int encontrado = False;

    tela_edit_funcionarios();
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
            break; //adicionado para previnir bug no windows
        }
    }

    fclose(arq_funcionarios);

    if(!encontrado){
        printf("Funcionario não encotrado no banco de dados!");
        enter();
    }

    free(fun);

}


void list_funcionarios(void) {

    FILE *arq_funcionarios;
    Funcionarios *fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    Novo_fun* lista = NULL; // Cabeça da lista encadeada (inicialmente vazia)
    Novo_fun* novo;
    Novo_fun* anter;
    Novo_fun* atual;

    tela_list_hospedes();

    arq_funcionarios = fopen("./data/funcionarios.dat", "rb");
    if (arq_funcionarios == NULL) {
        printf("Erro ao abrir o arquivo!");
        enter();
        return;
    }

    lista = NULL;

    // Aloca e copia strings do arquivo para a lista
    while (fread(fun, sizeof(Funcionarios), 1, arq_funcionarios)) {

        novo = (Novo_fun*)malloc(sizeof(Novo_fun));
        
        // Aloca e copia strings do arquivo para a lista
        novo->nome = malloc(strlen(fun->nome) + 1); // Aloca memória para nome (+1 para \0)
        novo->cell = malloc(strlen(fun->cell) + 1); // Aloca memória para telefone
        novo->cpf = malloc(strlen(fun->cpf) + 1); // Aloca memória para CPF
        
        strcpy(novo->nome, fun->nome); // Copia nome do arquivo para o nó
        strcpy(novo->cell, fun->cell); // Copia telefone do arquivo para o nó
        strcpy(novo->cpf, fun->cpf); // Copia CPF do arquivo para o nó
        novo->status = fun->status; // Copia status do funcionário

        // Caso 1: Lista está vazia (primeira inserção)
        if (lista == NULL) {
            lista = novo; // Novo nó se torna a cabeça da lista
            novo->prox = NULL; // Define próximo como NULL (fim da lista)
        }

        // Caso 2: Inserção no início (novo nome é menor que o primeiro)
        else if (strcasecmp(novo->nome, lista->nome) < 0) {
            novo->prox = lista; // Novo aponta para a antiga cabeça
            lista = novo; // Novo se torna a nova cabeça
        }

        // Caso 3: Inserção no meio ou final da lista
        else {
            anter = lista; // Começa pelo primeiro elemento
            atual = lista->prox; // Próximo elemento para comparação

            // Percorre lista até encontrar posição correta ou chegar ao final
            while ((atual != NULL) && strcasecmp(novo->nome, atual->nome) > 0) {
                anter = atual; // Avança ponteiro anterior
                atual = atual->prox; // Avança ponteiro atual
            }
            
            // Insere novo nó entre 'anter' e 'atual'
            anter->prox = novo; // Nó anterior aponta para o novo
            novo->prox = atual; // Novo nó aponta para o atual (pode ser NULL)
        }
    }
    fclose(arq_funcionarios);

    printf("%-15s %-30s %-15s\n", "NOME", "CPF", "TELEFONE");
    printf("--------------- ------------------------------ ---------------\n");
    
    atual = lista; // Começa pela cabeça da lista
    while (atual != NULL) {
        printf("%-15s %-30s %-15s\n", atual->nome, atual->cpf, atual->cell);
        atual = atual->prox; // Avança para próximo nó
    }
    printf("--------------- ------------------------------ ---------------\n");

    // Liberar memória
    atual = lista; // Começa pela cabeça para liberar memória
    while (lista != NULL) {
        lista = lista->prox; // Avança cabeça para próximo elemento
        free(atual->nome);
        free(atual->cell);
        free(atual->cpf);
        free(atual); 
        atual = lista; // Atualiza ponteiro para próximo nó a ser liberado
    }
    
    enter();
}


void busc_funcionarios(void){

    FILE *arq_funcionarios;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    char cpf_lido[18];
    int encontrado = False;

    tela_busc_funcionarios();
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
            break; //adicionado para previnir bug no windows
        }
    }

    fclose(arq_funcionarios);
    free(fun);

    if (!encontrado) {
        printf("Funcionario não encontrado do banco de dados!");
        enter();
    }
    
}


void exclu_funcionarios(void){

    FILE *arq_funcionarios;
    Funcionarios* fun;
    fun = (Funcionarios*)malloc(sizeof(Funcionarios));
    char cpf_lido[18];
    int escolha;
    int encontrado = False;

    tela_exclu_funcionarios();
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
            }
            break; //adicionado para previnir bug no windows
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
    // " ? " funciona como if simplificado
    // se for true printa "ativo" se for false printa "excluido"
}


char menu_edit_funcionarios(void){

    char op;

    tela_menu_edit_funcionarios();
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
                exib_funcionario(fun);
                enter();
                break;
            case '2':
                ler_nome(fun->nome, 55);
                exib_funcionario(fun);
                enter();
                break;
            case '3':
                ler_cell(fun->cell, 18);
                exib_funcionario(fun);
                enter();
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
