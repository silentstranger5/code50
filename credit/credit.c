#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for input a number
    long number = get_long("Number: ");

    // Count length of the number
    int length = 0;
    for (long i = number; i > 0; i /= 10)
    {
        length++;
    }

    // Calculate checksum
    long divisor = 10;
    int first_digits = 0, summ = 0;
    for (int i = 0; i < length; i++)
    {
        // Calculate value of a digit
        int digit = (number % divisor) / (divisor / 10);

        // Increase the summ value
        if (i % 2 == 0)
        {
            summ += digit;
        }
        else
        {
            summ += ((digit * 2) % 10) + ((digit * 2) / 10);
        }

        // Calculate value of the first two digits
        if (i == digits_number - 3)
        {
            first_digits = number / divisor;
        }

        // Increase divisor
        divisor *= 10;
    }

    // Evaluate conditions
    if (length == 15 && (first_digits == 34 || first_digits == 37) && summ % 10 == 0)
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (first_digits > 50 && first_digits < 56) && summ % 10 == 0)
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && first_digits / 10 == 4 && summ % 10 == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
