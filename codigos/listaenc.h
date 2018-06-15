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


typedef struct nolista {
	int dado;              // campo que guarda a informação
    struct nolista *prox;  // guarda o endere�o para o próximo nó da lista
}no;


typedef no* TListaEnc; // como um ponteiro para um nó da lista será chamado


//*************** A interface de uso do TAD Lista Encadeada ***********//

/* Criar uma lista encadeada vazia */
void criarLista( TListaEnc *lista );

/* Verificar se a lista est� vazia ou n�o */
int listaVazia( TListaEnc lista );

/* Verificar a quantidade de elementos na lista */
int tamanhoLista( TListaEnc lista );

/* Buscar um elemento mediante sua posição dentro da lista */
int elementoNaPosicao( TListaEnc lista, int posicao, int* dado );

/* Buscar a posição de um elemento na lista */
int posicaoDoElemento( TListaEnc lista, int elemento );

/* Inserir um elemento na lista mediante sua posição */
int inserirElemento( TListaEnc* lista, int posicao, int elemento );

/* Remover um elemento da lista mediante sua posição */
int removerElemento( TListaEnc* lista, int posicao, int *dado );

/* Exibir todos os elementos da lista */
void imprimir ( TListaEnc lista ); 