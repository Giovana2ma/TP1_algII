#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "palavra.h"

int Palavra(Node *pai,char **palavra){
  Node *aux;
  aux = pai;
  int i =0;
  while(aux->Pai!=NULL){
    (*palavra)[i] = aux->cadeia;
    i++;
    (*palavra) = (char*) realloc((*palavra), sizeof(char) * i+1);
    aux = aux->Pai;
  }
  inverte(*(palavra),0,i-1);
  (*palavra)[i] = '\0';
  return i;
}

void inverte(char *palavra,int pos,int tam){
  char aux;
  if(pos < tam){
    aux = palavra[pos];
    palavra[pos] = palavra[tam];
    palavra[tam] = aux;
    inverte(palavra,pos+1,tam-1);
  }
}