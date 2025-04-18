#ifndef _QDDLLBST_INTERFACE_H_
#define _QDDLLBST_INTERFACE_H_

#define SUCCESS 0
#define FAIL 1

typedef struct QDBST *pQDB, **ppQDB;

int cQDB(ppQDB pp, int sizedata);             // cria a QDB
int dQDB(ppQDB pp);                           // destroi a QDB
int iQDB(pQDB p, void *new);                  // insere na QDB
int sQDB(pQDB p, void *new);                  // busca na QDB
int rQDB(pQDB p, void *new);                  // remove na QDB
int prQDB(pQDB p, void (*printall)(void *p)); // imprime a QDB

#endif
