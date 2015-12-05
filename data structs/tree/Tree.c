#include <stdio.h>
#include <stdlib.h>
#include "Treeops.h"

int main(int argc, char ** argv)
{
	NODET root;
	root = CustomTree();
	Inorder(root);
	printf("\n");
	Postorder(root);
	printf("\n");
	Preorder(root);
	printf("\n");
	LevelOrder(root);
	printf("\n%d\n", hasPathSumRootToLeaf(root,10));
	printPath(root);
}