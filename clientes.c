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

int tela_clientes(){
    system("clear||cls");
    int op;
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
    scanf("%d", &op);
    getchar();
    printf("\n");
    return(op);
}
                
            
    
