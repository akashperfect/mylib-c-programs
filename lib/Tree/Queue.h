#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Queueadt.h"

//enqueue,dequeue,front
/*
Stackops.h - data definition
Stacks.h - Data structures
*/
NODET CreateNode(NODET root)
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));
    n->root=root;
    n->next = NULL;
    //n->s.st = (char*)malloc(100*sizeof(char));
    //n->s.w = 0;
    n->prev=NULL;
    return n;
}

queue CreateQueue()
{
    queue q;
    q.size = 0;
    q.front = NULL;
    return q;
}

queue Enqueue(queue q, NODET t)
{
    NODE curr,prev,n = CreateNode(t);
    curr=prev=q.front;
    if(q.front==NULL)
    q.front = n;
    else
    {
        while(curr!=NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = n;

    }
    q.size++;
    return q;
}

queue Dequeue(queue q)
{
    NODE del = q.front;
    q.front = q.front->next;
    free(del);
    return q;
}

NODE QueueTop(queue q)
{
    return q.front->root;
}

void PrintQueue(queue q)
{
    NODE pr = q.front;
    while(pr!=NULL)
    {
        printf("%d ",pr->root->data);
        pr = pr->next;
    }

}
#endif // QUEUE_H_INCLUDED
