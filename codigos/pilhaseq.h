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

#define MAX 10

//*************** Implementação da área de dados do TAD ***************//


// Definição da estrutura pilha sequencial
typedef struct pilha {
	int elementos[ MAX ]; // vetor que vai armazenar os elementos da pilha
    int topo; // variável usada para controlar o topo da pilha
}TPilha;


//************** Interface de uso do TAD Pilha Sequencial **************//


/* Criar uma pilha vazia */
void criarPilha( TPilha* pilha );

/* Verificar se a pilha está vazia ou não */
int pilhaVazia( TPilha* pilha );

/* Verificar se a pilha está cheia */
int pilhaCheia( TPilha* pilha );

/* Consultar o elemento que está topo da pilha (sem retirá-lo) */
int elementoTopo( TPilha* pilha, int *dado );

/* Empilhar um elemento */
int empilhar( TPilha* pilha, int elemento );

/* Desempilhar um elemento */
int desempilhar( TPilha* pilha, int *dado );

/* Exibir todos os elementos da pilha */
void imprimir( TPilha* pilha );
