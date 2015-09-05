#include "GraphopsSimple.h"

int Dijkstra(int st, int *all)
{
    NODE curr;
    int u,v, *set;
    InitializeSingleSource(st);
    set = (int *)calloc(g.size, sizeof(int));
    v = g.size;
    while(-- v)
    {
        u = GetMinNotIncl(set);
        all[u] = g.list[u].d;
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
    // int u1=1, u2=2, u3=3, u4=4, u5=5, u6=6, 
    // u7=7, u8=8, u9=9, *all, size;
    int size = 10;
    int *all = (int *)calloc(size, sizeof(int));
    CreateGraph(10);
    AddEdgeW(1, 2, 1);
    AddEdgeW(1, 3, 2);
    AddEdgeW(1, 4, 3);
    AddEdgeW(4, 3, 10);
    AddEdgeW(3, 5, 4);
    AddEdgeW(3, 6, 5);
    AddEdgeW(6, 7, 9);
    AddEdgeW(5, 7, 8);
    AddEdgeW(5, 8, 7);
    AddEdgeW(6, 9, 8);
    PrintGraph();
    // PrintWeightedGraph(w, 10);
    printf("%d", Dijkstra(1, all));
    PrintArray(all, 10);
    return 0;
}