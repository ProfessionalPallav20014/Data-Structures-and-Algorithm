# include <stdio.h>
# include <stdlib.h>

void printArray(int *arr, int n){
    for (int i=0; i<n; i++){
        printf("Elements: %d\n",arr[i]);
    }
}

void merge(int A[], int low, int mid, int high){
    int i, j, k;
    i=low;
    j=mid+1;
    k=0;
    int *B=(int *)malloc((high-low+1)*sizeof(int));
    while (i<=mid && j<=high){
        if (A[i]<A[j]){
            B[k]=A[i];
            i++; k++;
        }
        else{
            B[k]=A[j];
            j++; k++;
        }
    }
    while(i<=mid){
        B[k]=A[i];
        i++; k++;
    }
    while (j<=high){
        B[k]=A[j];
        j++; k++;
    }
    for(int i=low, k=0; i<=high; i++, k++){
        A[i]=B[k];
    }
    free(B);
}
void merge_sort(int A[], int low, int high){
    if (low<high){
        int mid =(low+high)/2;
        merge_sort(A, low, mid);
        merge_sort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}
int main(){
    int A[]={28, 15, 12, 41, 19, 17, 30};
    int n=sizeof(A)/sizeof(A[0]);
    printArray(A, n);
    merge_sort(A, 0, n-1);
    printf("after sorting\n");
    printArray(A, n);
    return 0;
}