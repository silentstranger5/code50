#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    // Prompt for the user input of minimum value
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // Prompt for the user input of maximum value
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Iterate over user-defined range of numbers
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

// Number primality estimate
bool prime(int number)
{
    // Check if number is greater than one
    if (number > 1)
    {
        // Check if a number is divisible by any number between 2 and the number itself
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
