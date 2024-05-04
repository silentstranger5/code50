#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    // Prompt for input the number of weeks
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    // Prompt for input the number of hours for each week
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    // Prompt for input the calculation mode
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    // Output the number of hours
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    // Calculate total amount of hours
    float summ = 0.0;
    for (int i = 0; i < weeks; i++)
    {
        summ += hours[i];
    }

    // Calculate average number of hours
    float average = summ / weeks;

    // Output the number of hours depending on user-provided mode
    if (output == 'T')
    {
        return summ;
    }
    else
    {
        return average;
    }
}
