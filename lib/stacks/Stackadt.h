#ifndef STACKS_H_INCLUDED
#define STACKS_H_INCLUDED
#include "..\\Linked lists\\Link.h"
#include "..\\Linked lists\\Linkops.h"

typedef struct stack * STACK;

typedef struct stack{
    int size;
    int d;
    STACK min;
    NODE top;
}stack;


#endif // STACKS_H_INCLUDED
