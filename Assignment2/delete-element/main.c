#include <stdio.h>


// this function is used to delete an element from an array
// parameters: array / size of the array / index to be deleted
// returns: 1 if the index successfully deleted
//          -1 if the index is not correct i.e ( > array size)
int deleteIndex(int [], int* , int );

void ArrayOperation(int [], int, char);

#define MAX_SIZE    100
int main(void){
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[MAX_SIZE];
    printf("Enter the array: ");
    ArrayOperation(arr, size, 'r');
    printf("Enter the index to be deleted: ");
    int index;
    scanf("%d", &index);

    if(deleteIndex(arr, &size, index) == 1){

        printf("Array After deleted: ");
        ArrayOperation(arr, size, 'w');

    }else{
        printf("INCORRECT INDEX");
    }
    printf("\n");
    return 0;
}

int deleteIndex(int arr[], int* size , int index){
    if(index < *size){
        int i = index;
        for(; i + 1 < *size; i++){
            arr[i] = arr[i + 1];
        }
        (*size)--;
        return 1;
    }

    return -1;
}


void ArrayOperation(int arr[], int size, char operation){
    for(int i = 0; i < size; i++){
        if(operation == 'w'){
            printf("%d ", arr[i]);
        }
        else if(operation == 'r'){
            scanf("%d", &arr[i]);
        }
    }
}

