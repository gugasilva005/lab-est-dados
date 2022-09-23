/* capturar_dados.c -- programa para obter dados básicos */
#include<stdio.h>
#include<ctype.h> // toupper()

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
/* protótipos de funções            */
/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
void limpar_buffer( void );

int main( void )
{
    char nome[ 41 ];
    char sexo;
    short int idade;
    float salario;

    /* capturar o nome */
    printf( "Por favor, digite seu nome:\n" );
    scanf( "%s", nome ); // note que não há &nome
    limpar_buffer();

    /* capturar o sexo (M ou F) */
    printf( "Agora, %s, digite seu sexo (M ou F):\n", nome );
    scanf( "%c", &sexo ); sexo = toupper( sexo );
    limpar_buffer();

    /* capturar a idade */
    printf( "Digite sua idade:\n" );
    scanf( "%hd", &idade );
    limpar_buffer();

    /* capturar o salário */
    printf( 
        "Finalmente, entre com o salário (e.g., 120.99):\n"
        "R$______\b\b\b\b\b\b"
    );
    scanf( "%f", &salario );
    limpar_buffer();

    /* exibir os dados */
    printf(
        "Os dados digitados foram:\n"
        "+++++++++++++++++++++++++\n"
        "Nome......:%s\n"
        "Sexo......:%c\n"
        "Idade.....:%hd\n"
        "Salário R$:%.2f\n" ,
        nome, sexo, idade, salario
    );

    return 0;
}

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
/* área de implementação de funções */
/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */

void limpar_buffer( void )
{
    int c;
    while( (c = getchar() ) != '\n' && c != EOF)
        /* discard */ 
    ;
}