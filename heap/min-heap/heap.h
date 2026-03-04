#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int* array;
    int* index;

}MinHeap;

MinHeap* createMinHeap(int size);

int parent(int i);
int left(int i);
int right(int i);

void minHeapify(MinHeap* h, int index);
void buildMinHeap(MinHeap* h);

void swap(MinHeap* h, int pos1, int pos2);
void printHeap(MinHeap* h);
