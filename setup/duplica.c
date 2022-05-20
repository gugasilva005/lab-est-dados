#include  <stdlib.h>
#include  <string.h>
#include  <stdio.h>

/* area dos prototipos de funcoes */ 
char* duplica( char* string_original );

int main  (void)
{
    char nome[ 41 ];

    printf( "Digite uma frase: " );
    scanf(" %40[^\n]s" , nome );

    char* ponteiro = duplica( nome );
    printf( "%s", ponteiro );
    
    free( ponteiro );
    return  0;
}

/* area do corpo da funcao */
char* duplica( char* string_original )
{
    if( string_original == NULL || 
        strlen( string_original ) == 0 )
            return NULL;

    const int tamanho = strlen( string_original);
    char* string_clone = (char*) malloc( 1 + ( tamanho * sizeof(char) ) );

    if( string_clone == NULL ) return NULL;

    strcpy( string_clone, string_original );
    
    return string_clone;
}
