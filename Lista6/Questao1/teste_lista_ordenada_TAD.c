#include<stdio.h>
#include"lista_ordenada_TAD.h"

void imprimirLista(tipo_lista* listaOrdenada)
{
    int *elementosLista, posicao;
    elementosLista = obterElementosLista(listaOrdenada);  //elementos lista vai apontar para o endereco do vetor de elementos obtidos retornado pela funcao 
    
    for (posicao = 0; posicao < quantidadeElementosLista(listaOrdenada); posicao++)
    {
        printf("%d ", elementosLista[posicao]);
    }
    printf("\n");
}

int main()
{
    tipo_lista* listaOrdenada1 = NULL, *listaOrdenada2 = NULL;

    listaOrdenada1 = criarListaVazia();
    listaOrdenada2 = criarListaVazia();
    
    //inserir na lista 1
    inserirElementoOrdenado(listaOrdenada1, 20);
    inserirElementoOrdenado(listaOrdenada1, 10);
    inserirElementoOrdenado(listaOrdenada1, 15);
    inserirElementoOrdenado(listaOrdenada1, 1);
    inserirElementoOrdenado(listaOrdenada1, 5);
    imprimirLista(listaOrdenada1);
    printf("\n");
   
     //excluir na lista 1
    excluirElementoOrdenado(listaOrdenada1, 5);
    imprimirLista(listaOrdenada1);

    excluirElementoOrdenado(listaOrdenada1, 1);
    imprimirLista(listaOrdenada1);

    excluirElementoOrdenado(listaOrdenada1, 20);
    imprimirLista(listaOrdenada1);

    excluirElementoOrdenado(listaOrdenada1, 15);
    imprimirLista(listaOrdenada1);

    excluirElementoOrdenado(listaOrdenada1, 10);
    imprimirLista(listaOrdenada1);
    
    
    //inserir na lista 2 
    inserirElementoOrdenado(listaOrdenada2, 35);
    inserirElementoOrdenado(listaOrdenada2, 40);
    inserirElementoOrdenado(listaOrdenada2, 30);
    inserirElementoOrdenado(listaOrdenada2, 45);
    inserirElementoOrdenado(listaOrdenada2, 25);
    imprimirLista(listaOrdenada2);
    
   
    //excluir na lista 2
    excluirElementoOrdenado(listaOrdenada2, 30);
    imprimirLista(listaOrdenada2);

    excluirElementoOrdenado(listaOrdenada2, 25);
    imprimirLista(listaOrdenada2);

    excluirElementoOrdenado(listaOrdenada2, 40);
    imprimirLista(listaOrdenada2);

    excluirElementoOrdenado(listaOrdenada2, 45);
    imprimirLista(listaOrdenada2);

    excluirElementoOrdenado(listaOrdenada2, 35);
    imprimirLista(listaOrdenada2);
    
    //insercao, quantidade de elementos, media e profundidade lista 1
    inserirElementoOrdenado(listaOrdenada1, 20);
    inserirElementoOrdenado(listaOrdenada1, 10);
    inserirElementoOrdenado(listaOrdenada1, 15);
    inserirElementoOrdenado(listaOrdenada1, 1);
    inserirElementoOrdenado(listaOrdenada1, 5);
    printf("\n\n Elementos da Lista 1: ");
    imprimirLista(listaOrdenada1);
    printf(" quantidade de elementos da lista 1: %d", quantidadeElementosLista(listaOrdenada1));
    printf("\n media aritmetica lista 1: %.2f", calcularMedia(listaOrdenada1));
    printf("\n Profundidade elemento 15: %d", verificarProfundidade(listaOrdenada1,15));
    
    //insercao, quantidade de elementos, media e profundidade lista 2
    inserirElementoOrdenado(listaOrdenada2, 35);
    inserirElementoOrdenado(listaOrdenada2, 40);
    inserirElementoOrdenado(listaOrdenada2, 30);
    inserirElementoOrdenado(listaOrdenada2, 45);
    inserirElementoOrdenado(listaOrdenada2, 25);
    printf("\n\n Elementos da Lista 2: ");
    imprimirLista(listaOrdenada2);
    printf(" quantidade de elementos da lista 2: %d", quantidadeElementosLista(listaOrdenada2));
    printf("\n media aritmetica lista 2: %.2f", calcularMedia(listaOrdenada2));
    printf("\n Profundidade elemento 45: %d \n", verificarProfundidade(listaOrdenada2,45));
    
    //verificando se as dus listas possuem o mesmo conteudo
    if(compararListas(listaOrdenada1, listaOrdenada2))
       printf("\n\n Lista1 e lista2 são iguais \n");
       else
           printf("\n\n Lista1 e lista2 são diferentes \n");
           
    //apagando lista 1
    listaOrdenada1 = apagarLista(listaOrdenada1);
    if (!listaOrdenada1)
    {
        printf(" Lista 1 apagada!\n");
    }
    else
    {
        printf(" A lista 1 ainda existe!\n");
    }
    
    //apagando lista 2
    listaOrdenada2 = apagarLista(listaOrdenada2);
    if (!listaOrdenada2)
    {
        printf(" Lista 2 apagada! \n");
    }
    else
    {
        printf(" A lista 2 ainda existe! \n");
    }
    return 0;
}
