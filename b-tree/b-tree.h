#include <stdio.h>
#include <stdlib.h>
#define M 3

// m = 3
// number of children: minimum 2, maximum 3.
// number of keys: minimum 1, maximum 2.

typedef struct node{
    int data[M-1];
    struct node* children[M];
    int leaf;

}BTree;

BTree* createTree(int m);
BTree* insert(BTree* tree, int data);
BTree* removeData(BTree* tree, int data);
BTree* search(BTree* tree, int data);