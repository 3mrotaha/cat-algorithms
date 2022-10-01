#include <stdio.h>

#define MAX_ELEMENTS    100


// this function is used to get the max element in array of size n
// parameters:  array / size of the array
// returns: the max element in the array
int maxElement(int [], int);



int main(void){
    int arr[10] = {1, 2, 3, 4, 9, 1, 0, -1};

    printf("%d\n", maxElement(arr, 10));
}


int maxElement(int arr[], int size){
    if(size == 1)
        return arr[0];
    else{
        int maxR, maxL, rightArr[MAX_ELEMENTS], j = 0;

        for(int i = size / 2; i < size; i++){
            rightArr[j++] = arr[i]; 
        }

        maxR = maxElement(rightArr, j);
        maxL = maxElement(arr, size - j);        

        if(maxR > maxL)
            return maxR;
        else
            return maxL;
    }
}