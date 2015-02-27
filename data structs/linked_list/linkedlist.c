#include<stdio.h>
#include<stdlib.h>
struct node;
typedef struct node NODE;
typedef NODE *LINK;
struct node{
int e;
LINK next;
};

typedef struct {
int size;
LINK Head;
}List;

List initialize()
{
    List ll;
    ll.size = 0;
    ll.Head = NULL;
    return ll;
}

List insert(List l, int e)
{
    LINK n,curr,prev,temp;int f=0;
    n = (LINK)malloc(sizeof(NODE));
    n->e=e;
    n->next=NULL;
    prev = curr = l.Head;
    if(l.Head==NULL) {l.Head = n;  return l;}
    while(curr!=NULL)
    {

        if(curr->e<=e){
        temp=curr;f=1;
        break;}
        prev=curr;
        curr = curr->next;
    }
    if(curr==l.Head) { l.Head = n; n->next = temp; return l;  }
    else if(curr==NULL)
    {
        prev->next=n; return l;
    }
    prev->next=n;
    n->next=curr->next;
    free(temp);

    return l;

}

List update(List l,int o,int e)
{
    LINK n,curr,prev,temp;int f=0;
    n = (LINK)malloc(sizeof(NODE));
    n->e=e;
    n->next=NULL;
    curr = l.Head;
    while(curr!=NULL)
    {

        if(curr->e==o){
        temp=curr;f=1;
        break;}
        prev=curr;
        curr = curr->next;
    }
    if(f==1){
    prev->next=n;
    n->next=curr->next;
    free(temp);}
    else printf("Not Found\n");
    return l;
}

List deleten(List l,int e)
{
    LINK curr,prev,temp;int f=0;
    curr = l.Head;
    prev=curr;
    while(curr!=NULL)
    {
        if(curr->e==e)
        {
            temp = curr;
            prev->next=curr->next;
            free(temp);f=1;
            break;
        }
        prev = curr;
        curr = curr->next;
    }if (f==1)
    l.size--;
    else printf("Not Found\n");
    return l;
}

void checkloop(List l)
{
    LINK f1,f2,temp;
    f1 = l.Head;
    f2 = l.Head;
    do
    {
        f1 = f1->next;
        if(f1==NULL) break;
        f1 = f1->next;
        f2 = f2->next;
    }while(f1!=f2&&f1!=NULL&&f2!=NULL);
    if(f1==f2) printf("Loop\n");
    else printf("No Loop\n");
}

int main(void)
{
    int in,o,d;
    char c,c1[2];
    List ll = initialize();
    do{
    fflush(stdin);
    printf("Insert(i),Update(u),Delete(d),Print(p),CheckLoop(l)\n");
    scanf("%c",&c);
    switch (c)
    {
        case 'i':
        {
            printf("Enter element\n");
            scanf("%d",&in);
            ll = insert(ll,in);
            break;
        }
        case 'u':
        {
            printf("Original and update element\n");
            scanf("%d%d",&o,&in);
            ll = update(ll,o,in);
            break;

        }
        case 'd':
        {
            printf("Element to delete\n");
            scanf("%d",&d);
            ll = deleten(ll,d);
            break;
        }
        case 'p':
        {
            LINK curr = ll.Head;
            while(curr!=NULL)
            {
                printf("%d # ",curr->e);
                curr = curr->next;
            }
            printf("\n");
            break;
        }
        case 'l':
        {
            checkloop(ll);
        }


    }
    printf("Continue(y/n)\n");
    }while(scanf("%s",c1)&&c1[0]=='y');
    return 0;

}
