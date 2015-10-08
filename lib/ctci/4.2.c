#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct node * NODE;
typedef struct node{
    int num;
    NODE next;
};

typedef struct{
    int size;
    NODE head;
    NODE tail;
}queue;

typedef struct {
int size;
NODE head;
}adl;

NODE NewNode(int v)
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));
    n->num = v;
    n->next = NULL;
    return n;
}

adl AddNode(adl a,int v)
{
    NODE ins = NewNode(v);
    if(a.head==NULL)
        a.head = ins;
    else
    {
        ins->next = a.head;
        a.head = ins;
    }
    a.size++;
    return a;
}

adl* Initialize()
{

    int size,t,ver,e,u,v,i;
    printf("Vertices = ");
    scanf("%d",&ver);
    printf("Edges = ");
    scanf("%d",&e);
    t = e;
    adl * g = (adl*)malloc((ver+1)*sizeof(adl));
    for(i=0;i<=ver;i++)
    {
    	g[i].head=NULL;
    	g[i].size=0;
    }
    while(t--)
    {
        scanf("%d%d",&u,&v);
        g[u] = AddNode(g[u],v);
    }
    return g;
}

queue InitializeQueue()
{
    queue q;
    q.size=0;
    q.head=NULL;
    q.tail=NULL;
    return q;

}
queue Enqueue(queue q, NODE s)
{
    NODE n = NewNode(s->num);
    if(q.head==NULL)
    {
        q.head = n;
        q.tail = n;
    }
    else
    {
        q.tail->next = n;
        q.tail = n;
    }
    q.size++;
    return q;
}

NODE Dequeue(queue *q)
{
    NODE n = (*q).head;
    (*q).head = (*q).head->next;
    return n;
}

int bfs(adl *graph, queue q, NODE s, int e)
{
    q = Enqueue(q,s);
    NODE no,list;
    while(q.head!=NULL)
    {
        no = Dequeue(&q);
        list = graph[no->num].head;
        while(list!=NULL)
        {
            if(list->num==e)
            return 1;
            q = Enqueue(q,list);
            list = list->next;
        }
    }
    return 0;
}

void print(adl * g)
{
    int i;
    for(i=0;i<9;i++)
    {
        NODE head = g[i].head;
        while(head!=NULL)
        {
            printf("%d->",head->num);
            head = head->next;
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int a,e,b;
    adl * graph; queue q;
    printf("start and end\n");
    scanf("%d%d",&a,&b);
    NODE s = NewNode(a);
    graph = Initialize(graph);
    //print(graph);
    q = InitializeQueue();
    if(bfs(graph,q,s,e))
    printf("Found\n");
    else
    printf("Not Found");

}
