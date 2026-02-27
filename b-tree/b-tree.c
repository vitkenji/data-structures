#include "b-tree.h"

BTree* createTree()
{
    return NULL;
}

BTree* insert(BTree* tree, int key)
{
    if(tree == NULL)
    {
        tree = createNode(1);
        tree->data[0] = key;
        tree->n = 1;
        return tree;
    }

    if(tree->n == M - 1)
    {
        BTree* new_root = createNode(0);
        new_root->children[0] = tree;

        splitChild(new_root, 0, tree);

        int i = 0;
        if(key > new_root->data[0])
        {
            i = 1;
        }

        insertNonFull(new_root->children[i], key);
        
        return new_root;
    }

    else
    {
        insertNonFull(tree, key);
        return tree;
    }
}

BTree* createNode(int leaf)
{
    BTree* node = (BTree*) malloc(sizeof(BTree));
    node->leaf = leaf;
    node->n = 0;
    for(int i = 0; i < M; i++)
    {
        node->children[i] = NULL;
    }
    for(int i = 0; i < M - 1; i++)
    {
        node->data[i] = 0;
    }
    return node;
}

void splitChild(BTree* parent, int i, BTree* fullChild)
{
    int mid = (M - 1) / 2;
    BTree* new_node = createNode(fullChild->leaf);
    new_node->n = (M - 1) - mid - 1;
    for (int j = 0; j < new_node->n; j++)
    {
        new_node->data[j] = fullChild->data[j + mid + 1];
    }

    if (!fullChild->leaf)
    {
        for(int j = 0; j <= new_node->n; j++)
        {
            new_node->children[j] = fullChild->children[j + mid + 1];
        }
    }

    fullChild->n = mid;

    for(int j = parent->n; j >= i + 1; j--)
    {
        parent->children[j + 1] = parent->children[j];
    }
    
    parent->children[i + 1] = new_node;
    
    for(int j = parent->n - 1; j >= i; j--)
    {
        parent->data[j + 1] = parent->data[j];
    }

    parent->data[i] = fullChild->data[mid];
    parent->n++;
}

