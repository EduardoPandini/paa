/* Arquivo EXEMPLO DE Aplicacao */
// MODIFIQUEM-o, CORRIJAM-o!
#include "main.h"

int main(int argc, char *argv[]) {
    
    pStack P = NULL;
    int ret=0;
    int valor=0;
    int *arg;
    int rlines=0;

    if (!fscanf(stdin, "%i", &rlines)) {
        return 1;
    }

    arg = (int*) malloc(sizeof(int)*(rlines));
  
    printf("Criando pilha\n");
    if (ret = stack(&P,sizeof(int)) == SUCCESS) {
        printf("Criado com sucesso\n");
    } else {
        printf("Erro ao criar\n");
    }

    printf("Inserindo dados\n");
    for (int i=0; i<rlines;i++) {
        if (!fscanf(stdin, "%i", &arg[i])) {
            return 1;
        }

        if (ret = push(P,&arg[i]) == SUCCESS) {
            printf("Inserido com sucesso\n");
        } else {
            printf("Erro ao inserir\n");
        }
    }

    printf("Retornando topo\n");
    if (ret = top(P,&valor) == SUCCESS) {
        printf("O topo é: %i\n", valor);
    } else {
        printf("Erro ao retornar o topo\n");
    }

    printf("Removendo dados\n");
    for (int i=0; i<rlines;i++) {
        if (ret = pop(P,&valor) == SUCCESS) {
            printf("Removido com sucesso: %i\n", valor);
        } else {
            printf("Erro ao remover\n");
        }
    }

    printf("Apagando pilha\n");
    if (ret = unstack(&P) == SUCCESS) {
        printf("Apagada com sucesso\n");
    } else {
        printf("Erro ao apagar\n");
    }
    free(arg);
  
    return 0;
}
