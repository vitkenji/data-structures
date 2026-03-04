#include "graph.h"

LGraph* create_L(int n)
{
    LGraph* G = (LGraph*) malloc(sizeof(LGraph));
    G->V = n;
    G->E = 0;
    G->adj =  (Node**) malloc(sizeof(Node*) * n);
    for(int i = 0; i < n; i++)
    {
        G->adj[i] = NULL;
    }
    return G;
}

void insertEdge_L(LGraph* G, int v1, int v2, int weight)
{
    if(v1 >= G->V || v2 >= G->V || v1 < 0 || v2 < 0)
    {
        printf("error: node doesn't exist");
        return;
    }

    Node* node = G->adj[v1];
    while(node != NULL)
    {
        if(node->index == v2)
        {
            return;
        }
        node = node->next;
    }

    node = G->adj[v2];
    while(node != NULL)
    {
        if(node->index == v1)
        {
            return;
        }
        node = node->next;
    }

    Node* inserted_1 = (Node*) malloc(sizeof(Node));
    inserted_1->index = v2;
    inserted_1->weight = weight;
    inserted_1->next = G->adj[v1];
    G->adj[v1] = inserted_1;

    Node* inserted_2 = (Node*) malloc(sizeof(Node));
    inserted_2->index = v1;
    inserted_2->weight = weight;
    inserted_2->next = G->adj[v2];
    G->adj[v2] = inserted_2;

    G->E++;
}

void removeEdge_L(LGraph* G, int v1, int v2)
{
    if(v1 >= G->V || v2 >= G->V || v1 < 0 || v2 < 0)
    {
        printf("error: node doesn't exist");
        return;
    }

    int removed = 0;

    Node* node = G->adj[v1];
    Node* prev = NULL;

    while(node != NULL)
    {
        if(node->index == v2)
        {
            if(prev == NULL)
            {
                G->adj[v1] = node->next;
            }
            else
            {
                prev->next = node->next;
            }
            free(node);
            removed = 1;
            break;
        }
        prev = node;
        node = node->next;
    }

    node = G->adj[v2];
    prev = NULL;
    while(node != NULL)
    {
        if(node->index == v1)
        {
            if(prev == NULL)
            {
                G->adj[v2] = node->next;
            }
            else
            {
                prev->next = node->next;
            }
            free(node);
            removed = 1;
            break;
        }
        prev = node;
        node = node->next;
    }
    if(removed)
    {
        G->E--;
    }
}

void print_L(LGraph* G)
{
    printf("\nGraph:\n");
    for(int i = 0; i < G->V; i++)
    {
        printf("\n %d |", i);
        Node* node = G->adj[i];
        while(node != NULL)
        {
            printf("-> %d(%d) ", node->index, node->weight);
            node = node->next;
        }
    }
    printf("\n"); 
}

MGraph* create_M(int n)
{
    MGraph* G = (MGraph*) malloc(sizeof(MGraph));
    G->V = n;
    G->E = 0;
    G->matrix = (int**) malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i ++)
    {
        G->matrix[i] = (int*) malloc(sizeof(int) * n);
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            G->matrix[i][j] = 0;
        }
    }

    return G;
}

void insertEdge_M(MGraph* G, int v1, int v2, int weight)
{  
    if(v1 >= G->V || v2 >= G->V || v1 < 0 || v2 < 0)
    {
        printf("error: node doesn't exist");
        return;
    }

    if(G->matrix[v1][v2] == 0 && G->matrix[v2][v1] == 0)
    {
        G->matrix[v1][v2] = weight;
        G->matrix[v2][v1] = weight;
        G->E++;
    }
}

void removeEdge_M(MGraph* G, int v1, int v2)
{
    if(v1 >= G->V || v2 >= G->V || v1 < 0 || v2 < 0)
    {
        printf("error: node doesn't exist");
        return;
    }

    else if(G->matrix[v1][v2] == 0)
    {
        printf("error: edge doesn't exist");
        return;
    }

    G->matrix[v1][v2] = 0;
    G->matrix[v2][v1] = 0;
    G->E--;
}

void print_M(MGraph* G)
{
    printf("\nGraph:");
    printf("\n\n   ");
    for(int i = 0; i < G->V; i++)
    {
        printf("|_%d_", i);
    } 
    printf("\n");
    for(int i = 0; i < G->V; i++)
    {
        printf("%d: ", i);
        for(int j = 0; j < G->V; j++)
        {
            printf("| %d ", G->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}