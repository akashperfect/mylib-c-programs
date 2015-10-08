#ifndef STACKOPS_H_INCLUDED
#define STACKOPS_H_INCLUDED
#include "Stack.h"
extern stack CreateStack();
extern stack push(stack s, int val);
extern stack pop(stack s);
extern NODE top(stack s);
extern void PrintStack(stack s);
#endif // STACKOPS_H_INCLUDED
