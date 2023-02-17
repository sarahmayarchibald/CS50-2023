#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    // Prompt user for number of weeks
    int weeks = get_int("Number of weeks taking CS50: ");
    // Declare array of hours and number of weeks
    int hours[weeks];

    // Prompt user for number of hours per week
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    // Change input to upper case
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    // print result
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

float calc_hours(int hours[], int weeks, char output)
{
    // Declare variables starting at 0
    float totalHours = 0;
    float averageHours = 0;

    // Iterate over each week's number of hours
    for (int i = 0; i < weeks; i++)
    {
        totalHours += hours[i];
    }

    // If output is T for Total, return the total number of hours
    if (output == 'T')
    {
        return totalHours;
    }
    // If output is A for Average, return the average number of hours
    else if (output == 'A')
    {
        averageHours = totalHours / weeks;
        return averageHours;
    }

    return 0;
}
