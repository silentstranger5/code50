#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for input height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Iterate over rows
    for (int i = 1; i <= height; i++)
    {
        // Print spaces before the hashes of the left pyramid
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // Print hashes of the left pyramid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // Print gap between pyramids
        for (int j = 0; j < 2; j++)
        {
            printf(" ");
        }

        // Print hashes of the right pyramid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // Transit to a new line
        printf("\n");
    }
}
