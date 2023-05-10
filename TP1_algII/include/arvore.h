#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct Node Node;

struct Node{
  char cadeia;
  int codigo;
  int numFilhos;
  Node* Pai;
  Node**Filhos;
};

Node* InsereArvore(Node **Pai, int posicao, char palavra, int codigo);
void CriaArvore(Node **Raiz);
Node* BuscaArvore(Node *no, char caractere);

#endif