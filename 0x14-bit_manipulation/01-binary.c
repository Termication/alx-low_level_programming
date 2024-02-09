#include <stdio.h>

/**
 * _pow_bitwise - calculates (base ^ power) efficiently using bitwise operations
 * @base: base of the exponent
 * @power: power of the exponent
 *
 * Return: value of (base ^ power)
 */
unsigned long int _pow_bitwise(unsigned int base, unsigned int power)
{
    unsigned long int result = 1;
    while (power)
    {
        if (power & 1)  // Check if the power is odd 
            result *= base;
        power >>= 1;   // Divide power by 2
        base *= base;  // Square the base
    }
    return result;
}

/**
 * print_binary_masking - prints a number in binary notation using bit manipulation
 * @n: number to print
 *
 * Return: void
 */
void print_binary_masking(unsigned long int n)
{
    int i;
    for (i = (sizeof(n) * 8) - 1; i >= 0; i--) {
        (n >> i) & 1 ? putchar('1') : putchar('0');
    }
    putchar('\n'); // Add a newline for cleaner output
}

int main()
{
    unsigned long int n = 15;

    printf("Binary representation of %lu is: ", n);
    print_binary_masking(n);

    return 0;
}
