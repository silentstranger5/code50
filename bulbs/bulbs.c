#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Prompt for input
    string message = get_string("Message: ");

    // Iterate over message characters
    for (int i = 0, l = strlen(message); i < l; i++)
    {
        // Convert character into integer
        int number = (int) message[i];

        // Initialize variables
        int factor = 1;
        int byte = 0;

        // Convert number to binary byte
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            if (number % 2 == 1)
            {
                byte += factor;
            }
            factor *= 10;
            number /= 2;
        }

        // Convert bits of byte to bulbs
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            if (byte % factor / (factor / 10) == 1)
            {
                print_bulb(1);
            }
            else
            {
                print_bulb(0);
            }
            factor /= 10;
        }
        printf("\n");
    }
}

// Print bulb emoji
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
