#include <stdio.h>

void printExponent(double x) {
    unsigned long long *ptr = (unsigned long long*)&x;
    unsigned long long exponentMask = 0x7FF0000000000000ULL;
    unsigned long long exponent = (*ptr & exponentMask) >> 52;
    
    // Hexadecimal format
    printf("Exponent in hexadecimal: 0x%llx\n", exponent);
    
    // Binary format
    printf("Exponent in binary: 0b");
    for (int i = 11; i >= 0; i--) {
        printf("%llu", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);
    return 0;
}