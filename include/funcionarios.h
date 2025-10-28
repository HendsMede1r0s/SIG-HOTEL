/////////////////////////////
//// Modulo Funcionarios ////
/////////////////////////////

struct funcionarios{

    char cpf[18];
    char nome[55];
    char cell[18];
    int status;
};

typedef struct funcionarios Funcionarios;

void modulo_funcionarios(void);
char tela_funcionarios(void);
void cad_funcionarios(void);
void edit_funcionarios(void);
void busc_funcionarios(void);
void list_funcionarios(void);
void exclu_funcionarios(void);
void exib_funcionario(Funcionarios *fun);
void menu_edit_funcionarios(void);
void switch_edit_funcionarios(Funcionarios *fun);