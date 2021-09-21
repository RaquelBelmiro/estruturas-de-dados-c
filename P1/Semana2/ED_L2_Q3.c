#include<stdio.h>
#include<stdlib.h>

int **ordenar(int n, int *vetorInteiro);

int main(){

   int n, *vetorInteiro, **vetorEnderecos, i;
   
   printf("\n\nDigite a quantidade de valores do vetor: ");
   scanf("%d", &n);
   
   vetorInteiro= (int*)(malloc(n*sizeof(int)));
   if(vetorInteiro==NULL){
	printf("Erro de alocação de Memoria");
        exit(1);
    }
  
   for(i=0;i<n;i++){
	printf("Digite o %d° valor do vetor de Inteiros: ", i+1);
	scanf("%d", &vetorInteiro[i]);
    }
    
   for(i=0;i<n;i++)
        printf("\n %d- Endereco: %p \n", vetorInteiro[i], vetorInteiro+i);
	  
    vetorEnderecos=ordenar(n,vetorInteiro);
    
   
    printf("\n valores em ordem crescente \n");
    for(i=0;i<n;i++)
        printf("\n %d- Endereco: %p \n",*vetorEnderecos[i], vetorEnderecos[i]);
        
        printf("\n\n");
        free(vetorInteiro);
        free(vetorEnderecos);
        
    
    return 0;
}
    
int **ordenar(int n, int *vetorInteiro){

    int **vetorEnderecos,menor, i,j,*aux;
    
    vetorEnderecos=(int**)(malloc(n*sizeof(int)));
       if(vetorEnderecos==NULL){
          printf("Erro de alocação de Memoria");
          exit(1);
    }
    
       for(i=0;i<n;i++)
           vetorEnderecos[i]=&vetorInteiro[i];
        
      
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(*vetorEnderecos[i]>*vetorEnderecos[j]){         
               aux=vetorEnderecos[i];     
               vetorEnderecos[i]=vetorEnderecos[j];     
               vetorEnderecos[j]=aux;       
             }
        }
   }
    return vetorEnderecos;
    
} 
