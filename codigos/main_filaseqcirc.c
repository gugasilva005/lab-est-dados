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

#include "filaseqcirc.h"
#include <stdio.h>

int main (void) {

	TFilaSeqCirc fila;
	
	// colocar a fila num estado inicial de "pronto"
	criarFila( &fila );

    if( filaVazia( &fila ) ) printf( "Esta vazia!" );
    
    // "povoar" a fila
	for( int i = 10; i < 50; i += 10 )
		enfileira( &fila, i ); 
    
    int retorno = 0;
	elementoFrente( &fila, &retorno ) ;
    printf( "\nElemento Frente: %d", retorno );
    imprimir( &fila );
 
	//retirar os elementos: 10, 20 e 30
	for( int i = 0; i < 3; i++ ){
		desenfileira( &fila, &retorno ); 
    	printf( "\nElemento removido: %d", retorno );
		elementoFrente( &fila, &retorno ) ;
    	printf( "\nElemento Frente: %d", retorno );
	}
    
    enfileira( &fila, 50 );
    imprimir( &fila );
   
    enfileira( &fila, 60 ); // uma inserção no modo "circular"
	elementoFrente( &fila, &retorno ) ;
	printf( "\nElemento Frente: %d", retorno );
	imprimir( &fila );
    
    enfileira( &fila, 70 ); // outra inserção no modo "circular"
	elementoFrente( &fila, &retorno ) ;
    printf( "\nElemento Frente: %d", retorno ); 
    imprimir( &fila );
    
    // imprimir o real estado do vetor
    // isso revelará a real posição de cada elemento no vetor
    printf( "\nVETOR:[" );
    for( int i = 0; i < MAX; i++ )
    	printf( "%d ", fila.elementos[ i ] );
    printf( "]\n" );
    
	return 0;
}
