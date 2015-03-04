#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MergeSort.h"
#include "QuickSort.h"

int main(int argc, char const *argv[])
{
	int i, *a, size = 100;
	a = (int *)calloc(size,4);
	for(i = 0 ; i < size ; i ++)
	{
		a[i] = rand();
	}
	QuickSort(a,0,size-1);
	for (i = 0; i < size; ++i)
	{
		printf("%d ",a[i]);
	}
	return 0;
}