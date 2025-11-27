////////////////////////
// modulo relatorios //
//////////////////////

typedef struct quartos_lista QuarList;
typedef struct quartos Quartos;

void modulo_relatorios(void);
char tela_relatorios(void);
// Relatórios de quartos
char tela_relatorio_quartos(void);
void relatorio_quartos(void);
void quartos_disponiveis(void);
void quartos_por_andar(void);
QuarList* novo_quarto(void);
void append_quartos(QuarList *l, Quartos* data);
void limpa_quarto(QuarList* l);
void deleta_quarto(QuarList* l);
void preenche_lista_quartos(QuarList* lista);
void listar_quartos_direto(void);
// Relatórios de hospedes
char tela_relatorio_hospedes(void);
void relatorio_hospedes(void);
void relatorio_hospedes_filtrado(void);
// Relatórios de funcionarios
char tela_relatorio_funcionarios(void);
void relatorio_funcionarios(void);
void relatorio_funcionarios_filtrado(void);
// Relatórios de reservas
char tela_relatorio_reservas(void);
void list_reservas_ampliado(void);
void relatorio_reservas(void);
// Relatórios de serviços
char tela_relatorio_servicos(void);
void relatorio_servicos(void);
void relatorio_servicos_quarto(void);