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
    Enqueue(&q, fr->data);
    while(q.front != NULL)
    {
        fr = q.front;
        printf("%d ", Value(fr));
        fr = g.list[Value(fr)].top;
        while(fr != NULL)
        {
            temp = CreateNode(fr->data);
            if(visit[Value(fr)] != 1)
            {
                Enqueue(&q, temp->data);
                visit[Value(fr)] = 1;
            }
            fr = fr->next;
        }
        Dequeue(&q);
    }
    return;
}

            

int main(void)
{
    graph g;
    int u1=1, u2=2, u3=3, u4=4, u5=5, u6=6, 
    u7=7, u8=8, u9=9;
    CreateGraph(&g, 10);
    AddEdge(&g, &u1, &u2);
    // PrintGraph(g);
    AddEdge(&g, &u1, &u4);
    AddEdge(&g, &u1, &u3);
    AddEdge(&g, &u4, &u2);
    AddEdge(&g, &u3, &u4);
    AddEdge(&g, &u3, &u5);
    AddEdge(&g, &u6, &u4);
    AddEdge(&g, &u5, &u9);
    AddEdge(&g, &u5, &u8);
    AddEdge(&g, &u7, &u8);
    PrintGraph(g);

    // printf("h %d ", Value(g.list[4].top));
    BFS(g);


}

