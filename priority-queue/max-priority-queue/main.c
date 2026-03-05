#include "priorityQueue.h"

int shouldInsertAndGetMaximum()
{
    PQueue* q = createPQueue(5);
    maxHeapInsert(q, 10, 0);
    maxHeapInsert(q, 25, 1);
    maxHeapInsert(q, 15, 2);

    return heapMaximum(q) == 25;
}

int shouldExtractMax()
{
    PQueue* q = createPQueue(5);
    maxHeapInsert(q, 20, 0);
    maxHeapInsert(q, 10, 1);
    maxHeapInsert(q, 30, 2);

    int firstMax = heapExtractMax(q);
    int secondMax = heapExtractMax(q);

    return firstMax == 30 && secondMax == 20;
}

int shouldIncreaseKey()
{
    PQueue* q = createPQueue(5);
    maxHeapInsert(q, 20, 0);
    maxHeapInsert(q, 30, 1);
    maxHeapInsert(q, 10, 2);

    heapIncreaseKey(q, 2, 50);

    return heapMaximum(q) == 50;
}

int fullTest()
{
    PQueue* q = createPQueue(10);
    
    maxHeapInsert(q, 20, 0);
    maxHeapInsert(q, 40, 1);
    maxHeapInsert(q, 60, 2);
    maxHeapInsert(q, 80, 3);
    maxHeapInsert(q, 100, 4);

    printPQueue(q);

    if (heapExtractMax(q) != 100) { return 0; }
    if (heapExtractMax(q) != 80) { return 0; }

    printPQueue(q);

    maxHeapInsert(q, 90, 5);
    maxHeapInsert(q, 95, 6);

    printPQueue(q);

    heapIncreaseKey(q, 3, 120);

    if (heapExtractMax(q) != 120) { return 0; }
    if (heapExtractMax(q) != 95) { return 0; }

    printPQueue(q);

    return heapMaximum(q) == 90;
}

int main()
{
    int tests_passed = 0;
    int tests_failed = 0;

    shouldInsertAndGetMaximum() == 1 ? tests_passed++ : tests_failed++;
    shouldExtractMax() == 1 ? tests_passed++ : tests_failed++;
    shouldIncreaseKey() == 1 ? tests_passed++ : tests_failed++;
    fullTest() == 1 ? tests_passed++ : tests_failed++;

    printf("%d Tests passed\n", tests_passed);
    printf("%d Tests failed\n", tests_failed);

    return 0;
}