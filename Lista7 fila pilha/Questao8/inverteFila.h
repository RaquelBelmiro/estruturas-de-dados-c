typedef struct reg_pilha tipo_pilha;
typedef struct reg_fila tipo_fila;

tipo_pilha *criarPilha();
int empilharElemento(tipo_pilha *, int);
int *obterElementosPilha(tipo_pilha *);
int desempilharElemento(tipo_pilha *);
int pilhaVazia(tipo_pilha *);
int tamanhoPilha(tipo_pilha *);
tipo_pilha* apagarPilha(tipo_pilha *);

tipo_fila *criarFila();
int adicionarElemento(tipo_fila *, int);
int excluirElemento(tipo_fila *);
int filaVazia(tipo_fila *);
int tamanhoFila(tipo_fila *);
void inverteFila(tipo_fila *,tipo_pilha *);
int *obterElementosFila(tipo_fila *fila);
tipo_fila* apagarFila(tipo_fila *);

