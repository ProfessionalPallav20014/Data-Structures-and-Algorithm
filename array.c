#include <stdio.h>
int main(){
    int marks[5]={50,56,45,53,88};
    marks[2] = 99; // Change the third element to 99
    
    int size = sizeof(marks) / sizeof(marks[0]);
    for(int i = 0; i < size; i++){
        printf("%d\n", marks[i]);
    }
    return 0;
}
