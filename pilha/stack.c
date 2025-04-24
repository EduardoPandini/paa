#include "stack_pub.h"
#include "stack_pri.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função para inicializar a pilha
int stack(ppStack pp, int size, int sizedata) {
    *pp = (pStack)malloc(sizeof(struct PE));
    if (*pp == NULL) {
        return FAIL;
    }

    (*pp)->data = malloc(size * sizedata);
    if ((*pp)->data == NULL) {
        free(*pp);
        return FAIL;
    }

    (*pp)->size = size;
    (*pp)->sizedata = sizedata;
    (*pp)->top = -1;

    return SUCCESS;
}

// Função para liberar a memória da pilha
int unstack(ppStack pp) {
    if (*pp == NULL) {
        return FAIL;
    }

    free((*pp)->data);
    free(*pp);
    *pp = NULL;

    return SUCCESS;
}

// Função para empilhar um elemento
int push(pStack p, void *element) {
    if (p == NULL || p->data == NULL) {
        return FAIL;
    }

    if (p->top >= p->size - 1) {
        return FAIL;
    }

    // Incrementa o topo da pilha
    p->top++;
    void *target = (char *)p->data + (p->top * p->sizedata);

    // Copia o ponteiro para o elemento na pilha
    memcpy(target, &element, p->sizedata);

    return SUCCESS;
}

// Função para desempilhar um elemento
int pop(pStack p, void *element) {
    if (p == NULL || p->data == NULL) {
        return FAIL;
    }

    if (p->top < 0) {
        return FAIL;
    }

    // Copia o ponteiro do topo da pilha para o elemento fornecido
    void *source = (char *)p->data + (p->top * p->sizedata);
    memcpy(element, source, p->sizedata);

    // Decrementa o topo da pilha
    p->top--;

    return SUCCESS;
}

// Função para limpar a pilha (mantendo a estrutura alocada)
int cleanStack(pStack p) {
    if (p == NULL || p->data == NULL) {
        return FAIL;
    }

    // Libera todos os elementos da pilha
    while (p->top >= 0) {
        GenericData *item;
        pop(p, &item);
    }

    p->top = -1;
    return SUCCESS;
}

// Função para acessar o elemento do topo sem removê-lo
int top(pStack p, void *top) {
    if (p == NULL || p->data == NULL) {
        return FAIL;
    }

    if (p->top < 0) {
        return FAIL;
    }

    void *source = (char *)p->data + (p->top * p->sizedata);
    memcpy(top, source, p->sizedata);

    return SUCCESS;
}