#include "queue_pub.h"

struct Queue
{
    int sizedata;
    int tamfila;
    int inicio;
    int fim;
    int elementosinseridos;
    void *data;
} Queue;

int filacheia(pQueue f);
int filavazia(pQueue f);