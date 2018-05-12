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

//*********************** A utilização do TAD Aluno  ***********************//

#include "aluno.h"
#include <stdio.h>

int main(void){
	char nome[41];
	int idade;
	float altura;
  
	printf( "Digite um nome para o aluno: " ); scanf("%40[^\n]", nome );
	printf( "Digite uma idade para o aluno: " ); scanf("%d", &idade );
	printf( "Digite uma altura para o aluno: " ); scanf("%f", &altura );

	TAluno * aluno = criarAluno( nome, idade, altura );
	
	if ( aluno != NULL ) exibirDados( aluno );
 	
	liberarAluno( aluno );
	return 0;
}