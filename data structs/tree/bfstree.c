#include<stdio.h>
#include<stdlib.h>
typedef struct treenode *tree;
struct treenode
{
    int val;
    tree left;
    tree right;
};
typedef struct queue *qu;
struct queue
{
    tree node;
    qu next;
};
qu createq()
{
    qu q;
    q = (qu*)malloc(sizeof(struct queue));
    q->node = NULL;
    q->next = NULL;
    return q;
}
qu addq(t,q)
{
    qu qnode = createq();
    qu q1 = q;
    qnode->node = t;
    if(q->node==NULL) return qnode;
    while(q->next!=NULL)
    q = q->next;
    qnode->next = q->next;
    q->next = qnode;
    return q1;
}
void bfstree(tree t)
{
    if(t!=NULL)
    {
        qu q = createq();
        q = addq(t,q);
        bfslevel(q);
    }
}
qu deleteq(qu q)
{
    qu q1=q->next;
    free(q);
    return q1;
}
void bfslevel(qu q)
{
    while(q!=NULL)
    {
        tree t = q->node;
        q = deleteq(q);
        tree ch = getchildren(t);
        while(more_ele(ch))
        {
            q = addq(getnext(ch),q);
        }

    }
}
tree fill(tree t,int d)
{
    tree n;
    if(t==NULL||t->val==-1)
    {
        n = (tree*)malloc(sizeof(struct treenode));
        n->val=d;
        n->left=NULL;
        n->right=NULL;
        return n;
    }
    else if(d<=t->val)
    {
        t->left =  fill(t->left,d);
    }
    else
    t->right =  fill(t->right,d);
    return t;
}
tree initialize(tree t)
{
    t = (tree*)malloc(sizeof(struct treenode));
    t->val=-1;
    t->left=NULL;
    t->right=NULL;
    return t;
}
void inorder(tree node) {
  if (node == NULL) return;
  inorder(node->left);
  printf("%d ", node->val);
  inorder(node->right);
}

int main(void)
{
    tree t;
    int d;
    t = initialize(t);
    while(1)
    {
        scanf("%d",&d);
        if(d==-1) break;
        t = fill(t,d);
    }
    inorder(t);
    //bfs(t);
}
