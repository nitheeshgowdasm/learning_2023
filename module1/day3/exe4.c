#include <stdio.h>

void findSmallestLargestDigits(int n, ...) {
    va_list numbers;
    va_start(numbers, n);

    int smallestDigit = 9;
    int largestDigit = 0;
    
    for (int i = 0; i < n; i++) {
        int num = va_arg(numbers, int);
        
        while (num != 0) {
            int digit = num % 10;
            
            if (digit < smallestDigit) {
                smallestDigit = digit;
            }
            
            if (digit > largestDigit) {
                largestDigit = digit;
            }
            
            num /= 10;
        }
    }
    
    va_end(numbers);
    
    if (smallestDigit == 9 || largestDigit == 0) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallestDigit);
        printf("Largest Digit: %d\n", largestDigit);
    }
}

int main() {
    int n;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid value of n\n");
        return 0;
    }
    
    int numbers[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &numbers[i]);
    }
    
    findSmallestLargestDigits(n, numbers[0], numbers[1], numbers[2]);
    
    return 0;
}