#ifndef STACK_PRI_H
#define STACK_PRI_H

// Estrutura interna da pilha (privada)
struct PE {
    void *data;      // Ponteiro para os dados armazenados na pilha
    int size;        // Tamanho máximo da pilha
    int sizedata;    // Tamanho de cada elemento
    int top;         // Índice do topo da pilha
};

// Estrutura genérica para armazenar dados (privada)
typedef struct {
    int type; // 1 = int, 2 = float, 3 = string
    void *data;
} GenericData;

#endif // STACK_PRI_H