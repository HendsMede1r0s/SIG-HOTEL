/////////////////////
// modulo reservas //
/////////////////////

struct reservas {
    char n_quarto [7];
    char cpf_hospede [18];
    char cpf_funcionario [18];
    char data_atendimento [14];
    char data_reserva [14];
    int status;
};

typedef struct reservas Reservas;

void modulo_reservas(void);
char tela_reservas(void);
void cad_reserva(void);
void edit_reserva(void);
void list_reservas(void);
void busc_reservas(void);
void exib_reserva(Reservas *res);
char menu_edit_reserva(void);
void switch_edit_reserva(Reservas *res);