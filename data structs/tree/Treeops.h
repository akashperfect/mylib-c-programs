#ifndef TREEOPS_H_INCLUDED
#define TREEOPS_H_INCLUDED
#include "Tree.h"
#include "../queue/Queue.h"
#include "../stack/Stack.h"
#include "../array/Array.h"

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

int isLeaf(NODET root)
{
    return (root->left == NULL && root->right == NULL);
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

int hasPathSumRootToLeaf(NODET root, int val)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        if(val == root->data)
            return 1;
        else
            return 0;
    val -= root->data;
    return hasPathSumRootToLeaf(root->left, val) || 
    			hasPathSumRootToLeaf(root->right, val);
}

void
hasPathSum_proc(stack *s, array *a)
{
	NODET *n = pop(s);
	append(a, (*n)->data);
	printArray(a);
	if((*n)->left != NULL){
		push(s, &((*n)->left));
		hasPathSum_proc(s, a);
	}
	if((*n)->right != NULL){
		push(s, &((*n)->right));
		hasPathSum_proc(s, a);
	}


}

void
hasPathSum_main(NODET root)
{
	stack s;
	array a;
	CreateStack(&s);
	createArray(&a, 10);
	push(&s, &root);
	hasPathSum_proc(&s, &a);
}


void printPaths(NODET root, NODET* a, int i)
{
    if(root == NULL)
        return;
    if(isLeaf(root))
    {
        int j = 0;
        for(; j < i ; j++)
            printf("%d ",a[j]->data);
        printf("%d\n", root->data);
    }
    a[i] = root;
    i++;
    printPaths(root->left, a, i);
    printPaths(root->right, a, i);
}

void printPath(NODET root)
{
    NODET *a;
    a = (NODET *)malloc((MaxDepth(root) + 1) *  sizeof(NODET));
    printPaths(root, a, 0);
}


#endif // TREEOPS_H_INCLUDED
