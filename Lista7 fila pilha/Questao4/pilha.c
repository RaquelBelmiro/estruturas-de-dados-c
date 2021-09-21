#include<stdlib.h>
#include<stdio.h>

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

int *imprimirPilha(tipo_pilha *pilha)
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
            dado=auxiliar->dado;
		    free(auxiliar);
            pilha->tamanhoPilha--;
            
            return dado;
	     }

    return -1;
}
int testarIgualdade(tipo_pilha *pilha1, tipo_pilha *pilha2){
      

    while((!pilhaVazia(pilha1))&&(!pilhaVazia(pilha2))){
               if((desempilharElemento(pilha1))!=(desempilharElemento(pilha2)))
               return 0;
        }
  
    if((pilhaVazia(pilha1))&&(pilhaVazia(pilha2)))
        return 1;

    return 0;
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
