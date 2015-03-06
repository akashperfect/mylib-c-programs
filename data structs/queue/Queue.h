#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    q.rear = NULL;
    return q;
}

queue Enqueue(queue q, void * data)
{
    NODE n = CreateNode(data);
    if(q.front == NULL)
        q.front = q.rear = n;
    else
    {
        q.rear->next = n;
        q.rear = n;
    }
    q.size++;
    return q;
}

queue Dequeue(queue q)
{
    if(q.size <= 0)
        return q; 
    NODE del = q.front;
    q.front = q.front->next;
    free(del);
    q.size--;
    return q;
}

void * QueueTop(queue q)
{
    return GetData(q.front);
}

void PrintQueue(queue q)
{
    NODE pr = q.front;
    while(pr!=NULL)
    {
        printf("%d ",*(int*) pr->data);
        pr = pr->next;
    }

}
#endif // QUEUE_H_INCLUDED
