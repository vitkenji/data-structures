#include "dllist.h"

DLList* create()
{
    return NULL;

}

DLList* insertBack(DLList* l, int data)
{
    DLList* node = (DLList*)malloc(sizeof(DLList));
    node->data = data;
    node->next = l;
    node->prev = NULL;
    if(l != NULL){l->prev = node;}
    return node;
}

DLList* insertFront(DLList* l, int data)
{
    DLList* node = (DLList*)malloc(sizeof(DLList));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    if(l == NULL){return node;}
    
    DLList* t = l;
    if (t == NULL)
    {
        return node;
    }
    while(t->next != NULL){t = t->next;}
    t->next = node;
    node->prev = t;

    return l;
}

void printDLList(DLList* l)
{
    printf("DLList: ");

    DLList* t = l;
    while(t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");

}

DLList* search(DLList* l, int data)
{
    if(l != NULL)
    {
        DLList* t = l;
        DLList* p = t;
        while(t != NULL)
        {
            if(t->data == data)
            {
                return t;
            }
            t = t->next;
        }
    }
    printf("%d not found\n", data);
    return NULL;
}

DLList* removeData(DLList* l, int data)
{
    DLList* t = l;
    
    while (t != NULL && t->data != data)
    {
        t = t->next;
    }

    if(t == NULL)
    {
        return l;   
    }

    else if (t->prev == NULL)
    {
        l = t->next;
        if(t->next != NULL)
        {
            t->next->prev = NULL;
        }
    }
    else if (t->next == NULL)
    {  
        t->prev->next = NULL;
    }
    else
    {
        t->prev->next = t->next;
        t->next->prev = t->prev;
    }
    free(t);
    return l;

}