#include "queue_pri.h"
#include "stdlib.h"
#include <string.h>

// "Construtor": aloca memória e inicializa as variáveis
int cQueue(ppQueue pf, int size, int sizedata) {
    if (pf == NULL) {
        return FAIL; //evita desreferenciar ponteiro nulo a seguir
    }

    if (size < 1) {
        return FAIL; //evita alocar array de tamanho inválido
    }

    if (sizedata < 1) {
        return FAIL; //evita erro no malloc do array
    }

    (*pf) = (pQueue)malloc(sizeof(Queue));
    (*pf)->sizedata = sizedata;
    (*pf)->tamfila = size;
    (*pf)->inicio = 0;
    (*pf)->fim = 0;
    (*pf)->elementosinseridos = 0;
    (*pf)->data = malloc(sizedata * size);

    if ((*pf)->data == NULL) {
        return FAIL; //falha na alocação
    }

    return SUCCESS;
}

// "Destrutor": libera memória da estrutura
int dQueue(ppQueue pf) {
    if (pf == NULL) {
        return FAIL; // evita desreferenciar ponteiro nulo a seguir
    }

    if ((*pf)->data == NULL) {
        return FAIL;
    }

    free((*pf)->data);
    free(*pf);
    return SUCCESS;
}

// **** "Operações de manipulação" ****
// Enfiera um elemento
int queue(pQueue f, void *element) {
    if (f == NULL) {
        return FAIL;
    }

    if(filacheia(f) == FAIL) {
        return FAIL;
    }

    if(sizeof(*element) > f->sizedata) {
        return FAIL;
    }

    // se não está cheia, podemos inserir.
    memcpy(f->data + (f->fim * f->sizedata), element, f->sizedata);
    f->fim = (f->fim + 1) % f->tamfila;
    int * elem = element;
    //printf("queue %d\n", *elem);
    f->elementosinseridos++;
    return SUCCESS;
}

// Desenfilera um elemento
int unqueue(pQueue f, void *element) {
    if (filavazia(f) == FAIL) {
        return FAIL;
    }

    memcpy(element, f->data + (f->inicio * f->sizedata), f->sizedata);
    f->inicio = (f->inicio + 1)%f->tamfila;
    int *elem = element;
    //printf("unqueue %d\n", *elem);
    f->elementosinseridos--;
    return SUCCESS;
}

// Remove todos os dados da fila mantendo o descritor alocado.
int cleanQueue(pQueue f) {
    f->inicio = 0;
    f->fim = 0;
    f->elementosinseridos = 0;
    return SUCCESS;
}

// **** "Operações de acesso" ****
// Retorna o máximo da fila
int sizeQueue(pQueue f) {
    return f->tamfila;
}

// Funções auxiliares
int filacheia(pQueue f) {
    if (f->elementosinseridos == f->tamfila) {
        return FAIL;
    }
    return SUCCESS;
}

int filavazia(pQueue f) {
    if (f->elementosinseridos == 0) {
        return FAIL;
    }
    return SUCCESS;
}
