#include  <math.h>
#include  <stdio.h>

int foo(int x)
{
    int y = x + 10;
    y++;
    return y;
}

int main  (void)
{
    double  x  =  sqrt  (9.0);
    double  y  =  pow  (2, 5);
    printf  ("A raiz quadrada de  9.0  é  %.2f\n",  x);
    printf  ("2 elevado a 5 é %.2f\n",  y);
    int  k = foo(5);
    int  j = k;
    j+= 1000;
    return  0;
}