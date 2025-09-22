#include <stdio.h>
void swap(int a, int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("%d, %d", a, b);
}
int main(){
    // int x = 8, y = 5;
    swap(8, 5);
    return 0;
}