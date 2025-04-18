#include "Stack_DDLL_pri.h"

int stack(ppStack pp, int sizedata){
    if (pp == NULL) {
        return FAIL;
    }

    (*pp) = (pStack)malloc(sizeof(ppStack));

    if ((*pp) == NULL) {
        return FAIL;
    }

    (*pp)->lista = (pDDLL *)malloc(sizeof(pDDLL));
    
    if ((*pp)->lista == NULL) {
        return FAIL;
    }

    return cDDLL((*pp)->lista, sizedata);
}

int unstack(ppStack pp) {
    if (pp == NULL) {
        return FAIL;
    }
    
    if ((*pp) == NULL) {
        return FAIL;
    }
    
    
    dDDLL((*pp)->lista);
    
    if ((*pp)->lista == NULL) {
        return FAIL;
    }
    free((*pp)->lista);
    free(*pp);

    return SUCCESS;
}

int push(pStack p, void *element) {
    if (p == NULL | element == NULL) {
        return FAIL;
    }

    return iEnd(*p->lista, element);
}

int pop(pStack p, void *element) {
    if (p == NULL | element == NULL) {
        return FAIL;
    }

    return rEnd(*p->lista, element);
}

int cleanStack(pStack p) {
    if (p == NULL) {
        return FAIL;
    }
    return cleanDDLL(*p->lista);
}

int top(pStack p, void *top) {
    if (p == NULL || top == NULL) {
        return FAIL;
    }

    return sEnd(*p->lista, top);
}