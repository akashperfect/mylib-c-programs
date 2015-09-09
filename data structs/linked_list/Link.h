#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// typedef struct arrayNode * arrNode;


typedef struct arrayNode
{
    void * data;
    int k;
}arrayNode;


typedef struct
{
    arrayNode *arr;
    int *pos; // store the current position of the element
    int capacity;
    int size;
}priorityQueue;

#endif // LINK_H_INCLUDED
