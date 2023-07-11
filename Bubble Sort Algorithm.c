#include <stdio.h>
int main(){
	float A[]={3,2,8,11,7,11,1};
    int size = (sizeof(A) / sizeof(A[0]) -1);
    printf("SIZE: %d", size+1);
    printf("\nstart: ");
	for(int i=0;i<=size;i++){
		printf("A[%d]=%f, ", i,A[i]);
    };
    for (int i=0;i<size;i++){
        for (int j=0;j<size-i;j++){
            if(A[j]> A[j+1]){
                float tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }

    printf("\nend: ");
    for(int k=0;k<=size;k++){
        printf("A[%d]=%f, ", k,A[k]);
    }
}