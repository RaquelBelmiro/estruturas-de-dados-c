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

tipo_lista* apagarLista(tipo_lista* lista)
{
    tipo_no *auxiliar;

    while (!listaVazia(lista)) //enquanto a lista não estiver vazia
    {
        auxiliar = lista->inicio;
        lista->inicio = lista->inicio->proximo; 
        lista->quantidadeElementos--;
        free(auxiliar);
    }
    free(lista);
    return NULL;
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

void inserirElementoFim(tipo_lista* lista, int dado){
     tipo_no *novo, *atual=lista->inicio;
    
    novo =(tipo_no *)malloc(sizeof(tipo_no));
    
    novo->dado=dado ;
	novo->proximo = NULL ;
	 
	 if( lista->inicio != NULL )           //se a lista nao estiver vazia
	 {
		 while ( atual-> proximo != NULL ) 
		 {
		 	atual = atual-> proximo ;     //percorre ate chegar no ultimo elemento
		 }
		 atual-> proximo = novo ;            //insere o endereco do novo elemento no ultimo no
	 }
	 else{
	 	lista->inicio = novo ;                    //se a lista estiver vazia o inicio comeca a apontar para o novo
	 }
	 lista->quantidadeElementos++;
}
void excluirElementoFim(tipo_lista* lista){
    
tipo_no * anterior = NULL , * atual = lista->inicio ;
   
   if ( lista->inicio != NULL )
   {
   
	   while ( atual-> proximo != NULL ){      //percorre até o último elemento
	          anterior = atual ;              
	          atual = atual-> proximo ;
        }
	    free (atual);
        lista->quantidadeElementos--;
	 
	    if ( anterior != NULL ){            //se existir o elemento anterior, atualiza o campo proximo
	        anterior-> proximo = NULL ;
	    }
	   
         else{
             lista->inicio = NULL ;             // se nao existir o campo anterior, o que foi apagado foi o primeiro e unico elemento
         }
   }
   
}
void apagarIguais(tipo_lista* lista,int dado){

     tipo_no * anterior = NULL , * atual = lista->inicio,*auxiliar ;
      
    if( lista->inicio != NULL )          
      {
   
	   while( atual != NULL )
            {      
               if(atual->dado!=dado){ 
	              anterior = atual ;              
	              atual = atual-> proximo ;
               }
                else{
                        if (anterior == NULL)
                        {
                             lista->inicio= atual->proximo;
                        }
                        else
                            {
                                anterior->proximo = atual->proximo ;
                            }
                        auxiliar = atual ;
                        atual=atual->proximo;
                        free ( auxiliar );
                        lista->quantidadeElementos--;
                }
                   
         }
     }
}

     
