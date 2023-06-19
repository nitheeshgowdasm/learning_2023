#include <stdio.h>

void swap(void *a, void *b, size_t size) {
    unsigned char *ptrA = (unsigned char*)a;
    unsigned char *ptrB = (unsigned char*)b;
    
    for (size_t i = 0; i < size; i++) {
        unsigned char temp = *(ptrA + i);
        *(ptrA + i) = *(ptrB + i);
        *(ptrB + i) = temp;
    }
}

int main() {
    int num1 = 10, num2 = 20;
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
    
    float f1 = 1.23, f2 = 4.56;
    printf("Before swapping: f1 = %.2f, f2 = %.2f\n", f1, f2);
    swap(&f1, &f2, sizeof(float));
    printf("After swapping: f1 = %.2f, f2 = %.2f\n", f1, f2);
    
    char c1 = 'A', c2 = 'B';
    printf("Before swapping: c1 = %c, c2 = %c\n", c1, c2);
    swap(&c1, &c2, sizeof(char));
    printf("After swapping: c1 = %c, c2 = %c\n", c1, c2);
    
    return 0;
}