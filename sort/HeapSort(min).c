#include<stdio.h>
#include<stdlib.h>
int min_heapify(int *a,int i,int size)
{
    int l = 2*i+1,r = 2*(i+1),temp,smallest;
    if(l<=size &&a[l]<a[i])
        smallest=l;
    else
        smallest=i;
    if(r<=size && a[r]<a[smallest])
        smallest=r;
    if(smallest!=i)
    {
        temp = *(a+i);
        *(a+i) = *(a+smallest);
        *(a+smallest) = temp;
        min_heapify(a,smallest,size);
    }
}

int build_max_heap(int *a,int size)
{
    int len=size-1,i;
    for(i=len/2;i>=0;i--)
    min_heapify(a,i,size);
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
        min_heapify(a,0,size);
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
