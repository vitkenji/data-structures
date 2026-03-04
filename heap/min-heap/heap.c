#include "heap.h"

MinHeap* createMinHeap(int size)
{
    MinHeap* h = (MinHeap*) malloc(sizeof(MinHeap));
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

void minHeapify(MinHeap* h, int index)
{
    int l = left(index);
    int r = right(index);
    int smallest;

    if(l < h->size && h->array[l] < h->array[index]) // which one is smaller: left or parent
    {
        smallest = l;
    }
    else
    {
        smallest = index;
    }

    if(r < h->size && h->array[r] < h->array[smallest]) // which one is smaller: left, parent, or right
    {
        smallest = r;
    }
    if(smallest != index)
    {
        swap(h, smallest, index); // places the smallest in parent position
        minHeapify(h, smallest); 
    }
}

void buildMinHeap(MinHeap* h)
{
    for(int i = (h->size / 2) - 1; i >= 0; i--) // i = 4,3,2,1,0
    {
        minHeapify(h, i);
    }
}

void swap(MinHeap* h, int pos1, int pos2)
{
    int aux = h->array[pos1];
    int aux_index = h->index[pos1];

    h->array[pos1] = h->array[pos2];
    h->index[pos1] = h->index[pos2];

    h->array[pos2] = aux;
    h->index[pos2] = aux_index;
}

void printHeap(MinHeap* h)
{
    printf("Heap: ");
    for(int i = 0; i != h->size; i++)
    {
        printf("%d ", h->array[i]);
    }
    printf("\n");
}