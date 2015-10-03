#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Lista{
	int chave;
	struct Lista *prox, *ant;
}lista;
typedef struct Header{
	int tamanho;
	lista *inicio;
}header;
void insere_fim_lista (header *controle_lista, int chave);
void ler_arquivo(header *controle_lista,char arquivo[30]);
void printar (header *controle_lista);
void verifica_igualdade (header *controle_lista1,header *controle_lista2);