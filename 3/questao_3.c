#include "questao_3.h"

int main(){
	header *controle_lista1=(header *)calloc(1,sizeof(header));
	header *controle_lista2=(header *)calloc(1,sizeof(header));
	ler_arquivo(controle_lista1,"fonte1.txt");
	ler_arquivo(controle_lista2,"fonte2.txt");
	verifica_igualdade(controle_lista1,controle_lista2);
	printf("\tLista 1:\n\t");
	printar(controle_lista1);
	printf("\n\tLista 2:\n\t");
	printar(controle_lista2);
	return 0;
}

void insere_fim_lista (header *controle_lista, int chave){
	lista *no=(lista *) calloc (1,sizeof (lista));
	no->chave=chave;
	if (controle_lista->inicio==NULL)
		controle_lista->inicio=controle_lista->fim=no;
	else{
		controle_lista->fim->prox=no;
		no->ant=controle_lista->fim;
	}
	controle_lista->fim=no;
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
			insere_fim_lista(controle_lista,chave);
		}
	}
}
void printar (header *controle_lista){
	lista * corrente;
	for (corrente=controle_lista->inicio;corrente!=NULL;corrente=corrente->prox){
		printf("%d ",corrente->chave);
	}
}
void verifica_igualdade (header *controle_lista1,header *controle_lista2){
	lista *corrente1=controle_lista1->inicio;
	lista *corrente2=controle_lista2->inicio;
	int flag=0;
	for (;corrente1!=NULL&&corrente2!=NULL;corrente1=corrente1->prox,corrente2=corrente2->prox){
		if(corrente1->chave!=corrente2->chave)
			flag=1;
	}
	if (flag==0)
		printf("**Listas Iguais**\n");
	if (flag==1)
		printf("**Listas Diferentes**\n");
}