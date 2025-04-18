#include "QDBST_pri.h"
#include "QDBST_pub.h"
#include <stdlib.h>
#include <string.h>

// Definição da função de comparação para BST
int cmp(void *p1, void *p2) {
    int index1 = *((int*)p1);
    int index2 = *((int*)p2);
    return index1 - index2;
}

int cQDB(ppQDB pp, int sizedata) {
    if (!pp || sizedata <= 0) return FAIL;

    *pp = (pQDB)malloc(sizeof(QDBST));
    if (!*pp) return FAIL;

    (*pp)->sizedata = sizedata;

    if (cDDLL(&((*pp)->qd), sizeof(int)) != SUCCESS) {
        free(*pp);
        return FAIL;
    }

    if (cBST(&((*pp)->bst), sizeof(int) + sizedata) != SUCCESS) {
        dDDLL(&((*pp)->qd));
        free(*pp);
        return FAIL;
    }

    return SUCCESS;
}

int dQDB(ppQDB pp) {
    if (!pp || !*pp) return FAIL;

    if (dDDLL(&((*pp)->qd)) != SUCCESS) return FAIL;
    if (dBST(&((*pp)->bst)) != SUCCESS) return FAIL;

    free(*pp);
    *pp = NULL;

    return SUCCESS;
}

int iQDB(pQDB p, void *new) {
    if (!p || !new) return FAIL;

    int index = rand();  // Gerar um índice aleatório
    if (iEnd(p->qd, &index) != SUCCESS) return FAIL;

    void *package = malloc(sizeof(int) + p->sizedata);
    if (!package) return FAIL;

    memcpy(package, &index, sizeof(int));
    memcpy((char*)package + sizeof(int), new, p->sizedata);

    if (iBST(p->bst, package, cmp) != SUCCESS) {
        rEnd(p->qd, &index);
        free(package);
        return FAIL;
    }
    
    free(package);

    return SUCCESS;
}

int sQDB(pQDB p, void *new) {
    if (!p || !new) return FAIL;

    int index;
    if (sBegin(p->qd, &index) != SUCCESS) return FAIL;

    void *package = malloc(sizeof(int) + p->sizedata);
    if (!package) return FAIL;

    memcpy(package, &index, sizeof(int));

    if (sBST(p->bst, package, cmp) != SUCCESS) {
        free(package);
        return FAIL;
    }

    memcpy(new, (char*)package + sizeof(int), p->sizedata);
    free(package);

    return SUCCESS;
}

int rQDB(pQDB p, void *new) {
    if (!p || !new) return FAIL;

    int index;
    if (rBegin(p->qd, &index) != SUCCESS) return FAIL;

    void *package = malloc(sizeof(int) + p->sizedata);
    if (!package) return FAIL;

    memcpy(package, &index, sizeof(int));

    if (rBST(p->bst, package, cmp) != SUCCESS) {
        free(package);
        return FAIL;
    }

    memcpy(new, (char*)package + sizeof(int), p->sizedata);
    free(package);

    return SUCCESS;
}

int prQDB(pQDB p, void (*printall)(void *p)) {
    if (!p || !printall) return FAIL;

    void printWrapper(void *package) {
        printall((char*)package + sizeof(int));
    }

    return orderPath(p->bst, printWrapper);
}
