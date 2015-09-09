#ifndef BUILD_GRAPH_H_INCLUDED
#define BUILD_GRAPH_H_INCLUDED
#include "../stack/Stack.h"
#include "../PriorityQueues.h"

typedef struct{
    int dest, wt;
}graph_edge;

typedef struct{
    stack * list;
    int size;
}graph; //Data structure of graph if it needs to be modified on the fly

graph g;

int *distVect;

// extern void CreateGraph(graph *g, int n);
// extern int ** CreateGraphAM(int n);
// extern graph AddNode(graph g, int n);
extern void AddEdge(int u, int v);
extern void AddEdgeW(int u, int v, int w);
// extern graph AddEdgeDirected(graph g, int v, int w);
// extern graph AddWeightedEdge(graph g, int *** w, int u, int v, int wt);
// extern void InitializeSingleSource(graph *g, int s);
// extern NODE GraphNodeV(graph g, int u, int v);
// extern void RelaxEdge(graph *g, PQ *q, int u, int v, int **w);
// extern void MakePQofGraph(PQ *, graph g);
// extern void PrintGraph(graph);

void
CreateGraph(int n)
{
    int i = 0;
    g.list = (stack *)calloc((n+1), sizeof(stack));
    while(i <= n)
    {
        CreateStack(&g.list[i]);
        i++;
    }
    g.size = n;
}

void
CreateDistanceVector()
{
    int i;
    distVect = (int *)calloc(10, sizeof(int));
    for (i = 0; i < 10; ++i){
        distVect[i] = -1;
    }
}

void
CreateSampleGraph()
{
    CreateGraph(10);
    AddEdge(1, 2);
    AddEdge(1, 4);
    AddEdge(1, 3);
    AddEdge(4, 2);
    AddEdge(3, 4);
    AddEdge(3, 5);
    AddEdge(6, 4);
    AddEdge(5, 9);
    AddEdge(5, 8);
    AddEdge(7, 8);
}

void
CreateSampleWeightedGraph()
{
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
}

void
CreatePQofGraph()
{
    int i = 1;
    CreatePQ(g.size);
    while(i < g.size){
        int *node = (int *)calloc(1, sizeof(int));
        *node = i;
        InsertMinPQ(node, g.list[i].d);
        i ++;
    }
    // pqueue.pos[g.size - 1] = 
}

void
CreateEdge(graph_edge **e, int dest, int w)
{
    *e = (graph_edge *)malloc(sizeof(graph_edge));
    (*e)->dest = dest;
    (*e)->wt = w;
}

void
CreateVertex(int **ver, int v)
{
    (*ver) = (int *)malloc(sizeof(int));
    *(*ver) = v;
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
AddEdge(int u, int v)
{
    int *src, *dest;
    CreateVertex(&src, u);
    CreateVertex(&dest, v);
    push(&g.list[u], dest);
    push(&g.list[v], src);
}

/*  Need to preserve the graph edge across 
    functions, being a ADT need to reserve
    a memory for the structure and store
    the pointer in our graph for the edges
*/

void
AddEdgeW(int u, int v, int w)
{
    //int ** we = (*w);
    graph_edge *e1, *e2;
    CreateEdge(&e1, v, w);
    CreateEdge(&e2, u, w);
    push(&g.list[u], e1);
    push(&g.list[v], e2);
}

graph AddEdgeDirected(graph g, int u ,int v)
{
    push(&g.list[u], &v);
    return g;
}

/*  Initializes the graph, containing
    all the vertices to Infinite
    which will later be used for 
    calculating min distance
*/

void
InitializeSingleSource(int s)
{
    int i = g.size;
    while(i >= 0)
    {
        g.list[i].d = MAXINT;
        i--;
    }
    g.list[s].d=0;
}

void
InitializePresent(int *set, int size)
{
    int i;
    set = (int *)calloc(size, sizeof(int));
    for (i = 0; i < size; ++i){
        set[i] = MAXINT;
        /* code */
    }
}

int GetMinNotIncl(int *set)
{
    int i, index = 0, min;
    min = MAXINT;
    for(i = 0; i < g.size; i++){
        if(g.list[i].d < min && set[i] != 1){
            min = g.list[i].d;
            index = i;
        }
    }
    set[index] = 1;
    return index;
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
RelaxEdge(int u, int v, int w)
{
    if(g.list[v].d > g.list[u].d + w)
    {
        g.list[v].d = g.list[u].d + w;
        DecreaseKeyPQ(pqueue.pos[v], g.list[v].d);
    }
}

void
RelaxEdgeSimple(int *set, int u, int v, int w)
{
    if(g.list[v].d > g.list[u].d + w){
        g.list[v].d = g.list[u].d + w;
    }
}

int 
EdgeDest(NODE temp)
{
    return ((graph_edge *) temp->data)->dest;
}

int 
EdgeWeight(NODE temp)
{
    return ((graph_edge *) temp->data)->wt;
}

/*  Makes a priority queue of 
    all the graph edges
*/
    
void printNode(void * data)
{
    printf("%d", *(int *) data);
}

void
PrintArray(int *a, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);   /* code */
    }
    printf("\n");
}

/*  Prints only the edges of the graph
*/
void
PrintGraph()
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
