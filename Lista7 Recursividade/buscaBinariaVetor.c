#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 20

int buscaBinaria(int *vetor, int n, int *nComparacoes);

int main(){
    int *vetor,n, i,resultado, nComparacoes=0;

    
    vetor=(int*)malloc(TAM*sizeof(int));
    
    for(i=0;i<TAM;i++)        //atribuindo valores ao vetor
        vetor[i]=i+1;
        
    
    printf("Vetor:\n");
    for(i=0;i<TAM;i++)
        printf("posicao: [%d], numero: [%d] \n", i,vetor[i]);   //printando posicoes e valores para checar funcionamento

   
    srand(time(NULL));
    n=rand()%30;              //sorteando numero de 0 a 29 para ser procurado
   
    resultado=buscaBinaria(vetor,n, &nComparacoes);
    if(resultado==-1)
       printf("numero %d nao encontrado no vetor \n",n);
    else
        printf("numero %d, encontrado na posicao: %d, Numero de Comparacoes: %d \n ", n,resultado, nComparacoes);
        
    
     return 0; 
  }    
int buscaBinaria(int *vetor, int n, int *nComparacoes){
    int inicio,meio,fim,pos=0;

    inicio=0;
    fim=TAM-1;

    while(inicio<=fim){    //10 20 30 40 50 60 70 80 90 100
          meio=(inicio+fim)/2;
          *nComparacoes=*nComparacoes+1;
          if(n<vetor[meio])
             fim=meio-1;
          else{ 
                 *nComparacoes=*nComparacoes+1;
                  if(n>vetor[meio])
                     inicio=meio+1;
                  else
                     return meio;
              }
       }
      return -1;
      
}
