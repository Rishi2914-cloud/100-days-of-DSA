#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int left, right;
    int isPalindrome = 1;   // Assume true initially

    printf("Enter a string: ");
    scanf("%s", s);

    left = 0;
    right = strlen(s) - 1;

    // Two pointer comparison
    while (left < right)
    {
        if (s[left] != s[right])
        {
            isPalindrome = 0;  // Not a palindrome
            break;
        }

        left++;
        right--;
    }

    if (isPalindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is NOT a palindrome.\n");

    return 0;
}
