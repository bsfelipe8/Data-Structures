#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

// Defini��o do TIPOCHAVE

struct aeronave{
	char voo [30];
	int prioridade; 
};

// Defini��o da estrutura de uma fila de prioridade

struct fila_prioridade {
	int quantidade;
 	struct aeronave dados[MAX];
};


FilaPrioridade* cria_FilaPrioridade(){
    
	FilaPrioridade *fp; // Declara um ponteiro do tipo FilaPrioridade;
   
    fp = (FilaPrioridade*) malloc(sizeof(struct fila_prioridade)); // Aloca��o din�mica
    fp->quantidade = 0; // Ao criar uma fila nenhum valor do array foi preenchido, portanto a posi��o zero � primeira posi��o vaga no array
    
	return fp;
}

int tamanho_FilaPrioridade(FilaPrioridade* fp){
	
	return fp->quantidade;
}

int verCheia_FilaPrioridade(FilaPrioridade* fp)
{
	return fp->quantidade == MAX;
}

int verVazia_FilaPrioridade(FilaPrioridade* fp)
{
	return fp->quantidade == 0;
}

void libera_FilaPrioridade(FilaPrioridade *fp){
    free(fp);
}



/* 
	Inserir um elemento na �rvore heap consiste em dois passos:  
	1 - inserir o elemento na primeira posi��o vaga do array: demarcado por fila_prioridade->quantidade 
	2 - promover o elemento para sua posi��o heap de acordo com sua prioridade: fun��o promoverElemento()  
*/



void promoverElemento(FilaPrioridade* fp, int filho){
	
	int pai;
	struct aeronave varTemp; //Declara��o de vari�vel tempor�ria
	
	pai = (filho - 1)/2 ; // Dado a posi��o de um elemento, � calculada a posi��o de seu 'pai' no array
	
	//� importante lembrar que essa f�rmula trata de divis�o inteira, sem contabilizar restos. 
	
	while ((filho > 0) && (fp->dados[pai].prioridade <= fp->dados[filho].prioridade))
	{
		
		//Realiza troca de posi��es entre 'pai' e 'filho' 
		
		varTemp = fp->dados[filho]; 
		fp->dados[filho] = fp->dados[pai];
		fp->dados[pai] = varTemp;
		
		
		filho = pai; // o valor da posi��o que era do 'pai' passa a ser do 'filho'
		pai = (pai - 1)/2 ; // Calcula a posi��o do novo 'pai'
		
	}
	

};


int insere_FilaPrioridade(FilaPrioridade* fp, char* voo, int prioridade)
{
	
	if (fp->quantidade == MAX) // Verifica se a fila est� cheia, se estiver, retorna 0;
		return 0;

	// Copia os valores dos par�metros para forma��o de um novo n� inserido na primeira posi��o vaga do array demarcado por: fila_prioridade->quantidade;        
	
	strcpy(fp->dados[fp->quantidade].voo, voo ); 
	fp->dados[fp->quantidade].prioridade = prioridade; 

	promoverElemento(fp, fp->quantidade); // Chamada da fun��o respons�vel por levar o elemento inserido para sua posi��o heap

	fp->quantidade++; // Atualiza  a pr�xima posi��o vaga da fila de prioridade 
	return 1;	
}


/* 
	Remover um elemento na �rvore heap consiste em 3 etapas:
	1 - Remover o elemento que est� no topo da heap, ou seja, inicio do array
	2- Copiar o elemento do final para o inicio do array
	3 - levar o elemento que foi colocado no topo da heap para sua respectiva posi��o de acordo com a sua prioridade	
*/


void rebaixarElemento (FilaPrioridade* fp, int pai){
	
	struct aeronave varTemp; 
	int filho;
	
	filho = 2 * pai + 1; // passado por par�metro a posi��o de um 'pai' � calculada a posi��o de um 'filho' no array 
	
	while (filho < fp->quantidade ) // Verifica se a posi��o do 'filho' � menor do que a �ltima posi��o do array
	{
		if (filho < fp->quantidade-1) //Verifica se 'pai' tem dois filhos. Ou seja, satisfesta esta condicional, significa dizer que 'filho' possui um 'irm�o'. 
			if (fp->dados[filho].prioridade < fp->dados[filho + 1].prioridade) //A partir da compara��o encontra o 'filho' de maior prioridade
				filho++;
		
		if (fp->dados[pai].prioridade >= fp->dados[filho].prioridade) //Se o 'pai' possui prioridade maior ou igual a do 'filho', n�o � necess�rio continuar movendo o elemento que anteriormente foi colocado no topo da heap.
			break; //Termina o processo
		 
		 
		//Realiza troca de posi��es entre 'filho' e 'pai'
		 
		 varTemp = fp->dados[pai];
		 fp->dados[pai] = fp->dados[filho];
		 fp->dados[filho] = varTemp;
		 
		 
		 pai = filho;
		 
		 filho = 2 * pai + 1; 		 
	}
	
}

int remove_FilaPrioridade(FilaPrioridade* fp){
	
	fp->quantidade--;
	fp->dados[0] = fp->dados[fp->quantidade]; // elemento da �ltima posi��o do array � colocado no topo da heap	
	
	rebaixarElemento(fp, 0); 
	return 1;
}

void imprimir_FilaPrioridade(FilaPrioridade* fp)
{
	int i;
	
	for(i=0; i <fp->quantidade; i++)
	{
		printf("Prioridade:(%d)  \t Voo:(%s) \n", fp->dados[i].prioridade, fp->dados[i].voo);
	}
}



