#include "Graphops.h"


int Dijkstra(int st)
{
    PQ q;
    NODE curr;
    int u,v;
    InitializeSingleSource(st);
    CreatePQofGraph(&q);
    PrintPQ(q);
    while(q.size > 0)
    {
        u = ExtractMinPQ(&q);
        PrintPQ(q);
        printf("u = %d\n", u);
        distVect[u] = g.list[u].d; // all logic needs 
        //                 // to be applied here
        curr = g.list[u].top;
        while(curr != NULL)
        {
            // RelaxEdge(&q, u, EdgeDest(curr), 
            //     EdgeWeight(curr));
            curr = curr->next;
        }
        return;
    }
    return MAXINT;
}

int main(int argc, char const *argv[])
{

    CreateSampleWeightedGraph();
    CreateDistanceVector();
    PrintGraph(g);
    Dijkstra(1);
    return 0;
}