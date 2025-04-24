#ifndef _BST_PRIVADO_H_
#define _BST_PRIVADO_H_

#include "QDBST_pub.h"
#include "DDLL_pub.h"
#include <string.h>
#include <stdio.h>

typedef struct QDBST {
    pDDLL qd;  // Ponteiro para a estrutura de DDLL usada como Queue Dynamic
    pBST bst;  // Ponteiro para a estrutura de BST
    int sizedata;  // Tamanho dos dados armazenados
} QDBST;

// Declaração da função de comparação
int cmp(void *p1, void *p2);

#endif
