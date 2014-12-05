#include<stdio.h>
void insertion_sort(int *a,int size)
{
    int j,e,i;
    /*  'j' holds the index of the current element to be inserted in sorted order in the list
        'e' holds the value at the 'j'th index
        'i' is used to shift the remaining elements in the list whose value is greater than 'e'*/
    for(j=1;j<=size;j++)
    {
        e = *(a+j);// e is assigned the value at 'j'th index
        i = j - 1;
        while(i>=0&&*(a+i)>e) //for shifting of elements greater than 'e' and index value less than 'j'
        {
            *(a+i+1) = *(a+i);
            i--;
        }
        *(a+i+1) = e; // finally placing the element in its right place
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
    insertion_sort(a,size);
    for(i=0;i<=size;i++)
    printf("%d\n",*(a+i));
}
