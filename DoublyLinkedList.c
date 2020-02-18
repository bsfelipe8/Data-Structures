#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct estrutura {
	struct estrutura* anterior; 
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
	novo->anterior = NULL;
	novo->proximo = l->inicio;
	
	if(l->inicio != NULL)
		l->inicio->anterior = novo;
	
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
	{
		novo->anterior = NULL;
		l->inicio = novo;
		
	}
		
	else 
	{
		while(aux->proximo != NULL)
		{
			aux = aux->proximo;
		}
		
		aux->proximo = novo;
		novo->anterior = aux;
	}
	
	return 1;
};

int removerElementoInicio(Lista *l)
{

	if(l->inicio == NULL) //LISTA VAZIA
		return 0;
	
	NO* aux = l->inicio;
	l->inicio = aux->proximo;
	
	
	
	if(aux->proximo != NULL) //MAIS DE UM ELEMENTO DE NA LISTA
	{
		aux->proximo->anterior = NULL;
	}
	
	
	free(aux); 
	return 1;
}


int removerElementoFim(Lista *l)
{
	if(l->inicio == NULL) //LISTA VAZIA
		return 0;
	
	NO* atual = l->inicio;	
	
	while (atual->proximo != NULL)
	{
		atual = atual->proximo;
	}
	
	if(atual->anterior == NULL) // Trata caso de uma lista com um único elemento.  
	{
		l->inicio = atual->proximo;	// Inicio da lista (cabeça) volta a apontar pra NULL.
	}
	
	else {
		atual->anterior->proximo = NULL;
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
	if(l->inicio == NULL) //LISTA VAZIA
		return 0;
	
	NO* atual = l->inicio;

	
	while(atual->chave != Ch && atual->proximo != NULL)
	{
		atual = atual->proximo;
	}
	
	if(atual == l->inicio)
	{
		l->inicio = atual->proximo;
		l->inicio->anterior = NULL;
		free (atual);
	}
	
	else
	{
		
		
		atual->anterior->proximo = atual->proximo;
		
		if(atual->proximo != NULL)
			atual->proximo->anterior = atual->anterior;
		
		free(atual);
	}
	
	return 1;
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

