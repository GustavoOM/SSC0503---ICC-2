#include <stdio.h>
#include <stdlib.h>

void countingSort(int * vetor, int tamanho, int valorMaximo);

int main(void) {
  int k;
  int n;
  int *v;
  scanf("%d",&k);
  scanf("%d",&n);
  v = (int*) calloc (n,sizeof(int));
  for(int i = 0; i < n; i++){
    scanf("%d",&v[i]);
  }
  countingSort(v,n,k);
  
  //printf("Vetor Final: ");
  //for(int i = 0; i < n; i++){
  //  printf("%d ",v[i]);
  //}
  return 0;
}

void countingSort(int * vetor, int tamanho, int valorMaximo){

  int *vetorOriginal;
  int *vetorDeContagem;
  vetorOriginal = (int*) calloc (tamanho,sizeof(int));
  vetorDeContagem = (int*) calloc (valorMaximo,sizeof(int)); 

  // copia o vetor original no vetor para não sobrepor o original
  for(int i = 0; i < tamanho; i++){
    vetorOriginal[i] = vetor[i];
    vetorDeContagem[vetor[i]]++;
  }
  
  // cria uma variável que inicia no valorMaximo e uma no tamanho, além de postular que o vetor 0 começa do 0
  int aux = valorMaximo;
  int discount = tamanho;
  vetorDeContagem[0] = 0;
  
  // no loop, reescreve o mesmo vetor de contagem descontando do tamanho quantas posições já foram do total(tamanho) - Assim, o vetorDeContagem é reescrito com a posição de início de cada um
  for(int i = aux-1; i > 0; i--){
    //printf("I = %d Aux: %d VetContAntes: %d\n",i,aux,vetorDeContagem[i]);
    vetorDeContagem[i] = discount - vetorDeContagem[i];
    //printf("VetContDps: %d\n\n", vetorDeContagem[i]);
    discount = vetorDeContagem[i];

  }
  // percorre o vetor e aumenta o contador de posição quando encontra o valor
  for(int i = 0; i < tamanho; i++){
    printf("%d %d\n",vetorOriginal[i],vetorDeContagem[vetorOriginal[i]]);
    vetor[vetorDeContagem[vetorOriginal[i]]] = vetorOriginal[i];
    vetorDeContagem[vetorOriginal[i]]++;
  }
}

/* 

max
5

tam
10

vetor
3 3 3 1 0 1 4 4 4 2

vetorOriginal
3 3 3 1 0 1 4 4 4 2

vetorContagem antes
1 2 1 3 3

aux
6

vetorContagem dps
0 2 3

*/

//gcc counting.c -o exeCounting && ./exeCounting < .in