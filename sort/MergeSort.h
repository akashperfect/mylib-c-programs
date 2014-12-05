#include <stdio.h>
#include <stdlib.h>

mergeoptimized(int *a, int l, int q, int r)
{
    int * b,i,j,k;
    b = (int * )malloc((r-l+1) * sizeof(int));
    for(i = l , j = q + 1 , k = 0 ; i <= q || j <= r ; k++)
    {
        if(i > q)
        {
            for(j ; j <= r ; j++ , k++)
            b[k] = a[j];
            break;
        }
        else if(j > r)
        {
            for(i ; i <= q ; i++ , k++)
            b[k] = a[i];
            break;
        }
        if(a[i] > a[j])
        {
            b[k] = a[j];
            j++;
        }
        else
        {
            b[k] = a[i];
            i++;
        }

    }
    for(i = l ; i <= r ; i++)
        a[i] = b[i-l];
}

MergeSort(int *a, int f, int l) // This function is called from main
{
    int mid;
    if(f < l)
    {
        mid = (f+l)/2; // dividing the array into two subsequence for sorting based on mid
        MergeSort(a,f,mid);  // sorting the first subsequence
        MergeSort(a,mid+1,l);  // sorting the second subsequence
//        merge(a,f,mid,l); // for combining the divided subsequences
        mergeoptimized(a,f,mid,l);
    }
}
