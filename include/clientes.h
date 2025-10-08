///////////////////
//modulo clientes//
///////////////////

void modulo_clientes(void);
char tela_clientes(void);
void cad_clientes(void);
void edit_clientes(void);
void list_clientes(void);
void busc_clientes(void);
void exclu_clientes(void);

struct clientes
{
    char cpf [18];
    char nome [55];
    char cell [18];
    char n_quarto [7];
    char status;
};

typedef struct clientes Clientes;