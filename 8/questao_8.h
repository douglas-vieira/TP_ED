#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Pilha{
	char dado;
	struct Pilha *prox;
}pilha;
typedef struct Header{
	int tamanho;
	pilha *inicio;
}header;