#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Pilha{
	int dado;
	struct Pilha *prox;
}pilha;
typedef struct Header_pilha{
	int tamanho;
	pilha *inicio,*fim;
}header_pilha;
typedef struct Fila{
	int dado;
	struct Fila *prox, *ant;
}fila;
typedef struct Header_fila{
	int tamanho;
	fila *inicio,*fim;
}header_fila;

void inverte(header_pilha *controle_pilha1,header_fila *controle_fila);
void push (header_pilha *controle_pilha1, int dado);
int pop (header_pilha *controle_pilha1);
void insere_fila (header_fila *controle_fila, int dado);
int retira_fila(header_fila *controle_fila);
void ler_arquivo(header_pilha *controle_pilha1);
void printar_pilha (header_pilha *controle_pilha1);
void printar_fila (header_fila *controle_pilha1);
