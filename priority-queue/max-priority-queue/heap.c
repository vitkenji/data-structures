#include "heap.h"

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

void maxHeapify(int* array, int size, int index)
{
    int l = left(index);
    int r = right(index);
    int biggest;

    if(l < size && array[l] > array[index])
    {
        biggest = l;
    }
    else
    {
        biggest = index;
    }
    if(r < size && array[r] > array[biggest])
    {
        biggest = r;
    }
    if(biggest != index)
    {
        swap(array, biggest, index);
        maxHeapify(array, size, biggest);
    }
}

void buildMaxHeap(int* array, int size)
{
    for(int i = (size / 2) - 1; i >= 0; i--)
    {
        maxHeapify(array, size, i);
    }
}

void minHeapify(int* array, int size, int index)
{
    int l = left(index);
    int r = right(index);
    int smallest;

    if(l < size && array[l] < array[index]) // which one is smaller: left or parent
    {
        smallest = l;
    }
    else
    {
        smallest = index;
    }

    if(r < size && array[r] < array[smallest]) // which one is smaller: left, parent, or right
    {
        smallest = r;
    }
    if(smallest != index)
    {
        swap(array, smallest, index); // places the smallest in parent position
        minHeapify(array, size, smallest); 
    }
}

void buildMinHeap(int* array, int size)
{
    for(int i = (size / 2) - 1; i >= 0; i--) // i = 4,3,2,1,0
    {
        minHeapify(array, size, i);
    }
}

void swap(int* array, int pos1, int pos2)
{
    int aux = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = aux;
}

void printArray(int* array, int size)
{
    printf("array: ");
    for(int i = 0; i != size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}