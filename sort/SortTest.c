#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MergeSort.h"
#include "QuickSelect.h"

int TestFunction(int *a, int n)
{
	int i;
	for(i = 0; i < n; i ++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

}

int main(int argc, char const *argv[])
{
	int i, *a, size = 10;
	a = (int *)calloc(size,4);
	for(i = 0 ; i < size ; i ++)
	{
		a[i] = rand();
	}
	// TestFunction(a+2, size-2);
	printf("%d\n", QuickSelect(a, 9, size-1));
	QuickSort(a,size-1);
	for (i = 0; i < size; ++i)
	{
		printf("%d ",a[i]);
	}


	return 0;
}