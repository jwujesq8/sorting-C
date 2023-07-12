#include <stdio.h>
void merge(float array[], int s, int m, int e){

    int sSize = m-s+1;
    int eSize = e-m;

    float S[sSize], E[eSize];
    for (int i = 0;i<sSize;i++){
        S[i] = array[s+i];
    }
    for(int j=0;j<eSize;j++){
        E[j] = array[m+1+j];
    }

    int i = 0,j = 0;
    int k=s;
    while(i<sSize && j<eSize){
        if(S[i] <= E[j]){
            array[k] = S[i];
            i++;
        } else{
            array[k] = E[j];
            j++;
        }
        k++;
    }

    while(i<sSize){
        array[k]=S[i];
        i++;
        k++;
    }
    while(j<eSize){
        array[k]=E[j];
        j++;
        k++;
    }
}

void sort(float array[], int s, int e){
    if(s<e){
        int m = (s+e-1)/2;

        sort(array, s, m);
        sort(array, m+1, e);

        merge(array, s,m,e);
    }
}

int main (){
    float A[]={3,11,8,11,7,1};
    int size = (sizeof(A) / sizeof(A[0])) - 1;
    printf("SIZE: %d", size+1);
    printf("\nstart: ");
    for(int k=0;k<=size;k++){
        printf("A[%d]=%f, ", k,A[k]);
    }
    sort(A, 0, size);
    printf("\nend: ");
    for(int k=0;k<=size;k++){
        printf("A[%d]=%f, ", k,A[k]);
    }

}