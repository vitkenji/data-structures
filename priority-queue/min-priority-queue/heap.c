#include "heap.h"

PQueue* createPQueue(int size)
{
    PQueue* q = (PQueue*) malloc(sizeof(PQueue));
    q->array = (int*) malloc(sizeof(int) * size);
    q->index = (int*) malloc(sizeof(int) * size);
    q->size = size;
    q->n = 0;

    return q;
}

int parent(int i)
{
    return((i - 1) / 2);
}

int left(int i)
{
    return(2 * i + 1);
}

int right(int i)
{
    return (2 * i + 2);
}

void minHeapify(PQueue* q, int index)
{
    int l = left(index);
    int r = right(index);
    int smallest;

    if(l < q->n && q->array[l] < q->array[index]) // which is smaller: left or parent
    {
        smallest = l;
    }
    else
    {
        smallest = index;
    }

    if(r < q->n && q->array[r] < q->array[smallest]) // which is the smallest: left, right or parent
    {
        smallest = r;
    }

    if(smallest != index)
    {
        swap(q, smallest, index); // the smallest goes to parent position
        minHeapify(q, smallest); 
    }
}

void buildMinHeap(PQueue* q)
{
    for(int i = (q->n / 2) - 1; i >= 0; i--)
    {
        minHeapify(q, i);
    }
}

void swap(PQueue* q, int pos1, int pos2)
{
    int aux = q->array[pos1];
    int aux_index = q->index[pos1];

    q->array[pos1] = q->array[pos2];
    q->index[pos1] = q->index[pos2];

    q->array[pos2] = aux;
    q->index[pos2] = aux_index;
}

void printPQueue(PQueue* q)
{
    printf("Priority Queue:\n");
    printf("Index: ");
    for(int i = 0; i < q->n; i++)
    {
        printf("%d ", q->index[i]);
    }
    printf("\nData:  ");
    for(int i = 0; i < q->n; i++)
    {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}