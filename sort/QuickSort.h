/* D&C type partitions array into two a[p..q-1], a[q+1..r] such that each element of first array is
lesser than or equal a[q] and each element of second array is bigger than or equal a[q] and the two
arrays are sorted by recursive calls to quicksort

Pivot : Always taken as the last element in the array
*/

#include <stdio.h>
#include <stdio.h>

int partition(int *a,int p,int r)   // rearranges sub-array A[p..r] in place
{
    int x = *(a+r);                 //x acts as a pivot element around which partition takes place
    int i = p-1,j,temp;
    for(j = p ; j <= r-1 ; j++)
    {
        if(*(a+j) <= x)
        {
            i++;
            temp = *(a+j);
            *(a+j) = *(a+i);
            *(a+i) = temp;
        }
    }
    temp = *(a+i+1);
    *(a+i+1) = *(a+r);
    *(a+r) = temp;
    return i+1;
}
void QuickSort(int *a,int p,int r)
{
    int q;
    if(p < r)
    {
        q = partition(a,p,r);       // partitioning the array based on the pivot, which is the last element of the array.
        QuickSort(a,p,q-1);
        QuickSort(a,q+1,r);
    }
}



