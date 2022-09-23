#include <stdio.h>
#include "helpers.h"

int binarySearch(int arr[], int size, int num){
    int start = 0, end = size - 1, mid = end + (start - end)/2;
    while(start <= end){
        if(arr[mid] == num)
            return mid;
        else if(arr[mid] > num)
            end = mid - 1;
        else
            start = mid + 1;
        mid = end + (start - end)/2;
    }
    
    return -1;
}

int binarySearchRec(int arr[], int size, int num){
    int start = 0, end = size - 1;
    
    return BSR(arr, start, end, num);

}

static int BSR(int arr[], int start, int end, int num){
    int mid = end + (start - end)/2;
    if(arr[mid] == num)
        return mid;
    else if(start > end)
        return -1;
    
    if(arr[mid] > num)
        return BSR(arr, start, mid - 1, num);
    else
        return BSR(arr, mid + 1, end, num);

}