#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//////Data Structure////
typedef struct node* NODE;

typedef struct node{
    int data;
    NODE next;
    NODE prev;
};

typedef struct
{
    int size;
    NODE head;
    NODE tail;
}List;

///////Helper Functions//////////

NODE CreateNode(int val)
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));
    n->data=val;
    n->prev = NULL;
    n->next=NULL;
    return n;
}

List CreateList()
{
    List l;
    l.size = 0;
    l.head = NULL;
    l.tail = NULL;
    return l;
}

List UnsortInsertDLL(List L, int n)
{
    NODE v;
    v = CreateNode(n);
    if(L.head == NULL)
    {
        L.head = v;
        L.tail = v;
    }
    else
    {
        v->next = L.head;
        L.head->prev = v;
        L.head = v;
    }
    L.size++;
    return L;
}

void PrintList(List L)
{
    NODE curr = L.head;
    int i=0;
    while(curr!=NULL)
    {
        printf("%d\n",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

//////////Quick Sort Code////////////

NODE partition_dll(NODE *s, NODE *en)
{
    if(*s==*en) return *s;

    int tempi;
    NODE small = *s ,piv = *en,curr = *s,temp;

    while(curr!=NULL && curr!=*en)
    {
        if(curr->data < piv->data)
        {
            tempi = small->data;
            small->data = curr->data;
            curr->data = tempi;
            small = small->next;
        }
        curr = curr->next;

    }
    tempi = piv->data;
    piv->data = small->data;
    small->data = tempi;
    return small;
}

void quicksort(List *L, NODE *s, NODE *en)
{
    NODE p;
    p = partition_dll(s,en);
    if(*s!=p)
    quicksort(L,s,&(p->prev));
    if(p!=*en)
    quicksort(L,&(p->next),en);
}

///////////Main or Driver Function/////////

int main(int argc, char *argv[])
{
    int i,r,n;
    FILE *fp;
    List L = CreateList();
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        L = UnsortInsertDLL(L,rand());
    }
    quicksort(&L,&(L.head),&(L.tail));
    PrintList(L);


}
