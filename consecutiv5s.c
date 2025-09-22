#include <stdio.h>

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    int consecutiveFives = 0;
    int maxConsecutiveFives = 0;

    while (num > 0) {
        int digit = num % 10;
        if (digit == 5) {
            consecutiveFives++;
            if (consecutiveFives > maxConsecutiveFives) {
                maxConsecutiveFives = consecutiveFives;
            }
        } else {
            consecutiveFives = 0; // reset on non-5
        }
        num /= 10;
    }

    if (maxConsecutiveFives >= 3) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
