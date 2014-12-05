#include "MSTKruskal.h"


int main()
{
    graph g;
    int ** w;
    g = CreateGraphMST(8);
    //w = CreateGraphAM(8);
    g = AddEdgeMST(g,1,2,5);
    g = AddEdgeMST(g,7,4,5);
    g = AddEdgeMST(g,8,3,1);
    g = AddEdgeMST(g,4,2,2);
    g = AddEdgeMST(g,3,4,1);
    g = AddEdgeMST(g,3,5,8);
    g = AddEdgeMST(g,6,5,2);
    g = AddEdgeMST(g,6,3,4);
    g = AddEdgeMST(g,2,8,7);
    g = AddEdgeMST(g,7,3,9);
    /*g = CreateGraphMST(8,10);
    printf("aa");
    g = AddEdgeMST(g,1,2,5);
    //g = AddEdgeMST(g,1,4,6);
    //g = AddEdgeMST(g,1,3,1);
    g = AddEdgeMST(g,4,2,2);
    g = AddEdgeMST(g,3,4,1);
    g = AddEdgeMST(g,3,5,8);
    g = AddEdgeMST(g,3,6,4);
    g = AddEdgeMST(g,2,8,7);
    g = AddEdgeMST(g,8,3,1);
    g = AddEdgeMST(g,3,7,9);
    g = AddEdgeMST(g,4,7,5);
    g = AddEdgeMST(g,5,6,2);*/
    forest A;
    A = Kruskal(g);
    PrintForest(A,g.V);

}
