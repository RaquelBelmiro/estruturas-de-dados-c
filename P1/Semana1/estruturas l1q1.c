#include<stdio.h>


int main(){

	int n, *ptrn, posicao;                          //Declare uma variável inteira n e um ponteiro ptrn para essa variável
	
	n=20;                                          //Atribua um valor para n
	ptrn=&n;
	
	printf("\n\n");
	printf("valor de n por ptrn: %d \n\n", *ptrn);        // Imprima o valor de n a partir de ptrn      
	
	printf("Endereco de n:%p, endereco de ptrn:%p \n\n", &n,&ptrn);     //Imprima o endereço de n e de ptrn
	
        *ptrn= *ptrn+1;                                                    //Incremente o valor de n usando o ponteiro ptrn
        
        printf("valor de n incrementado: %d \n\n", n);                    //Imprima o novo valor de n para confirmar se está correto
        
        
	return 0;
	
}
	
	
