#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

#ifndef PALAVRA_H_INCLUDED
#define PALAVRA_H_INCLUDED

int Palavra(Node *Pai,char **palavra); 
void inverte(char *palavra,int pos,int tam);

#endif