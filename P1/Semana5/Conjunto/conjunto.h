typedef struct conjunto tipo_conjunto;

tipo_conjunto *cria_conjunto_vazio(tipo_conjunto *);
tipo_conjunto *insere_elemento(tipo_conjunto *, int);
int remove_elemento(tipo_conjunto *, int);
tipo_conjunto *une_conjuntos(tipo_conjunto *, tipo_conjunto *);
tipo_conjunto *interseccao(tipo_conjunto *, tipo_conjunto *);
tipo_conjunto *diferenca(tipo_conjunto *, tipo_conjunto *);
int verifica_numero(tipo_conjunto *, int);
int verifica_menor(tipo_conjunto *);
int verifica_maior(tipo_conjunto *);
int testa_igualdade(tipo_conjunto *, tipo_conjunto *);
int tamanho(tipo_conjunto *);
int testa_vazio(tipo_conjunto *);
int *imprime_conjunto(tipo_conjunto *,int *);
tipo_conjunto *libera(tipo_conjunto *);
