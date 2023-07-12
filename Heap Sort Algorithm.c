#include <stdio.h>
void printArray(float array[], int size){
    for (int k=0; k<=size; k++){
        printf("A[%d]=%f ", k, array[k]);
    }
}
void swap(float* x, float* y){
    float tmp = *x;
    *x = *y;
    *y = tmp;
}

void heapify(float array[], int size, int p){
    int left = p*2+1;
    int right = p*2+2;
    int newP=p;

    if(left<=size && array[left]>array[newP]){
        newP = left;
    }
    if(right<=size && array[right]>array[newP]){
        newP = right;
    }

    if(newP!=p){
        swap(&array[p], &array[newP]);
        heapify(array, size, newP);
    }

}

void sort(float array[], int size){
    for (int i=size/2 ; i>=0;i--){
        heapify(array, size, i);
    }

    for (int j=size; j>=0;j--){
        swap(&array[0], &array[j]);
        heapify(array, j-1,0);
    }
}

int main(){
    float A[]={3,11,8,7,1,11,0,4};
    int size = (sizeof(A) / sizeof(A[0])) - 1;
    printf("SIZE: %d", size+1);
    printf("\nstart: ");
    printArray(A, size);

    sort(A, size);
    printf("end: ");
    printArray(A, size);
}