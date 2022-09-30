#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

void quickSort(int arr[], int arr_size){
	// declare the array of less, greater elements and the pivot
	// we can choose any index as the pivot (start, middle, end or 
	// anywhere inbetween the array size).
	int less[MAX_ARRAY_LENGTH], greater[MAX_ARRAY_LENGTH], pivot = arr_size / 2; // 1; // 0; // arr_size - 1;
	
	if(arr_size < 2){
		return;
	}

    // partitioning the array into 2 sub_arrays
    struct quick indeces = divide(less, greater, arr, (struct  quick){.arr_size = arr_size});

    quickSort(less, indeces.less_index); // Quick sort the sub-array of less elements
    quickSort(greater, indeces.greatest_index); // Quick sort the sub-array of greater elements
    
    //Collecting the array again
    collect(less, greater, arr, (struct quick){.arr_size = arr_size,.less_index=indeces.less_index, .pivot = pivot});
	
}

static struct quick divide(int Smallest[], int Greatest[], int arr[], struct quick forArr){
    int l_index = 0, g_index = 0;
    for(int i = 0; i < forArr.arr_size; i++){
        // store the less elements in a sub array (less)
        if(arr[i] <= arr[forArr.arr_size/2] && i != forArr.arr_size/2){
            Smallest[l_index] = arr[i];
            l_index++;
        }// store the greater elements in a sub-array (greater)
        else if(arr[i] >= arr[forArr.arr_size/2] && i != forArr.arr_size/2){
            Greatest[g_index] = arr[i];
            g_index++;
        }
    }
    return (struct quick){.less_index = l_index, .greatest_index = g_index};
}

static void collect(int Smallest[], int Greatest[], int arr[], struct quick forArr){
    arr[forArr.less_index] = arr[forArr.pivot];
    for(int i = 0, j = 0; i < forArr.arr_size; i++){
        if(i < forArr.less_index)
            arr[i] = Smallest[i];
        else if(i > forArr.less_index){
            arr[i] = Greatest[j];
            j++;
        }
    }
}