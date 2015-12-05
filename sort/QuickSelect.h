/* 	Function for finding an element in an array
  	with rank = k 
	FIXFIX partition with median of elements is not working

*/
#include "QuickSort.h"

void swap(int *a, int p, int r)
{
	int temp = *(a+p);
	*(a+p) = *(a+r);
	*(a+r) = temp;
}

int QuickMed(int n)
{
	int i, *b, x, m;
	if(n <= 5)
	{
		return n/2;
	} 
	m = (n - 1) / 5;
	b = (int *)calloc(m+1, sizeof(int));
	for(i = 0; i < m; i ++)
	{
		b[i] = i*5 + 2;
	}
	b[i] = i*5 + n/2;
	x = QuickMed(b, i);
	return x;
}

int Partition(int *a,int r,int x)   // rearranges sub-array A[p..r] in place
{
    int i = -1,j,temp;
    swap(a, r, x);
    for(j = 0 ; j < r ; j++)
    {
        if(*(a+j) <= x)
        {
            i++;
            swap(a, i, j);
        }
    }
    i++;
    *(a+r) = *(a+i);
    *(a+i) = x;
    return i;
}

int QuickSelect(int *a, int k, int n)
{
	int b, p;
	b = QuickMed(a, n);
	p = Partition(a, b, n);
	if(k == p)
		return a[k];
	else if(k < p)
		return QuickSelect(a, k, p-1);
	else
		return QuickSelect(a+p+1, k-p-1, n-p-1);
}