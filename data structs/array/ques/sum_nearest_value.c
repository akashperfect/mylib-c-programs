#include "array_basics.h"

/*	Given a sorted array and a num finds the pair
	with the sum closest to x
*/

int *
sum_nearest_value(int *a, int size, int x)
{
	int i, j, min, g_min, *result, sum;
	result = reserve_single_array(2);
	g_min = MAXINT;
	i = 0;
	j = size - 1;
	while( i < j ){
		sum = a[i] + a[j];
		if(sum == x){
			result[0] = a[i];
			result[1] = a[j];
			return result;
		}
		min = abs(sum - x);
		printf("sum = %d, min = %d\n", sum, min);
		if(min < g_min){
			result[0] = a[i];
			result[1] = a[j];
			g_min = min;
		}
		if(sum < x){
			i ++;
		}
		else{
			j --;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int *a, size = 10;
	a = linear_array(size);
	print_array(a, size);
	print_array(sum_nearest_value(a, size, 15), 2);
	return 0;
}

