#include <stdio.h>
#include <stdlib.h>
int main(){
	float A[]={2,5,4,9,1,6,3};
    int size = (sizeof(A) / sizeof(A[0])) - 1;
    printf("SIZE: %d\nstart: ", size+1);
	for(int i=0;i<=size;i++){
		printf("A[%d]=%f ", i,A[i]);
	}

	for(int i=0;i<size;i++){
		int minIndex=i;
		for(int j=i+1;j<=size;j++){
            if(A[j]<A[minIndex]){
                minIndex = j;
            }
        }
		if (i!=minIndex){
			float min=A[minIndex];
            A[minIndex]=A[i];
            A[i]=min;
		}

	}
    printf("\nend: ");
	for(int i=0;i<=size;i++){
		printf("A[%d]=%f, ", i,A[i]);
		}
}