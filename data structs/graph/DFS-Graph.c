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
    graph g;
    int u1=1, u2=2, u3=3, u4=4, u5=5, u6=6, 
    u7=7, u8=8, u9=9;
    CreateGraph(&g, 10);
    AddEdge(&g, &u1, &u2);
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
    DFS(g);


}
