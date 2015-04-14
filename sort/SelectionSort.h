#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED

void SelectionSort(int *arr, int n)
{
//pos_min is short for position of min
	int pos_min, temp, i, j ;

	for (i=0; i < n-1; i++)
	{
	    pos_min = i;//set pos_min to the current index of array
		
		for (j = i+1; j < n; j++)
		{

			if (arr[j] < arr[pos_min])
				pos_min = j;
	//pos_min will keep track of the index that min is in, this is needed when a swap happens
		}
		
	//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
        if (pos_min != i)
        {
             temp = arr[i];
             arr[i] = arr[pos_min];
             arr[pos_min] = temp;
        }
	}
}

#endif