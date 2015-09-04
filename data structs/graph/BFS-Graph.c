#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graphops.h"
#include "../queue/Queue.h"

//Insert Children
//queue InsertChildrenQueue()

void BFS(graph g)
{
    int no, start, *visit;
    queue q;
    NODE fr, temp;
    no = g.size;
    start = 1;
    visit = (int *)calloc((no+1), sizeof(int));
    fr = CreateNode(&start);
    q = CreateQueue();
    // fr = InsertValue(fr,1);
    visit[Value(fr)] = 1;
    q = Enqueue(q, fr);
    while(q.front!=NULL)
    {
        fr = q.front;
        printf("%d ", Value(fr));
        fr = g.list[Value(fr)].top;
        while(fr!=NULL)
        {
            temp = CreateNode();
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
    return;
}



int main(void)
{
    graph g;
    g = CreateGraph(9);
    g = AddEdge(g,1,2);
    g = AddEdge(g,1,4);
    g = AddEdge(g,1,3);
    g = AddEdge(g,4,2);
    g = AddEdge(g,3,4);
    g = AddEdge(g,3,5);
    g = AddEdge(g,6,4);
    g = AddEdge(g,5,9);
    g = AddEdge(g,5,8);
    g = AddEdge(g,7,8);
    //printf("%d ", Value(g[1].top->next));
    BFS(g);


}

