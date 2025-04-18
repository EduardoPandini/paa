#ifndef DDLL_PRI_H
#define DDLL_PRI_H

#include "DDLL_pub.h"

// Definição da estrutura de nó da lista duplamente encadeada
typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
} Node;

// Definição da estrutura de lista duplamente encadeada
typedef struct DDLL {
    Node *head;
    Node *tail;
    int size;
    int data_size;
} DDLL;

#endif