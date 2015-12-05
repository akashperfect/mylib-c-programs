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
                free(temp);
                visit[Value(fr)] = 1;
            }
            fr = fr->next;
        }
        Dequeue(&q);
    }
    free(visit);
    free(fr);
    DeleteQueue(&q);
    return;
}

            

int main(void)
{
    CreateSampleGraph();
    PrintGraph(g);
    BFS(g);
    DeleteGraph(&g);
}

