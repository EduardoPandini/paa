#include <stdio.h>
#include <stdlib.h>
#include "DDLL_pri.h"


// Função para criar uma lista duplamente encadeada
int cDDLL(ppDDLL pp, int sizedata) {
    *pp = (pDDLL)malloc(sizeof(DDLL));
    if (*pp == NULL)
        return 1;

    (*pp)->head = NULL;
    (*pp)->tail = NULL;
    (*pp)->size = 0;
    (*pp)->data_size = sizedata;
    return 0;
}

// Função para destruir uma lista duplamente encadeada
int dDDLL(ppDDLL pp) {
    if (cleanDDLL(*pp) == 1) // Verifica se houve falha na limpeza da lista
        return 1;
    free(*pp);
    *pp = NULL;
    return 0;
}

// Função para limpar todos os elementos de uma lista duplamente encadeada
int cleanDDLL(pDDLL p) {
    if (p == NULL)
        return 1;
    Node *current = p->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    p->head = NULL;
    p->tail = NULL;
    p->size = 0;
    if (p->head != NULL || p->tail != NULL || p->size != 0)
        return 1;
    
    return 0;
}

// Função para inserir um elemento no início da lista
int iBegin(pDDLL p, void *element) {
    if (p == NULL)
        return 1;
        
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
        return 1;

    new_node->data = malloc(p->data_size);
    if (new_node->data == NULL) {
        free(new_node);
        return 1;
    }

    memcpy(new_node->data, element, p->data_size);
    new_node->prev = NULL;
    new_node->next = p->head;

    if (p->head == NULL) {
        p->head = new_node;
        p->tail = new_node;
    } else {
        p->head->prev = new_node;
        p->head = new_node;
    }

    p->size++;
    return 0;
}

// Função para inserir um elemento no final da lista
int iEnd(pDDLL p, void *element) {
    if (p == NULL)
        return 1;
    
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
        return 1;

    new_node->data = malloc(p->data_size);
    if (new_node->data == NULL) {
        free(new_node);
        return 1;
    }

    memcpy(new_node->data, element, p->data_size);
    new_node->prev = p->tail;
    new_node->next = NULL;

    if (p->tail == NULL) {
        p->head = new_node;
        p->tail = new_node;
    } else {
        p->tail->next = new_node;
        p->tail = new_node;
    }

    p->size++;
    return 0;
}

// Função para inserir um elemento em uma posição específica da lista
int iPosition(pDDLL p, int N, void *element) {
    if (p == NULL)
        return 1;
        
    if (N < 0 || N > p->size)
        return 1;

    if (N == 0)
        return iBegin(p, element);
    else if (N == p->size)
        return iEnd(p, element);

    Node *current = p->head;
    for (int i = 0; i < N - 1; i++)
        current = current->next;

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
        return 1;

    new_node->data = malloc(p->data_size);
    if (new_node->data == NULL) {
        free(new_node);
        return 1;
    }

    memcpy(new_node->data, element, p->data_size);
    new_node->prev = current;
    new_node->next = current->next;
    current->next->prev = new_node;
    current->next = new_node;

    p->size++;
    return 0;
}


// Função para remover o primeiro elemento da lista
int rBegin(pDDLL p, void *element) {
    if (p == NULL)
        return 1;
        
    if (empty(p) == 0)
        return 1;

    Node *temp = p->head;
    memcpy(element, temp->data, p->data_size);

    if (p->head == p->tail) {
        p->head = NULL;
        p->tail = NULL;
    } else {
        p->head = p->head->next;
        p->head->prev = NULL;
    }

    free(temp->data);
    free(temp);
    p->size--;
    return 0;
}


// Função para remover o último elemento da lista
int rEnd(pDDLL p, void *element) {
    if (p == NULL)
        return 1;
        
    if (empty(p) == 0)
        return 1;

    Node *temp = p->tail;
    memcpy(element, temp->data, p->data_size);

    if (p->head == p->tail) {
        p->head = NULL;
        p->tail = NULL;
    } else {
        p->tail = p->tail->prev;
        p->tail->next = NULL;
    }

    free(temp->data);
    free(temp);
    p->size--;
    return 0;
}


// Função para remover um elemento de uma posição específica da lista
int rPosition(pDDLL p, int N, void *element) {
    if (p == NULL)
        return 1;
        
    if (empty(p) == 0 || N < 0 || N >= p->size)
        return 1;

    if (N == 0)
        return rBegin(p, element);
    else if (N == p->size - 1)
        return rEnd(p, element);

    Node *current = p->head;
    for (int i = 0; i < N; i++)
        current = current->next;

    memcpy(element, current->data, p->data_size);
    current->prev->next = current->next;
    current->next->prev = current->prev;

    free(current->data);
    free(current);
    p->size--;
    return 0;
}

// Função para buscar o primeiro elemento da lista
int sBegin(pDDLL p, void *element) {
    if (p == NULL)
        return 1;
        
    if (empty(p) == 0)
        return 1;

    memcpy(element, p->head->data, p->data_size);
    return 0;
}

// Função para buscar o último elemento da lista
int sEnd(pDDLL p, void *element) {
    if (p == NULL)
        return 1;
        
    if (empty(p) == 0)
        return 1;

    memcpy(element, p->tail->data, p->data_size);
    return 0;
}

// Função para buscar um elemento em uma posição específica da lista
int sPosition(pDDLL p, int N, void *element) {
    if (p == NULL)
        return 1;
        
    if (empty(p) == 0 || N < 0 || N >= p->size)
        return 1;

    Node *current = p->head;
    for (int i = 0; i < N; i++)
        current = current->next;

    memcpy(element, current->data, p->data_size);
    return 0;
}

// Função para verificar se a lista está vazia
int empty(pDDLL p) {
    if (p == NULL)
        return 1;
        
    if (p->size == 0)
        return 0;
    else
        return 1;
}


// Função para contar o número de elementos na lista
int countElements(pDDLL p) {
    if (p == NULL)
        return 1;
        
    return p->size;
}