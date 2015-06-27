
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Stackops.h"

void print_value(void *x)
{
    printf("%d\n", *(int *) x);
}

int main()
{
    stack s;
    CreateStack(&s);
    int x = 9;
    push(&s, &x);
    printf("%d\n", *(int *)pop(&s));
    x = 11;
    push(&s, &x);
    push(&s, &x);
    push(&s, &x);
    PrintStack(&s, print_value);
    is_stack_empty(&s);
    return 0;
}
