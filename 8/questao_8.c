#include "questao_8.h"

void push (header *controle_pilha1, char dado){
	pilha *no=(pilha *) calloc (1,sizeof (pilha));
	no->dado=dado;
	no->prox=controle_pilha1->inicio;
	controle_pilha1->inicio=no;
	controle_pilha1->tamanho++;
}

int pop (header *controle_pilha1){
	pilha *elimina;
	int dado;
	if(controle_pilha1->inicio!=NULL)
	{
		dado=controle_pilha1->inicio->dado;
		elimina=controle_pilha1->inicio;
		controle_pilha1->inicio=controle_pilha1->inicio->prox;
		free(elimina);
		controle_pilha1->tamanho--;
		return dado;
	}
	else
		return 0;
}

int pop_all (header *controle_pilha1){
	pilha *elimina;

	while(controle_pilha1->inicio!=NULL && controle_pilha1->inicio->dado!='(')
	{

		printf("%c",controle_pilha1->inicio->dado);
		elimina=controle_pilha1->inicio;
		controle_pilha1->inicio=controle_pilha1->inicio->prox;
		free(elimina);
		controle_pilha1->tamanho--;
	}
	//if(controle_pilha1->inicio->dado=='(')
		//pop(controle_pilha1);
	return 0;
}

int prioridade(header *controle_pilha1, char dado)
{
	if(controle_pilha1->inicio==NULL)
		return (1);
	else
	{
		if (dado=='*')
			return (controle_pilha1->inicio->dado!='/');	
		else
		{
			if (dado=='/')
				return (controle_pilha1->inicio->dado!='*');	
			else
			{
				if(dado=='+')
					return (controle_pilha1->inicio->dado!='*' && controle_pilha1->inicio->dado!='/'&& controle_pilha1->inicio->dado!='-');
				else
				{
					if(dado=='-')
						return (controle_pilha1->inicio->dado!='*' && controle_pilha1->inicio->dado!='/'&& controle_pilha1->inicio->dado!='+');
					else
					{
						if(dado=='(')
							return (1);
						else
						{
							if(dado=='=')
							{
								if(controle_pilha1->inicio->dado!='*' 
								&& controle_pilha1->inicio->dado!='/'
								&& controle_pilha1->inicio->dado!='+' 
								&& controle_pilha1->inicio->dado!='-'
								&& controle_pilha1->inicio->dado!='(')
									return(1);
							}
							else 
								return 0;
						}
					}
				}
			}
		}
	}
	return 0;
}


void ler_arquivo(header *controle_pilha1){
	FILE *arq;
	char dado;
	if (fopen("fonte.txt","r")==NULL)
	{
		printf("Arquivo fonte.txt nao encontrado");
		exit(1);
	}
	else
	{
		arq=fopen("fonte.txt","r");
		while(!feof(arq))
		{
			fscanf (arq,"%c",&dado);
			if(dado!='\n' && dado!='\0' && dado!='\r'&& dado!=EOF)
			{
				if((dado!='*') && (dado!='/') && (dado!='+') && (dado!='-') && (dado!=')') && (dado!='(') && (dado!='='))
				{
					printf("%c", dado);
				}
				else
				{
					if(dado!=')')
					{		
						if (prioridade(controle_pilha1,dado))
						{
							push(controle_pilha1,dado);
						}
						else
						{ 
							while (prioridade(controle_pilha1,dado)==0 && controle_pilha1->inicio!=NULL)
							printf("%c", pop(controle_pilha1));
							//push(controle_pilha1,dado);
						}
					}
					else
					{
						while (controle_pilha1->inicio->dado!='(' && controle_pilha1->inicio!=NULL)
							printf("%c", pop(controle_pilha1));
						//pop_all(controle_pilha1);
					}
				}
			}
		}
	}
}
void printar (header *controle_pilha1){
	pilha * corrente;
	for (corrente=controle_pilha1->inicio;corrente!=NULL;corrente=corrente->prox){
		printf("%c",corrente->dado);
	}
}


int main()
{
	header *controle_pilha1=calloc(1,sizeof(header));
	ler_arquivo(controle_pilha1);
	while(controle_pilha1->inicio!=NULL)
	{
		if (controle_pilha1->inicio->dado!='(')
			printf("%c",pop(controle_pilha1));
		else
			pop(controle_pilha1);
	}
	pop(controle_pilha1);
	//printar(controle_pilha1);
return 0;
}