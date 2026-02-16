#include "binaryTree.h"

Tree* createTree()
{
    return NULL;

}

Tree* buildTree(int data, Tree* left, Tree* right)
{
    Tree* t = (Tree*) malloc(sizeof(Tree));
    t->data = data;
    t->left = left;
    t->right = right;

    return t;

}

void preOrder(Tree* t)
{
    if(t != NULL)
    {
        printf("%d ", t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void inOrder(Tree* t)
{
    if(t != NULL)
    {
        inOrder(t->left);
        printf("%d ", t->data);
        inOrder(t->right);
    }
}

void postOrder(Tree* t)
{
    if(t != NULL)
    {
        postOrder(t->left);
        postOrder(t->right);
        printf("%d ", t->data);
    }
}

int search(Tree* t, int data)
{
    if(t != NULL)
    {
        if(t->data == data)
        {
            return 1;
        }
        else
        {
            int l, r;
            l = search(t->left, data);
            r = search(t->right, data);
            if(l == 1 || r == 1)
            {
                return 1;
            }
        }

        
        
    }
    return 0;
}

int countNodes(Tree* t)
{
    if(t != NULL)
    {
        return (1 + countNodes(t->left) + countNodes(t->right));
    }
    return 0;

}

int countLeaves(Tree* t)
{
    if(t != NULL)
    {
        if(t->left == NULL && t->right == NULL)
        {
            return 1;
        }
        else
        {
            return countLeaves(t->left) + countLeaves(t->right);
        }
        
    }
    return 0;
}

int calculateHeight(Tree* t)
{
    if(t != NULL)
    {
        int leftHeight = calculateHeight(t->left);
        int rightHeight = calculateHeight(t->right);

        if(leftHeight > rightHeight)
        {
            return 1 + leftHeight;

        }
        else
        {
            return 1 + rightHeight;
        }
    }
    return 0;
}

int sumLeaves(Tree* t)
{
    if(t != NULL)
    {
         if(t->left == NULL && t->right == NULL)
        {
            return t->data;
        }
         else
        {
            return sumLeaves(t->left) + sumLeaves(t->right);
        }
    }
    return 0;
}