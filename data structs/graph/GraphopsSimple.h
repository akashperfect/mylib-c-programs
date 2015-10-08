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

// extern void CreateGraph(int n);
// extern int ** CreateGraphAM(int n);
// extern void AddEdge(int *v, int *w);
// extern void InitializeSingleSource(int s);
// extern void RelaxEdgeSimple(int *set, int u, int v, int **w);
// extern void PrintGraph();

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
CreateEdge(graph_edge **e, int dest, int w)
{
    *e = (graph_edge *)malloc(sizeof(graph_edge));
    (*e)->dest = dest;
    (*e)->wt = w;
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
    printf("e1 = %d %d\n", e1->dest, e1->wt);
    push(&g.list[u], e1);
    push(&g.list[v], e2);
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

void printNode(void * data)
{
    printf("%d ", ((graph_edge *) data)->dest);
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

void
PrintWeightedGraph(int **w, int size)
{
    int i, j;
    printf("Printing Entire Weighted Graph\n");
    for(i = 0; i < size; i++){
        for (j = 0; j < size; ++j){  
            printf("%d ", w[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

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
