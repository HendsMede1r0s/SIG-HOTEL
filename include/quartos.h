void modulo_quartos(void);
char tela_quartos(void);
void check_in(void);
void list_quartos(void);
void check_out(void);
void exib_quartos(void);
void edit_quartos(void);
void cad_quartos(void);

struct quartos
{
    char n_quarto [7];
    char n_quarto_lido [7];
    char cpf [18];
    char quan_pessoas [5];
    char status;
    char op_quartos;
};

typedef struct quartos Quartos;
