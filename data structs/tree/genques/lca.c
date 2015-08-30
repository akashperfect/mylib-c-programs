#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Treeops.h"

/*	Kth smallest element in the BST
	using O(1) extra space
*/

int
lca(NODET root, int v1, int v2)
{
	if (root == NULL){
		return 0;
	}
	if(root->data >= v1 && root->data <= v2 ){
		return root->data;
	}
	if(root->data > v2){
		return lca(root->left, v1, v2);
	}
	if(root->data < v1){
		return lca(root->right, v1, v2);
	}

}

int main(int argc, char const *argv[])
{
	int lev = 3;
	NODET root = CustomTree();
	printf("%d \n", lca(root, 6, 10));
	return 0;
}