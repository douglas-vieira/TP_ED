#include "questao_6.h"

int main(){
	header_pilha *controle_pilha1=(header_pilha *)calloc(1,sizeof(header_pilha));
	header_fila *controle_fila=(header_fila *)calloc(1,sizeof(header_fila));

	ler_arquivo(controle_pilha1);
	printf("Pilha Original\n");
	printar_pilha(controle_pilha1);
	inverte(controle_pilha1,controle_fila);
	printf("\nPilha Invertida\n");
	printar_pilha(controle_pilha1);
	return 0;
}
void inverte(header_pilha *controle_pilha1,header_fila *controle_fila)
{
	while(controle_pilha1->tamanho>0)
		insere_fila(controle_fila, pop(controle_pilha1));
	while(controle_fila->tamanho>0)
		push(controle_pilha1, retira_fila(controle_fila));
}

void push (header_pilha *controle_pilha1, int dado){
	pilha *no=(pilha *) calloc (1,sizeof (pilha));
	no->dado=dado;
	no->prox=controle_pilha1->inicio;
	controle_pilha1->inicio=no;
	controle_pilha1->tamanho++;
}

int pop (header_pilha *controle_pilha1){
	pilha *elimina;
	int dado;
	dado=controle_pilha1->inicio->dado;
	elimina=controle_pilha1->inicio;
	controle_pilha1->inicio=controle_pilha1->inicio->prox;
	free(elimina);
	controle_pilha1->tamanho--;
	return dado;
}
void insere_fila (header_fila *controle_fila, int dado){
	fila *no=(fila *) calloc (1,sizeof (fila));
	no->dado=dado;
	if (controle_fila->inicio==NULL)
		controle_fila->inicio=controle_fila->fim=no;
	else{
		controle_fila->fim->prox=no;
		no->ant=controle_fila->fim;
	}
	controle_fila->fim=no;
	controle_fila->tamanho++;
}
int retira_fila(header_fila *controle_fila)
{
	fila *elimina;
	int dado;
	elimina=controle_fila->inicio;
	dado=controle_fila->inicio->dado;
	controle_fila->inicio=controle_fila->inicio->prox;
	free(elimina);
	controle_fila->tamanho--;
	return dado;
}
void ler_arquivo(header_pilha *controle_pilha1){
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
void printar_pilha (header_pilha *controle_pilha1){
	pilha * corrente;
	for (corrente=controle_pilha1->inicio;corrente!=NULL;corrente=corrente->prox)
		printf("%d ",corrente->dado);
	printf("\n");
}