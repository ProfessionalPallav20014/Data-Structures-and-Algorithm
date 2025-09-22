#include <stdio.h>
int main(){
    //to insert elements in an array of defined length and return sum all of them
    int n, sum=0;
    printf("Enter the number of elements you want to enter: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0; i<n; i++){
        printf("Enter the elements: ");
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    printf("Sum of all the elements in the array is: %d",sum);
    return 0;
}