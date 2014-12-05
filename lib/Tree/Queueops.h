#ifndef QUEUEOPS_H_INCLUDED
#define QUEUEOPS_H_INCLUDED
#include "Queue.h"

extern queue CreateQueue();
extern queue Enqueue(queue s, NODE n);
extern queue Dequeue(queue s);
extern NODE front(queue s);
extern void PrintQueue(queue s);


#endif // QUEUEOPS_H_INCLUDED
