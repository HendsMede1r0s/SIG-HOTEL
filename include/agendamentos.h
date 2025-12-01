/////////////////////////
// modulo agendamentos //
/////////////////////////

typedef struct agendamentos Agendamentos;
struct agendamentos {
    char id_agendamento[7];
    char cpf_funcionario[18];
    char n_quarto[7];
    char id_servico[7];
    int status;
};

typedef struct novo_agendamento {
    char *nome_func;
    char *nome_servico;
    int status;
    struct novo_agendamento *prox;
} Novo_agendamento;

void modulo_agendamentos(void);
char tela_agendamentos(void);
void cad_agendamentos(void);
void edit_agendamentos(void);
void list_agendamentos(void);
void exclu_agendamentos(void);
char menu_edit_agendamentos(void);
void switch_edit_agendamentos(Agendamentos *agendamento);