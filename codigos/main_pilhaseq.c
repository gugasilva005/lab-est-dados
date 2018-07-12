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

int main (void) {
	
	// cria uma pilha sequencial diretamente na memória
	TPilha pilha;

    // coloca a pilha num estado válido (e consistente)
    criarPilha( &pilha );

    if( pilhaVazia( &pilha ) ) printf( "Esta vazia!" );

	// empilhando elementos
	empilhar( &pilha, 10 );
    empilhar( &pilha, 20 );
    empilhar( &pilha, 30 );
	
	// consultando o topo da pilha
	int topo; 
	elementoTopo( &pilha, &topo );
    printf( "\nElemento topo: %d", topo  );

    imprimir( &pilha );

	// retirando elementos
	desempilhar( &pilha, &topo );
    printf( "\n\nElemento desempilhado: %d", topo );

    imprimir( &pilha );

    desempilhar( &pilha, &topo );
    printf( "\nElemento desempilhado: %d", topo );
	
    desempilhar( &pilha, &topo );
	printf( "\nElemento desempilhado: %d", topo );

    // e se quem utiliza a biblioteca comete equívocos?
    printf( "\n%s", desempilhar( &pilha, &topo ) ?
	                "Sucesso" : "Erro na retirada!" );

	imprimir( &pilha );
	return 0;
}
