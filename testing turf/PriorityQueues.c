#include "../data structs/PriorityQueues.h"

int
scale_test(int size, int mod)
{
	int i, curr, prev = -1, flag = 0, test;
	CreateMinPQ(size);
	// printf("\n");
	for(i = 0; i < size; i ++){
		test = rand() % mod;
		// printf("%d ", test);
		InsertMinPQ(NULL, test);
	}
	// PrintPQ();
	// printf("\n");
	for(i = 0; i < size; i ++){
		curr = ExtractMinPQ().k;
		// printf("%d ", curr);
		if(curr < prev){
			flag = 1;
		}
		else{
			prev = curr;
		}
	}
	// printf("\n");
	if (flag == 1)
	{
		return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int i, j;
	for(i = 1; i <= 100; i ++){
		for (j = 2; j <= 100; ++j)
		{
			// printf("Checking for %d %d \n", i , j);
			if(scale_test(i, j) == 0){
				printf("%d %d\n", i, j);
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
// 	CreateMinPQ(size);
// 	InsertMinPQ(NULL, 1);
// 	PrintPQ();
// 	InsertMinPQ(NULL, 3);
// 	PrintPQ();
// 	InsertMinPQ(NULL, 1);
// 	PrintPQ();
// 	InsertMinPQ(NULL, 1);
// 	PrintPQ();
// 	InsertMinPQ(NULL, 0);
// 	PrintPQ();
// 	InsertMinPQ(NULL, 1);
// 	PrintPQ();
// 	InsertMinPQ(NULL, 11);
// 	PrintPQ();
// 	InsertMinPQ(NULL, 2);
// 	PrintPQ();
// 	InsertMinPQ(NULL, 4);
// 	PrintPQ();
// 	InsertMinPQ(NULL, 2);
// 	PrintPQ();
// 	for(i = 0; i < size; i ++){
// 		printf("%d ", ExtractMinPQ().k);
// 	}
// 	return 0;
// }