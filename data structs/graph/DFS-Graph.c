#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graphops.h"
#include "../queue/Queue.h"

//Insert Children
//queue InsertChildrenQueue()

void DFS(graph g)
{
    int no, start, * visit;
    NODE top, temp;
    stack s;
    start = 1;
    no = g.size;
    CreateStack(&s);
    top = CreateNode(&start);
    visit = (int *)calloc( (no+1), sizeof(int));
    visit[Value(top)] = 1;
    push(&s, top->data);
    while(s.top != NULL)
    {
        top = CreateNode(s.top->data);
        pop(&s);
        printf("%d ", Value(top));
        top = g.list[Value(top)].top;
        while(top != NULL)
        {
            temp = CreateNode(top->data);
            if(visit[Value(top)] != 1)
            {
                push(&s, temp->data);
                visit[Value(top)] = 1;
            }
            top = top->next;
        }
    }
    return;
}


int main(void)
{
    CreateSampleGraph();
    PrintGraph(g);
    DFS(g);
}
