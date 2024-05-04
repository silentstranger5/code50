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

    // Print the pyramid

    // Iterate over rows
    for (int i = 1; i < height + 1; i++)
    {
        // Print spaces before hashes
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // Print hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // Transit to a new line
        printf("\n");
    }
}
