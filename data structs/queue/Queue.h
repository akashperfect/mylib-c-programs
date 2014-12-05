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

queue CreateQueue()
{
    queue q;
    q.size = 0;
    q.front = NULL;
    return q;
}

queue Enqueue(queue q, NODE n)
{
    NODE curr,prev;
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
    return q.front;
}

void PrintQueue(queue q)
{
    NODE pr = q.front;
    while(pr!=NULL)
    {
        printf("%d ",pr->s.num);
        pr = pr->next;
    }

}
#endif // QUEUE_H_INCLUDED
