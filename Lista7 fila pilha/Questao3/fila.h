typedef struct reg_fila tipo_fila;

tipo_fila *criarFila();
int adicionarElemento(tipo_fila *, int);
int *imprimirFila(tipo_fila *);
int excluirElemento(tipo_fila *);
int filaVazia(tipo_fila *);
int nrElementos(tipo_fila *);
tipo_fila* apagarFila(tipo_fila *);
