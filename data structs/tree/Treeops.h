#ifndef TREEOPS_H_INCLUDED
#define TREEOPS_H_INCLUDED
#include "Tree.h"
#include "Queue.h"

NODET CreateNodeTree(int val)
{
    NODET n;
    n = (NODET)malloc(sizeof(struct nodet));
    n->data=val;
    n->left = NULL;
    //n->s.st = (char*)malloc(100*sizeof(char));
    //n->s.w = 0;
    n->right=NULL;
    return n;
}

NODET InsertBST(NODET root, int val)
{
    if(root==NULL) return CreateNodeTree(val);
    if(val > root->data)
        root->right = InsertBST(root->right,val);
    else
        root->left = InsertBST(root->left,val);
    return root;
}

NODET GenerateTree(int n)
{
    int i;
    NODET root=NULL;
    for(i=0;i<n;i++)
    {
        root = InsertBST(root,rand());
    }
    return root;
}

void PrintTree(NODET root)
{
    if(root == NULL )return ;
    PrintTree(root->left);
    printf("%d ",root->data);
    PrintTree(root->right);

}

int MaxDepth(NODET root)
{
    if(root == NULL) return -1;
    int l = 1 + MaxDepth(root->left);
    int r = 1 + MaxDepth(root->right);
    return (l>r)?l:r;
}

void LevelOrder(NODET root)
{
    queue q = CreateQueue();
    q = Enqueue(q,root);
    int count=1,c=0,set=0,leveln=-1,level=1;
    while(q.front!=NULL)
    {
        c = 0;
        while(count--)
        {
            NODET node = QueueTop(q);
            q = Dequeue(q);
            printf("%d ",node->data);
            if(node->left!=NULL){
                q = Enqueue(q,node->left);
                c++;}
            if(node->right!=NULL){
                q = Enqueue(q,node->right);
                c++;}
        }
        printf("\n");
        count=c;
    }

}

#endif // TREEOPS_H_INCLUDED
