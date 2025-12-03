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


void tela_checkin_quartos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                 {Quartos -> Check-in}                    #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_checkout_quartos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                {Quartos -> Check-out}                    #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_menu_quartos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────────────┐\n");
    printf("|                              -Quartos-                             |\n");
    printf("├────────────────────────────────────────────────────────────────────┤\n");
    printf("|                                                                    |\n");
    printf("|        [1] -> Check-in                                             |\n");
    printf("|        [2] -> Check-out                                            |\n");
    printf("|        [3] -> Buscar quartos                                       |\n");
    printf("|        [4] -> Editar quartos                                       |\n");
    printf("|        [5] -> Cadastrar quartos                                    |\n");
    printf("|        [6] -> Listar quartos                                       |\n");
    printf("|        [0] -> Voltar                                               |\n");
    printf("|                                                                    |\n");
    printf("└────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_cad_quartos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Quartos -> Cadastrar}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_edit_quartos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Quartos -> Editar}                    #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_busc_quartos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Quartos -> Buscar}                     #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_list_quartos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Quartos -> Listar}                     #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_menu_edit_quartos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│                                                            │\n");
    printf("│                          -Hospedes-                        │\n");
    printf("│                                                            │\n");
    printf("│────────────────────────────────────────────────────────────│\n");
    printf("│                                                            │\n");
    printf("│        [1] -> N° do quarto                                 │\n");
    printf("│        [2] -> CPF                                          │\n");
    printf("│        [3] -> Quan. de pessoas                             │\n");
    printf("│        [0] -> Voltar                                       │\n");
    printf("│                                                            │\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


// telas servicos

void tela_menu_servicos(void){
    limpa_tela();

    printf("\n");
    printf("┌──────────────────────────────────────────────────────┐\n");
    printf("|                                                      |\n");
    printf("|                      -Serviços-                      |\n");
    printf("|                                                      |\n");
    printf("|──────────────────────────────────────────────────────|\n");
    printf("|                                                      |\n");
    printf("|       [1] -> Cadastrar Serviços                      |\n");
    printf("|       [2] -> Listar serviços                         |\n");
    printf("|       [3] -> Apagar servico                          |\n");
    printf("|       [0] -> Voltar                                  |\n");
    printf("└──────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_cad_servicos(void){
    limpa_tela();

    printf("\n");
    printf("┌───────────────────────────────────────────────────────┐\n");
    printf("|#######################################################|\n");
    printf("|#                                                     #|\n");
    printf("|#           {Serviços -> Cadastrar Serviço}           #|\n");
    printf("|#                                                     #|\n");
    printf("|#######################################################|\n");
    printf("└───────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_list_servicos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|############################################################|\n");
    printf("|#                                                          #|\n");
    printf("|#               {Serviço -> Listar Serviços}               #|\n");
    printf("|#                                                          #|\n");
    printf("|############################################################|\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_exclu_servicos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|############################################################|\n");
    printf("|#                                                          #|\n");
    printf("|#                   {Serviço -> Excluir}                   #|\n");
    printf("|#                                                          #|\n");
    printf("|############################################################|\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


// telas reservas


void tela_menu_reservas(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|                         -Reservas-                         |\n");
    printf("|                                                            |\n");
    printf("|────────────────────────────────────────────────────────────|\n");
    printf("|                                                            |\n");
    printf("|        [1] -> Cadastrar reserva                            |\n");
    printf("|        [2] -> Editar informacoes                           |\n");
    printf("|        [3] -> Listar reservas                              |\n");
    printf("|        [4] -> Buscar reserva                               |\n");
    printf("|        [5] -> Cancelar reservas                            |\n");
    printf("|        [0] -> Voltar                                       |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_cad_reservas(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Reservas -> Cadastrar}                 #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_edit_reservas(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Reservas -> Editar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_list_reservas(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Hospedes -> Listar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_busc_reservas(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                   {Reservas -> Buscar}                   #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_cancel_reservas(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│############################################################│\n");
    printf("│#                                                          #│\n");
    printf("│#                  {Reservas -> Cancelar}                  #│\n");
    printf("│#                                                          #│\n");
    printf("│############################################################│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_menu_edit_reserva(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|                       -Editar Reserva-                     |\n");
    printf("|                                                            |\n");
    printf("|────────────────────────────────────────────────────────────|\n");
    printf("|                                                            |\n");
    printf("|        [1] -> Número do Quarto                             |\n");
    printf("|        [2] -> CPF do Hóspede                               |\n");
    printf("|        [3] -> CPF do Funcionário                           |\n");
    printf("|        [4] -> Data da Reserva                              |\n");
    printf("|        [5] -> Data do Atendimento                          |\n");
    printf("|        [0] -> Voltar                                       |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


// telas agendamentos


void tela_menu_agendamentos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|                   -Agendamentos-                           |\n");
    printf("|                                                            |\n");
    printf("|────────────────────────────────────────────────────────────|\n");
    printf("|                                                            |\n");
    printf("|       [1] -> Cadastrar Agendamentos                        |\n");
    printf("|       [2] -> Editar Agendamentos                           |\n");
    printf("|       [3] -> Listar Agendamentos                           |\n");
    printf("|       [4] -> Apagar Agendamento                            |\n");
    printf("|       [0] -> Voltar                                        |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_cad_agendamentos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|               {Agendamentos -> Cadastrar}                  |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_edit_agendamentos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|               {Agendamentos -> Editar}                     |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_list_agendamentos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|               {Agendamentos -> Listar}                     |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_exclu_agendamentos(void){
    limpa_tela();

    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("|                                                            |\n");
    printf("|               {Agendamentos -> Excluir}                    |\n");
    printf("|                                                            |\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}


void tela_menu_edit_agendamentos(void){
    limpa_tela();
    
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│                                                            │\n");
    printf("│                          -Hospedes-                        │\n");
    printf("│                                                            │\n");
    printf("│────────────────────────────────────────────────────────────│\n");
    printf("│                                                            │\n");
    printf("│        [1] -> ID agendamento                               │\n");
    printf("│        [2] -> CPF funcionario                              │\n");
    printf("│        [3] -> N° quarto                                    │\n");
    printf("│        [4] -> ID serviço                                   │\n");
    printf("│        [5] -> Status                                       │\n");
    printf("│        [0] -> Voltar                                       │\n");
    printf("│                                                            │\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}