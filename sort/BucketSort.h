/* Implementing Bucket Sort 
Runtime : O(max number) - if range is in integers 
Space : O(max number)
*/

#include <stdio.h>
#include <stdlib.h>

void BucketSort(int *a, int size)
{
    int i,max = a[0],j;
    for(i = 1 ; i < size ; i++) 
        if (max < a[i]) 
            max = a[i];

    int * b = (int * )calloc((max+1),sizeof(int));  //Initializing the entire array with 0's

    for(i = 0 ; i < size ; i++)
        (*(b+*(a+i)))++;                            //Incrementing the count of the integers seen so far
 
    for(i = 0 , j = 0 ; i <= max ; i++)             //Updating the original table with the Sorted Values
    {
        while(b[i] > 0)
        {
            *(a+j++) = i;
            (*(b+i))--;
        }
    }
}


