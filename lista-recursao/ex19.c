#include <stdio.h>

int euclides(int a, int b);

int main()
{
    int a = 150, b = 20;
    printf("O mdc de %d e %d é %d", a, b, euclides(a, b));

    return 0;
}

int euclides(int a, int b)
{
    if ((a%b) == 0) return b;

    return euclides(b, a%b);
}