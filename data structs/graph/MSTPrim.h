#ifndef MSTPRIM_H_INCLUDED
#define MSTPRIM_H_INCLUDED

forest InserInForest(int u,int v, int wt)
{
    edge e;
    e.u=u;
    e.v=v;
    e.wt=wt;
    return e;
}

forest Prim(graph g, int **w)
{
    InitializeSingleSource(g,1);
    PQ p = MakePQofGraph(g);
    int u,v,index=0;
    while(p.size>0)
    {
        u = ExtractMinPQ(&p);
        curr = g.list[u].top;
        while(curr!=NULL)
        {
            v = curr->s.num;
            if(BelongsToPQ(p,v)&&w[u][v] < g.list[v].d)
            {
                g.list[v].d = w[u][v];
                A[index++] = InsertInForest(u,v,w[u][v]);
            }
            curr = curr->next;
        }
    }
    return A;
}


#endif // MSTPRIM_H_INCLUDED
