#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct estrutura {
	TIPOCHAVE chave;
	struct estrutura* proximo; 
} NO;


typedef struct {
	NO* inicio;
	
} Lista;

void inicializarLista(Lista *l)
{
	l->inicio = NULL;
}


int adicionarElementoInicio(Lista *l, TIPOCHAVE Ch)
{
	NO* novo;
	novo = (NO*) malloc(sizeof(NO)); 
	novo->chave = Ch;
	novo->proximo = l->inicio;
	l->inicio = novo;
	return 1;
}

int adicionarElementoFim(Lista *l, TIPOCHAVE Ch)
{
	NO* aux = l->inicio;
	NO* novo;
	
	novo = (NO*) malloc(sizeof(NO)); 
	novo->chave = Ch;
	novo->proximo = NULL;
	
	if(l->inicio == NULL)
		l->inicio = novo;

	else 
	{
		while(aux->proximo != NULL)
		{
			aux = aux->proximo;
		}
		
		aux->proximo = novo;
	}
	
	return 1;
};

int removerElementoInicio(Lista *l)
{
	NO* aux = l->inicio;
	l->inicio = aux->proximo;
	free(aux); 
	return 1;
}


int removerElementoFim(Lista *l)
{
	NO* atual = l->inicio;
	NO* ant;
	
	while (atual->proximo != NULL)
	{
		ant = atual;
		atual = atual->proximo;
	}
	
	if(atual == l->inicio) // Se atual não for diferente do inicio, significa uma lista com um único elemento.  
	{
		l->inicio = atual->proximo;	// Inicio da lista (cabeça) volta a apontar pra NULL.
	}
	
	else {
		ant->proximo = NULL;
	}
	
	free(atual);
	return 1;
}

void exibirLista(Lista *l)
{
	NO* aux = l->inicio;
	
	while (aux != NULL)
	{
		printf("%d\n", aux->chave);
		aux = aux->proximo;
	}
}

int removerElemento(Lista *l, TIPOCHAVE Ch)
{
	NO* atual = l->inicio;
	NO* ant;
	
	while(atual->chave != Ch && atual->proximo != NULL)
	{
		ant = atual;
		atual = atual->proximo;
	}
	
	if(atual == l->inicio)
	{
		l->inicio = atual->proximo;
		free (atual);
	}
	
	else
	{
		ant->proximo = atual->proximo;
		free(atual);
	}
}


int main (){
	
	Lista l; 
	
	inicializarLista(&l);
	

	adicionarElementoInicio(&l, 21);
	adicionarElementoInicio(&l, 13);
	adicionarElementoInicio(&l, 10);
	adicionarElementoFim(&l, 34);
	adicionarElementoFim(&l, 32);
	adicionarElementoFim(&l, 127);
	
	exibirLista(&l);
	
	printf("\n \n \n");
	
	removerElementoInicio(&l);
	removerElementoFim(&l);
	
	exibirLista(&l);
	
	printf("\n \n \n");		

	removerElemento(&l, 21);
	exibirLista(&l);
	
	
	
	return 0;
}

