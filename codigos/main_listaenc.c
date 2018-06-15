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
#include <stdio.h>

int main (void) {
	TListaEnc lista;

    criarLista( &lista );

    if( listaVazia( lista ) ) printf( "Esta vazia!" );

    inserirElemento( &lista, 1, 10 );
    inserirElemento( &lista, 2, 20 );
    inserirElemento( &lista, 3, 30 );

    printf( "\nQtd elementos na memoria: %d", tamanhoLista( lista ) );

    imprimir( lista );

    // e se quem utiliza a biblioteca comete equívocos?
    printf( "\n%s", inserirElemento( &lista, 5000, 40 ) ? 
	                "Sucesso" : "Erro na insercao!" );

    int retirado = 0;
	removerElemento( &lista, 2, &retirado );
    printf( "\nFoi retirado o: %d", retirado );
    printf( "\nQtd elementos na memoria: %d", tamanhoLista( lista ) );

    imprimir( lista );
    
    removerElemento( &lista, 2, &retirado );
    printf( "\nQtd elementos na memoria: %d", tamanhoLista( lista ) ); 
	imprimir( lista );  

	removerElemento( &lista, 1, &retirado );
    printf( "\nQtd elementos na memoria: %d", tamanhoLista( lista ) );
	imprimir( lista );  

	return 0;
}