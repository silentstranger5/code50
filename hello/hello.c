#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for input user name
    string name = get_string("What's your name? ");

    // Print message
    printf("hello, %s\n", name);
}
