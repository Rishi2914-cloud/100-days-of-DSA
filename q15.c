#include <stdio.h>

// Recursive function to calculate a^b
long long power(int a, int b)
{
    // Base case
    if (b == 0)
        return 1;

    // Recursive case
    return a * power(a, b - 1);
}

int main()
{
    int a, b;

    printf("Enter base (a) and exponent (b): ");
    scanf("%d %d", &a, &b);

    if (b < 0)
    {
        printf("This program does not handle negative exponents.\n");
    }
    else
    {
        long long result = power(a, b);
        printf("%d^%d = %lld\n", a, b, result);
    }

    return 0;
}
