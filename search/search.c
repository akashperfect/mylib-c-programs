#include "binarySearch.h"

int main(int argc, char const *argv[])
{
	int *a = (int *)calloc(10, sizeof(int));
	int b[10] = {1, 2, 4, 7, 8, 9, 10, 15, 20, 25};
	printf("Binary Search %d\n", binarySearch(b, 0, 10, 8));
	return 0;
}