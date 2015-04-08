#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MergeSort.h"
// #include "QuickSelect.h"
#include "QuickSort.h"

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
	int i, *a, size = 100;
	a = (int *)calloc(size,sizeof(int));
	for(i = 0 ; i < size ; i ++)
	{
		a[i] = rand()%100;
	}
	// TestFunction(a+2, size-2);
	// printf("%d\n", QuickSelect(a, 9, size-1));
	QuickSort(a,size-1);
	for (i = 0; i < size; ++i)
	{
		printf("%d ",a[i]);
	}


	return 0;
}