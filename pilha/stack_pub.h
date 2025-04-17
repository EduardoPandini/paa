#ifndef STACK_PUB_H
#define STACK_PUB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar memcpy

// Definições de retorno
#define SUCCESS 0
#define FAIL 1

// Estrutura de ponteiros para a pilha
typedef struct PE *pStack, **ppStack;

// Funções públicas da pilha

// Inicializa a pilha com o tamanho máximo e tamanho de cada elemento
int stack(ppStack pp, int size, int sizedata);

// Libera a memória da pilha
int unstack(ppStack pp);

// Empilha um elemento na pilha
int push(pStack p, void *element);

// Desempilha um elemento da pilha
int pop(pStack p, void *element);

// Limpa a pilha, mantendo a estrutura alocada
int cleanStack(pStack p);

// Retorna o elemento do topo sem removê-lo
int top(pStack p, void *top);

#endif // STACK_PUB_H