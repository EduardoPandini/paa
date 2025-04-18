#include "main.h"

typedef struct {
    int value;
} Data;

int compareData(void *p1, void *p2) {
    Data *d1 = (Data *)p1;
    Data *d2 = (Data *)p2;
    return d1->value - d2->value;
}

void printData(void *p) {
    Data *data = (Data *)p;
    printf("%d ", data->value);
}

int main() {
    pBST tree;
    if (cBST(&tree, sizeof(Data)) != SUCCESS) {
        printf("Error creating tree\n");
        return 1;
    }

    int values[] = {5, 3, 8, 1, 4, 7, 10};
    for (int i = 0; i < sizeof(values)/sizeof(values[0]); ++i) {
        Data newData = {values[i]};
        if (iBST(tree, &newData, compareData) != SUCCESS) {
            printf("Error inserting %d\n", values[i]);
        }
    }

    printf("In-order: ");
    orderPath(tree, printData);
    printf("\n");

    printf("Pre-order: ");
    preorderPath(tree, printData);
    printf("\n");

    printf("Post-order: ");
    postorderPath(tree, printData);
    printf("\n");

    int searchValue = 4;
    Data searchData = {searchValue};
    if (sBST(tree, &searchData, compareData) == SUCCESS) {
        printf("Value %d found in tree\n", searchValue);
    } else {
        printf("Value %d not found in tree\n", searchValue);
    }

    int removeValue = 3;
    Data removeData = {removeValue};
    if (rBST(tree, &removeData, compareData) == SUCCESS) {
        printf("Value %d removed from tree\n", removeValue);
    } else {
        printf("Value %d not found in tree\n", removeValue);
    }

    printf("In-order after removal: ");
    orderPath(tree, printData);
    printf("\n");

    cleanBST(tree);
    dBST(&tree);

    return 0;
}
