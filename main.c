#include <stdio.h>
#include <stdlib.h>
#include "sorting/quick-sort/quick.h"
#include "sorting/bubble-sort/bubble.h"
#include "sorting/merge-sort/merge.h"
#include "searching/binary-search/binary.h"

#define ARR_SIZE	100

/*
 - Choose the problem
	- QUICK
	- BUBBLE
	- MERGE
	- BS
*/
#define MERGE
int main(void){
	
	int arr[ARR_SIZE];
	int size;
	printf("Enter array size: ");
	scanf("%d", &size);
	printf("enter array elements: ");
	for(int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	#if defined(BS)
		int num;
		scanf("%d", &num);
		mergeSort(arr, size);
		printf("by loop: %d\n", binarySearch(arr, size, num));
		printf("by reb: %d\n", binarySearchRec(arr, size, num));
	#elif defined(MERGE) || defined(QUICK) || defined(BUBBLE)
		#if defined(BUBBLE)
			bubbleSort(arr, size);
		#elif defined(MERGE)
			mergeSort(arr, size);
		#elif defined(QUICK)
			quickSort(arr, size);
		#endif
		for(int i = 0; i < size; i++)
			printf("%d ", arr[i]);		
	#endif
	printf("\n");
	return 0;
}
