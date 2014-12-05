#ifndef BUILD-GRAPH_H_INCLUDED
#define BUILD-GRAPH_H_INCLUDED
#include "Stack.h"
#include "PriorityQueues.h"

typedef struct{
    stack * list;
    int size;
}graph; //Data structure of graph if it needs to be modified on the fly

extern graph CreateGraph(int n);
extern int ** CreateGraphAM(int n);
extern graph AddNode(graph g, int n);
extern graph AddEdge(graph g, int v, int w);
extern graph AddEdgeDirected(graph g, int v, int w);
extern graph AddWeightedEdge(graph g, int *** w, int u, int v, int wt);
extern graph InitializeSingleSource(graph g, int s);
extern NODE GraphNodeV(graph g, int u, int v);
extern graph RelaxEdge(graph g, PQ *q, int u, int v, int **w);
extern PQ MakePQofGraph(graph g);


graph CreateGraph(int n)
{
    graph g;
    int i=0;
    g.list = (stack*)malloc((n+1)*sizeof(stack));
    while(i<=n)
    {
        g.list[i] = CreateStack();
        i++;
    }
    g.size = n;
    return g;
}

int ** CreateGraphAM(int n)
{
    int ** w,i;
    w = (int**)malloc((n+1)*sizeof(int*));
    for(i=0;i<=n;i++)
    {
        (*w) = (int*)malloc((n+1)*sizeof(int));
    }
    return w;
}

graph AddNode(graph g, int n)
{
    g.list = (stack*)realloc(g.list,n * sizeof(stack));
    return g;
}

/*
stack * CreateGraph(int n)
{
    stack  list[n];
    return list;
}
*/

graph AddEdge(graph g, int v, int w)
{
    g.list[v] = push(g.list[v],w);
    g.list[w] = push(g.list[w],v);
    return g;
}
graph AddEdgeW(graph g, int u, int v, int wt, int ***w)
{
    //int ** we = (*w);
    g.list[u] = push(g.list[u],v);
    g.list[v] = push(g.list[v],u);
    *(*(*w+u)+v) = wt;
    *(*(*w+v)+u) = wt;
    return g;
}

graph AddEdgeDirected(graph g, int u ,int v)
{
    g.list[u] = push(g.list[u],v);
    return g;
}

graph AddWeightedEdge(graph g, int *** wi, int u, int v, int wt)
{
    int ** we = (*wi);
    g = AddEdge(g,u,v);
    //g.list[u].top->s.w = wt;
    //g.list[v].top->s.w = wt;
    we[u][v] = wt;
    we[v][u] = wt;
    (*wi) = we;
    return g;
}

graph InitializeSingleSource(graph g, int s)
{
    int i = g.size;
    while(i>0)
    {
        g.list[i].d = MAXINT;
        i--;
    }
    g.list[s].d=0;
    return g;
}

NODE GraphNodeV(graph g, int u, int v)
{
    NODE curr = g.list[u].top;
    while(curr!=NULL)
    {
        if(curr->s.num==v)
        return curr;
        curr = curr->next;
    }
    return ;
}

graph RelaxEdge(graph g, PQ *q, int u, int v, int **w)
{
    if(g.list[v].d > g.list[u].d + w[u][v])
    {
        g.list[v].d = g.list[u].d + w[u][v];
        *q = DecreaseKeyPQ(*q,v,g.list[v].d);
    }
    return g;
}

PQ MakePQofGraph(graph g)
{
    PQ p = CreatePQ();
    int i=1;
    while(i<g.size)
    {
        p = InsertMinPQ(p,g.list[i].d);
    }
    return p;
}
#endif // BUILD-GRAPH_H_INCLUDED
