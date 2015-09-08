#include "../data structs/PriorityQueues.h"

int
scale_test(int size, int mod)
{
	int i, curr, prev = MAXINT, flag = 0, test;
	CreatePQ(size);
	for(i = 0; i < size; i ++){
		test = rand() % mod;
		// printf("%d ", test);
		InsertPQ(NULL, test);
	}
	// PrintPQ();
	// printf("\n");
	for(i = 0; i < size; i ++){
		curr = ExtractMaxPQ().k;
		// printf("%d ", curr);
		if(curr > prev){
			flag = 1;
		}
		else{
			prev = curr;
		}
	}
	// printf("\n");
	if (flag == 1)
	{
		/* code */
		return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int i, j;
	for(i = 1; i <= 10; i ++){
		for (j = 2; j <= 100; ++j)
		{
			// printf("Checking for %d %d \n", i , j);
			if(scale_test(i, j) == 0){
				// printf("%d %d\n", i, j);
				printf("Found\n");
				return 0;
			}

			/* code */
		}
		
	// PrintPQ();
	// printf("pri %d\n", pqueue.arr[2].k);
	}
	// scale_test(10, 13);
	// PrintPQ();
	return 0;

}

// int main(int argc, char const *argv[])
// {
// 	int i , size = 10;
// 	CreatePQ(size);
// 	InsertPQ(NULL, 9);
// 	PrintPQ();
// 	InsertPQ(NULL, 12);
// 	PrintPQ();
// 	InsertPQ(NULL, 7);
// 	PrintPQ();
// 	InsertPQ(NULL, 11);
// 	PrintPQ();
// 	InsertPQ(NULL, 8);
// 	PrintPQ();
// 	InsertPQ(NULL, 1);
// 	PrintPQ();
// 	InsertPQ(NULL, 11);
// 	PrintPQ();
// 	InsertPQ(NULL, 2);
// 	PrintPQ();
// 	InsertPQ(NULL, 4);
// 	PrintPQ();
// 	InsertPQ(NULL, 2);
// 	PrintPQ();
	
// 	return 0;
// }