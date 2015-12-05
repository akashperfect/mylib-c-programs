#ifndef ARRAYOPS_H_INCLUDED
#define ARRAYOPS_H_INCLUDED
#include "Arrayadt.h"

void
createArray(array *a, int size)
{
	a->arr = (int *)calloc(size, sizeof(int));
	a->size = size;
	a->last = 0; 
}

void
append(array *a, int value)
{
	if(a->last == a->size - 1){
		printf("Array full cannot insert more\n");
		return ;
	}
	a->arr[a->last] = value;
	a->last ++;
}

void
printArray(array *a)
{
	int i = 0;
	printf("Printing the array\n");
	for( ; i < a->last ; i ++){
		printf("%d \n", a->arr[i]);
	}
	printf("\n");
}



#endif