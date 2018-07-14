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


// Definição da estrutura do nó da árvore binária
typedef struct noarvore {
      int dado;	 // campo de informação
      struct noarvore *esq; // ponteiro para o nó esquerdo
      struct noarvore *dir; // ponteiro para o nó direito
}no;

typedef no* TArvoreBin;


//************ A interface de uso do TAD árvore binária *********//

/* Inicializar uma árvore */
void inicializar( TArvoreBin * arv );

/* Verificar se a árvore está vazia ou não */
int arvoreVazia( TArvoreBin arv );

/* Constrói um nó na árvore */
no* constroi( int dado );

/* Criar um filho esquerdo na árvore */
int criarFilhoEsquerdo ( TArvoreBin arv, int dado );

/* Criar um filho direito na árvore */
int criarFilhoDireito( TArvoreBin arv, int dado );

/* Acessar um filho esquerdo na árvore */
no* filhoEsq( TArvoreBin arv );

/* Acessar um filho direito na árvore */
no* filhoDir( TArvoreBin arv );

/* Buscar um determinado nó na árvore */
int pesquisaNodo( TArvoreBin arv, int dado );

/* Imprimir todos os nós de uma árvore */
void imprimir( TArvoreBin arv );
