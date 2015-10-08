#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Treeops.h"

// UNDER CONSTRUCTION: CODE NOT WORKING 

/*	Calculate the maximum path sum in binary tree
	starting from any node and end at any node
*/

int 
maximum(int a, int b)
{
	return (a > b)?a:b;
}

int
maximum_path_sum_binaryTree(NODET root, int *g_max)
{
	int left, right, max;
	if(root == NULL){
		return 0;
	}
	left = maximum_path_sum_binaryTree(root->left, g_max);
	right = maximum_path_sum_binaryTree(root->right, g_max);
	max = maximum(left, right) + root->data;
	if(max > *g_max){
		*g_max = max;
	}
	else if(max < 0){
		return 0;
	}
	return max;
}


int main(int argc, char const *argv[])
{
	/* code */
	int max = 0;
	NODET root = CustomTree();
	Inorder(root);
	maximum_path_sum_binaryTree(root, &max);
	printf("Max = %d\n", max);
	return 0;
}