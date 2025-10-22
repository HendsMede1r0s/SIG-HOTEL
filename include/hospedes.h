///////////////////
//modulo hospedes//
///////////////////

struct hospedes
{
    char cpf [18];
    char nome [55];
    char cell [18];
    char n_quarto [7];
    char status;
};

typedef struct hospedes Hospedes;

void modulo_hospedes(void);
char tela_hospedes(void);
void cad_hospedes(void);
void edit_hospedes(void);
void list_hospedes(void);
void busc_hospedes(void);
void exclu_hospedes(void);
void exib_hospede(Hospedes *hos);

