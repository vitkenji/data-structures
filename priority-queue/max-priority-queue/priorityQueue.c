#include "priorityQueue.h"

int heapMaximum(PQueue* q)
{
    if(q->n == 0)
    {
        printf("Empty queue\n");
        exit(1);
    }
    return q->array[0];
}

int heapExtractMax(PQueue* q)
{
    if(q->n < 1)
    {
        printf("Error: heap underflow\n");
        exit(1);
    }
    int max = q->array[0];
    q->array[0] = q->array[q->n - 1];
    q->index[0] = q->index[q->n - 1];
    q->n--;
    maxHeapify(q, 0);
    return max;
}

void heapIncreaseKey(PQueue* q, int index, int key)
{
    if(key < q->array[index])
    {
        printf("Error: new key is lower than actual key\n");
        exit(1);
    }
    q->array[index] = key;
    
    while(index > 0 && q->array[parent(index)] < q->array[index])
    {
        swap(q, index, parent(index));
        index = parent(index);
    }
}

void maxHeapInsert(PQueue* q, int key, int index)
{
    if(q->n >= q->size)
    {
        printf("Error: heap overflow\n");
        return;
    }
    q->n++;
    q->index[q->n - 1] = index;
    q->array[q->n - 1] = -INT_MAX;
    heapIncreaseKey(q, q->n - 1, key);
}

