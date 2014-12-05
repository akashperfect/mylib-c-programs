#ifndef DISJOINTSET_H_INCLUDED
#define DISJOINTSET_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
    int u,v,wt;
}edge;

typedef edge* EDGE;

typedef edge* forest;

typedef struct
{
    int V,E;
    EDGE e;
}graph;


typedef struct
{
    int p;
    int rank;
}sub;

typedef sub* subset;

int numedges = 0;

graph CreateGraphMST(int V)
{
    graph g;
    g.V = V;
    g.E = 0;
    g.e = NULL;
    return g;
}

graph AddEdgeMST(graph g,int u,int v, int wt)
{
    g.E++;
    g.e = (EDGE)realloc(g.e,g.E*sizeof(edge));
    g.e[numedges].u = u;
    g.e[numedges].v = v;
    g.e[numedges].wt = wt;
    numedges++;
    return g;
}

forest CreateForest(int n)
{
    forest A;
    A = (forest)malloc((n+1)*sizeof(edge));
    return A;
}

subset BuildSubset(int size)
{
    subset s;
    s = (subset)malloc((size+1)*sizeof( sub));
    return s;
}

void MakeSet(subset s,int x)
{
    (*(s+x)).p = x;
    (*(s+x)).rank = 0;
}

int FindSet(int x, subset s)
{
    if(x!=s[x].p)
        (*(s+x)).p = FindSet(s[x].p,s);
    return s[x].p;
}

void LinkSet(int u, int v, subset s)
{
    if(s[u].rank>s[v].rank)
    (*(s+v)).p = u;
    else
    {
        (*(s+u)).p = v;
        if(s[u].rank==s[v].rank)
        (*(s+v)).rank++;
    }
}


void UnionSet(int u, int v, subset s)
{
    LinkSet(FindSet(u,s),FindSet(v,s), s);
}




#endif // DISJOINTSET_H_INCLUDED
