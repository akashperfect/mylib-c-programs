#include<stdio.h>
#include<stdlib.h>

merge(int *a,int f,int mid, int l) // function called by merge-sort for combining
/*  *a ->array, f,mid and l are first middle and last index of the  array a respectively */

{
    int n1,n2,i,j,k;
    n1 = mid-f;
    n2 = l-mid;
    int l1[n1+2],l2[n2+1];
    // two partitions L1 and L2 holding the elements from first to mid and mid+1 to last respectively
    for(i=0;i<=n1;i++)
        *(l1+i) = *(a+f+i); //assignment into the array L1
    for(i=0;i<n2;i++)
        *(l2+i) = *(a+mid+i+1);  //assignment into the array L2
    l1[n1+1]=l2[n2]=1000000; /* last element is set to maximum for taking care of the (possibly)
                                unequal number of elements */
    for(k=f,i=0,j=0;k<=l;k++)
    {
        if(*(l1+i) <= *(l2+j))  //comparison whichever element's value is lesser that is put in the final array
        {
            *(a+k) = *(l1+i);
            i++;
        }
        else
        {
            *(a+k) = *(l2+j);
            j++;
        }
    }
}
merge_sort(int *a, int f, int l) // This function is called from main
{
    int mid;
    if(f<l)
    {
        mid = (f+l)/2; // dividing the array into two subsequence for sorting based on mid
        merge_sort(a,f,mid);  // sorting the first subsequence
        merge_sort(a,mid+1,l);  // sorting the second subsequence
        merge(a,f,mid,l); // for combining the divided subsequences
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
    merge_sort(a,0,size);
    for(i=0;i<=size;i++)
    printf("%d\n",*(a+i));
}
