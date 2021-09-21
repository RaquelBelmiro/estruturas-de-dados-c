#include<stdio.h>
#include<stdlib.h>

int **ordenar(int n, int *vetorInteiro);

int main(){

   int n, *vetorInteiro, **w, posicao;
   
   printf("Digite a quantidade de valores do vetor: ");
   scanf("%d", &n);
   
   vetorInteiro= (int*)(malloc(n*sizeof(int)));
   if(vetorInteiro==NULL){
	printf("Erro de alocação de Memoria");
        exit(1);
    }
  
   for(posicao=0;posicao<n;posicao++){
	printf("Digite o %d valor do vetor de Inteiros: ", posicao+1);
	scanf("%d", &vetorInteiro[posicao]);
    }
    
   for(posicao=0;posicao<n;posicao++)
        printf("\n %d- Endereco: %p \n", vetorInteiro[posicao], vetorInteiro+posicao);
	  
    w=ordenar(n,vetorInteiro);
    
   
    printf("\nEndereços dos valores em ordem crescente do vetor de inteiros\n");
    for(posicao=0;posicao<n;posicao++)
        printf(" %p \n",w[posicao]);
        
        free(vetorInteiro);
        free(w);
    
    return 0;
}
    
int **ordenar(int n, int *vetorInteiro){

    int **w,menor, i,j,*aux;
    
    w=(int**)(malloc(n*sizeof(int)));
       if(w==NULL){
          printf("Erro de alocação de Memoria");
          exit(1);
    }
    
       for(i=0;i<n;i++)
           w[i]=&vetorInteiro[i];
        
      
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(*w[i]>*w[j]){         
               aux=w[i];     
               w[i]=w[j];     
               w[j]=aux;       
             }
        }
   }
    return w;
    
} 
