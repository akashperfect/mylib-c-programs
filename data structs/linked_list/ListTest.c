#include <stdio.h>
#include <stdlib.h>
#include "Linkops.h"

int main(int argc, char const *argv[])
{
	List l = CreateList();
	// FIXFIX there is an address mismatch over here 
	//Insertion is not implemented
	printf("%u \n", &l);
	l = CustomList(l);
	printf("%u \n", &l);
	printf("%d ",l.size);
	NODE curr = l.head;
	printf("%u \n", &l);
	// printf("%d ", *(int *) curr->data);
	PrintList(l);
	return 0;
}