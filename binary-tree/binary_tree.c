#include "binary_tree.h"

Tree* createTree()
{
    return NULL;
}

Tree* insertNode(int data, Tree* left, Tree* right)
{
    Tree* node = (Tree*) malloc(sizeof(Tree));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

void preOrder(Tree* t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void inOrder(Tree* t)
{
    if (t != NULL)
    {
        inOrder(t->left);
        printf("%d ", t->data);
        inOrder(t->right);
    }
}

void postOrder(Tree* t)
{
    if (t != NULL)
    {
        postOrder(t->left);
        postOrder(t->right);
        printf("%d ", t->data);
    }
}