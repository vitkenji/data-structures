#include <stdio.h>
#include <stdlib.h>
#define M 3

typedef struct node{
    int n;
    int data[M-1];
    struct node* children[M];
    int leaf;

}BTree;

BTree* createTree();

BTree* insert(BTree* tree, int key);
BTree* removeData(BTree* tree, int data);
BTree* search(BTree* tree, int data);
void printBTree(BTree* t);

BTree* createNode(int leaf);
void splitChild(BTree* parent, int i, BTree* fullChild);
void insertNonFull(BTree* node, int key);
int findKey(BTree* node, int key);
void removeFromNode(BTree* node, int key);
void removeFromLeaf(BTree* node, int index);
void removeFromNonLeaf(BTree* node, int index);
void merge(BTree* node, int index);
int getPredecessor(BTree* node, int index);
int getSuccessor(BTree* node, int index);
void fill(BTree* node, int index);
void borrowFromPrev(BTree* node, int index);
void borrowFromNext(BTree* node, int index);
