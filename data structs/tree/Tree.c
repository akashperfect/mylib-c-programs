#include <stdio.h>
#include <stdlib.h>
#include "Treeops.h"

int main(int argc, char ** argv)
{
	NODET root;
	root = CustomTree();
	PrintTree(root);
	printf("\n");
	Postorder(root);
	printf("\n");
	Preorder(root);
	printf("\n");
	LevelOrder(root);
}