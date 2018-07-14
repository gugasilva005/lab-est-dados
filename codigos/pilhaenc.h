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

//*************** Implementação da área de dados do TAD ***************//


// Definição da estrutura pilha encadeada
typedef struct nopilha {
	int dado;	// campo que guarda a informacao
	struct nopilha *prox; // guarda o endereço para prox nó
}no;
typedef no* TPilhaEnc;

//************** Interface de uso do TAD Pilha Sequencial **************//


/* Criar uma pilha vazia */
void criarPilha( TPilhaEnc *pilha );

/* Verificar se a pilha está vazia ou não */
int pilhaVazia( TPilhaEnc pilha );

/* Tamanho da pilha */
int tamanhoPilha( TPilhaEnc pilha );

/* Empilhar um elemento */
int empilhar( TPilhaEnc *pilha, int dado );

/* Desempilhar um elemento */
int desempilhar( TPilhaEnc *pilha, int *dado );

/* Consultar o topo pilha */
int elementoTopo( TPilhaEnc pilha, int *dado );

/* Exibir todos os elementos da pilha */
int imprimir ( TPilhaEnc pilha );