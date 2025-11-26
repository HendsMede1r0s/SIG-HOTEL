/////////////////////////
// modulo agendamentos //
/////////////////////////

struct agendamentos {
    char id_agendamento[7];
    char cpf_funcionario[18];
    char n_quarto[7];
    char id_servico[7];
    char status[15];
};

typedef struct agendamentos Agendamentos;

void modulo_agendamentos(void);
char tela_agendamentos(void);
void cad_agendamentos(void);
void edit_agendamentos(void);
void list_agendamentos(void);
void exclu_agendamentos(void);