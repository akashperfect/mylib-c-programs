#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"
#include "Treeops.h"


void NextNode(NODET root,NODET key)
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
            if(set == 1 && leveln==level){
            printf("next node = %d\n",node->data);
            return ;}
            if(node==key) {set=1;leveln=level;}
            if(node->left!=NULL){
                q = Enqueue(q,node->left);
                c++;}
            if(node->right!=NULL){
                q = Enqueue(q,node->right);
                c++;}
        }
        //printf("\n");
        level++;
        count=c;
    }

}


int main(int argc, char *argv[])
{
    NODET root = GenerateTree(20);
    //PrintTree(root);
    LevelOrder(root);
    NextNode(root,root->right->right->left);
    printf("\nheight = %d\n",MaxDepth(root));


}
