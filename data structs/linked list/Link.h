#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED
#include "MaxMin.h"


typedef struct {
    int num; // satellite data any number of vars can be added
    char* st;
    //int w; //added for weighted graphs where w stores the path weight from linked node to this node
}SAT;

typedef struct node* NODE;

typedef struct node{
    SAT s;
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
    SAT s;
    int k;
}priorityqueue;


typedef struct
{
    pq p;
    int size;
}PQ;

#endif // LINK_H_INCLUDED
