#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <unistd.h>

char* captureOutput(void (*traverse)(AvlTree*), AvlTree* t)
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

int shouldCreateTree()
{
    AvlTree* t = createTree();
    return t == NULL;
}

int shouldCreateNode()
{
    AvlTree* n = createNode(10);
    int result = (n != NULL && n->data == 10 && n->height == 1 && n->left == NULL && n->right == NULL);
    free(n);
    return result;
}

int shouldInsertAndBalance()
{
    AvlTree* t = createTree();
    t = insertNode(t, 10);
    t = insertNode(t, 20);
    t = insertNode(t, 30);
    return (t->data == 20 && t->left->data == 10 && t->right->data == 30);
}

int shouldPreOrder()
{
    AvlTree* t = createTree();
    t = insertNode(t, 10);
    t = insertNode(t, 20);
    t = insertNode(t, 30);
    t = insertNode(t, 40);
    t = insertNode(t, 50);
    t = insertNode(t, 25);

    char* output = captureOutput(preOrder, t);
    int result = strcmp(output, "30 20 10 25 40 50 ") == 0;
    free(output);
    return result;
}

int shouldInOrder()
{
    AvlTree* t = createTree();
    t = insertNode(t, 10);
    t = insertNode(t, 20);
    t = insertNode(t, 30);
    t = insertNode(t, 40);
    t = insertNode(t, 50);
    t = insertNode(t, 25);

    char* output = captureOutput(inOrder, t);
    int result = strcmp(output, "10 20 25 30 40 50 ") == 0;
    free(output);
    return result;
}

int shouldPostOrder()
{
    AvlTree* t = createTree();
    t = insertNode(t, 10);
    t = insertNode(t, 20);
    t = insertNode(t, 30);
    t = insertNode(t, 40);
    t = insertNode(t, 50);
    t = insertNode(t, 25);

    char* output = captureOutput(postOrder, t);
    int result = strcmp(output, "10 25 20 50 40 30 ") == 0;
    free(output);
    return result;
}

int main()
{
    int tests_passed = 0;
    int tests_failed = 0;

    shouldCreateTree()      ? tests_passed++ : tests_failed++;
    shouldCreateNode()      ? tests_passed++ : tests_failed++;
    shouldInsertAndBalance() ? tests_passed++ : tests_failed++;
    shouldPreOrder()        ? tests_passed++ : tests_failed++;
    shouldInOrder()         ? tests_passed++ : tests_failed++;
    shouldPostOrder()       ? tests_passed++ : tests_failed++;

    printf("\n%d Tests passed\n", tests_passed);
    printf("%d Tests failed\n", tests_failed);

    return 0;
}
