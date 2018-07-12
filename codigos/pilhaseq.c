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


#include "pilhaseq.h"
#include <stdio.h>

//****** Implementação da Interface de uso do TAD Pilha Sequencial *****//


/* Criar uma pilha sequencial vazia
 * Parâmetros: o ponteiro para o TAD (a struct será passada por referência )
 */
void criarPilha( TPilha* pilha ){ pilha->topo = -1; }

/* Verificar se a pilha sequencial está vazia ou n�o
 * Parâmetros: o ponteiro para o TAD (a struct será passada por referência )
 */
int pilhaVazia( TPilha* pilha ){ return pilha->topo == -1; }

/* Verificar se a pilha sequencial está cheia ou n�o
 * Parâmetros: o ponteiro para o TAD (a struct será passada por referência )
 */
int pilhaCheia( TPilha* pilha ){ return pilha->topo + 1 == MAX; }

/* Consultar o elemento que está no topo da pilha (sem retirá-lo)
 * Parâmetros: o ponteiro para o TAD (a struct será passada por referência )
 *			   e outro ponteiro que irá guardar o elem. "retornado"
 * Retorno: 1 em caso de sucesso ou 0, caso contrário
 */
int elementoTopo( TPilha* pilha, int *dado ){
	// se pilha está vazia
    if ( pilhaVazia( pilha ) ) return 0;
	*dado = pilha->elementos[ pilha->topo ];
    return 1;
}

/* Empilhar um novo elemento
 * Parâmetros: o ponteiro para o TAD (a struct será passada por referência )
 *			   e o elemento desejado.
 * Retorno: 1 em caso de sucesso ou 0, caso contrário
 */
int empilhar( TPilha* pilha, int elemento ){
	// a pilha está cheia?
    if ( pilhaCheia( pilha ) ) return 0;

	pilha->elementos[ ++pilha->topo ] = elemento;
    return 1;
}

/* Desempilhar o elemento que está no topo da pilha
 * Parâmetros: o ponteiro para o TAD (a struct será passada por referência )
 *			   e outro ponteiro para uma variável inteira
 *			   que deverá armazenar uma cópia do elemento retirado
 * Retorno: 0 em caso de fracasso ou 1 em caso de sucesso
 */
int desempilhar( TPilha* pilha, int *dado ){
	// a pilha está vazia?
    if ( pilhaVazia( pilha ) ) return 0;

	*dado = pilha->elementos[ pilha->topo-- ];
    return 1;
}

/* Exibir todos os elementos (da base até o topo)
 * O elemento que estiver no topo será marcado na impressão com um '*'
 * Parâmetros: o ponteiro para o TAD (a struct será passada por referência )
 */
void imprimir( TPilha* pilha ){

	printf("\nPilha=[ " );

	// varrendo todos os elementos
    for ( int i = 0; i <= pilha->topo ; i++ ) {
    	if( i == pilha->topo  )	printf( "*%d", pilha->elementos[ i ] );
        else printf( "%d, ", pilha->elementos[ i ] );
	}
   	printf(" ]");
}

