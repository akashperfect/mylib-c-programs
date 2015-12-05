#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "..\\Linked lists\\basicdef.h"
#include "..\\stacks\\Stackops.h"



int main(int argc, char *argv[])
{
    stack s = CreateStack();
    s = push(s, 10);
    s = push(s, 9);
    s = push(s, 15);
    s = push(s, 13);
    s = push(s, 2);
    s = push(s, 5);
    s = push(s, 19);
    PrintStack(s);
    printf("\n%d\n",s.min->top->data);
    s = pop(s);
    s = pop(s);
    s = pop(s);
    s = pop(s);
    s = pop(s);
    PrintStack(s);
    printf("\n%d\n",s.min->top->data);
    return 0;


}
