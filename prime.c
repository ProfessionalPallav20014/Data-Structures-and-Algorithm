#include <stdio.h>
int main(){
    //to check whether a number is prime or not
    int n, check=1;
    printf("Enter the number: ");
    scanf("%d",&n);
    if (n<=1){
        printf("The number is not prime\n");
    }
    else{
        for (int i=2; i<n; i++){
            if (n%i==0){
                check=0;
                break;
            }
        }
        if (check==1){
            printf("The number is prime\n");
        }
        else{
            printf("The number is not prime\n");
        }
    }

    return 0;
}