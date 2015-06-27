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

void
CreateStack(stack *s)
{
    s->size = 0;
    s->d = 0;
    s->top = NULL;
    return ;
}

void
push(stack *s, void* val)
{
    NODE n = CreateNode(val);
    if(s->top != NULL)
        n->next = s->top;
    s->top = n;
    s->size++;
    return ;
}

void* pop(stack *s)
{
    NODE temp;
    temp = s->top;
    if(s->top ==NULL)
    {
        printf("Error - NULL STACK");
        exit(0);
    }
    s->top = s->top->next;
    s->size--;
    return temp->data;
}

void* top(stack *s)
{
    return s->top->data;
}

int
is_stack_empty(stack *s)
{
    if(s == NULL || s->top == NULL){
        printf("Stack is Empty!!!\n");
        return 1;
    }
    return 0;
}

void PrintStack(stack *s, void (*printValue)(void *))
{
    NODE pr = s->top;
    while(pr != NULL)
    {
        // printf("%d ",pr->s.num);
        (*printValue)(pr->data);
        pr = pr->next;
    }
}
#endif // STACK_H_INCLUDED
