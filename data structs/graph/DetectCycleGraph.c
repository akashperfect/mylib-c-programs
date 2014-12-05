#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"
#include "DFS-Graph.c"


int IsCyclicGraph(graph g)
{
    int no = g.size;
    int * visit;
    visit = (int*)calloc((no+1),sizeof(int));
    stack s;
    NODE top = CreateNode();
    s = CreateStack();
    top = InsertValue(top,1);
    visit[Value(top)] = 1;
    s = push(s, Value(top));
    while(s.top!=NULL)
    {
        top = CreateNode();
        top = InsertValue(top,Value(s.top));
        s = pop(s);
        top = g.list[Value(top)].top;
        while(top!=NULL)
        {
            NODE temp = CreateNode();
            temp = InsertValue(temp,Value(top));
            if(visit[Value(top)] != 1)
            {
                s = push(s,Value(temp));
                visit[Value(top)] = 1;
            }
            else
            {
                printf("Graph is Cyclic %d\n",Value(top));
                return -1;
            }
            top = top->next;
        }
    }
    printf("Graph is Acyclic\n");
    return 1;
}


int main(int argc, char *argv[])
{
     graph g;
    g = CreateGraph(9);
    g = AddEdgeDirected(g,1,2);
    g = AddEdgeDirected(g,1,4);
    g = AddEdgeDirected(g,1,3);
    //g = AddEdgeDirected(g,4,2);
    //g = AddEdgeDirected(g,3,4);
    g = AddEdgeDirected(g,3,5);
    g = AddEdgeDirected(g,4,6);
    g = AddEdgeDirected(g,5,9);
    g = AddEdgeDirected(g,5,8);
    g = AddEdgeDirected(g,9,7);
    //printf("%d ", Value(g[1].top->next));
    IsCyclicGraph(g);

}
