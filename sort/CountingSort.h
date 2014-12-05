#include<stdio.h>
#include<stdlib.h>
/*int counting_sort(int *a,int *b,int k,int size)
// k is the largest integer *a is the actual array *b is an empty array size is the size-1 of array a
{
    int i,l=k+1,c[l],j;
    for(i=0;i<=k;i++)
        *(c+i) = 0;
    for(j=0;j<=size;j++)
         (*(c+*(a+j)))++;  //c[i] now contains the number of elements equal to i
    for (i=1;i<=k;i++)
        *(c+i) +=  *(c+i-1) ;  //c[i] now contains the number of elements less than or equal to i
    for(i=0;i<=k;i++)
        (*(c+i))--;
    for(j=size;j>=0;j--)
    {
        *(b+*(c+*(a+j))) = *(a+j);  // finally inserting into an array according to the elements placed in c
        (*(c+*(a+j)))--;
    }
}*/

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
/*int main(void)
{
    int *a,*b,k=-1,size,i;
    printf("Enter size and array\n");
    scanf("%d",&size);
    a = (int*)malloc(size*sizeof(int));
    b = (int*)malloc(size*sizeof(int));
    for(i=0;i<size;i++)
    {
        scanf("%d",(a+i));
        if(*(a+i)>k) k = *(a+i);
    }
    size--;
    counting_sort(a,b,k,size);
    for(i=0;i<=size;i++)
    printf("%d ",*(b+i));
}*/
