
struct quartos
{
    char n_quarto [7];
    char cpf [18];
    char quan_pessoas [5];
    char status;
};

typedef struct quartos Quartos;

void modulo_quartos(void);
char tela_quartos(void);
void check_in(void);
void check_out(void);
void busc_quartos(void);
void edit_quartos(void);
void cad_quartos(void);
void list_quartos(void);
void exib_quarto(Quartos *quar);
char menu_edit_quartos(void);
void switch_edit_quartos(Quartos *quar);
int verifica_n_quarto(const char *n_quarto_a_verificar);


