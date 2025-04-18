#include "QDBST_pub.h"
#include <stdio.h>


void printInt (void *myNode) {
    int * p = NULL;

    p = (int *) myNode;
    printf("\t(%i)", *p);
}


int main(int argc, char *argv[]) {
    pQDB qdb = NULL;
    int intput=0;
    int intret=0;

    
    // Criação da QDB
    printf("\n\t**** Criação ****\n");
    if (cQDB(&qdb,sizeof(int))) {
    		printf("    FAIL: Erro ao criar a QDB.\n");
	} else 
	    printf("    OK : QDB criada com SUCESSO.\n");

    // Leitura/Inserção da QDB
    printf("\n\t**** INSERCAO ****\n");
    while (1) {
        if (!fscanf(stdin, "%d", &intput)) 
            break;
        intput += 10000;

		if(iQDB(qdb, &intput) == SUCCESS){
			printf("    OK :inserido com SUCESSO(%d).\n",intput);
		}else{
			printf("    FAIL: falha na insercao.\n");
		}
        

    }
    printf("\n\t**** Impressão (Ordem) ****\n");        
    prQDB(qdb, printInt);
    printf("\n");

    // Busca da QDB
    printf("\n\t**** BUSCA ****\n");
    for (int i=0; i < 4; i++) {
        if (sQDB(qdb, &intret) == SUCCESS) {
    	    printf("    OK :buscado com SUCESSO(%d).\n",intret);        
        }
    }
    printf("\n");
    
    // Remoção da QDB
    printf("\n\t**** REMOCAO ****\n");
    for (int i=0; i < 4; i++)
        if (rQDB(qdb, &intret) == SUCCESS) {
                printf("    OK : removido com SUCESSO(%d).\n",intret);        
        }

    printf("\n\t**** Impressão (Ordem) ****\n");        
    prQDB(qdb, printInt);
    printf("\n");
        
    
    printf("\n\t**** Destruição ****\n");
    if (dQDB(&qdb)) {
    		printf("    FAIL: Erro ao destroir a QDB.\n");
	} else 
	    printf("    OK : QDB destruida com SUCESSO.\n");
    
    return 0;
}