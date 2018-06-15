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

#include "listaenc.h"
#include <malloc.h>

//----------------------------------------------------------------------

// funções auxiliares que apenas fatoram código comum as sub-rotinas...
TListaEnc aloca();

//----------------------------------------------------------------------


//*************** Implementação do TAD Lista Encadeada ***************//


/* Criar uma lista encadeada vazia
 * Parâmetros: o ponteiro que representa "a cabeça" da lista (por referência)
 */
void criarLista( TListaEnc *lista ){ *lista = NULL; }


/* Verificar se a lista está vazia ou não
 * Parâmetros: o ponteiro que representa "a cabeça" da lista (por valor)
 */
int listaVazia( TListaEnc lista ){ return lista == NULL; }


/* Verificar a quantidade de elementos na lista encadeada
 * Parâmetros: o ponteiro que representa "a cabeça" da lista (por valor)
 */
int tamanhoLista( TListaEnc lista ){
	int tamanho = 0;
    while( lista != NULL ) {
    	lista = lista->prox;
        tamanho++;
    }
    return tamanho;
}


/* Obter a posição de um elemento na lista encadeada
 * Parâmetros: lista = a lista encadeada
 *             elemento = o dado a ser pesquisado na lista
 * Retorno: a posição do elemento em caso de sucesso ou 0, caso contrário
 */
int posicaoDoElemento( TListaEnc lista, int elemento ){
    int posicao = 1;

	// lista vazia?
   	if ( listaVazia( lista ) ) return 0;

    while ( lista != NULL ) {
	    // testa se o elemento é igual ao dado do nó
   		if ( elemento == lista->dado ) return posicao;
	    
    	lista = lista->prox;
        posicao++;
    }
    return 0;
}


/*  Buscar um elemento mediante sua posição na lista
 *  Parâmetros: lista = a lista encadeada
 *              posicao = posição na qual se deseja buscar o elemento
 *              dado = passagem por referência "retornando" o elem. desejado
 *  Retorno: 1  em caso de sucesso ou 0 no caso de posição inválida
 */
int elementoNaPosicao( TListaEnc lista, int posicao, int* dado ){
	int posicaoAtual = 1;
    
    // se lista está vazia ou posição inválida
    if ( listaVazia( lista ) || posicao <= 0 ||
					posicao > tamanhoLista( lista ) ) return 0;

    while ( ( lista != NULL ) && ( posicaoAtual < posicao ) ){
    	lista = lista->prox;
        posicaoAtual++;
    }
    *dado = lista->dado;
   	return 1;
}


/* Inserir um elemento na lista mediante uma posição
 * Parâmetros: lista = a lista encadeada
 *             elemento = o dado a ser inserido
 *             posicao = posição na qual se deseja inserir o elemento
 * Retorno: 1 em caso de sucesso ou 0 caso contrário
 */
int inserirElemento( TListaEnc* lista, int posicao, int elemento ){
	TListaEnc novo = NULL, aux = NULL;
    int contador = 1;

    // inserção em uma lista que está vazia
    if( listaVazia( *lista ) ) {
    	// se a lista está vazia, so podemos inserir na posição 1, certo?
       	if( posicao != 1 ) return 0;

        // alocar o nó e testá-lo pra ver se tudo correu bem
        if( ( novo = aloca() ) == NULL ) return 0;

        novo->dado = elemento;
        novo->prox = NULL;
        *lista = novo;
        return 1;
    }

    // inserção na primeira posição de uma lista não vazia
    if( posicao == 1 ){
    	// alocar o nó e testá-lo pra ver se tudo correu bem
        if( ( novo = aloca() ) == NULL ) return 0;

        novo->dado = elemento;
        novo->prox = *lista;

        // faz cabeça da lista apontar para o "novo primeiro" da lista
        *lista = novo;
        return 1;
   	}

    // inserção após a primeira posição e em lista não-vazia
    aux = *lista;

    while( ( contador < posicao -1 ) && ( aux != NULL ) ) {
    	aux = aux->prox;
        contador++;
    }

    // se a posição foi maior que o tamanho da lista...
    if( aux == NULL ) return 0;

    // alocar o nó e testá-lo pra ver se tudo correu bem
    if( ( novo = aloca() ) == NULL ) return 0;

   	novo->dado = elemento;
    novo->prox = aux->prox;
    aux->prox = novo;
    
    return 1;
}


/* Remover um elemento da lista dada sua posição
 * Parâmetros: lista = a lista encadeada
 * 			   dado = passagem por referência retornando o elem. removido
 *             posicao = posição na qual se deseja remover o elemento
 * Retorno: 1 em caso de sucesso ou 0 caso contrário
 */
int removerElemento( TListaEnc* lista, int posicao, int *dado ){
	TListaEnc aux = NULL;
    TListaEnc anterior = NULL;
    int contador = 1;

    if ( listaVazia( *lista ) ) return 0;

    // faz aux apontar para o primeiro elemento
    aux = *lista;

    // testar se posição - 1, pois quero que "anterior" pare "uma casa antes"
    // da posição real desejada para remoção e, ainda, aux parar exatamente
    // em cima do nó a ser removido
    while( ( contador <= posicao - 1 ) && ( aux != NULL ) ){
    	anterior = aux;
        aux = aux->prox;
        contador++;
    }

    // se a posição foi maior que o esperado...
    if ( aux == NULL ) return 0;

    // ent�o a posição não é inválida (ou seja, posso obter o dado!)
    *dado = aux->dado;

    // se era o primeiro nó da lista...
    if( posicao == 1 ) *lista = aux->prox;
    else anterior->prox = aux->prox;

    // lembre-se de que, neste TAD, "remover" implica em desalocar memoria, tá?
    free( aux );
    return 1;
}


/* Exibir todos os elementos da lista
 * Parâmetros: lista = a lista encadeada
 */
void imprimir ( TListaEnc lista ) {
	printf( "\nLista: ( ");

	for( ;!listaVazia( lista ); lista = lista->prox )
	    printf("%d ", lista->dado );

	printf( ")" );
}


// alocar um novo nó na memória do computador
// função utilitária usada apenas para fatorar código comum às sub-rotinas
TListaEnc aloca(){ return (no*) malloc( sizeof( no ) ); }