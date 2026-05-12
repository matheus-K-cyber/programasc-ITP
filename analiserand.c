#include <stdio.h>
#include <stdlib.h>

/*
@brief gera um número aleatório no intervalo [min,max]
@param min o número minimo no range
@param max o número máximo no range
@return um número aleatório no intervalo [min,max]
*/
int rand_int_range(int min, int max){
   int range = max - min + 1;
   return min + rand() % range;
}

int *criarVetorAleatorio(int tamanho, int minimo, int maximo){
   int *vetor = malloc((tamanho + 3) * sizeof(int));
   vetor[0] = tamanho;
   vetor[1] = minimo;
   vetor[2] = maximo;

   for(int i = 3; i < tamanho + 3; i++){
      vetor[i] = rand_int_range(minimo, maximo);
   }

   return vetor;
}

int *criarHistograma(int *valores){
   int min = valores[1];
   int max = valores[2];
   int *histograma = calloc((max - min + 1) + 2, sizeof(int));
   histograma[0] = min;
   histograma[1] = max;

   for(int i = 3; i < valores[0] + 3; i++){
      int indice = (valores[i] - min) + 2;
      histograma[indice]++;
   }

   return histograma;
}

float *criarPorcentagens(int *histograma){
   int min = histograma[0];
   int max = histograma[1];
   int total = 0;

   for(int i = 2; i < (max - min + 1) + 2; i++){
      total += histograma[i];
   }

   float *porcentagens = malloc((max - min + 1) * sizeof(float));

   for(int i = 0; i < (max - min + 1); i++){
      porcentagens[i] = (histograma[i + 2] / (float)total) * 100;
   }

   return porcentagens;
}

void imprimePorcentagens(float *porcentagens, int *histograma){
   int min = histograma[0];
   int max = histograma[1];

   printf("Valor |Qtdade |Porcent\n");

   for(int i = 0; i < (max - min + 1); i++){
      printf("%d |%d |%.2f%%\n", min + i, histograma[i + 2], porcentagens[i]);
   }
}

void liberar(int *valores, float *porcentagens, int *histograma){
   free(valores);
   free(porcentagens);
   free(histograma);
}

int main(){
   int tamanho, maximo, minimo;

   scanf("%d", &tamanho);
   scanf("%d %d", &minimo, &maximo);

   int *valores = criarVetorAleatorio(tamanho, minimo, maximo);

   int *histograma = criarHistograma(valores);

   float *porcentagens = criarPorcentagens(histograma);

   imprimePorcentagens(porcentagens, histograma);

   liberar(valores, porcentagens, histograma);

   return 0;
}