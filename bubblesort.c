#include <stdio.h>
int main(){
    int temp;
    int arr[]={12,5,89,45,23,15};
    int sizear=sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<sizear; i++){
        for (int j=0; j<sizear; j++){
            if (arr[j]>arr[j+1]){
                arr[j],arr[j+1]=arr[j+1],arr[j];
            }
        }
    }
    for (int k=0; k<sizear; k++){
        printf("Elment: %d\n",arr[k]);
    }
    return 0;
}