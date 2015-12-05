#ifndef LINKOPS_H_INCLUDED
#define LINKOPS_H_INCLUDED
#include "Link.h"


NODE CreateNode()
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));
    n->num = -1;
    n->str = (char *)malloc(100);
    n->next = NULL;
    n->prev = NULL;
    return n;
}


#endif // LINKOPS_H_INCLUDED
