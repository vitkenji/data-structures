#include "heap.h"

MaxHeap* createMaxHeap(int size)
{
    MaxHeap* h = (MaxHeap*) malloc(sizeof(MaxHeap));
    h->array = (int*) malloc(sizeof(int) * size);
    h->index = (int*) malloc(sizeof(int) * size);
    h->size = size;

    return h;
}

int parent(int i)
{
    return((i - 1) / 2);
}

int left(int i)
{
    return(2*i + 1);
}

int right(int i)
{
    return (2*i + 2);
}

void maxHeapify(MaxHeap* h, int index)
{
    int l = left(index);
    int r = right(index);
    int biggest;

    if(l < h->size && h->array[l] > h->array[index])
    {
        biggest = l;
    }
    else
    {
        biggest = index;
    }
    if(r < h->size && h->array[r] > h->array[biggest])
    {
        biggest = r;
    }
    if(biggest != index)
    {
        swap(h, biggest, index);
        maxHeapify(h, biggest);
    }
}

void buildMaxHeap(MaxHeap* h)
{
    for(int i = (h->size / 2) - 1; i >= 0; i--)
    {
        maxHeapify(h,  i);
    }
}

void swap(MaxHeap* h, int pos1, int pos2)
{
    int aux = h->array[pos1];
    int aux_index = h->index[pos1];

    h->array[pos1] = h->array[pos2];
    h->index[pos1] = h->index[pos2];

    h->array[pos2] = aux;
    h->index[pos2] = aux_index;
}

void printHeap(MaxHeap* h)
{
    printf("Heap: ");
    for(int i = 0; i != h->size; i++)
    {
        printf("%d ", h->array[i]);
    }
    printf("\n");
}