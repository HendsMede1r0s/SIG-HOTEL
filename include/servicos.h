
struct servicos{

    char servi[55];
    char id[7];

};

typedef struct servicos Servicos;


void modulo_servicos(void);
int verifica_id(const char *id_a_verificar);
char tela_servicos(void);
void cad_servico(void);
void list_servicos(void);
void exclu_servicos(void);
