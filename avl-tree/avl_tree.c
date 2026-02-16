#include "avl_tree.h"

void preOrder(AvlTree* t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void inOrder(AvlTree* t)
{
    if (t != NULL)
    {
        inOrder(t->left);
        printf("%d ", t->data);
        inOrder(t->right);
    }
}

void postOrder(AvlTree* t)
{
    if (t != NULL)
    {
        postOrder(t->left);
        postOrder(t->right);
        printf("%d ", t->data);
    }
}

AvlTree* createTree()
{
    return NULL;
}

AvlTree* createNode(int data)
{
    AvlTree* node = (AvlTree*) malloc(sizeof(AvlTree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

AvlTree* insertNode(AvlTree* t, int data)
{
    if (t == NULL)
    {
        return createNode(data);
    }
    if(data < t->data)
    {
        t->left = insertNode(t->left, data);

    }
    else if(data > t->data)
    {
        t->right = insertNode(t->right, data);
    }
    else
    {
        return t;
    }
    
    t->height = 1 + max(height(t->left), height(t->right));

    if (balanceFactor(t) > 1 && data < t->left->data)
    {
        return rightRotation(t);
    }
    else if (balanceFactor(t) < -1 && data > t->right->data)
    {
        return leftRotation(t);
    }
    else if (balanceFactor(t) > 1 && data > t->left->data)
    {
        t->left = leftRotation(t->left);
        return rightRotation(t);
    }
    else if (balanceFactor(t) < -1 && data < t->right->data)
    {
        t->right = rightRotation(t->right);
        return leftRotation(t);
    }
    return t;

}

int height(AvlTree* t)
{
    if(t == NULL)
    {
        return 0;
    }
    return t->height;
}

int calculateHeight(AvlTree* t)
{
    if(t == NULL)
    {
        return 0;
    }
    int left = height(t->left);
    int right = height(t->right);
    return left > right ? left + 1 : right + 1;
}

int balanceFactor(AvlTree* t)
{
    if (t == NULL)
    {
        return 0;
    }
    return height(t->left) - height(t->right);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

AvlTree* leftRotation(AvlTree* t)
{
    AvlTree* aux = t->right;
    AvlTree* temp = aux->left;
    aux->left = t;
    t->right = temp;

    t->height = calculateHeight(t);
    aux->height = calculateHeight(aux);
    return aux;
}

AvlTree* rightRotation(AvlTree* t)
{
    AvlTree* aux = t->left;
    AvlTree* temp = aux->right;
    aux->right = t;
    t->left = temp;
 
    t->height = calculateHeight(t);
    aux->height = calculateHeight(aux);
    return aux;
}
