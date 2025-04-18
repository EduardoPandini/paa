#ifndef _BST_PRI_H_
#define _BST_PRI_H_

#include "BST_pub.h"

#define SUCCESS 0
#define FAIL 1

// Estrutura de nó da árvore binária
typedef struct BSTNode {
    void *data;
    struct BSTNode *left, *right;
} BSTNode;

// Estrutura da árvore binária
struct BST {
    BSTNode *root;
    int sizedata;
};

#endif
