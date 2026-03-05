#include "heap.h"

int heapMinimum(PQueue* q);
int heapExtractMin(PQueue* q);
void heapDecreaseKey(PQueue* q, int index, int key);
void minHeapInsert(PQueue* q, int key, int index);

