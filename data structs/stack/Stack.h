#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Stackadt.h"

//push,pop,top
/*
Stackops.h - data definition
Stacks.h - Data structures
*/

stack CreateStack()
{
    stack s;
    s.size=0;
    s.d = 0;
    s.top=NULL;
    return s;
}

stack push(stack s, int val)
{
    NODE n = CreateNode();
    n = InsertValue(n, val);
    if(s.top!=NULL)
    n->next = s.top;
    s.top = n;
    s.size++;
    return s;
}

stack pop(stack s)
{
    NODE temp;
    temp = s.top;
    if(s.top==NULL)
    {
        printf("Error - NULL STACK");
        exit(0);
    }
    s.top = s.top->next;
    s.size--;
    free(temp); // removing garbage value
    return s;
}

NODE top(stack s)
{
    return s.top;
}

void PrintStack(stack s)
{
    NODE pr = s.top;
    while(pr!=NULL)
    {
        printf("%d ",pr->s.num);
        pr = pr->next;
    }
}
#endif // STACK_H_INCLUDED
