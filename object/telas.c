#include <stdio.h>
#include <stdlib.h>
#include <telas.h>
#include "utilidades.h"

// telas genericas


void tela_menu_inicial(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|                      -Menu Principal-                      |\n");
    printf("|                                                            |\n");
    printf("|────────────────────────────────────────────────────────────|\n");
    printf("|                                                            |\n");
    printf("|        [1] -> Hospedes                                     |\n");
    printf("|        [2] -> Funcionarios                                 |\n");
    printf("|        [3] -> Quartos                                      |\n");
    printf("|        [4] -> Servicos                                     |\n");
    printf("|        [5] -> Reservas                                     |\n");
    printf("|        [6] -> Agendamentos                                 |\n"); 
    printf("|        [7] -> Equipe                                       |\n");
    printf("|        [8] -> Sobre                                        |\n");
    printf("|        [9] -> Relatorios                                   |\n");
    printf("|        [0] -> Sair                                         |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_voltar(void){
    printf("\n");
    printf("{Digite enter para voltar ao menu...}");
    getchar();
    printf("\n");
}


void tela_final(void){
    limpa_tela();
    printf("\n");
    printf(" __________________________________________________________________________________\n");
    printf("|                                                                                  |\n");
    printf("|                                   TELA FINAL                                     |\n");
    printf("|                                                                                  |\n");
    printf("|                                                                                  |\n");
    printf("|         Obrigado por utilizar o Sistema de Gestão para hotéis e pousadas.        |\n");
    printf("|                              Tenha um ótimo dia!                                 |\n");
    printf("|__________________________________________________________________________________|\n");
    printf("\n");
    printf("{Pressione ENTER para continuar...}");
    getchar();
}


void tela_op_invalida(void){
    limpa_tela();
    printf("\n");
    printf("┌──────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                                                                  |\n");
    printf("|                                 *OPCAO INVALIDA*                                 |\n");
    printf("|                                                                                  |\n");
    printf("└──────────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    getchar();
    printf("\n");
}


// telas hospedes


void tela_menu_hospedes(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│                                                            │\n");
    printf("│                          -Hospedes-                        │\n");
    printf("│                                                            │\n");
    printf("│────────────────────────────────────────────────────────────│\n");
    printf("│                                                            │\n");
    printf("│        [1] -> Cadastar                                     │\n");
    printf("│        [2] -> Editar informacoes                           │\n");
    printf("│        [3] -> Listar hospedes                              │\n");
    printf("│        [4] -> Buscar hospedes                              │\n");
    printf("│        [5] -> Excluir hospedes                             │\n");
    printf("│        [0] -> Voltar                                       │\n");
    printf("│                                                            │\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_cad_hospedes(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                 {Hospedes -> Cadastrar}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_edit_hospedes(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Hospedes -> Editar}                    #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_list_hospedes(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Hospedes -> Listar}                    #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_busc_hospedes(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Hospedes -> Buscar}                    #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_exclu_hospedes(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                 {Hospedes -> Excluir}                    #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_menu_edit_hospedes(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│                                                            │\n");
    printf("│                          -Hospedes-                        │\n");
    printf("│                                                            │\n");
    printf("│────────────────────────────────────────────────────────────│\n");
    printf("│                                                            │\n");
    printf("│        [1] -> CPF                                          │\n");
    printf("│        [2] -> Nome                                         │\n");
    printf("│        [3] -> Telefone                                     │\n");
    printf("│        [0] -> Voltar                                       │\n");
    printf("│                                                            │\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


// telas funcionarios


void tela_menu_funcionarios(void){
    limpa_tela();
    
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
}


void tela_cad_funcionarios(void){
    limpa_tela();

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#              {Funcionarios -> Cadastrar}              #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_edit_funcionarios(void){
    limpa_tela();

    printf("\n");
    printf("┌──────────────────────────────────────────────────────────┐\n");
    printf("|##########################################################|\n");
    printf("|#                                                        #|\n");
    printf("|#                {Funcionarios -> Editar}                #|\n");
    printf("|#                                                        #|\n");
    printf("|##########################################################|\n");
    printf("└──────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_list_funcionarios(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|############################################################│\n");
    printf("|#                                                          #│\n");
    printf("|#                 {Funcionarios -> Listar}                 #│\n");
    printf("|#                                                          #│\n");
    printf("|############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_busc_funcionarios(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|############################################################│\n");
    printf("|#                                                          #│\n");
    printf("|#               {Funcionarios -> Buscar}                   #│\n");
    printf("|#                                                          #│\n");
    printf("|############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_exclu_funcionarios(void){
    limpa_tela();

    printf("\n");
    printf("┌─────────────────────────────────────────────────────────┐\n");
    printf("|#########################################################|\n");
    printf("|#                                                       #|\n");
    printf("|#              {Funcionarios -> Excluir}               #|\n");
    printf("|#                                                       #|\n");
    printf("|#########################################################|\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_menu_edit_funcionarios(void){
    limpa_tela();

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
}


// telas quartos