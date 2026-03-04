#include "heap.h"

int main()
{
    MaxHeap* h = createMaxHeap(10);
    
    for(int i = 0; i < 10; i++)
    {
        h->array[i] = i;
    }
    printHeap(h);
    buildMaxHeap(h);
    printHeap(h);

    return 0;
}