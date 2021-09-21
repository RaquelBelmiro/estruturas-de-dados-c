#include<stdio.h>

int main(){

	int m,n,*ptrm,*ptrn;      //declarare duas variaveis inteiras e dois ponteiros para elas
	                          
	m=1;                     //atriua valores para as variaveis
	n=2;
	
	ptrm=&m;                
	ptrn=&n;
	
	
	
	if(*ptrm==*ptrn)                                       // Descubra qual o maior valor, acessando-as somente atraves dos ponteiros.
	   printf("\n\n m e n possuem valores iguais \n\n");
	   
	   else{
	   
	  	int maior= *ptrm;
	
	   	if(*ptrn>maior)
	           maior=*ptrn;
	        
	        printf("\n\n o maior valor e: %d \n\n", maior);
	        
	    }
	    
	    
	
	return 0;

}
	   
	
	 
