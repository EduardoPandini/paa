#ifndef STACK_PRI_H
#define STACK_PRI_H

// Estrutura interna da pilha (privada)
struct PE {
    void *data;      // Ponteiro para os dados armazenados na pilha
    int size;        // Tamanho máximo da pilha
    int sizedata;    // Tamanho de cada elemento
    int top;         // Índice do topo da pilha
};

#endif // STACK_PRI_H