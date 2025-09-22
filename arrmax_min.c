#include <stdio.h>
int main(){
    int marks[]={50,56,45,53,88};
    int temp;
    int size = sizeof(marks) / sizeof(marks[0]);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (marks[j] > marks[j + 1]){
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }
    printf("The max number is: %d\n", marks[size - 1]);
    printf("The min number is: %d\n", marks[0]);
    return 0;
}
