#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int size;
    int n;
    int* array;
    int* index;

} PQueue;

PQueue* createPQueue(int size);

int parent(int i);
int left(int i);
int right(int i);
void maxHeapify(PQueue* q, int index);
void buildMaxHeap(PQueue* q);

void swap(PQueue* q, int pos1, int pos2);
void printPQueue(PQueue* q);