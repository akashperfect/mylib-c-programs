#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Treeops.h"

// UNDER CONSTRUCTION: CODE NOT WORKING 

/*	Kth smallest element in the BST
	using O(1) extra space
*/

int
Kth_smallest(NODET root, int *lev)
{
	if (root == NULL){
		return ;
	}
	printf("root data = %d and level = %d\n", root->data, *lev);
	if(*lev == 1){
		*lev = 0;
		return root->data;
	}
	if(*lev > 1){
		Kth_smallest(root->left, lev);
		if(*lev == 1){
			*lev = 0;
			return root->data;
		}
		*lev -=  1;
		Kth_smallest(root->right, lev);
		if(*lev == 1){
			*lev = 0;
			return root->data;
		}
	}
}

int main(int argc, char const *argv[])
{
	int lev = 3;
	NODET root = CustomTree();
	printf("%d \n", Kth_smallest(root, &lev));
	return 0;
}