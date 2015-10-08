#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int partition(int *a,int p,int r)// rearranges sub-array A[p..r] in place
{
    int x = *(a+r); //x acts as a pivot element around which partition takes place
    int i = p-1,j,temp;
    for(j=p;j<=r-1;j++)
    {
        if(*(a+j)<=x)
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
int randomized_partition(int *a,int p, int r)
{
    int i,temp;
    i = rand()%(p-r)+r;
    temp = *(a+i);
    *(a+i) = *(a+r);
    *(a+r) = temp;
    return partition(a,p,r);
}
int randomized_select(int *a,int p,int r,int i)
{
    int k,q;
    if(p==r)
        return *(a+p);
    q = randomized_partition(a,p,r);
    k = q-p+1;
    if (i==k) //pivot value is the answer
        return *(a+q);
    else if(i<k)
        return randomized_select(a,p,q-1,i);
    else
        return randomized_select(a,q+1,r,i-k);
}
int main(void)
{
    int *a,size,i,n,x; //x is the nth largest element means n elements are smaller than x
    printf("Enter size and array\n");
    scanf("%d",&size);
    a = (int*)malloc(size*sizeof(int));
    for(i=0;i<size;i++)
    scanf("%d",(a+i));
    scanf("%d",&n);
    size--;
    x = randomized_select(a,0,size,n);
    printf("%d\n",x);
}
