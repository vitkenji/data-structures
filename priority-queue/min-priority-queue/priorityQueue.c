#include "priorityQueue.h"

int heapMinimum(PQueue* q)
{
    if(q->n == 0)
    {
        printf("Empty queue\n");
        exit(1);
    }
    return q->array[0];
}

int heapExtractMin(PQueue* q)
{
    if(q->n < 1)
    {
        printf("Error: heap underflow\n");
        exit(1);
    }
    int min = q->array[0];
    q->array[0] = q->array[q->n - 1];
    q->index[0] = q->index[q->n - 1];
    q->n--;
    minHeapify(q, 0);
    return min;
}

void heapDecreaseKey(PQueue* q, int index, int key)
{
    if(key > q->array[index])
    {
        printf("Error: new key is higher than actual key\n");
        exit(1);
    }
    q->array[index] = key;

    while(index > 0 && q->array[parent(index)] > q->array[index])
    {
        swap(q, index, parent(index));
        index = parent(index);
    }
}

void minHeapInsert(PQueue* q, int key, int index)
{
    if(q->n >= q->size)
    {
        printf("Error: heap overflow\n");
        return;
    }
    q->n++;
    q->index[q->n - 1] = index;
    q->array[q->n - 1] = +INT_MAX;
    heapDecreaseKey(q, q->n - 1, key);
}