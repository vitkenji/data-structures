#include "heap.h"
#define SIZE 10

int main()
{
    MinHeap* h = createMinHeap(10);
    
    for(int i = 0; i < 10; i++)
    {
        h->array[i] = 10 - i;
    }
    printHeap(h);
    buildMinHeap(h);
    printHeap(h);
    return 0;
}