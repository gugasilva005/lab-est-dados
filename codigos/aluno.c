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

#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

//*************** Implementação da interface de uso do TAD ******************//

// função de suporte que verifica se o ponteiro possui de fato um endereço válido
int enderecoValido( TAluno *a );

// operacao que cria um Aluno (dinamicamente) mediante nome, idade e uma altura
TAluno* criarAluno (char nome[], int idade, float altura){
    TAluno *p = NULL;

    if( ( p = (TAluno*) malloc( sizeof(TAluno) ) ) == NULL ) return NULL;

    p->nome = nome;
    p->idade = idade;
    p->altura = altura;

    return p;
}

// operação que libera a memória alocada por um Aluno
void liberarAluno (TAluno* a){ if( a != NULL ) free( a ); }

// operacao que imprime todos os dados do Aluno (no console)
void exibirDados (TAluno* a){
    if( enderecoValido(a) ) {
        printf( "Nome: %s", a->nome );
        printf( "\nIdade: %d", a->idade );
        printf( "\nAltura %.2f", a->altura );
        printf( "\nMaior 18 anos: %s", maiorDezoito( a ) ? "Sim\n": "Nao\n"  );

    } else {
        printf( "Nao ha dados a serem impressos. O aluno nao existe" );
    }
} 

// operacao booleana que verifica se a idade do aluno é igual ou superior a 18 anos
int maiorDezoito (TAluno* a){
    if ( enderecoValido( a ) ) return a->idade >= 18 ? 1 : 0;
    return 0;
}

// suporte para verificar a existência de um endereço
int enderecoValido( TAluno *a ){ return a != NULL; }