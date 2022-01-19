#include <stdio.h>
#include <stdlib.h>

int shell(int * vetor, int quantidadeDeElementos);
int quick(int * vetor, int quantidadeDeElementos);
void quickRecursivo(int * vetor, int comeco, int fim, int *operacoes);

int main(void) {
  int quantidadeDeElementos;
  if(scanf("%d",&quantidadeDeElementos)==0){
    return 0;
  }
  int * vetorPai;
  vetorPai = (int *) malloc(quantidadeDeElementos*sizeof(int));
  for(int i = 0; i < quantidadeDeElementos; i++){
    if(scanf("%d",&vetorPai[i])==0){
      return 0;
    }
  }

  for(int i = 1; i <= quantidadeDeElementos; i++) {
    int *vetorFilho1 = (int *) malloc(i * sizeof(int));
    int *vetorFilho2 = (int *) malloc(i * sizeof(int));
    for(int j = 0; j < i; j++) {
      vetorFilho1[j] = vetorPai[j];
      vetorFilho2[j] = vetorPai[j];
    }
    int comparacoesShell = shell(vetorFilho1, i);
    int comparacoesQuick = quick(vetorFilho2, i);
    if(comparacoesQuick < comparacoesShell){
      printf("Q ");
    } else if(comparacoesShell < comparacoesQuick) {
      printf("S ");
    } else {
      printf("- ");
    }
    free(vetorFilho1);
    free(vetorFilho2);
  }
  free(vetorPai);
  return 0;
}

int shell(int * vetor, int quantidadeDeElementos){
  int operacoes = 0;
  int gap = 1;
  while (gap < quantidadeDeElementos){
    gap *= 2;
  }
  gap = gap / 2 - 1;
  while (gap > 0) {
    for(int i = gap; i < quantidadeDeElementos; i++){
      int x = vetor[i];
      operacoes++;
      int j = i - gap;
      while (j >= 0 && vetor[j] > x){
        operacoes++;
        vetor[j + gap] = vetor[j];
        operacoes++;
        j -= gap;
      }
      if (j >= 0) {
        operacoes++;
      }
      vetor[j + gap] = x;
      operacoes++;
    }
    gap /= 2;
  }
  return operacoes;
}

int quick(int * vetor, int quantidadeDeElementos){
  int operacoes = 0;
  quickRecursivo(vetor, 0, quantidadeDeElementos - 1, &operacoes);
  return operacoes;
}

void quickRecursivo(int * vetor, int comeco, int fim, int *operacoes){
  if (comeco >= fim){
    return;
  }
  int m = (comeco + fim) / 2;
  int pivot = vetor[m];
  (*operacoes)++;
  int i = comeco;
  int j = fim;
  while (1){
    while(vetor[i] < pivot){
      (*operacoes)++;
      i++;
    }
    (*operacoes)++;
    while(vetor[j] > pivot){
      (*operacoes)++;
      j--; 
    }   
    (*operacoes)++;
    if (j <= i){
      break;
    }
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
    (*operacoes) += 3;
    i++;
    j--;
  }
  quickRecursivo(vetor, comeco, j, operacoes);
  quickRecursivo(vetor, j + 1, fim, operacoes);
}
