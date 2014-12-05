#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED

typedef struct node * NODE;

struct node{
    char * str;
    int num;
    NODE next;
    NODE prev;
};


#endif // LINK_H_INCLUDED
