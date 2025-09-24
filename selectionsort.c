#include<stdio.h>

void printArray(int *arr, int size){
    for (int i=0; i<size; i++){
        printf("Element: %d\n",arr[i]);
    }
}
// imagine this [8,2,10,0,1,7]
void selection_sort(int *arr, int n){
    int min_index;
    for (int i=0; i<n-1; i++){
        min_index=i;
        for (int j=i+1; j<n; j++){
            if (arr[min_index]>arr[j]){
                min_index=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
    printf("Your array has sorted\n");
}

int main(){
    int arr[]={8,2,10,0,1,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    selection_sort(arr,n);
    printArray(arr,n);

    return 0;
}