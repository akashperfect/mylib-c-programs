// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>

// /* Radix sort uses counting sort to sort the numbers based on the digits of each element of array a
// It starts sorting from the least significant bit to the most significant bit , which ensures the
// elements are sorted in place. It uses counting sort because its a stable sort. */

// void counting_sort(int *a,int *b,int k,int size,int d) // k is the largest integer
// {
//     int i,l=k+1,c[l],j,d1,n;
//     d1 = (int)pow(10.0,(double)d);
//     for(i=0;i<=k;i++)
//         *(c+i) = 0;
//     for(j=0;j<=size;j++)
//     {
//         n = ((*(a+j))%d1)/(d1/10);
//         (*(c+n))++;  //c[i] now contains the number of elements equal to i
//     }
//     for (i=1;i<=k;i++)
//         *(c+i) = *(c+i) + *(c+i-1) ;  //c[i] now contains the number of elements less than or equal to i
//     for(i=0;i<=k;i++)
//         (*(c+i))--;
//     for(j=size;j>=0;j--)
//     {
//         n = ((*(a+j))%d1)/(d1/10);
//         *(b+*(c+n)) = *(a+j);
//         (*(c+n))--;
//     }
//     for(i=0;i<=size;i++)
//     *(a+i)=*(b+i);

// }
// void RadixSort(int *a, int size)// d is the number of digits in all the elements
// // a is the actual array and b is an empty array to hold the final sorted list
// {
//     int i, *b, k = -1, count = 0, t;
//     b = (int*)calloc(size, sizeof(int));
//     t=*a;
//     while(1)
//     {
//         if(t!=0)
//         t/=10;
//         else break;
//         count++;
//     }
//     size--;
//     for(i=1;i<=count;i++)
//         counting_sort(a,b,9,size,i);
//     a = b;
// }
// // int test(void)
// // {
// //     int *a,*b,k=-1,size,i,count=0,t;
// //     printf("Enter size and array\n");
// //     scanf("%d",&size);
// //     a = (int*)malloc(size*sizeof(int));
// //     b = (int*)malloc(size*sizeof(int));
// //     for(i=0;i<size;i++)
// //     {
// //         scanf("%d",(a+i));
// //     }
// //     t=*a;
// //     while(1)
// //     {
// //         if(t!=0)
// //         t/=10;
// //         else break;
// //         count++;
// //     }
// //     size--;
// //     radixsort(a,b,count,size);
// //     for(i=0;i<=size;i++)
// //     printf("%d ",*(b+i));
// //     return 0;
// // }

int getMin(int arr[], int n)
{
    int mx = arr[0], i;
    for (i = 1; i < n; i++)
        if (arr[i] < mx)
            mx = arr[i];
    return mx;
}

int getMax(int arr[], int n)
{
    int mx = arr[0], i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by expr.
void countSort(int arr[], int n, int expr)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/expr)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual position of
    // this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/expr)%10 ] - 1] = arr[i];
        count[ (arr[i]/expr)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to curent digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using Radix Sort
void RadixSort(int arr[], int n)
{
    // Convert all numbers to positive
    int min = getMin(arr, n), i, flag;
    if(min < 0)
    {
        for(i = 0; i < n; i ++)
            arr[i] -= min;
        flag = 1;
    }
    // Find the maximum number to know number of digits
    int m = getMax(arr, n), expr;
 
    // Do counting sort for every digit. Note that instead of passing digit
    // number, expr is passed. expr is 10^i where i is current digit number
    for (expr = 1; m/expr > 0; expr *= 10)
        countSort(arr, n, expr);
    if(flag == 1)
    {
        for(i = 0; i < n; i ++)
            arr[i] += min;
    }
}