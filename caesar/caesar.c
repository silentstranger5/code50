#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string text);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Check for command usage of the arguments
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert first argument into a number
    int step = atoi(argv[1]);

    // Prompt for input
    string text = get_string("plaintext: ");

    // Output ciphertext
    printf("ciphertext: ");
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        printf("%c", rotate(text[i], step));
    }
    printf("\n");
}

// Check if string contains only digits
bool only_digits(string text)
{
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}

// Rotate character alphabetical position by step
char rotate(char c, int n)
{
    if (isupper(c))
    {
        c = (c - 'A' + n) % 26 + 'A';
    }
    else if (islower(c))
    {
        c = (c - 'a' + n) % 26 + 'a';
    }
    return c;
}
