// Implementações das funções da biblioteca (contém a implementação das funções da pilha)
#include "stack_pri.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

// "Construtor": aloca memória e inicializa as variáveis
int stack(ppStack pp, int size, int sizedata) {
    if (pp == NULL) {
        return FAIL; // evita que a função tente desreferenciar um ponteiro inválido a seguir
    }

    if (size < 1) {
        return FAIL; // evita que a função tente alocar uma pilha com capacidade para um número inválido de elementos
    }

    if (sizedata < 1)  {
        return FAIL; // evita que a função tente alocar uma pilha com dados de tamanho inválido
    }

    // todos os parâmetros são válidos, então podemos instanciar a pilha
    *pp = malloc(sizeof(PE)); // o ponteiro da pilha (referenciado por pp) recebe o endereço bloco de memória alocado

    if (*pp == NULL) {
        return FAIL; // a alocação falhou
    }

    // inicializando os membros da estrutura
    (*pp)->stack_capacity = size;
    (*pp)->data_size = sizedata;
    (*pp)->top_index = -1;
    (*pp)->data = malloc(size * sizedata);

    if ((*pp)->data == NULL) {
        return FAIL; // a alocação do array de dados falhou
    }

    return SUCCESS;
}

// "Destrutor": libera memória da estrutura
int unstack(ppStack pp) {
    if (pp == NULL) {
        return FAIL; // evita que a função tente desreferenciar um ponteiro inválido a seguir
    }

    if (*pp == NULL) {
        return FAIL; // evita tentar desalocar um endereço inválido de memória
    }

    if ((*pp)->data == NULL) {
        return FAIL; // evita tentar desalocar um endereço inválido de memória
    }

    free((*pp)->data); // libera a memória alocada para os elementos
    free((*pp)); // libera a memória alocada para a pilha

    return SUCCESS;
}


// **** "Operações de manipulação" ****
// Empilha um elemento 
int push(pStack p, void *element) {
    if (p == NULL) {
        return FAIL; // evita tentar inserir em uma pilha inválida
    }

    if (p->data == NULL) {
        return FAIL; // evita tentar inserir em uma pilha cuja estrutura que guarda os elementos foi inicializada incorretamente
    }

    if (element == NULL) {
        return FAIL; // evita tentar inserir um elemento inválido
    }

    if ((p->top_index + 1) == p->stack_capacity) {
        return FAIL; // evita inserir em uma pilha cheia
    }

    p->top_index++;
    
    // memcpy(destination, source, size)
    memcpy(p->data + (p->top_index * p->data_size), element, p->data_size); // destination: endereço do array de dados + quantos elementos * tamanho dos dados
    
    return SUCCESS;
}

// Desempilha um elemento
int pop(pStack p, void *element) {
    if (p == NULL) {
        return FAIL; // evita tentar inserir em uma pilha inválida
    }

    if (p->data == NULL) {
        return FAIL; // evita tentar inserir em uma pilha cuja estrutura que guarda os elementos foi inicializada incorretamente
    }

    if (element == NULL) {
        return FAIL; // evita copiar o retorno para um endereço inválido
    }

    if ((p->top_index) < 0) {
        return FAIL; // evita remover de uma pilha vazia
    }

    // memcpy(destination, source, size)
    memcpy(element, p->data + (p->top_index * p->data_size), p->data_size); // source: endereço do array de dados + quantos elementos * tamanho dos dados
    p->top_index--;

    return SUCCESS;
}

// Remove todos os dados da pilha mantendo o descritor alocado.
int cleanStack(pStack p) {
    
    if (p == NULL) {
        return FAIL; // evita tentar limpar de uma pilha inválida
    }

    if (p->data == NULL) {
        return FAIL; // evita tentar limpar os elementos de uma pilha cuja estrutura que guarda os elementos foi inicializada incorretamente
    }

    //p->top_index = -1; // retorna o ponteiro de topo para o início

    return SUCCESS;
}


// **** "Operações de acesso" ****
// Retorna uma cópia do dado do topo
int top(pStack p, void *top) {
    if (p == NULL) {
        return FAIL; // evita tentar inserir em uma pilha inválida
    }

    if (p->data == NULL) {
        return FAIL; // evita tentar inserir em uma pilha cuja estrutura que guarda os elementos foi inicializada incorretamente
    }

    if (top == NULL) {
        return FAIL; // evita copiar o retorno para um endereço inválido
    }

    if ((p->top_index) < 0) {
        return FAIL; // evita ler de uma pilha vazia
    }

    // memcpy(destination, source, size)
    memcpy(top, p->data + (p->top_index * p->data_size), p->data_size); // source: endereço do array de dados + quantos elementos * tamanho dos dados

    return SUCCESS;
}