#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXINT  2147483647
#define MININT -2147483648


typedef struct {
    int num; // satellite data any number of vars can be added
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
    SAT s;
    int k;
}priorityqueue;

typedef priorityqueue * pq;

typedef struct
{
    pq p;
    int size;
}PQ;

typedef struct {
    int size;
    int d;
    NODE top;
}stack;


typedef struct{
    stack * list;
    int size;
}graph;


typedef struct{
    int size;
    NODE front;
}queue;


extern NODE CreateNode();
extern NODE InsertValue(NODE n, int val);
extern int Value(NODE n);
extern stack CreateStack();
extern stack push(stack s, int val);
extern stack pop(stack s);
extern NODE top(stack s);
extern void PrintStack(stack s);
extern queue CreateQueue();
extern queue Enqueue(queue s, NODE n);
extern queue Dequeue(queue s);
extern NODE front(queue s);
extern void PrintQueue(queue s);
extern void printgraphd(graph g);
extern PQ MaxHeapify(PQ p, int i);
extern PQ InsertPQ(PQ p,int n);
extern int MaximumPQ(PQ p);
extern PQ IncreaseKeyPQ(PQ p, int x, int k);
extern int ExtractMaxPQ(PQ *p);
extern PQ CreatePQ(int n);
extern void ExchangePQ(priorityqueue *p,priorityqueue* q);
extern void InsertValuePQ(priorityqueue *p, int n);
extern void InsertKeyPQ(priorityqueue *p, int n);
extern PQ MinHeapify(PQ p, int i);
extern PQ InsertPQ(PQ p,int n);
extern PQ InsertMinPQ(PQ p,int k, int val);
extern int MinimumPQ(PQ p);
extern PQ DecreaseKeyPQ(PQ p, int x, int k);
extern int ExtractMinPQ(PQ *p);
extern graph CreateGraph(int n);
extern int ** CreateGraphAM(int n);
extern graph AddNode(graph g, int n);
extern graph AddEdge(graph g, int v, int w);
extern graph AddWeightedEdge(graph g, int u, int v, int wt, int *** wi );
extern graph AddEdgeW(graph g, int u, int v,int wt, int *** w);
extern graph InitializeSingleSource(graph g, int s);
extern NODE GraphNodeV(graph g, int u, int v);
extern graph RelaxEdge(graph g, PQ *q, int u, int v, int **w);
extern PQ MakePQofGraph(graph g);
extern void DFS(graph g);
extern void BFS(graph g);
extern int Dijkstra(graph g, int st, int e, int **w);


NODE CreateNode()
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));
    n->s.num=0;
    //n->s.w = 0;
    n->next=NULL;
    n->prev=NULL;
    return n;
}

NODE InsertValue(NODE n, int val)
{
    n->s.num = val;
    return n;
}

int Value(NODE n)
{
    return n->s.num;
}

int ValuePQ(priorityqueue p)
{
    return p.k;
}


stack CreateStack()
{
    stack s;
    s.size=0;
    s.d = 0;
    s.top=NULL;
    return s;
}

stack push(stack s, int val)
{
    NODE n = CreateNode();
    n = InsertValue(n, val);
    if(s.top!=NULL)
    n->next = s.top;
    s.top = n;
    s.size++;
    return s;
}

stack pop(stack s)
{
    NODE temp;
    temp = s.top;
    if(s.top==NULL)
    {
        printf("Error - NULL STACK\n");
        exit(0);
    }
    s.top = s.top->next;
    s.size--;
    free(temp); // removing garbage value
    return s;
}

NODE top(stack s)
{
    return s.top;
}

void PrintStack(stack s)
{
    NODE pr = s.top;
    while(pr!=NULL)
    {
        printf("%d ",pr->s.num);
        pr = pr->next;
    }
}



queue CreateQueue()
{
    queue q;
    q.size = 0;
    q.front = NULL;
    return q;
}

