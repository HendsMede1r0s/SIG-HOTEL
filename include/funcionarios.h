void modulo_funcionarios(void);
char tela_funcionarios(void);
void cad_funcionarios(void);
void edit_funcionarios(void);
void exib_funcionarios(void);
void exclu_funcionarios(void);

struct funcionarios{

    char cpf[18];
    char cpf_lido[18];
    char nome[55];
    char cell[18];
};

typedef struct funcionarios Funcionarios;