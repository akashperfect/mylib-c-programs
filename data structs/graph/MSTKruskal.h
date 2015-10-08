#ifndef MSTKRUSKAL_H_INCLUDED
#define MSTKRUSKAL_H_INCLUDED
#include "DisjointSet.h"


int partition(EDGE a,int p,int r)// rearranges sub-array A[p..r] in place
{
    int x = (*(a+r)).wt; //x acts as a pivot element around which partition takes place
    int i = p-1,j;
    edge temp;
    for(j=p;j<=r-1;j++)
    {
        if((*(a+j)).wt<=x)
        {
            i++;
            temp = (*(a+j));
            (*(a+j)) = (*(a+i));
            (*(a+i)) = temp;
        }
    }
    temp = (*(a+i+1));
    (*(a+i+1)) = (*(a+r));
    (*(a+r)) = temp;
    return i+1;
}

int quicksort(EDGE a,int p,int r)
{
    int q;
    if(p<r)
    {
        q = partition(a,p,r);
        // partitioning the array based on the pivot, which is the last element of the array.
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
int compare(const void* a, const void* b)
{
    edge* a1 = (edge*)a;
    edge* b1 = (edge*)b;
    return (*a1).wt>(*b1).wt;
}

forest Kruskal(graph g)
{
    forest A;
    subset s;
    A = CreateForest(g.V);
    s = BuildSubset(g.V);
    int i=1,index=0;
    while(i<=g.V)
    {
        MakeSet(s,i);
        i++;
    }
    quicksort(g.e,0,g.E-1);
    //qsort(g.e,0,g.E-1,compare);
    for(i=0;i<g.E;i++)
    {
        if(FindSet(g.e[i].u,s)!=FindSet(g.e[i].v,s))
        {
            A[index++] = g.e[i];
            UnionSet(g.e[i].u,g.e[i].v,s);
        }
    }
    return A;
}

void PrintForest(forest f, int size)
{
    int i=0,count=0;
    for(i;i<size-1;i++)
    {
        printf("%d %d -- %d\n",f[i].u,f[i].v,f[i].wt);
        count+= f[i].wt;
    }
    printf("Total weight = %d\n",count);
}


#endif // MSTKRUSKAL'S_H_INCLUDED
