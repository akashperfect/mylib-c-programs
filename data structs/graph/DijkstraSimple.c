#include "Graphops.h"

int Dijkstra(int st)
{
    NODE curr;
    int u,v, *set;
    InitializeSingleSource(st);
    set = (int *)calloc(g.size, sizeof(int));
    v = g.size;
    while(-- v)
    {
        u = GetMinNotIncl(set);
        distVect[u] = g.list[u].d; // all logic needs 
                        // to be applied here
        curr = g.list[u].top;
        while(curr != NULL)
        {
            RelaxEdgeSimple(set, u, EdgeDest(curr), 
                EdgeWeight(curr));
            curr = curr->next;
        }
    }
    return MAXINT;
}

int main(int argc, char const *argv[])
{
    int size = 10;
    // int *all = (int *)calloc(size, sizeof(int));
    CreateSampleWeightedGraph();
    CreateDistanceVector();
    PrintGraph();
    Dijkstra(1);
    PrintArray(distVect, 10);
    return 0;
}