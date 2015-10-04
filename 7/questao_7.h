#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Pilha{
	char dado;
	struct Pilha *prox;
}pilha;
typedef struct Header{
	int tamanho;
	pilha *inicio,*fim;
}header;

void ler_arquivo(header *controle_pilha1);
void push (header *controle_pilha1, char dado);
char pop (header *controle_pilha1);
void printar (header *controle_pilha1);
void verifica_palindrome(header *controle_pilha1,header *controle_pilha2);