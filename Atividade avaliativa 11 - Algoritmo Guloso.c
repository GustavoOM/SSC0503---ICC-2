#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200

void printReads(char **matriz, int tam);
int getOverlap(char * string1, char * string2);
void juntaMelhorOverlap(char * string1,char * string2 ,int overLap);

int main(){
    int quantidadeDeReads;
    char ** reads;
    if(!scanf("%d",&quantidadeDeReads)){
      printf("ERRO DE LEITURA\n");
      exit(0);
    }

    reads = malloc(sizeof(char*)*quantidadeDeReads);
    for(int i = 0; i < quantidadeDeReads; i++){
      reads[i] = malloc(sizeof(char)*MAX);
      if(!scanf("%s", reads[i])){
        printf("ERRO DE LEITURA\n");
        exit(0);
      }
    }

    int melhorOverlap;
    int posicaoMelhorOverlapPai;
    int posicaoMelhorOverlapFilho;
    int possivelOverlap;
    for(int i = 0; i < quantidadeDeReads; i++){
      melhorOverlap = -1;
      posicaoMelhorOverlapPai = -1;
      posicaoMelhorOverlapFilho = -1;
      for(int j = 0; j < quantidadeDeReads; j++){
        for(int k = 0; k < quantidadeDeReads; k++){
          if(j!=k && strlen(reads[j]) != 0  && strlen(reads[k]) != 0){
            possivelOverlap = getOverlap(reads[j],reads[k]);
            if(possivelOverlap > melhorOverlap){
              melhorOverlap = possivelOverlap;
              posicaoMelhorOverlapPai = j;
              posicaoMelhorOverlapFilho = k;
            }
          }
        }
      }
      if(melhorOverlap > -1){
        juntaMelhorOverlap(reads[posicaoMelhorOverlapPai],reads[posicaoMelhorOverlapFilho],melhorOverlap);
        strcpy(reads[posicaoMelhorOverlapFilho],"");

      }
    }

    for(int i = 0; i < quantidadeDeReads; i++){
      if(strlen(reads[i]) != 0){
        printf("%s\n",reads[i]);
      }
    }
    
    for(int i = 0; i < quantidadeDeReads; i++){
      free(reads[i]);
    }
    free(reads);

    return 0;
}

void printReads(char **matriz, int tam){

  for(int i = 0; i < tam; i++){
      printf("%s\n", matriz[i]);
    }
 
}

int getOverlap(char * string1, char * string2){
  if(strstr(string1, string2)){
    return strlen(string2); 
  }
  for(int i = 0; i < strlen(string1);i++){
        for(int j = 0; j < strlen(string2); j++){
            if(string1[i+j] == '\0' )
                return j;
            if(string2[j] != string1[i+j])
                break;
        }
    }
  return 0;
}

void juntaMelhorOverlap(char * string1,char * string2 ,int overLap){
  if(strlen(string1) == 0 || strlen(string2) == 0)
    return;
  for(int i = overLap; i < strlen(string2); i++){
    string1[strlen(string1)] = string2[i];
  }
}
