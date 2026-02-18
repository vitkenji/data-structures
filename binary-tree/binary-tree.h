#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;

}Tree;

Tree* createTree();
Tree* insertNode(int data, Tree* left, Tree* right);

void preOrder(Tree* t);
void inOrder(Tree* t);
void postOrder(Tree* t);
int search(Tree*, int data);