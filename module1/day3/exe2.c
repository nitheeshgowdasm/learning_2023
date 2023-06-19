#include <stdio.h>

void printBits(unsigned int num) {
    unsigned int mask = 1 << 31;  // Starting from the leftmost bit
    
    for (int i = 0; i < 32; i++) {
        if (num & mask)
            printf("1");
        else
            printf("0");
        
        num <<= 1;  // Shift left by 1 bit
    }
    
    printf("\n");
}

int main() {
    unsigned int number;
    
    printf("Enter a 32-bit integer: ");
    scanf("%u", &number);
    
    printf("Bits representation: ");
    printBits(number);
    
    return 0;
}