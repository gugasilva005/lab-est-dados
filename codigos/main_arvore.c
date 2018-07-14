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

int main (void) {
	TArvoreBin a;

    inicializar( &a );

    if( arvoreVazia( a ) ) printf( "Arvore vazia!" );
   								
    // montando a seguinte arvore: < 1 < 2 <3> <4> > <5> >
    a = constroi( 1 );
    
    criarFilhoEsquerdo ( a, 2 );
    criarFilhoDireito  ( a, 5 );
    criarFilhoEsquerdo ( filhoEsq(a), 3 );
    criarFilhoDireito  ( filhoEsq(a), 4 );

    // pesquisando por um nó qualquer
    printf( "\n%s", pesquisaNodo( a, 4 ) ? "4 Existe!" : "4 Nao Existe!" );

    printf( "\nImprimindo a arvore (pre-ordem): "); 
    imprimir( a );
	
	return 0;
}