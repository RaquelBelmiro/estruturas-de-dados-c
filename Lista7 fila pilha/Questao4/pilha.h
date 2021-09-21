typedef struct reg_pilha tipo_pilha;

tipo_pilha *criarPilha();
int empilharElemento(tipo_pilha *, int);
int *imprimirPilha(tipo_pilha *);
int desempilharElemento(tipo_pilha *);
int pilhaVazia(tipo_pilha *);
int tamanhoPilha(tipo_pilha *);
int testarIgualdade(tipo_pilha *, tipo_pilha *);
tipo_pilha* apagarPilha(tipo_pilha *);
