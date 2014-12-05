#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"
#include "BFS-Graph.c"

int IsPath2V(graph g, int u, int v)
{
    int no = g.size;
    int * visit;
    visit = (int*)calloc((no+1),sizeof(int));
    queue q;
    NODE fr = CreateNode();
    q = CreateQueue();
    fr = InsertValue(fr,1);
    visit[Value(fr)] = 1;
    q = Enqueue(q, fr);
    while(q.front!=NULL)
    {
        fr = q.front;
        if(Value(fr)==v) {printf("There is a path\n"); return 1;}
        printf("%d ", Value(fr));
        fr = g.list[Value(fr)].top;
        while(fr!=NULL)
        {
            NODE temp = CreateNode();
            temp = InsertValue(temp,Value(fr));
            if(visit[Value(fr)] != 1)
            {
                q = Enqueue(q,temp);
                visit[Value(fr)] = 1;
            }
            fr = fr->next;
        }
        q = Dequeue(q);
    }
    printf("There is no path\n");
    return -1;
}

int main(int argc, char *argv[])
{
     graph g;
    g = CreateGraph(9);
    g = AddEdgeDirected(g,1,2);
    g = AddEdgeDirected(g,1,4);
    g = AddEdgeDirected(g,1,3);
    g = AddEdgeDirected(g,4,2);
    g = AddEdgeDirected(g,3,4);
    g = AddEdgeDirected(g,3,5);
    g = AddEdgeDirected(g,4,6);
    g = AddEdgeDirected(g,5,9);
    g = AddEdgeDirected(g,5,8);
    g = AddEdgeDirected(g,7,9);
    IsPath2V(g,1,9);

}
