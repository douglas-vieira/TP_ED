#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Nodo{
	int dado[2];
	struct Nodo *prox;
}nodo;
typedef struct Header{
	int tamanho;
	struct Nodo *inicio,*fim;
}header;

void insere_inicio_lista (header *controle_lista, int dado[]);
void ler_arquivo(header *controle_lista);
void printar (header *controle_lista);