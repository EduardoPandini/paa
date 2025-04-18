// Estrutura e assinatura das operações internas (contém as definições das estruturas de dados e funções privadas da pilha)
#include "stack_pub.h"

// Definição da estrutura
typedef struct PE {
    int stack_capacity; // número máximo de elementos que a pilha pode armazenar
    int data_size; // o tamanho de cada elemento, o que permite que a pilha seja genérica.
    int top_index; // representa o índice do último elemento na pilha
    void * data; // aponta para o bloco de memória onde os elementos da pilha serão armazenados 
} PE;
