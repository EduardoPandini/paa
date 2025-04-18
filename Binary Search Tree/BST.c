#include "BST_pri.h"
#include <stdlib.h>
#include <string.h>


// Função auxiliar para criar um novo nó
static BSTNode* createNode(void *data, int sizedata) {
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    if (!node) return NULL;
    node->data = malloc(sizedata);
    if (!node->data) {
        free(node);
        return NULL;
    }
    memcpy(node->data, data, sizedata);
    node->left = node->right = NULL;
    return node;
}

// Função auxiliar para destruir um nó
static void destroyNode(BSTNode *node) {
    if (node) {
        free(node->data);
        free(node);
    }
}

int cBST(ppBST pp, int sizedata) {
    if (!pp || sizedata <= 0) return FAIL;
    *pp = (pBST)malloc(sizeof(struct BST));
    if (*pp == NULL)
        return 1;
    if (!(*pp)) return FAIL;
    (*pp)->root = NULL;
    (*pp)->sizedata = sizedata;
    return SUCCESS;
}

int dBST(ppBST pp) {
    if (pp == NULL)
        return 1;
    if (!pp || !(*pp)) return FAIL;
    cleanBST(*pp);
    free(*pp);
    *pp = NULL;
    return SUCCESS;
}

int cleanBST(pBST p) {
    if (p == NULL)
        return 1;
    if (!p) return FAIL;

    // Função auxiliar para limpar recursivamente a árvore
    void cleanRecursive(BSTNode *node) {
        if (node) {
            cleanRecursive(node->left);
            cleanRecursive(node->right);
            destroyNode(node);
        }
    }

    cleanRecursive(p->root);
    p->root = NULL;
    return SUCCESS;
}

int iBST(pBST p, void *new, int (* cmp)(void *p1, void *p2)) {
    if (p == NULL)
        return 1;
    if (!p || !new || !cmp) return FAIL;

    BSTNode **current = &(p->root);
    while (*current) {
        int comparison = cmp(new, (*current)->data);
        if (comparison < 0) {
            current = &(*current)->left;
        } else if (comparison > 0) {
            current = &(*current)->right;
        } else {
            return FAIL;  // Duplicates not allowed
        }
    }

    *current = createNode(new, p->sizedata);
    return (*current) ? SUCCESS : FAIL;
}

int rBST(pBST p, void *item, int (* cmp)(void *p1, void *p2)) {
    if (p == NULL)
        return 1;
    if (!p || !item || !cmp) return FAIL;

    BSTNode **current = &(p->root);
    BSTNode *parent = NULL;
    int isLeftChild = 0;

    while (*current) {
        int comparison = cmp(item, (*current)->data);
        if (comparison == 0) break;
        parent = *current;
        if (comparison < 0) {
            current = &(*current)->left;
            isLeftChild = 1;
        } else {
            current = &(*current)->right;
            isLeftChild = 0;
        }
    }

    if (!(*current)) return FAIL;  // Item not found

    BSTNode *nodeToRemove = *current;

    if (!nodeToRemove->left && !nodeToRemove->right) {
        *current = NULL;
    } else if (!nodeToRemove->left) {
        *current = nodeToRemove->right;
    } else if (!nodeToRemove->right) {
        *current = nodeToRemove->left;
    } else {
        BSTNode **successor = &nodeToRemove->right;
        while ((*successor)->left) {
            successor = &(*successor)->left;
        }
        BSTNode *successorNode = *successor;
        *successor = successorNode->right;
        successorNode->left = nodeToRemove->left;
        successorNode->right = nodeToRemove->right;
        *current = successorNode;
    }

    destroyNode(nodeToRemove);
    return SUCCESS;
}

int sBST(pBST p, void *item, int (* cmp)(void *p1, void *p2)) {
    if (p == NULL)
        return 1;
    if (!p || !item || !cmp) return FAIL;

    BSTNode *current = p->root;
    while (current) {
        int comparison = cmp(item, current->data);
        if (comparison == 0) return SUCCESS;
        current = (comparison < 0) ? current->left : current->right;
    }
    return FAIL;
}

int emptyBST(pBST p) {
    if (p == NULL)
        return 1;
    if (!p) return FAIL;
    return (p->root == NULL) ? SUCCESS : FAIL;
}

static void traverseInOrder(BSTNode *node, void (* process)(void *p)) {
    if (node) {
        traverseInOrder(node->left, process);
        process(node->data);
        traverseInOrder(node->right, process);
    }
}

int orderPath(pBST p, void (* process)(void *p)) {
    if (p == NULL)
        return 1;
    if (!p || !process) return FAIL;
    traverseInOrder(p->root, process);
    return SUCCESS;
}

static void traversePreOrder(BSTNode *node, void (* process)(void *p)) {
    if (node) {
        process(node->data);
        traversePreOrder(node->left, process);
        traversePreOrder(node->right, process);
    }
}

int preorderPath(pBST p, void (* process)(void *p)) {
    if (p == NULL)
        return 1;
    if (!p || !process) return FAIL;
    traversePreOrder(p->root, process);
    return SUCCESS;
}

static void traversePostOrder(BSTNode *node, void (* process)(void *p)) {
    if (node) {
        traversePostOrder(node->left, process);
        traversePostOrder(node->right, process);
        process(node->data);
    }
}

int postorderPath(pBST p, void (* process)(void *p)) {
    if (p == NULL)
        return 1;
    if (!p || !process) return FAIL;
    traversePostOrder(p->root, process);
    return SUCCESS;
}
