#include<stdio.h>

void maiorValor(int *ptrm, int *ptrn);

int main(){

	int m,n;
	
	m=1, n=2;
	
	maiorValor(&m,&n);
	
	
	return 0;

}

void maiorValor(int *ptrm, int *ptrn){
     
        int maior;	
	
	
	if(*ptrm==*ptrn)
	   printf("\n\n m e n possuem valores iguais \n\n");
	   
	else{
	   
	  	maior= *ptrm;
	
	   	if(*ptrn>maior)
	           maior=*ptrn;
	        
	        printf("\n\n o maior valor e: %d \n\n", maior);
	        
	    }
	    
}
