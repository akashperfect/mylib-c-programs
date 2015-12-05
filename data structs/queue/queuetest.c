#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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


typedef struct{
    int size;
    NODE front;
}queue;

extern NODE CreateNode();
extern NODE InsertValue(NODE n, int val);
extern int Value(NODE n);
extern queue CreateQueue();
extern queue Enqueue(queue s, NODE n);
extern queue Dequeue(queue s);
extern NODE front(queue s);
extern void PrintQueue(queue s);

NODE CreateNode()
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node*));
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


queue CreateQueue()
{
    queue q;
    q.size = 0;
    q.front = NULL;
    printf("nb");
    return q;
}

queue Enqueue(queue q, NODE n)
{
    NODE curr,prev;
    curr=prev=q.front;
    printf("gg");
    if(q.front==NULL)
    q.front = n;
    else
    {
        printf("tt");
        while(curr!=NULL)
        {
            prev = curr;
            curr = curr->next;
            printf("qq");
        }
        prev->next = n;

    }
    printf("yy");
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

int main()
{
    queue s = CreateQueue();
    NODE n = CreateNode();
    NODE n1 = CreateNode();
    NODE n2 = CreateNode();
    printf("aa");
    n = InsertValue(n,9);
    printf("bb");
    s = Enqueue(s,n);
    printf("cc");
    n1 = InsertValue(n1,6);
    s = Enqueue(s,n1);
    printf("dd");
     n2 = InsertValue(n2,4);
     printf("ff");
    s = Enqueue(s,n2);
    printf("ee");
    PrintQueue(s);
    s = Dequeue(s);
    PrintQueue(s);
    //printf("%d\n",top(s)->s.num);
    return 0;
}

