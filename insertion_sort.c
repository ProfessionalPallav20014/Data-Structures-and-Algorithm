# include <stdio.h>

void printArray(int *arr, int n){
    for (int i=0; i<n; i++){
        printf("Elements: %d\n",arr[i]);
    }
}
/*
[31|45,7,12,36,48,14] --> key=45, j=0, 31>45: False, 6 possible comparisons
[31,45|7,12,36,48,14] --> key=7, j=1, 45>7: True and j=0, 31>7: True, 5 possible comparisons
[7,31,45|12,36,48,14] --> key=12, j=2, 45>12: True and j=1, 31>12: True, 7>12: False, 4 possible comparisons
[7,12,31,45|36,48,14] --> key=36, j=3, 45>36: True and j=2, 31>36: False, 3 possible comparisons
[7,12,31,36,45|48,14] --> key=48, j=4, j=3, j=2, j=1 for these key is always greatest, 2 possible comparisons
[7,12,31,36,45,48|14] --> key=14, j=5, j=4, j=3, j=2 before these key will be placed, 1 possible comparisons
*/
void insertion_sort(int *arr, int n){
      for (int i=1; i<=(n-1); i++){
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j]; // arr[i-1+1]=arr[i-1]
            j--; // for comparison in left side 
        }
        arr[j+1]=key;
      }
      printf("Your array has sorted\n");
}

int main(){
    int arr[]={31,45,7,12,36,48,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    insertion_sort(arr,n);
    printArray(arr,n);
    return 0;
}