/*
 * Crie um exemplo de aplicação (main.c e main.h) para demonstrar o uso da biblioteca de pilha genérica.
 * No exemplo de aplicação, demonstre como criar uma pilha, empilhar e desempilhar elementos de diferentes tipos de dados.
 * Certifique-se de que a biblioteca e o exemplo de aplicação estejam compilando corretamente.
 * A pilha deve ser capaz de acomodar um número máximo de elementos especificado pelo usuário durante a sua inicialização;
 * O tamanho de cada elemento da pilha também deve ser especificado pelo usuário durante a inicialização.
 * Ao implementar as funções, verifique a integridade da pilha, tratando casos de pilha cheia, pilha vazia e outros erros possíveis.
 * Utilize ponteiros duplos (ppStack) para manipular a pilha, garantindo que as alterações feitas nas funções sejam refletidas fora delas.
 * Teste exaustivamente sua implementação, garantindo que todas as operações da pilha estejam funcionando corretamente e que não haja vazamento de
   memória ou comportamentos inesperados.
 * O módulo avaliar irá verificar vazamento de memória com o valgrind.
 * Envie os três arquivos da biblioteca (stack.c, stack_pub.h, stack_priv.h) e os arquivos de exemplo de aplicação (main.c, main.h),
   além de um arquivo de texto contendo qualquer informação adicional que considere relevante para avaliação.
*/

#include "main.h"

  int main(int argc, char *argv[]) {

  pStack P = NULL;
  int num_elements = 2;
  int valor = 101;
  int retorno = -1;
  int retorno_top = -1;

  // Testa se a pilha está sendo criada corretamente
  if (stack(&P, num_elements, sizeof(int))) {
    printf("Erro ao criar a pilha.\n");
    exit(1);
  } else {
    printf("Pilha criada com sucesso.\n");
  }

  // Testa empilhar um elemento
  if (push(P, &valor)) {
    printf("Erro ao empilhar elemento.\n");
    exit(1);
  } else {
    printf("Elemento empilhado com sucesso.\n");
  }

  // Testa retornar o elemento do topo
  if (top(P, &retorno_top)) {
    printf("Erro ao recuperar o elemento no topo.\n");
    exit(1);
  } else {
    printf("O elemento no topo é: %i.\n", retorno_top);
  }

  // Testa desempilhar um elemento
  if (pop(P, &retorno)) {
    printf("Erro ao desempilhar elemento.\n");
    exit(1);
  } else {
    printf("Elemento %i desempilhado com sucesso.\n", retorno);
  }

  // Testa se a pilha está sendo limpa corretamente
  if (cleanStack(P)) {
    printf("Erro ao limpar a pilha");
    exit(1);
  } else {
    printf("Pilha limpa com sucesso.\n");
  }

  // Testa se a pilha está sendo destruída corretamente
  if (unstack(&P)) {
    printf("Erro ao destruir a pilha");
    exit(1);
  } else {
    printf("Pilha destruída com sucesso.\n");
  }

  return 0;
}
