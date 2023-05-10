#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "arvore.h"
#include "palavra.h"

int main(int argc, char *argv[])
{
  char compactar[] = "-c";
  char descompactar[] = "-x";
  FILE *arquivo;
  FILE *saida;
  // compressão
  if (strcmp(argv[1], compactar) == 0)
  {
    arquivo = fopen(argv[2], "r");

    if (argc == 3)
    {
      char *comp = argv[2];
      int tam = strlen(comp);
      comp[tam - 1] = '8';
      comp[tam - 2] = '7';
      comp[tam - 3] = 'z';
      saida = fopen(comp, "wb");
    }
    else
    {
      saida = fopen(argv[3], "wb");
    }

    Node *Raiz;
    CriaArvore(&Raiz);
    int codigo = 1;
    Node *atual = Raiz;
    char caractere;
    while (fread(&caractere, sizeof(char), 1, arquivo))
    {

      if (BuscaArvore(atual, caractere) != NULL)
      {
        atual = BuscaArvore(atual, caractere);
      }
      else
      {
        fwrite(&atual->codigo, sizeof(int), 1, saida);
        fwrite(&caractere, sizeof(char), 1, saida);
        InsereArvore(&atual, atual->numFilhos, caractere, codigo);
        codigo++;
        atual = Raiz;
      }
    }

    if (atual != Raiz)
    {
      atual = atual->Pai;
      fwrite(&atual->codigo, sizeof(int), 1, saida);
      fwrite(&caractere, sizeof(char), 1, saida);
    }
  }

  // descompressão

  if (strcmp(argv[1], descompactar) == 0)
  {
    arquivo = fopen(argv[2], "rb");
    if (argc == 3)
    {
      char *comp = argv[2];
      int tam = strlen(comp);
      comp[tam - 1] = 't';
      comp[tam - 2] = 'x';
      comp[tam - 3] = 't';
      saida = fopen(comp, "w");
    }
    else
    {
      saida = fopen(argv[3], "w");
    }
    int codigo = 1;
    char caractere;

    Node *dicionario;
    CriaArvore(&dicionario);
    Node *aux;
    Node **lista = malloc(sizeof(Node));
    lista[0] = dicionario;
    int indice;

    while (fread(&indice, sizeof(int), 1, arquivo) & fread(&caractere, sizeof(char), 1, arquivo))
    {
      Node *pai = lista[indice];
      aux = InsereArvore(&pai, pai->numFilhos, caractere, codigo);
      lista = realloc(lista, (codigo + 1) * sizeof(Node *));
      lista[codigo] = aux;
      codigo++;
      char *palavra;
      palavra = (char *)malloc(sizeof(char));
      Palavra(aux, &palavra);
      fputs(palavra, saida);
    }
  }

  return 0;
}