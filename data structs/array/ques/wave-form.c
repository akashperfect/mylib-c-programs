#include "array_basics.h"

/*	Arranges the array like this
	a >= b <= c >= d <= e
*/

void
arrange_array_in_wave_form(int * a, int size)
{
	int i;
	for(i = 0; i < size - 1; i ++){
		if(i % 2 == 0){
			if(a[i] < a[i+1]){
				swap(&a[i], &a[i+1]);
			}
		}
		else{
			if(a[i] > a[i+1]){
				swap(&a[i], &a[i+1]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int *a, size = 10;
	a = random_array(size);
	print_array(a, size);
	arrange_array_in_wave_form(a, size);
	print_array(a, size);
	return 0;
}