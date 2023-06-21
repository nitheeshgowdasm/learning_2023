#include <stdio.h>

struct Complex {
    double real;
    double imag;
};

// Function to read a complex number
struct Complex readComplex() {
    struct Complex num;
    printf("Enter real part: ");
    scanf("%lf", &num.real);
    printf("Enter imaginary part: ");
    scanf("%lf", &num.imag);
    return num;
}

// Function to write a complex number
void writeComplex(struct Complex num) {
    printf("Complex number: %.2lf + %.2lfi\n", num.real, num.imag);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex sum;
    sum.real = num1.real + num2.real;
    sum.imag = num1.imag + num2.imag;
    return sum;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex num1, struct Complex num2) {
    struct Complex product;
    product.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    product.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    return product;
}

int main() {
    struct Complex num1, num2, sum, product;

    printf("Reading Complex Number 1:\n");
    num1 = readComplex();

    printf("\nReading Complex Number 2:\n");
    num2 = readComplex();

    printf("\nComplex Number 1:\n");
    writeComplex(num1);

    printf("\nComplex Number 2:\n");
    writeComplex(num2);

    sum = addComplex(num1, num2);
    printf("\nSum of Complex Numbers:\n");
    writeComplex(sum);

    product = multiplyComplex(num1, num2);
    printf("\nProduct of Complex Numbers:\n");
    writeComplex(product);

    return 0;
}
