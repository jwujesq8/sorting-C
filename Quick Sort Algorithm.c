#include <stdio.h>
void swap(float* x, float* y){
    float tmp = *x;
    *x = *y;
    *y = tmp;
}

int findMedianIndex(float array[], int low, int high){
    float lastElement = array[high];
    int medianIndex = low-1;

    for(int j=low; j <= high-1; j++){
        if(array[j] < lastElement){
            medianIndex++;
            swap(&array[medianIndex], &array[j]);
        }
    }

    swap(&array[high], &array[medianIndex+1]);
    return medianIndex+1;
}

void sort(float array[], int low, int high){
    if(low < high){
        int index = findMedianIndex(array, low, high);
        sort(array, low, index-1);
        sort(array, index+1, high);

    }

}

int main(){
    float A[]={3,11,8,11,7,1};
    int size = (sizeof(A) / sizeof(A[0])) - 1;
    printf("\nstart:");
    for(int k=0;k<=size;k++){
        printf("A[%d]=%f, ", k,A[k]);
    }

    sort(A, 0, size);

    printf("\nend: ");
    for(int k=0;k<=size;k++){
        printf("A[%d]=%f, ", k,A[k]);
    }

}