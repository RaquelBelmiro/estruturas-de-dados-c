typedef struct reg_fila tipo_fila;

tipo_fila *criarFila();
int adicionarElemento(tipo_fila *, int);
int filaVazia(tipo_fila *);
int *obterElementos(tipo_fila *);
int excluirElemento(tipo_fila *);
int tamanhoFila(tipo_fila *);
void separaFilas(tipo_fila* , tipo_fila*, tipo_fila*);
tipo_fila* apagarFila(tipo_fila *);
