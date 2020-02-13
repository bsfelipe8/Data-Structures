#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "heap.cpp"

int main (){
	FilaPrioridade* fp;
	fp = cria_FilaPrioridade();

	 struct aeronave itens[6] = 
	 {	
	 	{"Boeing G31614", 4},
	 	{"Airbus AD9385", 6},
	 	{"Airbus A319CJ", 9},
	 	{"Boeing N2Z7",   5},
	 	{"Embraer G320123",8},
	 	{"Bombardier AR1229", 2}
	};
	 
	 
	printf("============= Ordem de Insercao =================\n\n");
	 
	int i;
    for (i=0; i< 6; i++){
        printf("%d) %d %s\n",i,itens[i].prioridade, itens[i].voo);
        insere_FilaPrioridade(fp, itens[i].voo,itens[i].prioridade);
    }

	printf("\n");

 	printf("===================== Heap ======================\n\n");

	imprimir_FilaPrioridade(fp);
	
	printf("\n");
	
	printf("==================== Remover ====================\n\n");
	
	remove_FilaPrioridade(fp);
	
	imprimir_FilaPrioridade(fp); 
	printf("\n");

	printf("==================== Remover ====================\n\n");
	
	remove_FilaPrioridade(fp);
	
	imprimir_FilaPrioridade(fp); 
	printf("\n\n\n");

	system("pause");
}
