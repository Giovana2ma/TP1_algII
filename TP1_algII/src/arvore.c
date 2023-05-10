#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void CriaArvore(Node **Raiz)
{
    *Raiz = malloc(sizeof(Node));
    (*Raiz)->cadeia = '\0';
    (*Raiz)->codigo = 0;
    (*Raiz)->numFilhos = 0;
    (*Raiz)->Filhos = NULL;
    (*Raiz)->Pai = NULL;
}

Node *InsereArvore(Node **Pai, int posicao, char palavra, int codigo)
{
    (*Pai)->Filhos = realloc((*Pai)->Filhos, ((*Pai)->numFilhos + 1) * sizeof(Node *));
    (*Pai)->Filhos[posicao] = malloc(sizeof(Node));
    (*Pai)->Filhos[posicao]->cadeia = palavra;
    (*Pai)->Filhos[posicao]->codigo = codigo;
    (*Pai)->Filhos[posicao]->numFilhos = 0;
    (*Pai)->Filhos[posicao]->Pai = *Pai;
    (*Pai)->Filhos[posicao]->Filhos = malloc(sizeof(Node *));
    (*Pai)->numFilhos++;
    return (*Pai)->Filhos[posicao];
}

Node *BuscaArvore(Node *no, char caractere)
{
    int achou = 0;
    int indice = 0;
    for (int i = 0; i < no->numFilhos; i++)
    {
        if (no->Filhos[i]->cadeia == caractere)
        {
            indice = i;
            achou = 1;
            break;
        }
    }
    if (achou == 0)
        return NULL;
    else
        return no->Filhos[indice];
}