#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "utilidades.h"

//////////////////////////////
//funcoes do modulo clientes//
//////////////////////////////

void modulo_clientes(void){

    char op;

    do {
        op = tela_clientes();
        switch (op) {
            case '1':
                cad_clientes();
                break;
            case '2':
                edit_clientes();
                break;
            case '3':
                exib_clientes();
                break;
            case '4':
                exclu_clientes();
                break;
        }
    } while (op != '0'); 
}

char tela_clientes(void){
    limpa_tela();

    char op;

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│                                                            │\n");
    printf("│                          -Clientes-                        │\n");
    printf("│                                                            │\n");
    printf("│────────────────────────────────────────────────────────────│\n");
    printf("│                                                            │\n");
    printf("│        [1] -> Cadastar                                     │\n");
    printf("│        [2] -> Editar informacoes                           │\n");
    printf("│        [3] -> Exibir clientes                              │\n");
    printf("│        [4] -> Excluir clientes                             │\n");   
    printf("│        [0] -> Voltar                                       │\n");
    printf("│                                                            │\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite uma opçao: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return(op);
}

void cad_clientes(void){
    limpa_tela();

    char cpf [18];
    char nome [55];
    char cell [18];
    char n_quarto [7];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Clientes -> Cadastrar}                 #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o CPF do cliente:");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf("Digite o nome do cliente:");
    scanf("%s", nome);
    getchar();
    printf("\n");
    printf("Digite o telefone do cliente:");
    scanf("%s", cell);
    getchar();
    printf("\n");
    printf("Digite o numero do quarto do cliente:");
    scanf("%s", n_quarto);
    getchar();
    printf("\n");

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#            {Clientes cadastrado com sucesso!}            #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("{Digite ENTER para continuar}");
    getchar();
    printf("\n");
}


void edit_clientes(void){
    limpa_tela();

    char cpf [18];
    char nome [55];
    char cell [18];
    char n_quarto [7];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Clientes -> Editar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite as novas informaçoes do cliente.");
    printf("\n");
    printf("Digite o CPF do cliente:");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf("Digite o nome do cliente:");
    scanf("%s", nome);
    getchar();
    printf("\n");
    printf("Digite o telefone do cliente:");
    scanf("%s", cell);
    getchar();
    printf("\n");
    printf("Digite o numero do quarto do cliente:");
    scanf("%s", n_quarto);
    getchar();
    printf("\n");

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                    {Cliente editado!}                    #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("{Digite ENTER para continuar}");
    getchar();
    printf("\n");
}
    
void exib_clientes(void){
    limpa_tela();

    char cpf [18];
    char nome [55];
    char cell [18];
    char n_quarto [7];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Clientes -> Exibir}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o CPF do cliente a ser exibido:");
    scanf("%s", cpf);
    getchar();
    printf("\n");
}

void exclu_clientes(void){
    limpa_tela();

    char cpf [18];
    char nome [55];
    char cell [18];
    char n_quarto [7];

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Clientes -> Excluir}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Digite o CPF do cliente que deseja excluir:");
    scanf("%s", cpf);
    getchar();
    printf("\n");

    limpa_tela();
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                    {Cliente excluido!}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("{Digite ENTER para continuar}");
    getchar();
    printf("\n"); 
}