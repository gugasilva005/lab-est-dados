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

//############## Implementação da área de dados do TAD ################//

// Definição da estrutura do nó da fila
typedef struct nofila {
	int dado;	// campo de informação
    struct nofila *prox; // ponteiro para o próximo nó
}no;

// Definição da estrutura "cabeça" da fila
typedef struct cabeca {
	no* inicio;	  // início da fila (nó frente)
    no* final; 	  // final da fila  (ultimo nó)
    int tamanho;  // guardará o tamanho atual da fila
}TFilaEncCab;


//############# A interface de uso do TAD Fila Encadeada Cabeça ##############//


/* Criar uma fila vazia */
void criarFila(TFilaEncCab *fila );

/* Verificar se a fila está vazia ou n�o */
int filaVazia(TFilaEncCab fila );

/* Verificar a quantidade de elementos da fila */
int tamanhoFila(TFilaEncCab fila);

/* Consultar o elemento que está na frente da fila (sem retirá-lo) */
int elementoFrente(TFilaEncCab fila, int *valor );

/* Enfileirar um elemento */
int enfileirar(TFilaEncCab *fila, int elemento );

/* Desenfileirar um elemento */
int desenfileirar(TFilaEncCab *fila, int *valor );

/* Exibir todos os elementos da fila */
void imprimir(TFilaEncCab fila);
