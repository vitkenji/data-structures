#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int* array;
    int* index;

}MaxHeap;

MaxHeap* createMaxHeap(int size);

int parent(int i);
int left(int i);
int right(int i);
void maxHeapify(MaxHeap* h, int index);
void buildMaxHeap(MaxHeap* h);

void swap(MaxHeap* h, int pos1, int pos2);
void printHeap(MaxHeap* h);
