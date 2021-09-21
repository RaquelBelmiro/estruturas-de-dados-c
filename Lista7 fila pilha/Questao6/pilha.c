#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#define TAM 20

typedef struct no
{
	char *frase;
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

int empilharElemento(tipo_pilha *pilha, char *frase){

	tipo_no *novo=NULL;
	
	novo=(tipo_no*) malloc(sizeof(tipo_no));
	if(novo==NULL)
       return 0;
     
    novo->frase=(char*) malloc(strlen(frase));
	strcpy(novo->frase,frase);
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

char **obterElementosPilha(tipo_pilha *pilha)             
{
    tipo_no *atual = pilha->topo;               
    char **aux;                              
    int i,j;

   if(!pilhaVazia(pilha))                    
    {
        aux= (char**) malloc(tamanhoPilha(pilha)* sizeof(char)); 
        for(i=0;i<tamanhoPilha(pilha);i++)
            aux[i]=(char*)malloc(TAM*sizeof(char));

        while (atual != NULL)                 //enquanto não chegar o fim da pilha
        {
            
            for(i=0;i<tamanhoPilha(pilha);i++)
                aux[i]=atual->frase;    
            atual = atual->proximo;
        }
                
        return aux;

    }

   return NULL;
}

char *desempilharElemento(tipo_pilha *pilha){
	
	tipo_no *auxiliar;
    char *frase;

	if(!pilhaVazia(pilha))
	    {
		    auxiliar=pilha->topo;
            pilha->topo=pilha->topo->proximo;
            frase= auxiliar->frase;
		    free(auxiliar);
		    pilha->tamanhoPilha--;

            return frase;
	     }

    return NULL;
}
void inverterFrase(tipo_pilha *pilha){

     char *frase,*fraseInvertida;
     int i,j=0;

    fraseInvertida=(char*)malloc(TAM*sizeof(char));

     if(!pilhaVazia(pilha)){
         frase=desempilharElemento(pilha);
         for(i=strlen(frase)-1;i>=0;i--){
             fraseInvertida[j]=frase[i];
             j++;
          }
               empilharElemento(pilha, fraseInvertida);
      }

}
int verificaParenteses(tipo_pilha *pilha){
    char **aux;
    int i,j,aberto=0,fechado=0;

    aux=obterElementosPilha(pilha);
    for(i=0;i<pilha->tamanhoPilha;i++){
          for(j=0;j<strlen(aux[i]);j++){
              if((aux[i][j])=='(')
                 aberto++;
              if((aux[i][j])==')')
                 fechado++;
           }
      }

    if(aberto==fechado)
           return 1;
        else 
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

