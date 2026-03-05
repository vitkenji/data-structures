#include "priorityQueue.h"

int shouldInsertAndGetMinimum()
{
    PQueue* q = createPQueue(5);
    minHeapInsert(q, 10, 0);
    minHeapInsert(q, 5, 1);
    minHeapInsert(q, 15, 2);

    return heapMinimum(q) == 5;
}

int shouldExtractMin()
{
    PQueue* q = createPQueue(5);
    minHeapInsert(q, 20, 0);
    minHeapInsert(q, 10, 1);
    minHeapInsert(q, 30, 2);

    int firstMin = heapExtractMin(q);
    int secondMin = heapExtractMin(q);

    return firstMin == 10 && secondMin == 20;
}

int shouldDecreaseKey()
{
    PQueue* q = createPQueue(5);
    minHeapInsert(q, 20, 0);
    minHeapInsert(q, 30, 1);
    minHeapInsert(q, 40, 2);

    heapDecreaseKey(q, 1, 5);

    return heapMinimum(q) == 5;
}

int fullTest()
{
    PQueue* q = createPQueue(10);
    
    minHeapInsert(q, 100, 0);
    minHeapInsert(q, 80, 1);
    minHeapInsert(q, 60, 2);
    minHeapInsert(q, 40, 3);
    minHeapInsert(q, 20, 4);

    printPQueue(q);

    if (heapExtractMin(q) != 20) { return 0; }
    if (heapExtractMin(q) != 40) { return 0; }

    printPQueue(q);

    minHeapInsert(q, 10, 5);
    minHeapInsert(q, 5, 6);

    printPQueue(q);

    heapDecreaseKey(q, 2, 2);

    if (heapExtractMin(q) != 2) { return 0; }
    if (heapExtractMin(q) != 5) { return 0; }

    printPQueue(q);

    return heapMinimum(q) == 10;
}

int main()
{
    int tests_passed = 0;
    int tests_failed = 0;

    shouldInsertAndGetMinimum() == 1 ? tests_passed++ : tests_failed++;
    shouldExtractMin() == 1 ? tests_passed++ : tests_failed++;
    shouldDecreaseKey() == 1 ? tests_passed++ : tests_failed++;
    fullTest() == 1 ? tests_passed++ : tests_failed++;

    printf("%d Tests passed\n", tests_passed);
    printf("%d Tests failed\n", tests_failed);

    return 0;
}