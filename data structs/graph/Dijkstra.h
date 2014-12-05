#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED
#include "Graphops.h"


int Dijkstra(graph g, int st, int e, int **w)
{
    InitializeSingleSource(g,st);
    PQ p = MakePQofGraph(g);
    stack s;
    NODE curr;
    int u,v;
    while(p.size>0)
    {
        u = ExtractMinPQ(&p);
        if(u==e) return g.list[u].d;
        s = push(s,u);
        curr = g.list[u].top;
        while(curr!=NULL)
        {
            g = RelaxEdge(g,&p,u,curr->s.num,w);
            curr = curr->next;
        }
    }
    return MAXINT;
}

#endif // DIJKSTRA_H_INCLUDED
