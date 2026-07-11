#include <stdio.h>

// Structure to represent a complex number
typedef struct
{
    float real;
    float imag;
} Complex;

// Function to read a complex number
Complex readComplex()
{
    Complex num;
    printf("Enter the real and imaginary parts of the complex number: ");
    scanf("%f%f", &num.real, &num.imag);
    return num;
}

// Function to write a complex number
void writeComplex(Complex num)
{
    printf("%.2f + %.2fi\n", num.real, num.imag);
}

// Function to add two complex numbers
Complex addComplex(Complex num1, Complex num2)
{
    Complex sum;
    sum.real = num1.real + num2.real;
    sum.imag = num1.imag + num2.imag;
    return sum;
}

// Function to multiply two complex numbers
Complex multiplyComplex(Complex num1, Complex num2)
{
    Complex product;
    product.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    product.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    return product;
}

int main()
{
    Complex num1, num2, sum, product;

    // Reading two complex numbers
    printf("Enter the first complex number:\n");
    num1 = readComplex();
    printf("Enter the second complex number:\n");
    num2 = readComplex();

    // Writing the two complex numbers
    printf("The first complex number is: ");
    writeComplex(num1);
    printf("The second complex number is: ");
    writeComplex(num2);

    // Performing addition of two complex numbers
    sum = addComplex(num1, num2);
    printf("The sum of the two complex numbers is: ");
    writeComplex(sum);

    // Performing multiplication of two complex numbers
    product = multiplyComplex(num1, num2);
    printf("The product of the two complex numbers is: ");
    writeComplex(product);

    return 0;
}
