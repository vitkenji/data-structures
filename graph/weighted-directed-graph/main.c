#include "graph.h"

int main()
{
    LGraph* LG = create_L(9);

    insertEdge_L(LG, 0,1,2);
    insertEdge_L(LG, 0,3,7);
    insertEdge_L(LG, 7,8,3);
    insertEdge_L(LG, 6,7,4);
    print_L(LG);

    MGraph* MG = create_M(6);

    insertEdge_M(MG, 0, 1, 2);
    insertEdge_M(MG, 1, 2, 3);
    insertEdge_M(MG, 2, 3, 6);
    insertEdge_M(MG, 3, 0, 8);
    insertEdge_M(MG, 0, 4, 4);
    insertEdge_M(MG, 1, 4, 5);
    insertEdge_M(MG, 2, 5, 7);

    print_M(MG);
    
    return 0;
}