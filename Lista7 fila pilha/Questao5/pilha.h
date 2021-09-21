typedef struct reg_pilha tipo_pilha;

tipo_pilha *criarPilha();
int empilharElemento(tipo_pilha *, char *);
char **obterElementosPilha(tipo_pilha *);
char *desempilharElemento(tipo_pilha *);
int pilhaVazia(tipo_pilha *);
int tamanhoPilha(tipo_pilha *);
void inverterFrase(tipo_pilha *);
tipo_pilha* apagarPilha(tipo_pilha *);
