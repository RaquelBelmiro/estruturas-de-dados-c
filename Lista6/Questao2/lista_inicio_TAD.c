#include<stdlib.h>


typedef struct no
{
    int dado;
    struct no *proximo;
} tipo_no;

typedef struct reg_lista
{
    tipo_no *inicio;
    int quantidadeElementos;
} tipo_lista;

tipo_lista* criarListaVazia()
{
    tipo_lista* lista = (tipo_lista*)malloc(sizeof(tipo_lista)); //criou a estrutura da lista mas não alocou nenhum nó
    lista->inicio = NULL;                                        //inicio aponta para null porque lista está vazia                                
    lista->quantidadeElementos = 0;
    return lista;
}

int listaVazia(tipo_lista* lista)
{
    if (lista->quantidadeElementos == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int quantidadeElementosLista(tipo_lista* lista)
{
    return lista->quantidadeElementos;
}


int* obterElementosLista(tipo_lista* lista)
{
    tipo_no *atual = lista->inicio;
    int *elementosObtidos, posicao;

    elementosObtidos = (int*) malloc(lista->quantidadeElementos * sizeof(int)); //alocacao de espaco para o vetor de elementos obtidos

    posicao = 0;
    while (atual != NULL)     //passa por todos os elementos de uma lista encadeada colocando em uma lista simples(vetor)
    {
        elementosObtidos[posicao] = atual->dado;
        atual = atual->proximo;
        posicao++;
    }
    return elementosObtidos; //retorna o endereço do vetor de elementos
}

void inserirElementoInicio(tipo_lista* lista, int dado){
     tipo_no *novo=NULL;
     
     novo= (tipo_no*)(malloc(sizeof(tipo_no)));
     
     novo->dado= dado;
     novo->proximo=lista->inicio;       //proximo vai apontar para o no criado anteriormente
     lista->inicio=novo;                       //inicio passa a apontar para o novo nó

     lista->quantidadeElementos++;
}
void excluirElementoInicio(tipo_lista* lista){
    tipo_no *auxiliar=NULL;
   
    if(!listaVazia(lista)){
        auxiliar = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(auxiliar);

        lista->quantidadeElementos--;
    }
}
void concatenarListas(tipo_lista* lista1, tipo_lista* lista2){
      tipo_no *atual = lista1->inicio;
     

      if( atual != NULL )           //se a lista nao estiver vazia
	 {
		 while (atual-> proximo != NULL ) 
		 {
		 	atual = atual-> proximo ;     //percorre ate chegar no ultimo elemento
		 }
		 atual-> proximo = lista2->inicio;           //insere o endereco da lista 2 no ultimo no
	 }
	 else{
	 	lista1->inicio = lista2->inicio ;                    
	 }   
     lista1->quantidadeElementos+=lista2->quantidadeElementos;
    
}
tipo_lista* apagarLista(tipo_lista* lista)
{
    tipo_no *auxiliar;

    while (!listaVazia(lista)) //enquanto a lista não estiver vazia
    {
       excluirElementoInicio(lista);
    }
    free(lista);
    return NULL;
}

