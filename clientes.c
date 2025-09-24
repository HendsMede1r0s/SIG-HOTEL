#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

void modulo_clientes(void){

    char op;

    do {
        op = tela_clientes();
        switch (op) {
            case '1':
                getchar();
                break;
        }
    } while (op != '0'); 
}

char tela_clientes(void){
    system("clear||cls");
    char op;
    printf("\n");
    printf("___________________________________\n");
    printf("|                                  |\n");
    printf("|            Clientes              |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|        1 - Cadastar              |\n");
    printf("|        2 - Editar informacoes    |\n");
    printf("|        3 - Ver clientes          |\n");
    printf("|        0 - Voltar                |\n");
    printf("|__________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...\n");
    printf("Digite uma opçao: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return(op);
}

void cad_clientes(void){
    system("clear||cls");

    char cpf [18];
    char nome [55];
    char cell [18];
    char n_quarto [7];

    printf("\n");
    printf("|============================================================|\n");
    printf("|                                                            |\n");
    printf("|                   {Clientes -> Cadastrar}                  |\n");
    printf("|                                                            |\n");
    printf("|============================================================|\n");
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
    print("\n");
    printf("Digite o numero do quarto do cliente:");
    scanf("%s", n_quarto);
    getchar();
    printf("\n");

    system("clear||cls");
    printf("\n");
    printf("|============================================================|\n");
    printf("|                                                            |\n");
    printf("|              {Cliente cadastrado com sucesso!}             |\n");
    printf("|                                                            |\n");
    printf("|============================================================|\n");
    printf("\n");
    getchar();
    printf("\n");
}


void edit_clientes(void){
    system("clear||cls");

    char cpf [18];
    char nome [55];
    char cell [18];
    char n_quarto [7];

    printf("\n");
    printf("|============================================================|\n");
    printf("|                                                            |\n");
    printf("|                    {Clientes -> Editar}                    |\n");
    printf("|                                                            |\n");
    printf("|============================================================|\n");
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
    print("\n");
    printf("Digite o numero do quarto do cliente:");
    scanf("%s", n_quarto);
    getchar();
    printf("\n");

    system("clear||cls");
    printf("\n");
    printf("|============================================================|\n");
    printf("|                                                            |\n");
    printf("|              {Cliente editado com sucesso!}                |\n");
    printf("|                                                            |\n");
    printf("|============================================================|\n");
    printf("\n");
    getchar();
    printf("\n");
}
    
