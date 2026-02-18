#include "exercises.h"

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