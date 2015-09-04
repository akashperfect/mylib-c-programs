#ifndef BUILD_GRAPH_H_INCLUDED
#define BUILD_GRAPH_H_INCLUDED
#include "../stack/Stack.h"
#include "../PriorityQueues.h"

typedef struct{
    stack * list;
    int size;
}graph; //Data structure of graph if it needs to be modified on the fly

extern void CreateGraph(graph *g, int n);
extern int ** CreateGraphAM(int n);
extern graph AddNode(graph g, int n);
extern void AddEdge(graph *g, int *v, int *w);
extern graph AddEdgeDirected(graph g, int v, int w);
extern graph AddWeightedEdge(graph g, int *** w, int u, int v, int wt);
extern void InitializeSingleSource(graph *g, int s);
extern NODE GraphNodeV(graph g, int u, int v);
extern void RelaxEdge(graph *g, PQ *q, int u, int v, int **w);
extern PQ MakePQofGraph(graph g);
extern void PrintGraph(graph);

void
CreateGraph(graph *g, int n)
{
    int i = 0;
    g->list = (stack *)calloc((n+1), sizeof(stack));
    while(i <= n)
    {
        CreateStack(&g->list[i]);
        i++;
    }
    g->size = n;
}

int ** CreateGraphAM(int n)
{
    int ** w,i;
    w = (int **)calloc((n+1), sizeof(int *) );
    for(i = 0; i <= n; i++)
    {
        w[i] = (int *)calloc((n+1), sizeof(int) );
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

void
AddEdge(graph *g, int *v, int *w)
{
    push(&g->list[*v], w);
    push(&g->list[*w], v);
}

void
AddEdgeW(graph *g, int *u, int *v, int wt, int **w)
{
    //int ** we = (*w);
    push(&g->list[*u], v);
    push(&g->list[*v], u);
    // *(*(*w+*u)+*v) = wt;
    // *(*(*w+*v)+*u) = wt;
    w[*u][*v] = wt;
    w[*v][*u] = wt;
}

graph AddEdgeDirected(graph g, int u ,int v)
{
    push(&g.list[u], &v);
    return g;
}

graph AddWeightedEdge(graph g, int *** wi, int u, int v, int wt)
{
    int ** we = (*wi);
    AddEdge(&g, &u, &v);
    //g.list[u].top->s.w = wt;
    //g.list[v].top->s.w = wt;
    we[u][v] = wt;
    we[v][u] = wt;
    (*wi) = we;
    return g;
}

void
InitializeSingleSource(graph *g, int s)
{
    int i = g->size;
    while(i>0)
    {
        g->list[i].d = MAXINT;
        i--;
    }
    g->list[s].d=0;
}

NODE GraphNodeV(graph g, int u, int v)
{
    NODE curr = g.list[u].top;
    while(curr!=NULL)
    {
        if(*(int *)curr->data == v)
            return curr;
        curr = curr->next;
    }
    return ;
}

void
RelaxEdge(graph *g, PQ *q, int u, int v, int **w)
{
    if(g->list[v].d > g->list[u].d + w[u][v])
    {
        g->list[v].d = g->list[u].d + w[u][v];
        *q = DecreaseKeyPQ(*q,v,g->list[v].d);
    }
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

void printNode(void * data)
{
    printf("%d ", *(int *) data);
}

void
PrintGraph(graph g)
{
    int i;
    printf("Printing the Graph\n");
    for(i = 0; i < g.size; i ++){
        printf("%d -> ", i);
        PrintStack(&g.list[i], printNode);
        printf("\n");

    }
    printf("\n");
}
#endif // BUILD-GRAPH_H_INCLUDED
