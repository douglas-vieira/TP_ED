#include "questao_5.h"

int main(){
	header *controle_pilha1=(header *)calloc(1,sizeof(header));
	header *controle_pilha2=(header *)calloc(1,sizeof(header));
	header *controle_pilha3=(header *)calloc(1,sizeof(header));
	ler_arquivo(controle_pilha1);
	printf("\nPilha Original");
	printar(controle_pilha1);
	inverte(controle_pilha1,controle_pilha2,controle_pilha3);
	printf("\nPilha Invertida");
	printar(controle_pilha1);
	return 0;
}
void inverte(header *controle_pilha1,header *controle_pilha2,header *controle_pilha3)
{
	while(controle_pilha1->tamanho>0)
		push(controle_pilha2, pop(controle_pilha1));
	while(controle_pilha2->tamanho>0)
		push(controle_pilha3, pop(controle_pilha2));
	while(controle_pilha3->tamanho>0)
		push(controle_pilha1, pop(controle_pilha3));
}

void push (header *controle_pilha1, int dado){
	pilha *no=(pilha *) calloc (1,sizeof (pilha));
	no->dado=dado;
	no->prox=controle_pilha1->inicio;
	controle_pilha1->inicio=no;
	controle_pilha1->tamanho++;
}

int pop (header *controle_pilha1){
	pilha *elimina;
	int dado;
	dado=controle_pilha1->inicio->dado;
	elimina=controle_pilha1->inicio;
	controle_pilha1->inicio=controle_pilha1->inicio->prox;
	free(elimina);
	controle_pilha1->tamanho--;
	return dado;
}

void ler_arquivo(header *controle_pilha1){
	FILE *arq;
	int dado;
	if (fopen("fonte.txt","r")==NULL){
		printf("Arquivo fonte.txt nao encontrado");
		exit(1);
	}
	else{
		arq=fopen("fonte.txt","r");
		while(!feof(arq)){
			fscanf (arq,"%d",&dado);
			push(controle_pilha1,dado);
		}
	}
}

void printar (header *controle_pilha1){
	pilha * corrente;
	printf("\n");
	for (corrente=controle_pilha1->inicio;corrente!=NULL;corrente=corrente->prox){
		printf("%d ",corrente->dado);
	}
}