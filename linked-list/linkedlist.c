#include "linkedlist.h"

List* create()
{
    return NULL;

}

List* insert(List* l, int data)
{
    List* node = (List*)malloc(sizeof(List));
    node->next = l;
    node->data = data;

    return node;
}

List* search(List* l, int data)
{
    if(l != NULL)
    {
        List* t = l;
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


List* removeData(List* l, int data)
{
    List* t = l;
    List* p = NULL;

    while(t != NULL && t->data != data)
    {
        p = t;
        t = t->next;
    }

    if(t == NULL){return l;}
    if(p == NULL){l = t->next;}
    else{p->next = t->next;}
    free(t);
    return l;

}

void printList(List* l)
{
    List* t = l;

    printf("List: ");
    while(t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;

    }
    printf("\n");
}