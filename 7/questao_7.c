#include "questao_7.h"

int main(){
	header *controle_pilha1=(header *)calloc(1,sizeof(header));
	header *controle_pilha2=(header *)calloc(1,sizeof(header));

	ler_arquivo(controle_pilha1);
	printf("Palavra original\n");
	printar(controle_pilha1);
	verifica_palindrome (controle_pilha1,controle_pilha2);
	return 0;
}
void verifica_palindrome(header *controle_pilha1,header *controle_pilha2)
{
	int aux,flag=0;
	if(controle_pilha1->tamanho%2==0)
	{
		for(aux=controle_pilha1->tamanho/2;aux>0;aux--)
			push(controle_pilha2, pop(controle_pilha1));
	}
	else
	{
		for(aux=controle_pilha1->tamanho/2;aux>0;aux--)
			push(controle_pilha2, pop(controle_pilha1));
		pop(controle_pilha1);
	}
	while(controle_pilha1->tamanho>0 && controle_pilha1->tamanho>0 && flag==0)
	{
		if(pop(controle_pilha1)!=pop(controle_pilha2))
			flag=1;
	}
	if (flag)
		printf("\n\nNao e Palindrome\n");
	else
		printf("\n\nE Palindrome\n");
	
}
void ler_arquivo(header *controle_pilha1){
	FILE *arq;
	char dado;
	if (fopen("fonte.txt","r")==NULL){
		printf("Arquivo fonte.txt nao encontrado");
		exit(1);
	}
	else{
		arq=fopen("fonte.txt","r");
		while(!feof(arq)){
			dado=getc (arq);
			if (dado!='\n' && dado!=' '&& dado!='\r'&& dado!=EOF)
			push(controle_pilha1,dado);
		}
	}
}
void push (header *controle_pilha1, char dado){
	pilha *no=(pilha *) calloc (1,sizeof (pilha));
	no->dado=dado;
	no->prox=controle_pilha1->inicio;
	controle_pilha1->inicio=no;
	controle_pilha1->tamanho++;
}
char pop (header *controle_pilha1){
	pilha *elimina;
	char dado;
	dado=controle_pilha1->inicio->dado;
	elimina=controle_pilha1->inicio;
	controle_pilha1->inicio=controle_pilha1->inicio->prox;
	free(elimina);
	controle_pilha1->tamanho--;
	return dado;
}
void printar (header *controle_pilha1){
	pilha * corrente;
	for (corrente=controle_pilha1->inicio;corrente!=NULL;corrente=corrente->prox)
		printf("%c ",corrente->dado);
}
