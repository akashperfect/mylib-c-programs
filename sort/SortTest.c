#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "MergeSort.h"
// #include "QuickSelect.h"
// #include "QuickSort.h"
// #include "BubbleSort.h"
// #include "SelectionSort.h"
#include "InsertionSort.h"

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
	int i, *a, size = 25000;
	a = (int *)calloc(size,sizeof(int));
	for(i = 0 ; i < size ; i ++)
	{
		a[i] = rand()%100;
	}
	// TestFunction(a+2, size-2);
	// printf("%d\n", QuickSelect(a, 9, size-1));
	clock_t start = clock();
	InsertionSort(a,size);
	clock_t end = clock();
	// BubbleSort(a,size);
	// QuickSort(a,size-1);
	printf("%lf\n", (double)(end - start)/CLOCKS_PER_SEC);
	// for (i = 0; i < size; ++i)
	// {
	// 	printf("%d ",a[i]);
	// }


	return 0;
}