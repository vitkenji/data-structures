#include "b-tree.h"

int shouldCreateTree()
{
    BTree* t = createTree();
    return t == NULL;
}
int shouldInsert()
{
    BTree* t = NULL;
    
    t = insert(t, 10);
    t = insert(t, 20);
    t = insert(t, 5);

    int success = (t != NULL);
    success = success && (search(t, 10) != NULL);
    success = success && (search(t, 20) != NULL);
    success = success && (search(t, 5) != NULL);

    return success;
}

int shouldSearch()
{
    BTree* t = createTree();
    
    t = insert(t, 50);
    t = insert(t, 30);
    t = insert(t, 70);
    t = insert(t, 10);

    BTree* found = search(t, 70);
    BTree* notFound = search(t, 99);

    return (found != NULL && notFound == NULL);
}

int shouldRemoveData()
{
    BTree* t = createTree();
    
    t = insert(t, 100);
    t = insert(t, 200);
    t = insert(t, 300);
    t = insert(t, 400);

    t = removeData(t, 200);

    BTree* found100 = search(t, 100);
    BTree* found200 = search(t, 200); 
    BTree* found300 = search(t, 300);
    BTree* found400 = search(t, 400);

    return (found200 == NULL && found100 != NULL && found300 != NULL && found400 != NULL);
}

void fullTest()
{
  BTree* t = createTree();

    t = insert(t, 5);
    t = insert(t, 4);
    t = insert(t, 3);

    printBTree(t);
}

int main()
{
    int tests_passed = 0;
    int tests_failed = 0;
    shouldCreateTree() == 1 ? tests_passed++ : tests_failed++;
    shouldInsert() == 1 ? tests_passed++ : tests_failed++;
    shouldSearch() == 1 ? tests_passed++ : tests_failed++;
    shouldRemoveData() == 1 ? tests_passed++ : tests_failed++;

    printf("\n%d Tests passed", tests_passed);
    printf("\n%d Tests failed", tests_failed);

    fullTest();

   return 0;
}