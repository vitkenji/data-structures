#include "binary_tree.h"
#include <string.h>
#include "exercises.h"

char* captureOutput(void (*traverse)(Tree*), Tree* t)
{
    FILE* temp = tmpfile();
    if (!temp) return NULL;

    fflush(stdout);
    int stdout_fd = dup(fileno(stdout));
    dup2(fileno(temp), fileno(stdout));

    traverse(t);

    fflush(stdout);
    dup2(stdout_fd, fileno(stdout));
    close(stdout_fd);

    fseek(temp, 0, SEEK_SET);
    char* buffer = malloc(256);
    fread(buffer, 1, 255, temp);
    buffer[255] = '\0';
    fclose(temp);

    return buffer;
}

int shouldPreOrder()
{
    Tree* t = insertNode(1,
                insertNode(2, insertNode(4, NULL, NULL), insertNode(5, NULL, NULL)),
                insertNode(3, NULL, NULL));

    char* output = captureOutput(preOrder, t);
    int result = strcmp(output, "1 2 4 5 3 ") == 0;
    free(output);
    return result;
}

int shouldInOrder()
{
    Tree* t = insertNode(1,
                insertNode(2, insertNode(4, NULL, NULL), insertNode(5, NULL, NULL)),
                insertNode(3, NULL, NULL));

    char* output = captureOutput(inOrder, t);
    int result = strcmp(output, "4 2 5 1 3 ") == 0;
    free(output);
    return result;
}

int shouldPostOrder()
{
    Tree* t = insertNode(1,
                insertNode(2, insertNode(4, NULL, NULL), insertNode(5, NULL, NULL)),
                insertNode(3, NULL, NULL));

    char* output = captureOutput(postOrder, t);
    int result = strcmp(output, "4 5 2 3 1 ") == 0;
    free(output);
    return result;
}

int shouldCreateTree()
{
    Tree* t = createTree();
    return t == NULL;
}

int shouldInsertNode()
{
    Tree* t = createTree();
    t = insertNode(10, insertNode(20, NULL, NULL), insertNode(30, NULL, NULL));
    return (t->data == 10 && t->left->data == 20 && t->right->data == 30);
}



int main()
{
    int tests_passed = 0;
    int tests_failed = 0;
    shouldCreateTree() == 1 ? tests_passed++ : tests_failed++;
    shouldInsertNode() == 1 ? tests_passed++ : tests_failed++;
    shouldPreOrder() == 1 ? tests_passed++ : tests_failed++;
    shouldInOrder() == 1 ? tests_passed++ : tests_failed++;
    shouldPostOrder() == 1 ? tests_passed++ : tests_failed++;
    printf("%d Tests passed\n", tests_passed);
    printf("%d Tests failed\n", tests_failed);

    return 0;
}