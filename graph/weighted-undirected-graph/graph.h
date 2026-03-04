#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int index;
    int weight;
    struct node* next;

}Node;

typedef struct Lgraph{
    int E;
    int V;
    Node** adj;
    
}LGraph;

LGraph* create_L(int n);
void insertEdge_L(LGraph* G, int v1, int v2, int weight);
void removeEdge_L(LGraph* G, int v1, int v2);
void print_L(LGraph* G);

typedef struct Mgraph{
    int E;
    int V;
    int** matrix;

}MGraph;

MGraph* create_M(int n);
void insertEdge_M(MGraph* G, int v1, int v2, int weight);
void removeEdge_M(MGraph* G, int v1, int v2);
void print_M(MGraph* G);