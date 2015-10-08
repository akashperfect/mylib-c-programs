/* D&C type partitions array into two a[p..q-1], a[q+1..r] such that each element of first array is
lesser than or equal a[q] and each element of second array is bigger than or equal a[q] and the two
arrays are sorted by recursive calls to quicksort

Pivot : Always taken as the last element in the array

This is a special implementation using only higher value
QuickSort(int *a, int r)
instead of QuickSort(int *a, int p, int r)
*/

#include <stdio.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int rand_partition(int *a, int r)   // rearranges sub-array A[p..r] in place
{
    swap(a + rand()%r, a + r);  
    int x = *(a + r);               //x acts as a pivot element around which partition takes place
    int i = -1,j,temp;
    for(j = 0 ; j < r ; j++)
    {
        if(*(a+j) <= x)
        {
            i++;
            temp = *(a+j);
            *(a+j) = *(a+i);
            *(a+i) = temp;
        }
    }
    i++;
    *(a+r) = *(a+i);
    *(a+i) = x;
    return i;
}

int partition(int *a, int r)   // rearranges sub-array A[p..r] in place
{
    int x = *(a+r);                 //x acts as a pivot element around which partition takes place
    int i = -1,j,temp;
    for(j = 0 ; j < r ; j++)
    {
        if(*(a+j) <= x)
        {
            i++;
            temp = *(a+j);
            *(a+j) = *(a+i);
            *(a+i) = temp;
        }
    }
    i++;
    *(a+r) = *(a+i);
    *(a+i) = x;
    return i;
}
void QuickSort(int *a, int r)
{
    int q;
    if(r > 0)
    {
        q = rand_partition(a, r);       // partitioning the array based on the pivot, which is the last element of the array.
        QuickSort(a, q-1);
        QuickSort(a+q+1, r-q-1);
    }
}