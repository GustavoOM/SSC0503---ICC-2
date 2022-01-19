#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bolha(int* vetor, int quantidadeDeElementos) {
  int auxiliarDeTroca;
  int lugarQueTrocou = quantidadeDeElementos;
  int final = quantidadeDeElementos;
  for(int i = 0; i < quantidadeDeElementos; i++){
      final = lugarQueTrocou;
      for(int j = 0; j < final-1; j++){
          printf("C %d %d\n", j, j+1);
          if(vetor[j] > vetor[j+1]){
              lugarQueTrocou = j+1;
              printf("T %d %d\n", j, j+1);
              auxiliarDeTroca = vetor[j];
              vetor[j] = vetor[j+1];
              vetor[j+1] = auxiliarDeTroca;
          }
      }
      if(lugarQueTrocou == final){
          break;
      }
  }
  for(int i = 0; i < quantidadeDeElementos; i++){
      printf("%d ", vetor[i]);
  }
}

void selecao(int* vetor, int quantidadeDeElementos){
  int auxiliarDeTroca;
  int menor;
  for(int i = 0; i < quantidadeDeElementos; i++){
      menor = i;
      for(int j = i+1; j < quantidadeDeElementos; j++){
          printf("C %d %d\n", menor, j);
          if(vetor[menor] > vetor[j]){
              menor = j;
          }
      }
      if(menor != i){
              printf("T %d %d\n", i, menor);
              auxiliarDeTroca = vetor[menor];
              vetor[menor] = vetor[i];
              vetor[i] = auxiliarDeTroca;
      }
  }
  for(int i = 0; i < quantidadeDeElementos; i++){
      printf("%d ", vetor[i]);
  }
}

int main(){
  int * vetor;
  int quantidadeDeElementos = 0;
  char metodo[10];

  setbuf(stdin, 0);
  fgets(metodo,24,stdin);
  metodo[strcspn(metodo, "\n")] = 0;

  scanf("%d", &quantidadeDeElementos);

  vetor = (int*) calloc (quantidadeDeElementos,sizeof(int));

  for(int i = 0; i < quantidadeDeElementos; i++){
      scanf("%d", &vetor[i]);
  }
  
  if(!strcmp(metodo, "selecao")){
      selecao(vetor, quantidadeDeElementos);
  }
  else if(!strcmp(metodo, "bolha")){
      bolha(vetor, quantidadeDeElementos);
  }
  else{
      printf("Opção inválida de método de ordenação");
  }
  printf("\n");
  free(vetor);
}