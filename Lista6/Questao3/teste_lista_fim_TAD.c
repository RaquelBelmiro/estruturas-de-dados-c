#include<stdio.h>
#include"lista_fim_TAD.h"

void imprimirLista(tipo_lista* lista)
{
    int *elementosLista, posicao;
    elementosLista = obterElementosLista(lista);  //elementos lista vai apontar para o endereco do vetor de elementos obtidos retornado pela funcao 
    
    for (posicao = 0; posicao < quantidadeElementosLista(lista); posicao++)
    {
        printf("%d ", elementosLista[posicao]);
    }
    printf("\n");
}

int main()
{
    tipo_lista *lista=NULL;

    lista = criarListaVazia();

    
    
     //inserindo na lista
     inserirElementoFim(lista, 2);
     inserirElementoFim(lista, 3);
     inserirElementoFim(lista, 1);
     printf("\n\n Elementos da lista: ");
     imprimirLista(lista);
     
     //excluindo lista
     

     printf("\n lista apos exclusao no fim: ");
     excluirElementoFim(lista);
     imprimirLista(lista);
     printf("\n lista apos exclusao no fim: ");
     excluirElementoFim(lista);
     imprimirLista(lista);
     printf("\n lista apos exclusao no fim: ");
     excluirElementoFim(lista);
     imprimirLista(lista);

     //inserindo na lista
     inserirElementoFim(lista, 2);
     inserirElementoFim(lista, 3);
     inserirElementoFim(lista, 3);
     inserirElementoFim(lista, 1);
     inserirElementoFim(lista, 2);
     printf("\n\n Impressão da lista: ");
     imprimirLista(lista);
     if(listaVazia(lista))
        printf("\n A lista esta vazia");
        else
            printf("\n A lista nao esta vazia ");
     printf("\n\n Quantidade de elementos lista: %d \n", quantidadeElementosLista(lista));

     apagarIguais(lista,2);
     apagarIguais(lista,3);
     printf("\nImpressão da lista apos retirar elementos 2 e 3: ");
     imprimirLista(lista);

    lista=apagarLista(lista);
    if (!lista)
    {
        printf("Lista apagada!\n\n");
    }
    else
    {
        printf("A lista ainda existe!");
    }

    return 0;
}
