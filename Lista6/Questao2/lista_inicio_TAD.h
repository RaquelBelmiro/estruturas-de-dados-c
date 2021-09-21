
typedef struct reg_lista tipo_lista;

tipo_lista* criarListaVazia();
int listaVazia(tipo_lista*);
void inserirElementoInicio(tipo_lista*, int);
void excluirElementoInicio(tipo_lista*);
int quantidadeElementosLista(tipo_lista*);
int* obterElementosLista(tipo_lista*);
void concatenarListas(tipo_lista*, tipo_lista*);
tipo_lista* apagarLista(tipo_lista*);


