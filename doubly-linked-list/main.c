#include "dllist.h"
int shouldInsertBack()
{
    DLList* l = create();
    l = insertBack(l, 10);
    l = insertBack(l, 20);
    l = insertBack(l,30);
    //printDLList(l);
    return l->data == 30;
}

int shouldInsertFront()
{
    DLList* l = create();
    l = insertFront(l, 10);
    l = insertFront(l, 20);
    l = insertFront(l, 30);
    //printDLList(l);
    return l->data == 10;
}

int shouldRemove()
{
    DLList* l = create();
    for (int i = 1; i <= 5; i++)
    {
        l = insertFront(l, i * 10);
    }
    //printDLList(l);
    l = removeData(l, 30);
    //printDLList(l);
    return search(l, 30) == NULL;
}

int shouldSearch()
{
    DLList* l = create();
    for (int i = 1; i <= 5; i++)
    {
        l = insertBack(l, i * 10);
    }
    return search(l, 30)->data == 30;
}

int fullTest()
{
    DLList* l = create();
    
    l = insertFront(l, 20);
    l = insertBack(l, 30);
    l = insertFront(l, 10);
    
    if (search(l, 10) == NULL || search(l, 30) == NULL) return 0;
    
    l = removeData(l, 20);
    if (search(l, 20) != NULL) return 0;
    
    l = removeData(l, 10);
    l = removeData(l, 30);
    
    return l == NULL;
}
  
int main()
{
    int tests_passed = 0;
    int tests_failed = 0;
    
    shouldInsertBack() == 1 ? tests_passed++ : tests_failed++;
    shouldInsertFront() == 1 ? tests_passed++ : tests_failed++;
    shouldSearch() == 1 ? tests_passed++ : tests_failed++;
    shouldRemove() == 1 ? tests_passed++ : tests_failed++;
    fullTest() == 1 ? tests_passed++ : tests_failed++;
    
    printf("%d Tests passed\n", tests_passed);
    printf("%d Tests failed\n", tests_failed);


    return 0;
}