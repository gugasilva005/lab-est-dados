#include  <math.h>
#include  <stdio.h>

/* area dos prototipos de funcoes */ 
int foo( int a, int c );

int main  (void)
{
    double  x  =  sqrt  (9.0);
    double  y  =  pow  (2, 5);
    printf  ("A raiz quadrada de  9.0  é  %.2f\n",  x);
    printf  ("2 elevado a 5 é %.2f\n",  y);
    int  k = foo(5, 6);
    int  j = k;
    j+= 1000;
    return  0;
}

/* area do corpo da funcao */
int foo(int a, int c)
{
    int b= a + 10 + c;
    b++;
    return b;
}
