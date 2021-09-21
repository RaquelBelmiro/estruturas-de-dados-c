typedef struct reg_no_arvore **tipo_no_arvore;

tipo_no_arvore inicializar_arvore(tipo_no_arvore);
void incluir_no_arvore(tipo_no_arvore, int);
void percurso_em_ordem(tipo_no_arvore);
void percurso_em_pre_ordem(tipo_no_arvore);
void percurso_em_pos_ordem(tipo_no_arvore);
int encontrar_elemento(tipo_no_arvore, int);
int numero_nos(tipo_no_arvore);
int qtdFolha(tipo_no_arvore);
int qtdNull(tipo_no_arvore);
int altura(tipo_no_arvore);
void copiarArvore(tipo_no_arvore,tipo_no_arvore);
