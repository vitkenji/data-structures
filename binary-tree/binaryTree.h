#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;

}Tree;

Tree* createTree();
Tree* buildTree(int data, Tree* left, Tree* right);

void preOrder(Tree* t);
void inOrder(Tree* t);
void postOrder(Tree* t);

int search(Tree*, int data);
int countNodes(Tree* t);
int calculateHeight(Tree* t);
int countLeaves(Tree* t);
int sumLeaves(Tree* t);
