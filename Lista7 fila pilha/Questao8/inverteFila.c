#include<stdlib.h>

typedef struct no
{
	int dado;
	struct no *proximo;
}tipo_no;

typedef struct reg_pilha
{
	tipo_no *topo;
	int tamanhoPilha;
	
}tipo_pilha;

typedef struct reg_fila
{
	tipo_no *inicio;
        tipo_no *fim;
	int tamanhoFila;
	
}tipo_fila;

//Funcionalidades Pilha
tipo_pilha *criarPilha(){
    
	tipo_pilha *pilha;
	
	pilha=(tipo_pilha*)malloc(sizeof(tipo_pilha));
	
	pilha->topo=NULL;
	pilha->tamanhoPilha=0;
	
	return pilha;
}

int empilharElemento(tipo_pilha *pilha, int dado){

	tipo_no *novo=NULL;
	
	novo=(tipo_no*) malloc(sizeof(tipo_no));
	if(novo==NULL)
       return 0;

	novo->dado=dado;
	novo->proximo=pilha->topo;
	pilha->topo=novo;
	pilha->tamanhoPilha++;	

    return 1;
}
int pilhaVazia(tipo_pilha *pilha){

	if(pilha->topo == NULL)
	  {
        	return 1;
      }
   
    return 0;
        
}

int tamanhoPilha(tipo_pilha *pilha){

	return pilha->tamanhoPilha;
}

int *obterElementosPilha(tipo_pilha *pilha)
{
    tipo_no *atual = pilha->topo;
    int *vetor, posicao= 0;

    vetor= (int*) malloc(tamanhoPilha(pilha) * sizeof(int));

   if(!pilhaVazia(pilha))
    {
        while (atual != NULL)
        {
            vetor[posicao] = atual->dado;
            atual = atual->proximo;
            posicao++;
        }
        return vetor;
    }

   return NULL;
}

int desempilharElemento(tipo_pilha *pilha){
	
	tipo_no *auxiliar=NULL;
    int dado;

	if(!pilhaVazia(pilha))
	    {
		    auxiliar=pilha->topo;
            pilha->topo=pilha->topo->proximo;
            dado= auxiliar->dado;

		   
		    free(auxiliar);
		    pilha->tamanhoPilha--;

            return dado;
	     }

    return -1;
}

tipo_pilha* apagarPilha(tipo_pilha *pilha){
    
	tipo_no *auxiliar;

	while(!pilhaVazia(pilha)) 
             {
               desempilharElemento(pilha);
             }
    
	free(pilha);
    
	return NULL;
}

//Funcionalidades fila

tipo_fila *criarFila(){
    
	tipo_fila *fila;
	
	fila=(tipo_fila*)malloc(sizeof(tipo_fila));
	
	fila->inicio=NULL;
    fila->fim=NULL;
   
	fila->tamanhoFila=0;
	
	return fila;
}
int filaVazia(tipo_fila *fila){

	if(fila->inicio == NULL)
	  {
        	return 1;
      }
   
    return 0;
        
}
int adicionarElemento(tipo_fila *fila, int dado){

	tipo_no *novo;

	novo=(tipo_no*) malloc(sizeof(tipo_no));
	if(novo==NULL)
       return 0;

    novo -> dado = dado ;
	novo -> proximo = NULL ;

    if(filaVazia(fila))         
	 {
         fila->inicio = novo ;                   
         fila->fim=novo;
	 }
	 else{
	 	fila->fim->proximo=novo;
        fila->fim=novo;
	 }
	 
	fila->tamanhoFila++;
    return 1;
}


int tamanhoFila(tipo_fila *fila){

	return fila->tamanhoFila;
}
int *obterElementosFila(tipo_fila *fila)
{
    tipo_no *atual = fila->inicio;
    int *vetor, posicao= 0;

    vetor= (int*) malloc(tamanhoFila(fila) * sizeof(int));

   if(!filaVazia(fila))
    {
        while (atual != NULL)
        {
            vetor[posicao] = atual->dado;
            atual = atual->proximo;
            posicao++;
        }
        return vetor;
    }

   return NULL;
}

int excluirElemento(tipo_fila *fila){
	
	tipo_no *auxiliar=NULL;
    int dado;

	if(!filaVazia(fila))
	    {
		    auxiliar=fila->inicio;
            fila->inicio=fila->inicio->proximo;
            dado= auxiliar->dado;

		   
		    free(auxiliar);
		    fila->tamanhoFila--;
  
            return dado;
	     }

    return -1;
}
void inverteFila(tipo_fila *fila, tipo_pilha *pilha){
    int aux;
    
       if(!filaVazia(fila)){
          while(!filaVazia(fila)){
               aux=excluirElemento(fila);
               empilharElemento(pilha, aux);
               }
          free(fila);
        }

       if(!pilhaVazia(pilha)){
          while(!pilhaVazia(pilha)){
                aux=desempilharElemento(pilha);
                adicionarElemento(fila, aux);
          }
         free(pilha);
       }
                
}
tipo_fila* apagarFila(tipo_fila *fila){
    
	tipo_no *auxiliar;

	while(!filaVazia(fila)) 
             {
               excluirElemento(fila);
             }
    
	free(fila);
    
	return NULL;
}
