#include "priorityQueue.h"

int heapMaximum(int* array)
{
    return array[0];
}

int heapExtractMax(int* array, int* size)
{
    if(*size < 1)
    {
        printf("heap underflow");
        exit(1);
    }
    int max = array[0];
    array[0] = array[*size -1];
    (*size)--;
    maxHeapify(array, *size, 0);
    return max;
}

void heapIncreaseKey(int* array, int index, int key)
{
    if(key < array[index])
    {
        printf("new key is lower than actual key");
        exit(1);
    }
    array[index] = key;
    
    while(index > 0 && array[parent(index)] < array[index])
    {
        swap(array, index, parent(index));
        index = parent(index);
    }
}

void maxHeapInsert(int* array, int* size, int key)
{
    (*size)++;
    array[(*size)] = -INT_MAX;
    heapIncreaseKey(array, (*size) - 1, key);
}

int heapMinimum(int* array)
{
    return array[0];
}

int heapExtractMin(int* array, int* size)
{
    if(*size < 1)
    {
        printf("heap underflow");
        exit(1);
    }
    int min = array[0];
    array[0] = array[*size - 1];
    (*size)--;
    minHeapify(array, *size, 0);
    return min;

}

void heapDecreaseKey(int* array, int index, int key)
{
    if(key > array[index])
    {
        printf("new key is higher than actual key");
        exit(1);
    }
    array[index] = key;
    while(index > 0 && array[parent(index)] > array[index])
    {
        swap(array, index, parent(index));
        index = parent(index);
    }

}

void minHeapInsert(int* array, int* size, int key)
{
    (*size)++;
    array[(*size)] = -INT_MAX;
    heapDecreaseKey(array, *size - 1, key);
}