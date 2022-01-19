#include <stdio.h>
#include <stdlib.h>

//void NAOMANDARradixsort(int * vetor, int tamanho, int e);
void countingSort(int *vetor, int tam, int valorMax);
void radixsort(int *vetor, int tamanho, int e);
int power(int b, int e);
int getMaxValue(int *, int);
int divisoesConsecutivas(int value, int divisor);

int main(void) {
  int e;
  int n;
  // data input
  scanf("%d",&e);
  scanf("%d",&n);

  int *v = calloc(n , sizeof(int));
  for(int i = 0; i < n; i++){
    scanf("%d",&v[i]);
  }
  radixsort(v,n,e);
  return 0;
}


void radixsort(int *vetorOrg, int tamanho, int e){

  int* vetor = (int*) calloc(tamanho, sizeof(int));
  for(int i=0;i< tamanho;i++){
    vetor[i] = vetorOrg[i];
  }


  // define a base como potencia de 2
  int base = 1 << e;

  // define mask
  int mask = ( (1<<e) -1);

  // define variável do while, d para pegar o digito da 'casa decimal' e para colocar os elementos na sua posicao no counting
  int p=0, d;
  
  // duas funcoes calculam de forma bem burra quantos bits tem no max
  int max = getMaxValue(vetorOrg, tamanho);
  int vezes = divisoesConsecutivas(max, base);

  // loop para cada bit
  while(p<vezes){

  int *vetorDeContagem = (int*) calloc(base ,sizeof(int));

  for(int i = 0; i < tamanho; i++){
    d = ( vetorOrg[i] >> (p * e) ) & mask; 
    vetorDeContagem[d]++;
  }

  int *vetorPosicoes = (int*) calloc(base, sizeof(int));
  for(int i=1;i<base;i++){
    vetorPosicoes[i] = vetorPosicoes[i-1] + vetorDeContagem[i-1];
  }


  // acha as posicoes iniciais de cada elemento 
  for(int i = 0; i < tamanho; i++){ 
    d = (vetorOrg[i] >> (p * e)) & mask;
    vetor[vetorPosicoes[d]] = vetorOrg[i];
    vetorPosicoes[d]++;
  }

  // copia o vetor(aux) n vetor org para aproveitar a ordenacao na proxima
  for(int i=0;i< tamanho;i++){
    vetorOrg[i] = vetor[i];
  }

  for (int i = 0; i < tamanho; i++){
    	  printf("%d ",vetor[i]);
      }
      printf("\n");

      
    p++;
  }
  
}
int getMaxValue(int * vetor, int n){
  int max = 0;
  for(int i = 0; i < n; i++){
    if(vetor[i] > max){
      max = vetor[i];
    }
  }
  return max;
}

int divisoesConsecutivas(int value, int divisor){
  int i = 0;
  while(value > 0){
    value /= divisor;
    i++;
  }
  return i;
}

int power(int b, int e){
  if(e == 0){
    return 1;
  }

  int x = b;

  for(int i=2;i<=e;i++){
    x *=b;
  }
  return x;
}