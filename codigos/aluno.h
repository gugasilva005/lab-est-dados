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

//******************** Implementação da área de dados do TAD ****************//
typedef struct aluno {
	char* nome;
	int idade;
    float altura;
}TAluno;

//******************** A interface de uso do TAD Aluno ***********************//

// operacao que cria um Aluno (dinamicamente) mediante nome, idade e uma altura
TAluno* criarAluno (char nome[], int idade, float altura);

// operacao que libera a memoria alocada por um Aluno
void liberarAluno (TAluno* a);

// operacao que imprime todos os dados do Aluno (no console)
void exibirDados (TAluno* a); 

// operacao booleana que verifica se a idade do aluno >= 18 anos
int maiorDezoito (TAluno* a); 