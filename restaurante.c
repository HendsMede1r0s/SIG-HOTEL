#include "restaurante.h"

int tela_restaurante(void){
    system("clear||cls");
    int op_restaurante;
    printf("\n");
    printf(" _______________________________________________________________________\n");
    printf("|                                                                       |\n");
    printf("|                              RESTAURANTE                              |\n");
    printf("|_______________________________________________________________________|\n");
    printf("|                                                                       |\n");
    printf("|           1 - Cafe da manha                                           |\n");
    printf("|           2 - Almoco                                                  |\n");
    printf("|           3 - Jantar                                                  |\n");
    printf("|           4 - Sobremesas                                              |\n");
    printf("|           5 - Bebidas                                                 |\n");
    printf("|           0 - Sair                                                    |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\n");
    printf("PRESSIONE ENTER PARA CONTINUAR...");
    printf("Escolha uma opcao: ");
    scanf("%d",&op_restaurante);
    getchar();
    return(op_restaurante);
}