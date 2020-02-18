#include <stdio.h>
#include <stdlib.h>

struct arv {
	int info;
	struct arv* esquerda;
	struct arv* direita;
};


typedef struct arv Arv;

Arv* arv_criavazia()
{
	return NULL;
}

Arv* arv_cria(int c, Arv* sae, Arv* sad){

	Arv* no = (Arv*) malloc(sizeof(Arv));
	no->info = c;
	no->esquerda = sae;
	no->direita = sad;
	return no;
}



int arv_vazia(Arv* p)
{
	return p == NULL;
}


void arv_imprime(Arv* p)
{
	if (!arv_vazia(p))
	{
		
		printf("%d ", p->info);
		arv_imprime (p->esquerda);
		arv_imprime (p->direita);		

	}
}

int arv_insere (Arv* raiz, int valor)
{
	if (raiz == NULL) return 0;
	
	Arv* no = (Arv*) malloc (sizeof(Arv));
	no->info = valor; 
	no->direita = NULL;
	no->esquerda = NULL;
	
	Arv* atual = raiz;
	Arv* anterior; 
	
	while (atual != NULL)
	{
		anterior = atual; 
		
		if(valor == atual->info)
			return 0; //não se deve inserir elementos de mesmo valor nesta árvore binária
		
		if (valor > atual->info)
			atual = atual->direita;
			
		else 
			atual = atual->esquerda;
		
	}
	
	if( valor > anterior->info)
		anterior->direita = no;
	
	else 
		anterior->esquerda = no;
	
	return 1;	
}


int retorna_pai (Arv* raiz, int elemento)
{
	if(raiz == NULL) return 0;
	
	Arv* atual = raiz;
	Arv* anterior; 

	
	while (atual != NULL && atual->info != elemento)
	{
	 	anterior = atual; 
	
		if(elemento > atual->info)
			atual = atual->direita;
		else 
			atual = atual->esquerda;		
	}
	
	if (atual->info == elemento)
	{
		return anterior->info;
	}
	else{
		return NULL; //Árvore percorrida até o final, elemento não encontrado;
	}
}

int main (){
	
	Arv* a = arv_cria(9, arv_criavazia(), arv_criavazia());
	arv_insere(a, 12);
	arv_insere(a, 7);
	arv_insere(a, 17);
	arv_insere(a, 8);
	arv_insere(a, 2);

	int x = retorna_pai(a, 12);
	
	printf("%d ", x);
}
