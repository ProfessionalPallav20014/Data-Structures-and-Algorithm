#include <stdio.h>

int main() {
    int num, original, sum = 0, n = 0, temp, digit;

    printf("Enter the number: ");
    scanf("%d", &num);
    original = num;
    temp = num;

    // Count digits
    while (temp != 0) {
        temp /= 10;
        n++;
    }

    temp = num;
    while (temp != 0) {
        digit = temp % 10;

        // Compute digit^n using integer multiplication
        int power = 1;
        for (int i = 0; i < n; i++) {
            power *= digit;
        }

        sum += power;
        temp /= 10;
    }

    if (sum == original) {
        printf("The number is Armstrong\n");
    } else {
        printf("The number is not Armstrong\n");
    }

    return 0;
}
