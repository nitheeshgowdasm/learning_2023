#include <stdio.h>

int main() {
    int arr[] = {64, 84, 21, 36, 17, 90, 77, 10, 48, 55};
    int evenIndexSum = 0, oddIndexSum = 0;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        if (i % 2 == 0) {
            evenIndexSum += arr[i];
        } else {
            oddIndexSum += arr[i];
        }
    }

    int diff = evenIndexSum - oddIndexSum;

    printf("Sum of even indexed elements: %d\n", evenIndexSum);
    printf("Sum of odd indexed elements: %d\n", oddIndexSum);
    printf("Difference: %d\n", diff);

    return 0;
}