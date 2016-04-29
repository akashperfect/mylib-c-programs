#include <stdio.h>
#include <stdlib.h>

int 
binarySearch(int *a, int low, int high, int search) {
	int mid;
	if(low < 0 || high < low) {
		return -1;
	}
	mid = (high + low) / 2;
	if (a[mid] == search) {
		return mid;
	}
	else if (a[mid] < search){
		return binarySearch(a, mid + 1, high, search);
	}
	else if (a[mid] > search){
		return binarySearch(a, low, mid - 1 , search);
	}
	return -1;
}