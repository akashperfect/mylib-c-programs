#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED


typedef struct {
    int num; // satellite data any number of vars can be added
    char* st;
    //int w; //added for weighted graphs where w stores the path weight from linked node to this node
}SAT;

typedef struct node* NODE;

typedef struct node{
    int data;
    NODE next;
    NODE prev;
};

typedef struct
{
    int size;
    NODE head;
    NODE tail;
}List;

typedef struct
{
    SAT s;
    int k;
}priorityqueue;

typedef priorityqueue * pq;

typedef struct
{
    pq p;
    int size;
}PQ;

#endif // LINK_H_INCLUDED