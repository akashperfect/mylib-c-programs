#ifndef MSTPRIM_H_INCLUDED
#define MSTPRIM_H_INCLUDED
#include "Graphops.h"


void
InsertInForest(graph_edge* edge, int u, int v, int wt)
{
    edge->src = u;
    edge->dest = v;
    edge->wt = wt;
}

graph_edge * Prim()
{

    int u, v, w, index = 0, t;
    NODE curr;
    graph_edge *forest;
    forest = (graph_edge *)calloc(g.size + 1, sizeof(graph_edge));
    InitializeSingleSource(1);
    CreatePQofGraph();
    while(pqueue.size > 0)
    {
        u =  *(int *)(ExtractMinPQ().data);
        curr = g.list[u].top;
        while(curr != NULL)//curr != NULL)
        {
            v = EdgeDest(curr);
            w = EdgeWeight(curr);
            printf("u = %d, v = %d w = %d\n", u, v, w);
            if(EdgeWeight(curr) < g.list[v].d)
            {
                g.list[v].d = w;
                printf("index = %d\n", index);
                // InsertInForest(&forest[index++],u,v,w);
                forest[index].src = u;
                forest[index].dest = v;
                forest[index].wt = w;
                index ++;
            }
            curr = curr->next;
        }
        // return forest;
    }
    PrintArrayAny(forest, 10, printEdge);
    for(t = 0; t < g.size; t ++)
    printEdge(&forest[t]);
    return forest;
}


#endif // MSTPRIM_H_INCLUDED
