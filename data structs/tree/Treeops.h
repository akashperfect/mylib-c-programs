#ifndef TREEOPS_H_INCLUDED
#define TREEOPS_H_INCLUDED
#include "Tree.h"
#include "../queue/Queue.h"

NODET CreateNodeTree(int val)
{
    NODET n;
    n = (NODET)malloc(sizeof(struct nodet));
    n->data=val;
    n->left = NULL;
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
    NODET root = NULL;
    for(i=0;i<n;i++)
    {
        root = InsertBST(root,rand());
    }
    return root;
}

/* 
the above function returns a tree like this
          5  
      3       8
   2    4  6     9
1             7     10

*/
NODET CustomTree()
{
    NODET root = NULL;
    root = InsertBST(root,5);
    root = InsertBST(root,3);
    root = InsertBST(root,8);
    root = InsertBST(root,2);
    root = InsertBST(root,4);
    root = InsertBST(root,1);
    root = InsertBST(root,6);
    root = InsertBST(root,7);
    root = InsertBST(root,9);
    root = InsertBST(root,10);
}

void Inorder(NODET root)
{
    if(root == NULL )return ;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);

}

void Postorder(NODET root)
{
    if(root == NULL )return ;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);

}

void Preorder(NODET root)
{
    if(root == NULL )return ;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);

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
    q = Enqueue(q , &root);
    while(q.front != NULL)
    {
        NODET node = *(NODET*) QueueTop(q);
        q = Dequeue(q);
        printf("%d ",node->data);
        if(node->left!=NULL){
            q = Enqueue(q , &node->left);
        }
        if(node->right!=NULL){
            q = Enqueue(q , &node->right);
        }
    }
}

int hasPathSum(NODET root, int val)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        if(val == root->data)
            return 1;
        else
            return 0;
    val -= root->data;
    return hasPathSum(root->left, val) || hasPathSum(root->right, val);
}

#endif // TREEOPS_H_INCLUDED
