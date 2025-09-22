#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (n % 2 == 0)
        goto even;
    else
        goto odd;
even:
    printf("Even");
    exit(0);
odd:
    printf("Odd");
    return 0;
}
