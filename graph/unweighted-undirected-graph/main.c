#include "graph.h"

int main()
{
    LGraph* LG = create_L(6);

    insertEdge_L(LG, 0, 1);
    insertEdge_L(LG, 1, 2);
    insertEdge_L(LG, 2, 0);
    insertEdge_L(LG, 2, 3);
    insertEdge_L(LG, 2, 4);
    insertEdge_L(LG, 4, 5);

    MGraph* MG = create_M(6);

    insertEdge_M(MG, 0, 1);
    insertEdge_M(MG, 0, 2);
    insertEdge_M(MG, 0, 3);
    insertEdge_M(MG, 0, 4);
    insertEdge_M(MG, 0, 5);

    print_L(LG);
    print_M(MG);
    
    return 0;
}