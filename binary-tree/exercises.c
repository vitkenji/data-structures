#include "exercises.h"

int height(Tree* t)
{
    if(t == NULL)
    {
        return 0;
    }
    int left = height(t->left);
    int right = height(t->right);
    return left > right ? left + 1 : right + 1;
}
