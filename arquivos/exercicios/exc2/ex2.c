#include <stdio.h>
#include <string.h>

#define MAX 100

int main() 
{
    FILE *file;
    char fileName[MAX+5];     // +1 para o "\0" e +4 para o ".txt";
    int maiorNumero = 0;
    int valor = 0;

    scanf(" %99s", fileName); // %99s define limite de largura de apenas 100 caracteres (0 a 99)
    strcat(fileName, ".txt"); // concatena nomeDoArquio+.txt

    file = fopen(fileName, "r");

    if (file == NULL) 
    {
        return 0;             // termina o programa se o arquivo não foi aberto
    }

    valor = fscanf(file, " %d", &valor); // determina o primeiro elemento dentro do .txt como o maior valor inicial

    while (feof(file) == 0) {            // enquanto o arquivo não estiver no fim (ultimo byte), continua
        if (valor > maiorNumero) {
            maiorNumero = valor;
        }

        fscanf(file, " %d", &valor);
    }
    
    printf("Maior número: %d\n", maiorNumero);

    int fechado = fclose(file);

    if (fechado == 0) {
        printf("Arquivo foi fechado.\n");
    } else {
        printf("Arquivo não foi fechado.\n");
    }

    return 0;
}