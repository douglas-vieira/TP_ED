#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Pilha{
	int dado;
	struct Pilha *prox;
}pilha;
typedef struct Header{
	int tamanho;
	pilha *inicio,*fim;
}header;
void push (header *controle_pilha, int dado);
int pop (header *controle_pilha);
void ler_arquivo(header *controle_pilha);
void printar (header *controle_pilha);
void inverte(header *controle_pilha1,header *controle_pilha2,header *controle_pilha3);