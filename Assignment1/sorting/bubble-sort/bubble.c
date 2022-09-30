#include <stdio.h>
#include "helpers.h"



void bubbleSort(int arr[], int size){
    int temp;
    for(int i = 0; i < size; i++){
        for(int j = size - 1; j > i; j--){
            if(arr[j - 1] > arr[j]){
                swapTwoNumbers(&arr[j - 1], &arr[j]);
            }
        }
    }
}

static void swapTwoNumbers(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}