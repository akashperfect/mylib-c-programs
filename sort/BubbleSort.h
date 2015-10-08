#ifndef BUBBLE_H_INCLUDED
#define BUBBLE_H_INCLUDED

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int *a, int size)
{
	int i,j;
	for(i = 0; i < size - 1; i ++)
	{
		for(j = 0; j < size - i - 1; j ++)
		{
			if(a[j] > a[j+1])
				swap(a + j, a + j + 1);
		}
	}
}

#endif