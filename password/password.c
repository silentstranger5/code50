// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    // Prompt for input the password
    string password = get_string("Enter your password: ");

    // Check if password is correct
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // Declare boolean variables of password conditions
    bool islower = false;
    bool isupper = false;
    bool isdigit = false;
    bool issymbol = false;

    // Check for conditions
    for (int i = 0, l = strlen(password); i < l; i++)
    {
        if (islower(password[i]))
        {
            islower = true;
        }
        else if (isupper(password[i]))
        {
            isupper = true;
        }
        else if (isdigit(password[i]))
        {
            isdigit = true;
        }
        else
        {
            issymbol = true;
        }
    }

    // Return boolean value
    if (islower && isupper && isdigit && issymbol)
    {
        return true;
    }
    else
    {
        return false;
    }
}
