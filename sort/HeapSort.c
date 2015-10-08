#include<stdio.h>
#include<stdlib.h>
int max_heapify(int *a,int i,int size)
{
    int l = 2*i+1,r = 2*(i+1),temp,largest;
    if(l<=size &&a[l]>a[i])
        largest=l;
    else
        largest=i;
    if(r<=size && a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        temp = *(a+i);
        *(a+i) = *(a+largest);
        *(a+largest) = temp;
        max_heapify(a,largest,size);
    }
}

int build_max_heap(int *a,int size)
{
    int len=size-1,i;
    for(i=len/2;i>=0;i--)
    max_heapify(a,i,size);
}
int heapsort(int *a,int size)
{
    build_max_heap(a,size);
    int i,temp;
    for(i=size;i>0;i--)
    {
        temp=*(a);
        *(a)=*(a+i);
        *(a+i)=temp;
        size--;
        max_heapify(a,0,size);
    }
}
int main(void)
{
    int *a,size,i;
    printf("Enter size and array\n");
    scanf("%d",&size);
    a = (int*)malloc(size*sizeof(int));
    for(i=0;i<size;i++)
    scanf("%d",(a+i));
    size--;
    heapsort(a,size);
    for(i=0;i<=size;i++)
    printf("%d\n",*(a+i));
}
