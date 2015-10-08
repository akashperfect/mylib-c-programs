#ifndef QUEUEADT_H_INCLUDED
#define QUEUEADT_H_INCLUDED

typedef struct node* NODE;

typedef struct node{
    NODET root;
    NODE next;
    NODE prev;
};


typedef struct{
    int size;
    NODE front;
}queue;


#endif // QUEUEADT_H_INCLUDED
