#include "binary-tree.h"
#include "exercises.h"
#include <string.h>
#include <io.h>
#include <unistd.h>

char* captureOutput(void (*traverse)(Tree*), Tree* t)
{
    FILE* temp = fopen("local_temp_output.txt", "w+");
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
    
    if (buffer)
    {
        size_t bytesRead = fread(buffer, 1, 255, temp);
        buffer[bytesRead] = '\0'; 
    }
    
    fclose(temp);
    remove("local_temp_output.txt"); 

    return buffer;
}

int shouldPreOrder()
{
    Tree* t = insertNode(1,
                insertNode(2, insertNode(4, NULL, NULL), insertNode(5, NULL, NULL)),
                insertNode(3, NULL, NULL));

    char* output = captureOutput(preOrder, t);

    if (output == NULL)
    {
        printf("error: captureOutput failed to return a string.\n");
        return 0; 
    }

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

    if (output == NULL)
    {
        printf("error: captureOutput failed to return a string.\n");
        return 0; 
    }

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

    if (output == NULL)
    {
        printf("error: captureOutput failed to return a string.\n");
        return 0; 
    }

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

int shouldCountNodes()
{
    Tree* t = insertNode(1,
                insertNode(2, insertNode(4, NULL, NULL), NULL),
                insertNode(3, NULL, NULL));
    
    int result = countNodes(t);
    return result == 4;
}

int shouldCalculateHeight()
{
    Tree* t = insertNode(1,
                insertNode(2, insertNode(4, NULL, NULL), insertNode(5, NULL, NULL)),
                insertNode(3, NULL, NULL));
    
    int result = calculateHeight(t);
    return result == 3;
}

int shouldCountLeaves()
{
    Tree* t = insertNode(1,
                insertNode(2, insertNode(4, NULL, NULL), insertNode(5, NULL, NULL)),
                insertNode(3, NULL, NULL));
    
    int result = countLeaves(t);
    return result == 3;
}

int shouldSumLeaves()
{
    Tree* t = insertNode(10,
                insertNode(20, insertNode(5, NULL, NULL), insertNode(5, NULL, NULL)),
                insertNode(30, NULL, NULL));
    
    int result = sumLeaves(t);
    return result == 40; 
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
    shouldCountNodes() == 1 ? tests_passed++ : tests_failed++;
    shouldCalculateHeight() == 1 ? tests_passed++ : tests_failed++;
    shouldCountLeaves() == 1 ? tests_passed++ : tests_failed++;
    shouldSumLeaves() == 1 ? tests_passed++ : tests_failed++;

    printf("%d Tests passed\n", tests_passed);
    printf("%d Tests failed\n", tests_failed);

    return 0;
}