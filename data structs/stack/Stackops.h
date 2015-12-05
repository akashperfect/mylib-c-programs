#ifndef STACKOPS_H_INCLUDED
#define STACKOPS_H_INCLUDED
#include "Stack.h"
extern void CreateStack(stack *s);
extern void push(stack *s, void *val);
extern void* pop(stack *s);
extern void* top(stack *s);
extern void PrintStack(stack *s, void printValue(void *val));
#endif // STACKOPS_H_INCLUDED
