#include <stdio.h>
int main(){
    float A[]={3,5,2,7,0,9,4};
    int size = (sizeof(A) / sizeof(A[0])) - 1;
    printf("SIZE: %d\n", size+1);
    printf("start: ");
	for (int k=0;k<=size;k++){
		printf("A[%d]=%f, ",k,A[k]);
	}

	for (int i=1;i<=size;i++){
		float currentElement = A[i];
		int j = i-1;
		while(j>=0 && A[j]>currentElement){
			A[j+1]=A[j];
			j--;
            A[j+1]=currentElement;
        }
    }
    printf("\nend: ");
    for (int k=0;k<=size;k++){
        printf("A[%d]=%f, ",k,A[k]);
    }
}