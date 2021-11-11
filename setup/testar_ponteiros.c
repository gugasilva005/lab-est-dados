#include <math.h>
#include <stdio.h>

int main(void)
{
    int idade = 56;
    //float f = 1.23F;
    //char c = 'A';
    int *p;     // declarando...
    p = &idade; // direcionar/apontar...

    *p = 88; // *p leia-se "o conteúdo de quem p olha (idade!)"
    printf("idade=%d\n", idade);

    /* aritmética de ponteiros e ponteiros para vetores */
    char nome[] = {'a', 'b', 'c', '\0'};
    char *p1 = "XYZ";
    printf(">%c\n", *(p1 + 2)); // p1[2]

    char *pnome = nome; // char* pnome = &nome[0] == a 
    printf(">%c\n", *(pnome + 2)); // pnome[2]
    while (*pnome) // leia-se o conteudo de quem pnome olha...
        putchar(*pnome++);

    printf("\n"); // flush buffer
    int codigos[] = {22, 33};
    int *pcodigos = &codigos[0];
    printf(">%d\n", *(pcodigos + 1)); // pcodigos[1]

    return 0;
}