#include <stdio.h>

int findLargestNumber(int number) {
    int largestNumber = 0;
    
    for (int i = 0; i < 4; i++) {
        int temp = number / 10;  // remove the rightmost digit
        temp *= pow(10, i);  // shift digits to the right
        temp += number % 10;  // add the rightmost digit
        
        if (temp > largestNumber) {
            largestNumber = temp;
        }
        
        number /= 10;  // remove the leftmost digit
    }
    
    return largestNumber;
}

int main() {
    int number;
    
    printf("Enter a 4-digit number: ");
    scanf("%d", &number);
    
    int largestNumber = findLargestNumber(number);
    
    printf("The largest number by deleting a single digit: %d\n", largestNumber);
    
    return 0;
}