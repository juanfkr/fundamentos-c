#include <stdio.h>

int contaDigitosIterativo(int n);
int contaDigitosRecursivo(int n);

int main()
{
    int n = 123;

    printf("O número %d tem %d dígitos.\n", n, contaDigitosIterativo(n));

    return 0;
}

int contaDigitosIterativo(int n)
{
    int contador = 0;

    while (n > 10)
    {
        contador++;
        n = n/10;
    }
}

// conta quantos dígitos tem em um número
int contaDigitos(int n)
{
    if (n < 10) return 1;

    return 1 + contaDigitos(n/10);
}

