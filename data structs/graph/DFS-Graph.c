#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Graphops.h"
#include "Queue.h"

//Insert Children
//queue InsertChildrenQueue()

void DFS(graph g)
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
        printf("%d ", Value(top));
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
            top = top->next;
        }
    }
    return;
}


/*
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
    g = AddEdge(g,7,9);
    //printf("%d ", Value(g[1].top->next));
    DFS(g);


}
*/
