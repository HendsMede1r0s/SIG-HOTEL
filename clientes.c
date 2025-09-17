#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

int tela_clientes(){
    system("clear||cls");
    int op_cliente;
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
    scanf("%d", &op_cliente);
    getchar();
    return(op_cliente);
}


int area_clientes(){
    int op_clientes = 4;
    while(op_clientes != 0){
        op_clientes = tela_clientes();
        if (op_clientes == 1){
            printf("Cadastro de clientes");
            getchar();
        }
        else if (op_clientes == 2){
            printf("Editar informações de clientes");
            getchar();
        }
        else if (op_clientes == 3){
            printf("Ver clientes cadastrados");
            getchar();
        }
        
    }
    return 0;
}
                
            
    
