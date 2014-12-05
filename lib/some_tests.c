#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include "basicdef.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"

int * counting_sort(int *a,int size)
// k is the largest integer *a is the actual array *b is an empty array size is the size-1 of array a
{
    int  i,k=a[0];
    for(i=1;i<size;i++) if(a[i] > k) k = a[i];
    int *b = (int*)malloc(size*sizeof(int));
    int l=k+1,j,*c = (int*)calloc(l,sizeof(int));
    for(j=0;j<=size;j++)
         (*(c+*(a+j)))++;  //c[i] now contains the number of elements equal to i
    for (i=1;i<=k;i++)
        *(c+i) = *(c+i) + *(c+i-1) ;  //c[i] now contains the number of elements less than or equal to i
    for(i=0;i<=k;i++)
        (*(c+i))--;
    for(j=size;j>=0;j--)
    {
        *(b+*(c+*(a+j))) = *(a+j);  // finally inserting into an array according to the elements placed in c
        (*(c+*(a+j)))--;
    }
    return b;
}

void bucketsort(int *a, int size)
{
    int i,max = a[0],j;
    for(i=1;i<size;i++) if (max < a[i]) max = a[i];
    int *b = (int*)calloc((max+1),sizeof(int));
    for(i=0;i<size;i++)
    (*(b+*(a+i)))++;
    for(i=0,j=0;i<=max;i++)
    {
        while(b[i] > 0)
        {
            *(a+j++) = i;
            (*(b+i))--;
        }
    }
    //return a;
}


int main(int argc, char *argv[])
{
    int *a,i;
    clock_t begin, end;
    FILE *fp;
    fp = fopen("Time Test.txt","a+");
    a = (int*)malloc(10000000*sizeof(int));
    for(i=0;i<10000000;i++)
    a[i] = rand();
    //printarrays(a,1000000);
    begin = clock();
    a = quicksort(a,0,10000000-1);
    end = clock();
    fprintf(fp,"Quick sort time : %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);
    //printarrays(a,1000000);


}
