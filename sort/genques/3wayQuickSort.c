#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../data structs/array/ques/array_basics.h"

void
three_way_partition(int *a, int s, int e, int *l, int *r)
{
	int x = rand()%(e-s) + s, p, i;
	swap(&a[x], &a[e]);
	p = a[e];
	for(i = s, *l = *r = s; i < e; i ++){
		if(a[i] == p){
			swap(&a[*r], &a[i]);
			(*r) ++;
		}
		else if(a[i] < p){
			swap(&a[*r], &a[i]);
			swap(&a[*r], &a[*l]);
			(*l) ++;
			(*r) ++;
		}
	}
	swap(&a[*r], &a[e]);
	swap(&a[*r], &a[*l]);
	(*l) ++;
	(*r) ++;
}

three_way_quicksort(int *a, int s, int e)
{
	int l = 0, r = 0;
	if(s < e - 1){
		three_way_partition(a, s, e, &l, &r);
		three_way_quicksort(a, s, l);
		three_way_quicksort(a, r, e);
	}
}

int main(int argc, char const *argv[])
{
	int a[18] = {1,2,3,4,4,7,2,1,2,1,2,1,4,2,3,1,2,3};
	three_way_quicksort(a, 0 ,17);
	print_array(a, 18);
	return 0;
}