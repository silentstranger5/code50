// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    // Check for appropriate number of the arguments
    if (argc != 2)
    {
        printf("Usage: ./no-vowels.c word\n");
        return 1;
    }
    // Output replaced string
    printf("%s\n", replace(argv[1]));
}

// Replace vowels with digits
string replace(string word)
{
    for (int i = 0, l = strlen(word); i < l; i++)
    {
        switch (word[i])
        {
        case 'a':
            word[i] = '6';
            break;
        case 'e':
            word[i] = '3';
            break;
        case 'i':
            word[i] = '1';
            break;
        case 'o':
            word[i] = '0';
            break;
        }
    }
    return word;
}
