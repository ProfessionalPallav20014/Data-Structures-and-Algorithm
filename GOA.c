#include <stdio.h>
int main(){
    //to find the greatest of all the 10 elements in an array
    int max;
    int arr[10];
    for (int i=0; i<10; i++){
        printf("Enter the element: ");
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    for (int i=1; i<10; i++){
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("The greatest element is: %d\n", max);

    return 0;
}