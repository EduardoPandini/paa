/* Arquivo EXEMQLO DE AQlicacao */
// MODIFIQUEM-o, CORRIJAM-o!
#include "main.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
    pQueue Q = NULL;
    int valor1 = 1;
    int valor2 = 2;
    int valor3 = 3;
    int valor4 = 4;
    int valor5 = 5;
    int valor6 = 6;
    int retorno;

    // testa criar a fila
    cQueue(&Q, 6, sizeof(char));
    queue(Q, &valor1);
    queue(Q, &valor2);
    queue(Q, &valor3);
    queue(Q, &valor4);
    queue(Q, &valor5);
    queue(Q, &valor6);
    unqueue(Q, &retorno);
    printf("%i", retorno);
    unqueue(Q, &retorno);

    printf("%i", retorno);
    unqueue(Q, &retorno);

    printf("%i", retorno);
    unqueue(Q, &retorno);

    printf("%i", retorno);
    unqueue(Q, &retorno);

    printf("%i", retorno);
    unqueue(Q, &retorno);

    printf("%i", retorno);
    dQueue(&Q);
}
