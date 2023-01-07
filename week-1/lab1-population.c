#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for minimum size of the population, loop if number less than 9
    int min_size;
    do
    {
        min_size = get_int("Enter minimum size of the population: ");
    }
    while (min_size < 9);

    // Prompt user for maximum size of the population, loop if number less than minimum size
    int max_size;
    do
    {
        max_size = get_int("Enter the maximum size of the population: ");
    }
    while (max_size < min_size);

    // Calculate number of years until the max population is reached
    int years = 0;
    // If starting population same as ending population print 0 years
    if (min_size == max_size)
    {
        printf("Years: %i\n", years);
        return years;

    }
    else
    {
        do
        {
            min_size = min_size + ((min_size / 3) - (min_size / 4));
            years++;
        }
        while (min_size < max_size);
    }
    // Print number of years population reached its maximum
    printf("Years: %i\n", years);
}
