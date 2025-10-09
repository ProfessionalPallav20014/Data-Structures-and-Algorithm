# include<stdio.h>
# include<stdlib.h>
# include<limits.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void countsort(int arr[], int n){
    int i, j; 
    int max=INT_MIN;
    for (i=0; i<n; i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    int *max_arr = (int *)malloc((max + 1) * sizeof(int));
    for (j = 0; j <= max; j++) {
        max_arr[j] = 0;
    }
    for (j = 0; j < n; j++) {
        max_arr[arr[j]] += 1;
    }
    i=0;// i is a counter for given array and j is a counter for max_array
    j=0;
    while (j<=max){
        if (max_arr[j]>0){
            arr[i]=j;
            max_arr[j]--;
            i++;
        }
        else{
            j++;
        }
    }
    free(max_arr);
}

int main(){
    int arr[]={9,1,4,14,4,10,6,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    countsort(arr,size);
    printArray(arr,size);
    return 0;
}