queue Enqueue(queue q, NODE n)
{
    NODE curr,prev;
    curr=prev=q.front;
    if(q.front==NULL)
    q.front = n;
    else
    {
        while(curr!=NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = n;

    }
    q.size++;
    return q;
}

queue Dequeue(queue q)
{
    NODE del = q.front;
    q.front = q.front->next;
    free(del);
    return q;
}

NODE QueueTop(queue q)
{
    return q.front;
}

void PrintQueue(queue q)
{
    NODE pr = q.front;
    while(pr!=NULL)
    {
        printf("%d ",pr->s.num);
        pr = pr->next;
    }

}


PQ CreatePQ(int n)
{
    PQ p;
    p.p = (pq)malloc(n*sizeof(priorityqueue));
    p.size=0;
    return p;
}

PQ MaxHeapify(PQ p, int i)
{
    int left = 2*i+1, right = 2*i+2,large;
    if (left<p.size&&ValuePQ(p.p[left])>ValuePQ(p.p[i]))
        large = left;
    else
        large = i;
    if (right<p.size && ValuePQ(p.p[right])>ValuePQ(p.p[large]))
        large = right;
    if(large!=i)
    {
        ExchangePQ(&p.p[i],&p.p[large]);
        p = MaxHeapify(p,large);
    }
    return p;
}

PQ InsertPQ(PQ p,int n)
{
    InsertValuePQ(&p.p[p.size],-1);
    p = IncreaseKeyPQ(p,p.size,n);
    p.size++;
    return p;
}

int MaximumPQ(PQ p)
{
    return ValuePQ(p.p[0]);
}

PQ IncreaseKeyPQ(PQ p, int x, int k)
{
    if(ValuePQ(p.p[x])>k)
    {
        printf("ERROR: new key smaller than previous\n");
        return p;
    }
    InsertValuePQ(&p.p[x],k);
    while(x>0&&ValuePQ(p.p[x/2])<ValuePQ(p.p[x]))
    {
        ExchangePQ(&p.p[x], &p.p[x/2]);
        x = x/2;
    }
    return p;
}


int ExtractMaxPQ(PQ *q)
{
    PQ p = *q;
    int max = ValuePQ(p.p[0]);
    p.p[0].k =  p.p[p.size-1].k;
    p.size--;
    p = MaxHeapify(p, 0);
    *q = p;
    return max;
}

void PrintPQ(PQ p)
{
    int i=0;
    printf("\nsize %d\n",p.size);
    while(i<p.size)
    {
        printf("%d,%d ",ValuePQ(p.p[i]),p.p[i].s.num);
        i++;
    }
}

void printgraphd(graph g)
{
    int i=1;
    //printf("\nsize %d\n",p.size);
    while(i<=g.size)
    {
        printf("%d ",g.list[i].d);
        i++;
    }
}

void ExchangePQ(priorityqueue *p,priorityqueue* q)
{
    /*pq * temp;
    temp = p;
    p = q;
    q = temp;*/
    //printf("bp = %d bq = %d",(*p).k,(*q).k);
    priorityqueue temp;
    temp = *p;
    *p = *q;
    *q = temp;
    //printf("ap = %d aq = %d\n",(*p).k,(*q).k);
}

void InsertValuePQ(priorityqueue *p, int n)
{
    (*p).s.num = n;
    //printf("aa");
}

void InsertKeyPQ(priorityqueue *p, int n)
{
    (*p).k = n;
    //printf("aa");
}

PQ MinHeapify(PQ p, int i)
{
    int left = 2*i+1, right = 2*i+2,small;
    if (left<p.size&&ValuePQ(p.p[left])<ValuePQ(p.p[i]))
        small = left;
    else
        small = i;
    if (right<p.size && ValuePQ(p.p[right])<ValuePQ(p.p[small]))
        small = right;
    if(small!=i)
    {
        ExchangePQ(&p.p[i],&p.p[small]);
        p = MinHeapify(p,small);
    }
    return p;
}

PQ InsertMinPQ(PQ p,int k, int val)
{
    InsertKeyPQ(&p.p[p.size],MAXINT);
    p.p[p.size].s.num = val;
    //printf("p.size = %d val = %d p.p[3]num = %d\n",p.size,val,p.p[3].s.num);
    p = DecreaseKeyPQ(p,p.size,k);
    p.size++;
    return p;

}

int MinimumPQ(PQ p)
{
    return ValuePQ(p.p[0]);
}

PQ DecreaseKeyPQ(PQ p, int x, int k)
{
    int i=0;
    for(i;i<p.size;i++)
    {
        if(p.p[i].s.num==x)
        {x=i;break;}

    }
    if(ValuePQ(p.p[x])<k)
    {
        printf("ERROR: new key larger than previous");
        return p;
    }
    p.p[x].k = k;
    while(x>0&&p.p[x/2].k>p.p[x].k)
    {
        ExchangePQ(&p.p[x], &p.p[x/2]);
        x = x/2;
    }
    return p;
}


int ExtractMinPQ(PQ *q)
{
    PQ p = *q;
    int min = p.p[0].s.num;
    p.p[0] =  p.p[p.size-1];
    p.size--;
    p = MinHeapify(p, 0);
    *q = p;
    return min;
}



graph CreateGraph(int n)
{
    graph g;
    int i=0;
    g.list = (stack*)malloc((n+1)*sizeof(stack));
    while(i<=n)
    {
        g.list[i] = CreateStack();
        i++;
    }
    g.size = n+1;
    return g;
}

int ** CreateGraphAM(int n)
{
    int ** w,i;
    w = (int**)calloc((n+1),sizeof(int*));
    for(i=0;i<=n;i++)
    {
        w[i] = (int*)calloc((n+1),sizeof(int));
    }
    return w;
}

graph AddNode(graph g, int n)
{
    g.list = (stack*)realloc(g.list,n * sizeof(stack));
    return g;
}

/*
stack * CreateGraph(int n)
{
    stack  list[n];
    return list;
}
*/

graph AddEdge(graph g, int v, int w)
{
    g.list[v] = push(g.list[v],w);
    g.list[w] = push(g.list[w],v);
    return g;
}

graph AddWeightedEdge(graph g,  int u, int v, int wt, int *** wi)
{
    //int ** we = (*wi);
    g = AddEdge(g,u,v);
    //g.list[u].top->s.w = wt;
    //g.list[v].top->s.w = wt;
    /*we[u][v] = wt;
    we[v][u] = wt;
    (*wi) = we;*/
    return g;
}

graph AddEdgeW(graph g, int u, int v, int wt, int ***w)
{
    //int ** we = (*w);
    g.list[u] = push(g.list[u],v);
    g.list[v] = push(g.list[v],u);
    *(*(*w+u)+v) = wt;
    *(*(*w+v)+u) = wt;
    return g;
}

graph InitializeSingleSource(graph g, int s)
{
    int i = g.size;
    while(i>0)
    {
        g.list[i].d = MAXINT;
        i--;
    }
    g.list[s].d=0;
    return g;
}

NODE GraphNodeV(graph g, int u, int v)
{
    NODE curr = g.list[u].top;
    while(curr!=NULL)
    {
        if(curr->s.num==v)
        return curr;
        curr = curr->next;
    }
    return ;
}

graph RelaxEdge(graph g, PQ *q, int u, int v, int **w)
{
    PQ p = *q;
    if(g.list[v].d > g.list[u].d + w[u][v])
    {
        g.list[v].d = g.list[u].d + w[u][v];
        p = DecreaseKeyPQ(p,v,g.list[v].d);
    }
    *q = p;
    return g;
}

PQ MakePQofGraph(graph g)
{
    PQ p = CreatePQ(g.size+1);
    int i=1;
    while(i<g.size)
    {
        p = InsertMinPQ(p,g.list[i].d,i);
        i++;
    }
    return p;
}


int Dijkstra(graph g, int st, int e, int **w)
{
    InitializeSingleSource(g,st);
    PQ p = MakePQofGraph(g);
    stack s;
    NODE curr;
    int u,v;
    while(p.size>0)
    {
        u = ExtractMinPQ(&p);
        if(u==e) return g.list[u].d;
        //s = push(s,u);
        curr = g.list[u].top;
        while(curr!=NULL)
        {
            v = curr->s.num;
            if(g.list[v].d > g.list[u].d + w[u][v])
            {
                g.list[v].d = g.list[u].d + w[u][v];
                p = DecreaseKeyPQ(p,v,g.list[v].d);
            }
            curr = curr->next;
        }
    }
    return MAXINT;
}

int main()
{
    graph g;
    int ** w;
    g = CreateGraph(9);
    w = CreateGraphAM(9);
    g = AddEdgeW(g,1,2,5,&w);
    g = AddEdgeW(g,1,4,6,&w);
    g = AddEdgeW(g,1,3,7,&w);
    g = AddEdgeW(g,4,2,2,&w);
    g = AddEdgeW(g,3,4,1,&w);
    g = AddEdgeW(g,3,5,8,&w);
    g = AddEdgeW(g,6,4,9,&w);
    g = AddEdgeW(g,5,9,1,&w);
    g = AddEdgeW(g,5,8,4,&w);
    g = AddEdgeW(g,7,8,2,&w);
    NODE curr = g.list[1].top;
    printf("%d",curr->s.num);
    printf("path = %d\n",Dijkstra(g,1,5,w));

    return 0;

}
