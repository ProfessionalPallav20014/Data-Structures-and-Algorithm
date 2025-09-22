#include <stdio.h>
int main(){
    //to write a code for checking whether a number is palindrome or not
    int num, num1, revnum=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    num1=num;
    while (num1>0){
        revnum*=10;
        revnum+=num1%10;
        num1=num1/10;
    }
    if (num==revnum){
        printf("%d is a palindrome", num);
    }
    else{
        printf("%d is not a palindrome", num);
    }
    return 0;
}