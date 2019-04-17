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

// número máximo de nós na fila
#define MAX 5

//*************** Implementação da área de dados do TAD **************//

// Definição da estrutura Fila Seq. Circular

typedef struct filacircular {
	int elementos[ MAX ]; // vetor que vai armazenar os elementos
	int frente; // variável usada para controlar o início da fila
    int final; // variável usada para controlar o final da fila
    int tam;  // número de elementos na fila
}TFilaSeqCirc;


//************ A interface de uso do TAD Fila Seq. Circular **********//

/* Criar uma fila sequencial circular vazia */
void criarFila( TFilaSeqCirc* fila );

/* Verificar se a fila circular está vazia */
int filaVazia( TFilaSeqCirc* fila );

/* Verificar se a fila circular está cheia */
int filaCheia( TFilaSeqCirc* fila );

/* Consultar o elemento que está na frente da fila circular */
int elementoFrente( TFilaSeqCirc* fila, int* valor );

/* Inserir (enfileirar) um elemento na fila circular */
int enfileira( TFilaSeqCirc* fila, int elemento );

/* Retirar (desenfileirar) um elemento da fila circular */
int desenfileira ( TFilaSeqCirc* fila, int* valor );

/* Imprimir o conteúdo da fila circular */
void imprimir( TFilaSeqCirc* fila );
