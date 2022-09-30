#include <stdio.h>
#include "helpers.h"



void mergeSort(int arr[], int size){
    if(size < 2)
        return;

    int arrL[MAX_ARRAY_LEN], arrR[MAX_ARRAY_LEN];

    divide(arrL, arrR, arr, size);
    
    mergeSort(arrL, size/2);
    mergeSort(arrR, size - size/2);

    merge(arrL, arrR, arr, size);
}


static void divide(int arrL[], int arrR[], int arr[], int size){
        for(int i = 0, j = size / 2, k = 0; i < size / 2 || j < size; i++, j++, k++){
        if(i < size / 2) arrL[k] = arr[i];
        if(j < size) arrR[k] = arr[j];
    }
}

static void merge(int arrL[], int arrR[], int arr[], int size){
    for(int i = 0, j = 0, k = 0; i < size; i++){
        if(j < size/2 && k < size - size/2){
            if(arrL[j] < arrR[k]){
                arr[i] = arrL[j];
                j++;
            }
            else if(arrR[k] <= arrL[j]){
                arr[i] = arrR[k];
                k++;
            }
            continue;
        }

        if(j < size/2)
            arr[i] = arrL[j++];
        else
            arr[i] = arrR[k++];
    }
}