#include "priorityQueue.h"
#define SIZE 10

int main()
{
    int size = SIZE;
    int* array = (int*) malloc(sizeof(int)*size);
    for(int i = 0; i < size; i++)
    {
        array[i] = 10 - i;
    }
    buildMinHeap(array, size);
    printArray(array, size);
    minHeapInsert(array, &size, 0);
    printArray(array, size);
    return 0;
}