#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string substitution(string key, string text);

int main(int argc, string argv[])
{
    // Check for correct number of the arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check for correct length of the key
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check for correctness of the key contents
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
        for (int j = 0; j < l; j++)
        {
            if (i != j && argv[1][i] == argv[1][j])
            {
                printf("Key must contain each letter exactly once.\n");
                return 1;
            }
        }
    }

    // Prompt for input
    string text = get_string("plaintext: ");

    // Output ciphertext
    printf("ciphertext: %s\n", substitution(argv[1], text));
}

// Substitute plaintext
string substitution(string key, string text)
{
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        int pointer = 0;
        if (isupper(text[i]))
        {
            text[i] = toupper(key[text[i] - 'A']);
        }
        else if (islower(text[i]))
        {
            text[i] = tolower(key[text[i] - 'a']);
        }
    }
    return text;
}
