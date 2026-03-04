#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

//max heap
int heapMaximum(int* array);
int heapExtractMax(int* array, int* size);
void heapIncreaseKey(int* array, int index, int key);
void maxHeapInsert(int* array, int* size, int key);

//min heap
int heapMinimum(int* array);
int heapExtractMin(int* array, int* size);
void heapDecreaseKey(int* array, int index, int key);
void minHeapInsert(int* array, int* size, int key);

