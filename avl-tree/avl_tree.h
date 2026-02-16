#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;

}AvlTree;

AvlTree* createTree();
AvlTree* createNode(int data);
AvlTree* insertNode(AvlTree* t, int data);
int height(AvlTree* t);
int balanceFactor(AvlTree* t);
int max(int a, int b);
AvlTree* leftRotation(AvlTree* t);
AvlTree* rightRotation(AvlTree* t);
int calculateHeight(AvlTree* t);
void preOrder(AvlTree* t);
void inOrder(AvlTree* t);
void postOrder(AvlTree* t);
