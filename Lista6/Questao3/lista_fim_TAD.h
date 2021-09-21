
typedef struct reg_lista tipo_lista;

tipo_lista* criarListaVazia();
int listaVazia(tipo_lista*);
void inserirElementoFim(tipo_lista*, int);
void excluirElementoFim(tipo_lista*);
int quantidadeElementosLista(tipo_lista*);
int* obterElementosLista(tipo_lista*);
void apagarIguais(tipo_lista*,int);
tipo_lista* apagarLista(tipo_lista*);
