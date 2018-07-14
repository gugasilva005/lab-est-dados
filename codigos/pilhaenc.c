/*****************************************************************************
 * Instituto Federal de Educação Ciência e Tecnologia da Paraíba			 
 * Campus Campina Grande													 
 * Curso Superior em Engenharia da Computação								 
 * Professor: Cesar Vasconcelos												 
 * 																			 
 * Copyright - Cesar Vasconcelos											 
 * Este marerial foi elaborado apenas para ser utilizado pelos alunos da 	 
 * disciplina Estruturas de Dados, do curso de Eng. da Computação do IFPB.	 
 * 																			 
 * Nenhuma parte deste material pode ser reproduzida ou transmitida			 
 * de qualquer modo ou por qualquer meio sem prévia autorização do 			 
 * autor e sem lhe ser dado o devido crédito.								 
 * **************************************************************************/

#include "pilhaenc.h"
#include <stdio.h>
#include <stdlib.h>

/* Criar uma pilha vazia */
void criarPilha( TPilhaEnc *pilha )
{
	*pilha = NULL;
}

/* Verificar se a pilha está vazia ou não */
int pilhaVazia( TPilhaEnc pilha )
{
	return pilha == NULL;
}

/* Tamanho da pilha */
int tamanhoPilha( TPilhaEnc pilha )
{
	int tamanho = 0;
	while( pilha != NULL ) {
		pilha = pilha->prox;
		tamanho++;
	}
	return tamanho;
}

/* Empilhar um elemento */
int empilhar( TPilhaEnc *pilha, int dado )
{
	TPilhaEnc novo;

	// aloca o no e testa pra ver se o SO alocou mesmo
	if( (novo = (no*) malloc(sizeof(no))) == NULL ) return 0;

	novo->dado = dado;
	novo->prox = *pilha;
	*pilha = novo;
	return 1;
}

/* Desempilhar um elemento */
int desempilhar( TPilhaEnc *pilha, int *dado )
{
	// se pilha está vazia
   	if ( pilhaVazia( *pilha ) ) return 0;

	TPilhaEnc aux;

	aux = *pilha;
	*dado = aux->dado;
	*pilha = (*pilha)->prox;
	
	// libera memória do nó desempilhado
	free( aux );

    return 1;
}


/* Consultar o topo pilha */
int elementoTopo( TPilhaEnc pilha, int *dado )
{
	if( pilhaVazia( pilha ) ) return 0;

	*dado = pilha->dado; // já que topo é igual ao primeiro no
	return 1;
}

/* Exibir todos os elementos da pilha */
int imprimir ( TPilhaEnc pilha )
{
	// se pilha está vazia
   	if ( pilhaVazia( pilha ) ) return 0;

    printf("\n Pilha=[ ");

	// varrendo todos os elementos
	while( !pilhaVazia(pilha) ){
		printf("%d ", pilha->dado);
		pilha = pilha->prox;
	}

    printf("]");
     return 1;
}