#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    // Prompt for input a positive integer
    string input = get_string("Enter a positive integer: ");

    // Check if input is valid
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    // Base case: length of string is one
    if (strlen(input) == 1)
    {
        return input[0] - '0';
    }

    // Convert digits recursively
    else
    {
        int digit = input[strlen(input) - 1] - '0';
        input[strlen(input) - 1] = '\0';
        return digit + 10 * convert(input);
    }
}
