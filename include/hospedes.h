/////////////////////
// modulo hospedes //
/////////////////////

struct hospedes {
    char cpf [18];
    char nome [55];
    char cell [18];
    int status;
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
char menu_edit_hospedes(void);
void switch_edit_hospedes(Hospedes *hos);
int verifica_cpf_hospedes(const char *cpf_a_verificar);
char* pega_nome_hospede(const char *cpf_a_buscar);

