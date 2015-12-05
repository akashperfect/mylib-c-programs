#ifndef HASHTABLEADT_H_INCLUDED
#define HASHTABLEADT_H_INCLUDED
#include "Linkops.h"

typedef struct
{
    int size;
    NODE head;
    NODE tail;
} bucket;

typedef struct
{
    bucket *buckets;
    int size;
}hashtable;



typedef struct hashtable * HashTable;

#endif // HASHTABLEADT_H_INCLUDED
