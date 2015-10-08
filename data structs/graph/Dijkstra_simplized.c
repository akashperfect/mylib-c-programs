#include "Graphops.h"


int Dijkstra(graph *g, int st, int **w, int *all)
{
    NODE curr;
    int u,v, *set;
    InitializeSingleSource(g, st);
    set = (int *)calloc(g->size, sizeof(int));
    v = g->size;
    while(-- v)
    {
        u = GetMinNotIncl(*g, set);
        all[u] = g->list[u].d;
        curr = g->list[u].top;
        while(curr != NULL)
        {
            RelaxEdgeSimple(g, set, u, Value(curr), w);
            curr = curr->next;
        }
    }
    return MAXINT;
}

int main(int argc, char const *argv[])
{
    graph g;
    int u1=1, u2=2, u3=3, u4=4, u5=5, u6=6, 
    u7=7, u8=8, u9=9, **w, *all;
    all = (int *)calloc(10, sizeof(int));
    w = CreateGraphAM(10);
    CreateGraph(&g, 10);
    AddEdgeW(&g, &u1, &u2, 1, w);
    AddEdgeW(&g, &u1, &u3, 2, w);
    AddEdgeW(&g, &u1, &u4, 3, w);
    AddEdgeW(&g, &u4, &u3, 10, w);
    AddEdgeW(&g, &u3, &u5, 4, w);
    AddEdgeW(&g, &u3, &u6, 5, w);
    AddEdgeW(&g, &u6, &u7, 9, w);
    AddEdgeW(&g, &u5, &u7, 8, w);
    AddEdgeW(&g, &u5, &u8, 7, w);
    AddEdgeW(&g, &u6, &u9, 8, w);
    PrintGraph(g);
    // PrintWieghtedGraph(w, 10);
    printf("%d", Dijkstra(&g, u1, w, all));
    PrintArray(all, 10);
    return 0;
}