void insertNonFull(BTree* node, int key)
{
    int i = node->n - 1;

    if(node->leaf)
    {
        while(i >= 0 && key < node->data[i])
        {
            node->data[i + 1] = node->data[i];
            i--;
        }
        node->data[i + 1] = key;
        node->n++;
    }

    else
    {
        while(i >= 0 && key < node->data[i])
        {
            i--;
        }

        i++;

        if(node->children[i] && node->children[i]->n == M - 1)
        {
            splitChild(node, i, node->children[i]);
            
            if(key > node->data[i])
            {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}


int findKey(BTree* node, int key)
{
    int index = 0;
    while(index < node->n && node->data[index] < key)
    {
        index++;
    }
    return index;

}

void removeFromNode(BTree* node, int key)
{
    int index = findKey(node, key);
    
    if(index < node->n && node->data[index] ==  key)
    {
        node->leaf ? removeFromLeaf(node, index) : removeFromNonLeaf(node, index);
    }
    else
    {
        if(node->leaf)
        {
            printf("error: key not found");
            return;
        }
        int flag = index == node->n;
        if(node->children[index] && node->children[index]->n < (M + 1)/2 - 1)
        {
            fill(node, index);
        }

        if(flag && index > node->n)
        {
            removeFromNode(node->children[index -1], key);
        }
        else
        {
            removeFromNode(node->children[index], key);
        }
    }
}

void removeFromLeaf(BTree* node, int index)
{
    for(int i = index + 1; i < node->n; i++)
    {
        node->data[i - 1] = node->data[i];
    }
    node->n--;

}

void removeFromNonLeaf(BTree* node, int index)
{
    int key = node->data[index];
    int MIN_KEYS = (M + 1)/2 - 1;
    if(node->children[index]->n >= MIN_KEYS + 1)
    {
        int pred = getPredecessor(node, index);
        node->data[index] = pred;
        removeFromNode(node->children[index], pred);
    }

    else if(node->children[index + 1]->n >= MIN_KEYS + 1)
    {
        int succ = getSuccessor(node, index);
        node->data[index] = succ;
        removeFromNode(node->children[index + 1], succ);
    }

    else
    {
        merge(node, index);
        removeFromNode(node->children[index], key);
    }
}

void merge(BTree* node, int index)
{
    BTree* child = node->children[index];
    BTree* sibling = node->children[index + 1];

    child->data[child->n] = node->data[index];

    for(int i = 0; i < sibling->n; i++)
    {
        child->data[i + child->n + 1] = sibling->data[i];
    }

    if(!child->leaf)
    {
        for(int i = 0; i <= sibling->n; i++)
        {
            child->children[i + child->n + 1] = sibling->children[i];
        }
    }

    for(int i = index + 1; i < node->n; i++)
    {
        node->data[i - 1] = node->data[i];
    }

    for(int i = index + 2; i <= node->n; i++)
    {
        node->children[i - 1] = node->children[i];
    }

    child->n += sibling->n + 1;
    node->n--;
    node->children[node->n + 1] = NULL;
    free(sibling);

}

void fill(BTree* node, int index)
{
    int MIN_KEYS = (M + 1)/2 - 1;
    
    if(index != 0 && node->children[index - 1]->n > MIN_KEYS)
    {
        borrowFromPrev(node, index);
    }

    else if(index != node->n && node->children[index + 1]->n > MIN_KEYS)
    {
        borrowFromNext(node, index);
    }

    else
    {
        if(index != node->n)
        {
            merge(node, index);
        }
        else
        {
            merge(node, index - 1);
        }
    }
}

int getPredecessor(BTree* node, int index)
{
    BTree* cur = node->children[index];
    while(!cur->leaf)
    {
        cur = cur->children[cur->n];
    }
    return cur->data[cur->n - 1];
}

int getSuccessor(BTree* node, int index)
{
    BTree* cur = node->children[index + 1];
    while(!cur->leaf)
    {
        cur = cur->children[0];
    }
    return cur->data[0];
}

void borrowFromPrev(BTree* node, int index)
{
    BTree* child = node->children[index];
    BTree* sibling = node->children[index - 1];

    for(int i = child->n - 1; i >= 0; i--)
    {
        child->data[i + 1] = child->data[i];
    }

    if(!child->leaf)
    {
        for(int i = child->n; i >= 0; i--)
        {
            child->children[i + 1] = child->children[i];
        }
    }

    child->data[0] = node->data[index - 1];

    if(!child->leaf)
    {
        child->children[0] = sibling->children[sibling->n];
    }

    node->data[index - 1] = sibling->data[sibling->n - 1];

    child->n++;
    sibling->n--;

}

void borrowFromNext(BTree* node, int index)
{
    BTree* child = node->children[index];
    BTree* sibling = node->children[index + 1];
    child->data[child->n] = node->data[index];

    if(!child->leaf)
    {
        child->children[child->n + 1] = sibling->children[0];
    }

    node->data[index] = sibling->data[0];
    for(int i = 1; i < sibling->n; i++)
    {
        sibling->data[i - 1] = sibling->data[i];
    }

    if(!sibling->leaf)
    {
        for(int i = 1; i <= sibling->n; i++)
        {
            sibling->children[i - 1] = sibling->children[i];
        }
    }

    child->n++;
    sibling->n--;
}


BTree* removeData(BTree* tree, int data)
{
    if(!tree)
    {
        return NULL;
    }
    removeFromNode(tree,data);

    if(tree->n == 0)
    {
        BTree* tmp = tree;
        if(tree->leaf)
        {
            tree = NULL;
        }
        else
        {
            tree = tree->children[0];
        }
        free(tmp);
    }
    return tree;
}



BTree* search(BTree* tree, int data)
{
    if (tree == NULL)
    {
        //printf("\n%d not found", data);
        return NULL;  
    }

    int i = 0;
    while (i < tree->n && data > tree->data[i])
    {
        i++;
    }
    if (i < tree-> n && tree->data[i] == data)
    {
        //printf("\n%d found", data);
        return tree;
    }
    if (tree->leaf)
    {
        //printf("\n%d not found", data);
        return NULL;  
    }

    return search(tree->children[i], data);
}


void printBTree(BTree* t)
{
    if(t != NULL)
    {
        printf("\nNode: ");
        for(int i = 0; i < t->n; i++)
        {
            printf("%d ", t->data[i]);
        }
        for(int i = 0; i <= t->n; i++)
        {
            if(t->children[i] != NULL)
            printBTree(t->children[i]);
        }
    }
}
