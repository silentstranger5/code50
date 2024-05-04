#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Declare funtions prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt for input text
    string text = get_string("Text: ");

    // Calculate number of letters, words and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate average number of letters and sentences per 100 words
    float l = letters / ((float) words / 100);
    float s = sentences / ((float) words / 100);

    // Calculate total index
    float index = 0.0588 * l - 0.296 * s - 15.8;

    // Calculate grade level by rounding index
    int grade = round(index);

    // Output grade level
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Count the number of letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// Count the number of words
int count_words(string text)
{
    int words = 1;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (isblank(text[i]))
        {
            words++;
        }
    }
    return words;
}

// Count the number of sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
