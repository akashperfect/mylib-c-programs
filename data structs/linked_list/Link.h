#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED
#include "../../lib/MaxMin.h"


// typedef struct {
//     int num; // satellite data any number of vars can be added
//     void* data;
//     char* st;
//     //int w; //added for weighted graphs where w stores the path weight from linked node to this node
// }SAT;

/*  Generic NODE used for linked list and queues
    void * data holding the data structures address
    next and prev implementing doubly linked lists
*/

typedef struct node* NODE;

struct node{
    void * data; 
    NODE next;
    NODE prev;
};

typedef struct
{
    int size;
    NODE head;
}List;

typedef struct priorityqueue * pq;


typedef struct priorityqueue
{
    void * data;
    int k;
}priorityqueue;


typedef struct
{
    pq p;
    int size;
}PQ;

#endif // LINK_H_INCLUDED
