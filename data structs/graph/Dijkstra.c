#include "Graphops.h"


int Dijkstra(int st)
{
    NODE curr;
    int u,v, t = 4;
    InitializeSingleSource(st);
    CreatePQofGraph();
    while(pqueue.size > 0 )
    {
        u = *(int *)(ExtractMinPQ().data);
        distVect[u] = g.list[u].d; // all logic needs 
                             // to be applied here
        curr = g.list[u].top;
        while(curr != NULL)
        {
            RelaxEdge(u, EdgeDest(curr), 
                EdgeWeight(curr));
            curr = curr->next;
        }
    }
    return MAXINT;
}

int main(int argc, char const *argv[])
{

    CreateSampleWeightedGraph();
    CreateDistanceVector();
    PrintGraph();
    Dijkstra(1);
    PrintArray(distVect, 10);
    return 0;
}