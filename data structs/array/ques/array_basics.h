#ifndef ARRAYBASICS_H_INCLUDED
#define ARRAYBASICS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXINT 2147483647

int *
reserve_single_dim_array(int size);

void
print_array(int *, int );

void
swap(int *, int *);

int * 
make_random_array(int );

int *
linear_array(int );

int *
reserve_single_array(int size)
{
	int *a;
	a = (int *)calloc(size, sizeof(int));
	return a;
}

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int * 
random_array(int size)
{
	int i, *a; 
	a = reserve_single_array(size);
	for(i = 0; i < size; i ++){
		a[i] = rand()%10;
	}
	return a;
}

int *
linear_array(int size)
{
	int i, *a; 
	a = reserve_single_array(size);
	for(i = 0; i < size; i ++){
		a[i] = i;
	}
	return a;
}

void
print_array(int *a, int size)
{
	int i = 0;
	printf("Printing the array\n");
	for(i = 0; i < size; i ++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

#endif // ARRAYBASICS_H_INCLUDED