#include "questao_4.h"

int main(){
	header *controle_lista1=(header *)calloc(1,sizeof(header));
	header *controle_lista2=(header *)calloc(1,sizeof(header));
	header *controle_lista3=(header *)calloc(1,sizeof(header));
	ler_arquivo(controle_lista1,"fonte1.txt");
	ler_arquivo(controle_lista2,"fonte2.txt");
	//concatena_ordenando(controle_lista1,controle_lista2,controle_lista3);
	concatena_intercalando(controle_lista1,controle_lista2,controle_lista3);
	printf("\tLista 1:\n\t");
	printar(controle_lista1);
	printf("\n\tLista 2:\n\t");
	printar(controle_lista2);
	printf("\n\tLista 3:\n\t");
	printar(controle_lista3);
	return 0;
}
void insere_inicio_lista (header *controle_lista, int chave){
	lista *no=(lista *) calloc (1,sizeof (lista));
	no->chave=chave;
	no->prox=controle_lista->inicio;
	controle_lista->inicio=no;
	controle_lista->tamanho++;
}
void concatena_intercalando(header *controle_lista1,header *controle_lista2,header *controle_lista3)
{
	lista *corrente1,*corrente2;
	int tamanho;
	if(controle_lista1->tamanho>=controle_lista2->tamanho)
		tamanho=controle_lista1->tamanho;
	else
		tamanho=controle_lista2->tamanho;
	for (corrente1=controle_lista1->inicio,corrente2=controle_lista2->inicio;tamanho;tamanho--)
	{
		if(corrente1->prox!=NULL){
			insere_inicio_lista (controle_lista3, corrente1->chave);
		 	corrente1=corrente1->prox;
		}
		if(corrente2->prox!=NULL){
			insere_inicio_lista (controle_lista3, corrente2->chave);
			corrente2=corrente2->prox;
		}
	}
}
void concatena_ordenando(header *controle_lista1,header *controle_lista2,header *controle_lista3)
{
	lista *corrente;
	for (corrente = controle_lista1->inicio;corrente!=NULL; corrente=corrente->prox)
		insere_ordenando (controle_lista3, corrente->chave);
	for (corrente = controle_lista2->inicio;corrente!=NULL; corrente=corrente->prox)
		insere_ordenando (controle_lista3, corrente->chave);
}

void insere_ordenando (header *controle_lista, int chave)
{
	lista *corrente;
	lista *no=(lista *) calloc (1,sizeof (lista));
	no->chave=chave;
	if (controle_lista->inicio==NULL)
		controle_lista->inicio=no;
	else if(controle_lista->inicio->chave > chave){
		no->prox=controle_lista->inicio;
		controle_lista->inicio->ant=no;
		controle_lista->inicio=no;
	}
	else{
		corrente=controle_lista->inicio;
		while (corrente->prox!=NULL && corrente->prox->chave < chave)
			corrente=corrente->prox;
		no->prox=corrente->prox;
		corrente->ant=no;
		corrente->prox=no;
	}
	controle_lista->tamanho++;
}
void ler_arquivo(header *controle_lista,char arquivo[30]){
	FILE *arq;
	int chave;
	if (fopen(arquivo,"r")==NULL){
		printf("Arquivo %s nao encontrado",arquivo);
		exit(1);
	}
	else{
		arq=fopen(arquivo,"r");
		while(!feof(arq)){
			fscanf (arq,"%d",&chave);
			insere_ordenando(controle_lista,chave);
		}
	}
}
void printar (header *controle_lista){
	lista * corrente;
	for (corrente=controle_lista->inicio;corrente!=NULL;corrente=corrente->prox){
		printf("%d ",corrente->chave);
	}
}