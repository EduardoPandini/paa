/* Arquivo EXEMPLO DE Aplicacao */
// MODIFIQUEM-o, CORRIJAM-o!
#include "main.h"

int main() {
    // Variáveis para pilhas de diferentes tipos
    pStack intStack = NULL;   // Pilha para inteiros
    pStack floatStack = NULL; // Pilha para floats
    pStack stringStack = NULL; // Pilha para strings

    int ret; // Variável para armazenar retornos das funções

    // **1. Trabalhando com inteiros**
    int intElements[] = {1,1,1,1,1,1,1,1,1,1,1,1,10, 20, 30, 40, 50};
    int intValue;
    int intSize = 5; // Tamanho fixo da pilha de inteiros

    // Inicializa a pilha para inteiros
    ret = stack(&intStack, intSize, sizeof(int));
    if (ret == FAIL) {
        printf("Erro ao inicializar a pilha de inteiros.\n");
        return 1;
    }

    // Empilha os inteiros
    for (int i = 0; i < sizeof(intElements)/sizeof(int); i++) {
        ret = push(intStack, &intElements[i]);
        if (ret == FAIL) {
            printf("Erro ao empilhar o inteiro %d.\n", intElements[i]);
        } else {
            printf("Empilhado (int): %d\n", intElements[i]);
        }
    }

    // Desempilha os inteiros
    printf("Desempilhando inteiros:\n");
    while (pop(intStack, &intValue) == SUCCESS) {
        printf("Desempilhado (int): %d\n", intValue);
    }

    // Libera a pilha de inteiros
    unstack(&intStack);

    // **2. Trabalhando com floats**
    float floatElements[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float floatValue;
    int floatSize = 5; // Tamanho fixo da pilha de floats

    // Inicializa a pilha para floats
    ret = stack(&floatStack, floatSize, sizeof(float));
    if (ret == FAIL) {
        printf("Erro ao inicializar a pilha de floats.\n");
        return 1;
    }

    // Empilha os floats
    for (int i = 0; i < sizeof(floatElements)/sizeof(float); i++) {
        ret = push(floatStack, &floatElements[i]);
        if (ret == FAIL) {
            printf("Erro ao empilhar o float %.2f.\n", floatElements[i]);
        } else {
            printf("Empilhado (float): %.2f\n", floatElements[i]);
        }
    }

    // Desempilha os floats
    printf("Desempilhando floats:\n");
    while (pop(floatStack, &floatValue) == SUCCESS) {
        printf("Desempilhado (float): %.2f\n", floatValue);
    }

    // Libera a pilha de floats
    unstack(&floatStack);

    // **3. Trabalhando com strings**
    char *stringElements[] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","casa", "carro", "moto", "bicicleta", "avião"};
    char *stringValue;
    int stringSize = 5; // Tamanho fixo da pilha de strings

    // Inicializa a pilha para strings
    ret = stack(&stringStack, stringSize, sizeof(char *));
    if (ret == FAIL) {
        printf("Erro ao inicializar a pilha de strings.\n");
        return 1;
    }

    // Empilha as strings
    for (int i = 0; i < sizeof(stringElements) / sizeof(char *); i++) {
        ret = push(stringStack, &stringElements[i]);
        if (ret == FAIL) {
            printf("Erro ao empilhar a string \"%s\".\n", stringElements[i]);
        } else {
            printf("Empilhado (string): \"%s\"\n", stringElements[i]);
        }
    }

    // Desempilha as strings
    printf("Desempilhando strings:\n");
    while (pop(stringStack, &stringValue) == SUCCESS) {
        printf("Desempilhado (string): \"%s\"\n", stringValue);
    }

    // Libera a pilha de strings
    unstack(&stringStack);

    return 0;
}
