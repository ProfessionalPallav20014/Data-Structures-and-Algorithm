#include <stdio.h>
int main(){
    int a=10;
    int *ptr;
    ptr=&a;
    printf("%d\n",ptr);
    printf("%d\n",*ptr);
    printf("%u\n",ptr);
    printf("%p\n",ptr);
}