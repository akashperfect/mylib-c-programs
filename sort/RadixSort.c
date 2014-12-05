#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Radix sort uses counting sort to sort the numbers based on the digits of each element of array a
It starts sorting from the least significant bit to the most significant bit , which ensures the
elements are sorted in place. It uses counting sort because its a stable sort. */

int counting_sort(int *a,int *b,int k,int size,int d) // k is the largest integer
{
    int i,l=k+1,c[l],j,d1,n;
    d1 = (int)pow(10.0,(double)d);
    for(i=0;i<=k;i++)
        *(c+i) = 0;
    for(j=0;j<=size;j++)
    {
        n = ((*(a+j))%d1)/(d1/10);
        (*(c+n))++;  //c[i] now contains the number of elements equal to i
    }
    for (i=1;i<=k;i++)
        *(c+i) = *(c+i) + *(c+i-1) ;  //c[i] now contains the number of elements less than or equal to i
    for(i=0;i<=k;i++)
        (*(c+i))--;
    for(j=size;j>=0;j--)
    {
        n = ((*(a+j))%d1)/(d1/10);
        *(b+*(c+n)) = *(a+j);
        (*(c+n))--;
    }
    for(i=0;i<=size;i++)
    *(a+i)=*(b+i);

}
int radixsort(int *a,int *b,int d,int size)// d is the number of digits in all the elements
// a is the actual array and b is an empty array to hold the final sorted list
{
    int i;
    for(i=1;i<=d;i++)
    counting_sort(a,b,9,size,i);
}
int main(void)
{
    int *a,*b,k=-1,size,i,count=0,t;
    printf("Enter size and array\n");
    scanf("%d",&size);
    a = (int*)malloc(size*sizeof(int));
    b = (int*)malloc(size*sizeof(int));
    for(i=0;i<size;i++)
    {
        scanf("%d",(a+i));
    }
    t=*a;
    while(1)
    {
        if(t!=0)
        t/=10;
        else break;
        count++;
    }
    size--;
    radixsort(a,b,count,size);
    for(i=0;i<=size;i++)
    printf("%d ",*(b+i));
    return 0;
}
