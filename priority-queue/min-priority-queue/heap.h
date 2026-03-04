#include <stdio.h>
#include <stdlib.h>

int parent(int i);
int left(int i);
int right(int i);
void maxHeapify(int* array, int size, int index);
void minHeapify(int* array, int size, int index);
void buildMaxHeap(int* array, int size);
void buildMinHeap(int* array, int size);

void swap(int* array, int pos1, int pos2);
void printArray(int* array, int size);
