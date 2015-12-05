#include "../sort/QuickSort.h"
#   define swap(a, b) { int tmp = a; a = b; b = tmp; }
int select(int *a, int s, int e, int k){
    // if the partition length is less than or equal to 5
    // we can sort and find the kth element of it
    // this way we can find the median of n/5 partitions
    if(e-s+1 <= 5){
        QuickSort(a+s, a+e);
        return s+k-1;
    }
    int i=0;
    // if array is bigger 
    // we partition the array in subarrays of size 5
    // no. of partitions = n/5 = (e+1)/5
    // iterate through each partition
    // and recursively calculate the median of all of them
    // and keep putting the medians in the starting of the array
    for(i=0; i<(e+1)/5; i++){
        int left = 5*i;
        int right = left + 4;
        if(right > e) right = e;
        int median = select(a, 5*i, 5*i+4, 3);
        swap(a[median], a[i]);
    }
    
    // now we have array 
    // a[0] = median of 1st 5 sized partition
    // a[1] = median of 2nd 5 sized partition
    // and so on till n/5
    // to find out the median of these n/5 medians
    // we need to select the n/10th element of this set (i.e. middle of it)
    return select(a, 0, (e+1)/5, (e+1)/10);
}

int main(){
    int a[] = {6,7,8,1,2,3,4,5,9,10};
    int n = 10;
    
    int mom = select(a, 0, n-1, n/2);
    printf("Median of Medians: %d " , a[mom]);
    return 0;
}