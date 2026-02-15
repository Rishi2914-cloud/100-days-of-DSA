#include <stdio.h>

// Recursive function to find nth Fibonacci number
int fib(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Recursive case
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Fibonacci is not defined for negative numbers.\n");
    }
    else
    {
        printf("Fibonacci number at position %d is: %d\n", n, fib(n));
    }

    return 0;
}
