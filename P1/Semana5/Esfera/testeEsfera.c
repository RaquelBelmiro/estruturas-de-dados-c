#include <stdio.h>
#include "esfera.h"

int main (){

    tipo_esfera *esfera1;
    float raio;
   
    printf (" Entre com o valor do raio:");
    scanf ("%f", &raio);
 
   esfera1 = criar_esfera(raio);

   printf ("\nArea da esfera: %.2f\n",calcular_area(esfera1));

   printf("volume da esfera: %.2f m³ \n",calcular_volume(esfera1));

   esfera1=libera(esfera1);
   return 0;
 }
