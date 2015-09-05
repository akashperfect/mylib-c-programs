#include "Graphops.h"


int Dijkstra(graph g, int st, int e, int **w)
{
    PQ q;
    NODE curr;
    int u,v, *set;
    InitializeSingleSource(&g, st);
    set = (int *)calloc(g.size, sizeof(int));
    v = g.size;
    // set[st] = 0;
    while(v --)
    {
        GetMinNotIncl(g, set);
        if(u == e) 
            return g.list[u].d;
        curr = g.list[u].top;
        while(curr != NULL)
        {
            curr = curr->next;
        }
    }
    return MAXINT;
}

int main(int argc, char const *argv[])
{
    graph g;
    int u1=1, u2=2, u3=3, u4=4, u5=5, u6=6, 
    u7=7, u8=8, u9=9, **w;
    w = CreateGraphAM(10);
    CreateGraph(&g, 10);
    AddEdgeW(&g, &u1, &u2, 2, w);
    AddEdgeW(&g, &u1, &u4, 5, w);
    AddEdgeW(&g, &u1, &u3, 7, w);
    AddEdgeW(&g, &u4, &u2, 1, w);
    AddEdgeW(&g, &u3, &u4, 3, w);
    AddEdgeW(&g, &u3, &u5, 4, w);
    AddEdgeW(&g, &u6, &u4, 8, w);
    AddEdgeW(&g, &u5, &u9, 9, w);
    AddEdgeW(&g, &u5, &u8, 6, w);
    AddEdgeW(&g, &u7, &u8, 10, w);
    PrintGraph(g);
    Dijkstra(g, u1, u8, w);
    return 0;
}