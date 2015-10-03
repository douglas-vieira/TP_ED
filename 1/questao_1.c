#include "questao_1.h"
int main(){
	header *controle_lista=(header *)calloc(1,sizeof(header));
	ler_arquivo(controle_lista);
	printar(controle_lista);
	return 0;
}

void insere_inicio_lista (header *controle_lista, int dado[]){
	nodo *no=(nodo *) calloc (1,sizeof (nodo));
	no->dado[0]=dado[0];
	no->dado[1]=dado[1];
	no->prox=controle_lista->inicio;
	controle_lista->inicio=no;
}

void ler_arquivo(header *controle_lista){
	FILE *arq;
	int dado[2];
	if (fopen("fonte.txt","r")==NULL){
		printf("Arquivo fonte.txt nao encontrado");
		exit(1);
	}
	else{
		arq=fopen("fonte.txt","r");
		while(!feof(arq)){
			fscanf (arq,"%d",&dado[0]);
			if (feof(arq))
				dado[1]=-2147483647;
			else
				fscanf (arq,"%d",&dado[1]);
			insere_inicio_lista(controle_lista,dado);
		}
	}
}

void printar (header *controle_lista){
	nodo * corrente;
	for (corrente=controle_lista->inicio;corrente!=NULL;corrente=corrente->prox){
		printf("%d\t",corrente->dado[0]);
		if(corrente->dado[1]==-2147483647)
			printf("--\n");
		else
			printf("%d\n",corrente->dado[1]);
	}
}