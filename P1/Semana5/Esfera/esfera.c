#include<stdlib.h>
#include<math.h>


typedef struct t_esfera{
        float raio;

}tipo_esfera;


tipo_esfera *criar_esfera(float raio){

	tipo_esfera *esfera;
	
	esfera = (tipo_esfera*)malloc(sizeof( tipo_esfera));
	
	esfera->raio=raio;
	
	return esfera;
}

float calcular_area(tipo_esfera *esfera){

       float area;

       area=4*3.14*pow(esfera->raio,2);

        
       return area;
}
float calcular_volume(tipo_esfera *esfera){

      float volume;
      
      volume= (4*3.14*pow(esfera->raio,3))/3;
      
      return volume;
}
tipo_esfera *libera(tipo_esfera *esfera){

     free(esfera);
     
     return NULL;
}
       

