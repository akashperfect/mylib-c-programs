#include "Graphops.h"


int Dijkstra(int st)
{
    NODE curr;
    int u,v, t = 4;
    InitializeSingleSource(st);
    CreatePQofGraph();
    PrintPQData(printNode);
    PrintArray(pqueue.pos, 10);
    while(pqueue.size > 0 )
    {
        u = *(int *)(ExtractMinPQ().data);
        PrintPQData(printNode);
        PrintArray(pqueue.pos, 10);
        printf("u = %d\n", u);
        distVect[u] = g.list[u].d; // all logic needs 
    // //     //                 // to be applied here
        curr = g.list[u].top;
        while(curr != NULL)
        {
            RelaxEdge(u, EdgeDest(curr), 
                EdgeWeight(curr));
            curr = curr->next;
            // break ;
        }
        PrintPQData(printNode);
        PrintGraph();
        // PrintPQ();
        // return;
    }
    return MAXINT;
}

int main(int argc, char const *argv[])
{

    CreateSampleWeightedGraph();
    CreateDistanceVector();
    PrintGraph(g);
    Dijkstra(1);
    PrintArray(distVect, 10);
    return 0;
}