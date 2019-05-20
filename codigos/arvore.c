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


#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------------------

// função auxiliar que fator código comum às demais sub-rotinas...
no* aloca();

//----------------------------------------------------------------------


//*************** Implementação do TAD Arvore Binária ***********//


/* Inicializar uma árvore binária colocando-a num estado valido */
void inicializar( TArvoreBin * arv ){ *arv = NULL; }

/* Verificar se uma árvore binária está ou não vazia
 * parâmetro: um ponteiro representando "a raiz" */
int arvoreVazia( TArvoreBin arv ){	return arv == NULL; }

/* Construir um novo nó para a árvore binária.
 * Parâmetros: um número representando o campo de informação do nó 
 * Retorno: o endereço do nó recém-criado */
no* constroi( int dado ){
	no* novo;
	 
	if ( ( novo = aloca() ) == NULL ) return NULL;
	novo->dado = dado;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;
}

/* Criar um filho esquerdo na árvore mediante um "nó-pai"
 * parâmetro: um apontador para o nó-pai e um número representando
 * o campo de informação do nó.
 * Retorno: 1 em caso de sucesso ou 0, caso contrário.
 * Note que a sub-rotina deve verificar ainda se o "nó-pai" não está nulo
 * ou se já tem um filho esquerdo. Caso não tenha um filho esquerdo,
 * será construído um novo nó a partir do "nó-pai" passado como parâmetro */
int criarFilhoEsquerdo( TArvoreBin arv, int dado ) {
	no* novo;
	
	// nó-pai nulo?
   	if ( arv == NULL ) return 0;

	// já possui um filho esquerdo?
	if ( arv->esq != NULL ) return 0;
 	
	if ( ( novo = constroi( dado ) ) == NULL ) return 0;
	arv->esq = novo;
    return 1;
}

/* Criar um filho direito na árvore mediante um "nó-pai"
 * parâmetro: um apontador para o nó-pai e um número representando
 * o campo de informação do nó.
 * Retorno: 1 em caso de sucesso ou 0, caso contrário.
 * Note que a sub-rotina deve verificar ainda se o "nó-pai" não está nulo
 * ou se já tem um filho direito. Caso não tenha um filho direito,
 * será construído um novo nó a partir do "nó-pai" passado com parâmetro */
int criarFilhoDireito( TArvoreBin arv, int dado ) {
	no* novo;
	
	// nó-pai nulo?
   	if ( arv == NULL ) return 0;

	// já possui um filho esquerdo?
	if ( arv->dir != NULL ) return 0;
 	
	if ( ( novo = constroi( dado ) ) == NULL ) return 0;
	arv->dir = novo;
    return 1;
}

/* Acessar um filho esquerdo na árvore mediante um "nó-pai".
 * parâmetro: um apontador para o nó-pai.
 * Retorno: um apontador para o filho esquerdo. */
no* filhoEsq( TArvoreBin arv ){	return arv->esq; }

/* Acessar um filho direito na árvore mediante um "nó-pai".
 * parâmetro: um apontador para o nó-pai.
 * Retorno: um apontador para o filho direito */
no* filhoDir( TArvoreBin arv ){	return arv->dir; }

/* Buscar um determinado nó na árvore.
 * parâmetro: um apontador para a raiz e um dado a ser buscado
 * Retorno: 1 em caso de sucesso ou 0, se não encontrá-lo */ 
int pesquisaNodo( TArvoreBin arv, int dado ) {
	if ( arvoreVazia( arv ) ) return 0;
	
	if ( dado == arv->dado ) // estava na raiz?
		return 1; 
	else if ( pesquisaNodo ( filhoEsq(arv), dado ) )
		return 1;
	else 
		return pesquisaNodo ( filhoDir(arv), dado );
}

/* Imprimir todos os nós de uma árvore. 
 * Aqui, será utilizado o percurso pré-ordem.
 * parâmetro: um apontador para a raiz da árvore  */
void imprimir( TArvoreBin arv ){
	if ( !arvoreVazia(arv) ) {
		printf( "%d\t", arv->dado ); // a raiz corrente
		imprimir( filhoEsq(arv) );
		imprimir( filhoDir(arv) );
	}
}

// alocar um novo nó na memória do computador
// função auxiliar usada para fatorar código comum
no* aloca( void ){  return ( (no*) malloc( sizeof(no) ) ); }
