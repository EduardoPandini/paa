/* Arquivo EXEMPLO DE Aplicacao */
// MODIFIQUEM-o, CORRIJAM-o!
#include "main.h"
#include "ctype.h"

int main() {
    pStack myStack = NULL; // Pilha genérica
    int ret, stackSize; // Variáveis para tamanho e retorno

    printf("Digite o tamanho da pilha: ");
    scanf("%d", &stackSize);

    // Inicializa a pilha para armazenar ponteiros para GenericData
    ret = stack(&myStack, stackSize, sizeof(GenericData *));
    if (ret == FAIL) {
        printf("Erro ao inicializar a pilha.\n");
        return 1;
    }

    printf("Digite os dados para empilhar (digite 'fim' para parar):\n");
    while (1) {
        char input[100];
        printf("Entrada: ");
        scanf("%s", input);

        if (strcmp(input, "fim") == 0) break;

        if (strcmp(input, "-top") == 0) {
            // Verifica o topo da pilha
            GenericData *topItem;
            ret = top(myStack, &topItem);
            if (ret == FAIL) {
                printf("A pilha está vazia.\n");
            } else {
                if (topItem->type == 1) {
                    printf("Topo da pilha (int): %d\n", *(int *)topItem->data);
                } else if (topItem->type == 2) {
                    printf("Topo da pilha (float): %.2f\n", *(float *)topItem->data);
                } else if (topItem->type == 3) {
                    printf("Topo da pilha (string): %s\n", (char *)topItem->data);
                }
            }
            continue;
        }

        if (strcmp(input, "-pop") == 0) {
            // Desempilha manualmente
            GenericData *poppedItem;
            ret = pop(myStack, &poppedItem);
            if (ret == FAIL) {
                printf("A pilha está vazia, não é possível desempilhar.\n");
            } else {
                if (poppedItem->type == 1) {
                    printf("Desempilhado (int): %d\n", *(int *)poppedItem->data);
                    free(poppedItem->data);
                } else if (poppedItem->type == 2) {
                    printf("Desempilhado (float): %.2f\n", *(float *)poppedItem->data);
                    free(poppedItem->data);
                } else if (poppedItem->type == 3) {
                    printf("Desempilhado (string): %s\n", (char *)poppedItem->data);
                    free(poppedItem->data);
                }
                free(poppedItem);
            }
            continue;
        }

        if (strcmp(input, "-clean") == 0) {
            // Limpa a pilha
            ret = cleanStack(myStack);
            if (ret == FAIL) {
                printf("Erro ao limpar a pilha.\n");
            } else {
                printf("Pilha limpa com sucesso.\n");
            }
            continue;
        }

        // Empilha o item
        ret = push(myStack, input);
        if (ret == FAIL) {
            printf("Erro ao empilhar o dado.\n");
        } else {
            printf("Dado empilhado com sucesso.\n");
        }
    }

    printf("Desempilhando todos os dados restantes:\n");
    GenericData *item;
    while (pop(myStack, &item) == SUCCESS) {
        if (item->type == 1) {
            printf("Desempilhado (int): %d\n", *(int *)item->data);
            free(item->data);
        } else if (item->type == 2) {
            printf("Desempilhado (float): %.2f\n", *(float *)item->data);
            free(item->data);
        } else if (item->type == 3) {
            printf("Desempilhado (string): %s\n", (char *)item->data);
            free(item->data);
        }
        free(item);
    }

    // Libera a pilha
    unstack(&myStack);

    return 0;
}
