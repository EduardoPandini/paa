#include "stack_pub.h"
#include "stack_pri.h"

// Função para inicializar a pilha
int stack(ppStack pp, int size, int sizedata) {
    // Aloca memória para a estrutura da pilha
    *pp = (pStack)malloc(sizeof(struct PE));
    if (*pp == NULL) {
        return FAIL; // Retorna erro se a alocação falhar
    }

    // Inicializa os campos da pilha
    (*pp)->data = malloc(size * sizedata); // Aloca memória para os dados
    if ((*pp)->data == NULL) {
        free(*pp); // Libera a memória da estrutura se a alocação dos dados falhar
        return FAIL;
    }

    (*pp)->size = size;        // Define o tamanho máximo da pilha
    (*pp)->sizedata = sizedata; // Define o tamanho de cada elemento
    (*pp)->top = -1;           // Inicializa o topo como -1 (pilha vazia)

    return SUCCESS; // Retorna sucesso
}

// Função para liberar a memória da pilha
int unstack(ppStack pp) {
    if (*pp == NULL) {
        return FAIL; // Retorna erro se a pilha já estiver desalocada
    }

    free((*pp)->data); // Libera a memória dos dados
    free(*pp);         // Libera a memória da estrutura da pilha
    *pp = NULL;        // Define o ponteiro como NULL para evitar acessos inválidos

    return SUCCESS; // Retorna sucesso
}

// Função para empilhar um elemento
int push(pStack p, void *element) {
    if (p == NULL || p->data == NULL) {
        return FAIL; // Retorna erro se a pilha não foi inicializada
    }

    if (p->top >= p->size - 1) {
        return FAIL; // Retorna erro se a pilha estiver cheia
    }

    // Copia o elemento para o topo da pilha
    p->top++;
    void *target = (char *)p->data + (p->top * p->sizedata);
    memcpy(target, element, p->sizedata);

    return SUCCESS; // Retorna sucesso
}

// Função para desempilhar um elemento
int pop(pStack p, void *element) {
    if (p == NULL || p->data == NULL) {
        return FAIL; // Retorna erro se a pilha não foi inicializada
    }

    if (p->top < 0) {
        return FAIL; // Retorna erro se a pilha estiver vazia
    }

    // Copia o elemento do topo para o ponteiro fornecido
    void *source = (char *)p->data + (p->top * p->sizedata);
    memcpy(element, source, p->sizedata);
    p->top--;

    return SUCCESS; // Retorna sucesso
}

// Função para limpar a pilha (mantendo a estrutura alocada)
int cleanStack(pStack p) {
    if (p == NULL || p->data == NULL) {
        return FAIL; // Retorna erro se a pilha não foi inicializada
    }

    p->top = -1; // Reseta o topo para -1 (pilha vazia)

    return SUCCESS; // Retorna sucesso
}

// Função para acessar o elemento do topo sem removê-lo
int top(pStack p, void *top) {
    if (p == NULL || p->data == NULL) {
        return FAIL; // Retorna erro se a pilha não foi inicializada
    }

    if (p->top < 0) {
        return FAIL; // Retorna erro se a pilha estiver vazia
    }

    // Copia o elemento do topo para o ponteiro fornecido
    void *source = (char *)p->data + (p->top * p->sizedata);
    memcpy(top, source, p->sizedata);

    return SUCCESS; // Retorna sucesso
}